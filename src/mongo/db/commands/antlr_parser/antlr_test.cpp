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

#include "mongo/db/pipeline/aggregation_context_fixture.h"

#include "mongo/unittest/unittest.h"
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wattributes"
// #include "third_party/antlr4/runtime/Cpp/runtime/src/antlr4-runtime.h"
#include "antlr4-runtime.h"
#include "mongo/db/commands/antlr_parser/aggErrorListener.h"
#include "mongo/db/commands/antlr_parser/aggWalker.h"
#include "mongoAgg-gen/MongoAggLexer.h"
#include "mongoAgg-gen/MongoAggParser.h"
#pragma GCC diagnostic pop
namespace mongo {
namespace {

class TestErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override {
        std::string errMsg = "Syntax error from parser on " + std::to_string(line) + ":" +
            std::to_string(charPositionInLine) + " with msg: " + msg +
            "| Offending symbol was: " + offendingSymbol->getText();
        errors.push_back(errMsg);
    }
    std::vector<std::string> errors;
};

class ANTLRTest : public AggregationContextFixture {
public:
    auto tokenizeAndParse(BSONObj obj) {
        auto cmdString = obj.toString();
        antlr4::ANTLRInputStream input(cmdString);
        MongoAggLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        tokens.fill();
        MongoAggParser parser(&tokens);
        parser.removeErrorListeners();
        TestErrorListener errorListener;
        parser.addErrorListener(&errorListener);
        auto ctx = parser.aggregate();
        _errs = errorListener.errors;
        return ctx;
    }

    BSONObj buildFromPipeline(std::string pipeline) {
        auto cmdString = "{aggregate: \"test\", pipeline: " + pipeline + "}";
        return fromjson(cmdString);
    }

    void logErrors() {
        for (const auto& err : _errs) {
            std::cout << err << '\n';
        }
    }
    std::vector<std::string> _errs;
};

TEST_F(ANTLRTest, LimitSimple) {
    auto cmdObj = buildFromPipeline("[{$limit: 1}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, SkipSimple) {
    auto cmdObj = buildFromPipeline("[{$skip: 1}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, CountSimple) {
    auto cmdObj = buildFromPipeline("[{$count: \"count\"}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, ProjectSimple) {
    auto cmdObj = buildFromPipeline("[{$project: {test: 1}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, MultipleInclusionProjection) {
    auto cmdObj = buildFromPipeline("[{$project: {test: 1, val: 1, other: 1}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, MixedInclusionExclusionProjection) {
    auto cmdObj = buildFromPipeline("[{$project: {test: 1, val: 0, other: 1}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
}

TEST_F(ANTLRTest, ValueProjectSimple) {
    auto cmdObj = buildFromPipeline("[{$project: {test: 7}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, ValueProjectString) {
    auto cmdObj = buildFromPipeline("[{$project: {test: \"sphinx\"}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
    ASSERT(_errs.empty());
}

TEST_F(ANTLRTest, MultipleValueProjection) {
    auto cmdObj = buildFromPipeline("[{$project: {test: \"first\", val: 6, other: \"chimera\"}}]");
    tokenizeAndParse(cmdObj);
    logErrors();
}

}  // namespace
}  // namespace mongo
