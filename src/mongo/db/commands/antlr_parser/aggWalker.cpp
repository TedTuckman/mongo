/**
 *    Copyright (C) 2018-present MongoDB, Inc.
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

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kQuery

#include "mongo/platform/basic.h"

#include "mongo/db/commands/antlr_parser/aggWalker.h"
#include "mongo/db/pipeline/document_source_count.h"
#include "mongo/db/pipeline/document_source_limit.h"
#include "mongo/db/pipeline/document_source_project.h"
#include "mongo/db/pipeline/document_source_skip.h"
#include "mongo/logv2/log.h"

namespace mongo {

namespace {
void logEntering(std::string name, std::string text) {
    // logd("---TEDLOG in {}  +++{}+++---", name, text);
}
void logLeaving(std::string name) {
    // logd("---TEDLOG leaving {}", name);
}
void logLeaving(std::string name, std::string content) {
    // logd("---TEDLOG leaving {} with {}", name, content);
}
}  // namespace

antlrcpp::Any AggWalker::visitAggregate(MongoAggParser::AggregateContext* ctx) {
    logEntering(__func__, ctx->getText());
    // visitPipeline(ctx->pipeline());
    visitPipelineArg(ctx->pipelineArg());
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitObject(MongoAggParser::ObjectContext* ctx) {
    logEntering(__func__, ctx->getText());
    auto numPairs = ctx->keyValPair().size();
    BSONObjBuilder bob;
    for (unsigned long i = 0; i < numPairs; ++i) {
        auto childRes = visitKeyValPair(ctx->keyValPair(i));
        invariant(childRes.is<BSONObj>());
        auto childObj = childRes.as<BSONObj>();
        bob.appendElements(childObj);
    }
    auto retObj = bob.done();
    logLeaving(__func__, retObj.toString(false));
    return retObj;
}

antlrcpp::Any AggWalker::visitKeyValPair(MongoAggParser::KeyValPairContext* ctx) {
    logEntering(__func__, ctx->getText());
    auto fieldName = visitFieldName(ctx->fieldName());
    auto value = visitValue(ctx->value());
    logLeaving(__func__);
    invariant(fieldName.is<std::string>());
    if (value.is<std::string>()) {
        return BSON(fieldName.as<std::string>() << value.as<std::string>());
    } else if (value.is<long>()) {
        return BSON(fieldName.as<std::string>() << value.as<long>());
    } else {
        logd("keyValPair unknown value type");
    }
    MONGO_UNREACHABLE;
}

antlrcpp::Any AggWalker::visitFieldName(MongoAggParser::FieldNameContext* ctx) {
    logEntering(__func__, ctx->getText());
    // I don't think this is possible, but lets verify.
    invariant(!ctx->STRING() || !ctx->string());
    if (ctx->STRING()) {
        logLeaving(__func__);
        return ctx->STRING()->getText();
    }
    // Its a quoted string. UNTESTED PATH
    auto qString = visitString(ctx->string());
    invariant(qString.is<std::string>());
    logLeaving(__func__, qString.as<std::string>());
    return qString;
}

antlrcpp::Any AggWalker::visitString(MongoAggParser::StringContext* ctx) {
    logEntering(__func__, ctx->getText());
    auto tNode = ctx->QSTRING();
    auto string = tNode->getText();
    // Filter off quotation marks. TODO: Move this to grammar
    auto retStr = string.substr(1, string.length() - 2);
    logLeaving(__func__, retStr);
    return retStr;
}

antlrcpp::Any AggWalker::visitValue(MongoAggParser::ValueContext* ctx) {
    logEntering(__func__, ctx->getText());
    if (ctx->NUMBER()) {
        auto numStr = ctx->NUMBER()->getText();
        logd("visitValue returning {}", numStr);
        return std::stol(numStr);
    } else if (ctx->string()) {
        auto qString = visitString(ctx->string());
        invariant(qString.is<std::string>());
        logLeaving(__func__, qString.as<std::string>());
        return qString;
    } else if (ctx->object()) {
        auto childRet = visitObject(ctx->object());
        invariant(childRet.is<BSONObj>());
        logLeaving(__func__, childRet.as<BSONObj>().toString(false));
        return childRet;
    }
    logd("visitValue returning unreachable");
    MONGO_UNREACHABLE;
}

antlrcpp::Any AggWalker::visitPipeline(MongoAggParser::PipelineContext* ctx) {
    logEntering(__func__, ctx->getText());
    if (ctx->stageArray()) {
        visitStageArray(ctx->stageArray());
    }
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitStageObj(MongoAggParser::StageObjContext* ctx) {
    logEntering(__func__, ctx->getText());
    auto retVal = visitStage(ctx->stage());
    logLeaving(__func__);
    return retVal;
}

antlrcpp::Any AggWalker::visitStage(MongoAggParser::StageContext* ctx) {
    logEntering(__func__, ctx->getText());
    if (ctx->projectStage()) {
        auto proj = visitProjectStage(ctx->projectStage());
        logLeaving(__func__);
        return proj;
    } else if (auto stageCtx = ctx->countStage()) {
        return visitCountStage(stageCtx);
    } else if (auto stageCtx = ctx->limitStage()) {
        return visitLimitStage(stageCtx);
    } else if (auto stageCtx = ctx->skipStage()) {
        return visitSkipStage(stageCtx);
        // } else if (auto unionCtx = ctx->unionStage()) {
        // return visitUnionStage(unionCtx);
    }
    MONGO_UNREACHABLE;
}

antlrcpp::Any AggWalker::visitStageArray(MongoAggParser::StageArrayContext* ctx) {
    logEntering(__func__, ctx->getText());
    auto numPairs = ctx->stageObj().size();
    for (unsigned long i = 0; i < numPairs; ++i) {
        auto childRes = visitStageObj(ctx->stageObj(i));
        invariant(childRes.is<bool>());
    }
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitPipelineArg(MongoAggParser::PipelineArgContext* ctx) {
    invariant(ctx->pipeline());
    return visitPipeline(ctx->pipeline());
}

antlrcpp::Any AggWalker::visitCollArg(MongoAggParser::CollArgContext* ctx) {
    invariant(ctx->string());
    return visitString(ctx->string());
}

antlrcpp::Any AggWalker::visitProjectStage(MongoAggParser::ProjectStageContext* ctx) {
    logEntering(__func__, ctx->getText());
    invariant(ctx->object());
    auto objAny = visitObject(ctx->object());
    invariant(objAny.is<BSONObj>());
    auto stage =
        DocumentSourceProject::create(objAny.as<BSONObj>(), _expCtx, ctx->PROJECT()->getText());
    _stages.push_back(stage);
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitCountStage(MongoAggParser::CountStageContext* ctx) {
    logEntering(__func__, ctx->getText());
    invariant(ctx->COUNT() && ctx->string());
    auto countStr = ctx->COUNT()->getText();
    auto valStr = visitString(ctx->string());
    invariant(valStr.is<std::string>());
    // count only has createFromBSON
    auto obj = BSON(countStr << valStr.as<std::string>());
    auto stageList = DocumentSourceCount::createFromBson(obj.firstElement(), _expCtx);
    for (auto& stage : stageList) {
        _stages.push_back(stage);
    }
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitLimitStage(MongoAggParser::LimitStageContext* ctx) {
    logEntering(__func__, ctx->getText());
    invariant(ctx->NUMBER());
    auto numStr = ctx->NUMBER()->getText();
    auto stage = DocumentSourceLimit::create(_expCtx, std::stol(numStr));
    _stages.push_back(stage);
    logLeaving(__func__);
    return true;
}

antlrcpp::Any AggWalker::visitSkipStage(MongoAggParser::SkipStageContext* ctx) {
    logEntering(__func__, ctx->getText());
    invariant(ctx->NUMBER());
    auto numStr = ctx->NUMBER()->getText();
    auto stage = DocumentSourceSkip::create(_expCtx, std::stol(numStr));
    _stages.push_back(stage);
    logLeaving(__func__);
    return true;
}

// antlrcpp::Any AggWalker::visitUnionStage(MongoAggParser::UnionStageContext *ctx) {
// logEntering(__func__, ctx->getText());
// invariant(ctx->unionArgs() || ctx->collArg());
// if (ctx->unionArgs()) {
// // do pipeline stuff
// auto unionArgs = visitUnionArgs(ctx->unionArgs());
// } else if (auto collCtx = ctx->collArg()) {
// auto collAny = visitCollArg(collCtx);
// auto collStr = collAny.as<std::string>();
// }
// logLeaving(__func__);
// return nullptr;
// }

// antlrcpp::Any AggWalker::visitUnionArgs(MongoAggParser::UnionArgsContext *ctx) {
// logEntering(__func__, ctx->getText());
// invariant(ctx->collArg() && ctx->pipelineArg());
// auto collArg = visitCollArg(ctx->collArg());
// auto pipelineArg = visitPipelineArg(ctx->pipelineArg());
// logLeaving(__func__);
// return nullptr;
// }

std::unique_ptr<Pipeline, PipelineDeleter> AggWalker::toPipeline(
    MongoAggParser::AggregateContext* ctx, const boost::intrusive_ptr<ExpressionContext>& expCtx) {
    _expCtx = expCtx;
    visitAggregate(ctx);
    return Pipeline::create(std::move(_stages), expCtx);
}

antlrcpp::Any AggWalker::defaultResult() {
    return nullptr;
}
antlrcpp::Any AggWalker::visitTerminal(antlr4::tree::TerminalNode* node) {
    return defaultResult();
}

}  // namespace mongo
