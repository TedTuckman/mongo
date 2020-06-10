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

#pragma once

#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wattributes"
#include "antlr4-runtime.h"
#include "mongoAgg-gen/MongoAggBaseVisitor.h"
#pragma GCC diagnostic pop

#include "mongo/db/pipeline/expression_context.h"
#include "mongo/db/pipeline/pipeline.h"
#include "mongo/db/pipeline/pipeline_d.h"
namespace mongo {

class AggWalker : public MongoAggBaseVisitor {
public:
    antlrcpp::Any visitAggregate(MongoAggParser::AggregateContext* ctx) override;

    antlrcpp::Any visitObject(MongoAggParser::ObjectContext* ctx) override;

    antlrcpp::Any visitKeyValPair(MongoAggParser::KeyValPairContext* ctx) override;

    antlrcpp::Any visitFieldName(MongoAggParser::FieldNameContext* context) override;

    antlrcpp::Any visitString(MongoAggParser::StringContext* ctx) override;

    antlrcpp::Any visitValue(MongoAggParser::ValueContext* ctx) override;

    antlrcpp::Any visitPipeline(MongoAggParser::PipelineContext* ctx) override;

    antlrcpp::Any visitStageObj(MongoAggParser::StageObjContext* ctx) override;

    antlrcpp::Any visitStage(MongoAggParser::StageContext* ctx) override;

    antlrcpp::Any visitStageArray(MongoAggParser::StageArrayContext* ctx) override;

    antlrcpp::Any visitCollArg(MongoAggParser::CollArgContext* ctx) override;

    antlrcpp::Any visitPipelineArg(MongoAggParser::PipelineArgContext* ctx) override;

    antlrcpp::Any visitProjectStage(MongoAggParser::ProjectStageContext* ctx) override;

    antlrcpp::Any visitCountStage(MongoAggParser::CountStageContext* ctx) override;

    antlrcpp::Any visitLimitStage(MongoAggParser::LimitStageContext* ctx) override;

    antlrcpp::Any visitSkipStage(MongoAggParser::SkipStageContext* ctx) override;

    // antlrcpp::Any visitUnionStage(MongoAggParser::UnionStageContext *ctx) override;

    // antlrcpp::Any visitUnionArgs(MongoAggParser::UnionArgsContext *ctx) override;

    std::unique_ptr<Pipeline, PipelineDeleter> toPipeline(
        MongoAggParser::AggregateContext* ctx,
        const boost::intrusive_ptr<ExpressionContext>& expCtx);

    virtual antlrcpp::Any visitTerminal(antlr4::tree::TerminalNode* node) override;

    void setExpressionContext(boost::intrusive_ptr<ExpressionContext> expCtx) {
        _expCtx = expCtx;
    }

protected:
    virtual antlrcpp::Any defaultResult() override;

private:
    boost::intrusive_ptr<ExpressionContext> _expCtx = nullptr;
    Pipeline::SourceContainer _stages;
};
}  // namespace mongo
