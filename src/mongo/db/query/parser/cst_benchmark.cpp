/**
 *    Copyright (C) 2020-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#include "mongo/platform/basic.h"

#include <benchmark/benchmark.h>
#include <boost/intrusive_ptr.hpp>

#include "mongo/unittest/unittest.h"
#include "mongo/util/assert_util.h"
#include "mongo/util/processinfo.h"
#include "mongo/util/time_support.h"

#include "mongo/db/query/parser/bson_lexer.h"
#include "mongo/db/query/parser/cst_node.h"
#include "mongo/db/query/parser/mql_parser_gen.hpp"

#include "mongo/db/pipeline/aggregation_request.h"
#include "mongo/db/pipeline/expression_context_for_test.h"
#include "mongo/db/pipeline/pipeline.h"
#include "mongo/db/query/projection_ast.h"
#include "mongo/db/query/projection_parser.h"
#include "mongo/db/query/query_test_service_context.h"

#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wattributes"
#include "antlr4-runtime.h"
#include "mongo/db/commands/antlr_parser/aggErrorListener.h"
#include "mongo/db/commands/antlr_parser/aggWalker.h"
#include "mongo/db/commands/antlr_parser/mongoAgg-gen/MongoAggLexer.h"
#include "mongo/db/commands/antlr_parser/mongoAgg-gen/MongoAggParser.h"
#pragma GCC diagnostic pop

namespace mongo {
namespace {

static const auto seed = SecureRandom().nextInt64();
static PseudoRandom rng{seed};

std::string randomField() {
    const StringData kViableChars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"_sd;
    size_t randomStrLength = 5;
    std::string randomStr(randomStrLength, '\0');
    for (std::size_t i = 0; i < randomStrLength; i++) {
        randomStr[i] = kViableChars[rng.nextInt32(kViableChars.size())];
    }

    return randomStr;
}

BSONObj buildSimpleProject(int nFields) {
    std::vector<std::string> genFields;
    BSONObjBuilder projectSpec;
    for (auto i = 0; i < nFields; i++) {
        genFields.emplace_back(randomField());
        projectSpec.append(genFields.back(), "hey");
    }
    return BSON("$project" << projectSpec.obj());
}

}  // namespace

void BM_Bison_project_simple(benchmark::State& state) {
    // std::cout << "Running Bison project with seed " << seed << std::endl;

    auto project = buildSimpleProject(state.range(0));
    auto pipelineObj = BSON("pipeline" << BSON_ARRAY(project));
    // std::cout << "NICKZ pipeline: " << pipelineObj << std::endl;

    // This is where recording starts.
    for (auto keepRunning : state) {
        CSTPipeline output;
        BSONLexer driver(pipelineObj);
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());
        benchmark::ClobberMemory();
    }
}

void BM_ANTLR_project_simple(benchmark::State& state) {
    // ANTLR expects field names of $project to be quoted.
    // auto ss = str::stream();
    auto project = buildSimpleProject(state.range(0));
    auto pipelineObj = BSON("aggregate" << "test" << "pipeline" << BSON_ARRAY(project));
    // ss << "pipeline: [{$project: { ";
    // for (auto i = 0; i < state.range(0); i++) {
        // if (i > 0)
            // ss << ",";
        // ss << "\"" << randomField() << "\": \"hey\"";
    // }
    // ss << "}}]";

    // std::cout << "ANTLR pipeline: " << ss << std::endl;
    // This is where recording starts.
    for (auto keepRunning : state) {
        try {
            auto ss = pipelineObj.toString();
            antlr4::ANTLRInputStream input(ss);  // cmd.toString());
            MongoAggLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            tokens.fill();
            MongoAggParser parser(&tokens);
            benchmark::DoNotOptimize(parser.aggregate());
            // benchmark::DoNotOptimize(parser.pipelineArg());
            benchmark::ClobberMemory();
        } catch (std::invalid_argument& e) {
            std::cout << "ANTLR threw: " << e.what() << std::endl;
        }
    }
}

void BM_baseline_project_simple(benchmark::State& state) {
    auto project = buildSimpleProject(state.range(0));

    QueryTestServiceContext testServiceContext;
    auto opCtx = testServiceContext.makeOperationContext();
    const auto kTestNss = NamespaceString("test.bm");
    AggregationRequest request(kTestNss, {project});
    boost::intrusive_ptr<ExpressionContextForTest> expCtx =
        new ExpressionContextForTest(opCtx.get(), request);

    // This is where recording starts.
    auto projectSpec = project["$project"].embeddedObject();
    for (auto keepRunning : state) {
        auto policies = ProjectionPolicies::aggregateProjectionPolicies();
        benchmark::DoNotOptimize(projection_ast::parse(expCtx, projectSpec, policies));
        benchmark::ClobberMemory();
    }
}

/**
Notes
    * Parsing with ANTLR operates on strictly formatted JSON strings (cannot just use
bson::toString).
    * ANTLR does not include the time to convert from BSON to string
    * ANTLR parses at the top level aggregate command (likely not relevant)
    * Both parsers traverse the $project spec
        * Bison stores them as a set of KV pairs
        * ANTLR builds a BSON per KV pair, then collapses into a single BSON at the end
    * Baseline is stressing the projection_ast parser, which is the closest thing to a CST for
$project
 */
BENCHMARK(BM_baseline_project_simple)->Arg(1)->Arg(10)->Arg(100)->Arg(1000);
BENCHMARK(BM_Bison_project_simple)->Arg(1)->Arg(10)->Arg(100)->Arg(1000);
BENCHMARK(BM_ANTLR_project_simple)->Arg(1)->Arg(10)->Arg(100)->Arg(1000);

}  // namespace mongo
