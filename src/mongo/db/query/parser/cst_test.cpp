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
#include "mongo/db/pipeline/document_source_union_with.h"
#include "mongo/db/query/parser/bson_lexer.h"
#include "mongo/db/query/parser/cst_node.h"
#include "mongo/db/query/parser/mql_parser_gen.hpp"

#include "mongo/unittest/unittest.h"

namespace mongo {
namespace {

using CSTPipeline = std::vector<boost::intrusive_ptr<mongo::CSTNode>>;

class CSTTest : public AggregationContextFixture {
public:
    std::vector<BSONObj> parseAndSerialize(BSONObj input) {
        CSTPipeline output;
        BSONLexer driver(std::move(input["pipeline"].Array()));
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());

        // Now translate from CST nodes to a Pipeline.
        CSTPipelineVisitor visitor(getExpCtx());
        for (auto&& node : output) {
            node->acceptVisitor(&visitor);
        }
        return std::move(visitor.releasePipeline()->serializeToBson());
    }
};

TEST_F(CSTTest, ProjectSimple) {
    CSTPipeline output;
    auto input = fromjson("{pipeline: [{$project: {a: 1}}]}");
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    // parseTree.set_debug_level(true);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, ProjectSimpleWithReservedFieldName) {
    CSTPipeline output;
    // 'coll' is a reserved keyword, it is a named argument for several stages.
    auto input = fromjson("{pipeline: [{$project: {coll: 1}}]}");
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    // parseTree.set_debug_level(true);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, ProjectInvalid) {
    CSTPipeline output;
    auto input = fromjson("{pipeline: [{$project: 1}]}");
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(1, parseTree.parse());
}

TEST_F(CSTTest, ProjectSimpleTranslation) {
    auto translated = parseAndSerialize(fromjson("{pipeline: [{$project: {_id: 0, a: 1}}]}"));
    ASSERT_EQ(1, translated.size());
    ASSERT_BSONOBJ_EQ(translated[0], fromjson("{$project: {a: true, _id: false}}"));

    translated = parseAndSerialize(fromjson("{pipeline: [{$project: {_id: 0}}]}"));
    ASSERT_EQ(1, translated.size());
    ASSERT_BSONOBJ_EQ(translated[0], fromjson("{$project: {_id: false}}"));
}

TEST_F(CSTTest, ProjectVariousNumericArguments) {
    {
        CSTPipeline output;
        auto input = fromjson("{pipeline: [{$project: {a: 1.0}}]}");
        BSONLexer driver(std::move(input["pipeline"].Array()));
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());
    }

    {
        CSTPipeline output;
        auto input = fromjson("{pipeline: [{$project: {a: true}}]}");
        BSONLexer driver(std::move(input["pipeline"].Array()));
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());
    }

    {
        CSTPipeline output;
        auto input = fromjson("{pipeline: [{$project: {a: NumberLong(1)}}]}");
        BSONLexer driver(std::move(input["pipeline"].Array()));
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());
    }

    {
        CSTPipeline output;
        auto input = fromjson("{pipeline: [{$project: {a: '1'}}]}");
        BSONLexer driver(std::move(input["pipeline"].Array()));
        auto parseTree = MQLBisonParser(driver, &output);
        ASSERT_EQ(0, parseTree.parse());
    }
}

TEST_F(CSTTest, UnionValid) {
    CSTPipeline output;
    auto input = BSON("pipeline" << BSON_ARRAY(BSON("$unionWith"
                                                    << "test")));
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    // parseTree.set_debug_level(true);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, UnionNoPipelineSpecified) {
    CSTPipeline output;
    auto input = BSON("pipeline" << BSON_ARRAY(BSON("$unionWith" << BSON("coll"
                                                                         << "test"))));
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, UnionEmptyPipeline) {
    CSTPipeline output;
    auto input = fromjson("{pipeline: [{$unionWith: {coll: 'test', pipeline: []}}]}");
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, UnionValidNestedPipeline) {
    CSTPipeline output;
    auto input = BSON(
        "pipeline" << BSON_ARRAY(BSON("$unionWith" << BSON("coll"
                                                           << "test"
                                                           << "pipeline"
                                                           << BSON_ARRAY(BSON("$unionWith"
                                                                              << "otherColl"))))));
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, UnionValidSwitchedArgs) {
    CSTPipeline output;
    auto input = BSON("pipeline" << BSON_ARRAY(
                          BSON("$unionWith" << BSON("pipeline" << BSON_ARRAY(BSON("$unionWith"
                                                                                  << "otherColl"))
                                                               << "coll"
                                                               << "test"))));
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    // parseTree.set_debug_level(false);
    ASSERT_EQ(0, parseTree.parse());
}

TEST_F(CSTTest, UnionInvalidUnion) {
    CSTPipeline output;
    auto input = BSON("pipeline" << BSON_ARRAY(BSON("$unionWith" << BSON("coll" << 1))));
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(1, parseTree.parse());
}

TEST_F(CSTTest, UnionInvalidNestedPipeline) {
    CSTPipeline output;
    auto input = fromjson("{pipeline: [{$unionWith: {coll: 'test', pipeline: ['illegal']}}]}");
    BSONLexer driver(std::move(input["pipeline"].Array()));
    auto parseTree = MQLBisonParser(driver, &output);
    ASSERT_EQ(1, parseTree.parse());
}

TEST_F(CSTTest, UnionBasicTranslateToPipeline) {
    auto translated = parseAndSerialize(fromjson("{pipeline: [{$unionWith: 'test'}]}"));
    ASSERT_EQ(1, translated.size());
    ASSERT_BSONOBJ_EQ(translated[0], fromjson("{$unionWith: {coll: 'test', pipeline: []}}"));
}

TEST_F(CSTTest, UnionNestedTranslateToPipeline) {
    auto translated = parseAndSerialize(fromjson(
        "{pipeline: [{$unionWith: {coll: 'test', pipeline: [{$unionWith: 'otherColl'}]}}]}"));
    ASSERT_EQ(1, translated.size());
    ASSERT_BSONOBJ_EQ(translated[0],
                      fromjson("{$unionWith: {coll: 'test', pipeline: [{$unionWith: {coll: "
                               "'otherColl', pipeline: []}}]}}]"));
}

}  // namespace
}  // namespace mongo
