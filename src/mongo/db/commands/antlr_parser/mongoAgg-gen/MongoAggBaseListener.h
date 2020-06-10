
// Generated from MongoAgg.g4 by ANTLR 4.8

#pragma once


#include "MongoAggListener.h"
#include "antlr4-runtime.h"


/**
 * This class provides an empty implementation of MongoAggListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class MongoAggBaseListener : public MongoAggListener {
public:
    virtual void enterAggregate(MongoAggParser::AggregateContext* /*ctx*/) override {}
    virtual void exitAggregate(MongoAggParser::AggregateContext* /*ctx*/) override {}

    virtual void enterObject(MongoAggParser::ObjectContext* /*ctx*/) override {}
    virtual void exitObject(MongoAggParser::ObjectContext* /*ctx*/) override {}

    virtual void enterKeyValPair(MongoAggParser::KeyValPairContext* /*ctx*/) override {}
    virtual void exitKeyValPair(MongoAggParser::KeyValPairContext* /*ctx*/) override {}

    virtual void enterFieldName(MongoAggParser::FieldNameContext* /*ctx*/) override {}
    virtual void exitFieldName(MongoAggParser::FieldNameContext* /*ctx*/) override {}

    virtual void enterString(MongoAggParser::StringContext* /*ctx*/) override {}
    virtual void exitString(MongoAggParser::StringContext* /*ctx*/) override {}

    virtual void enterValue(MongoAggParser::ValueContext* /*ctx*/) override {}
    virtual void exitValue(MongoAggParser::ValueContext* /*ctx*/) override {}

    virtual void enterPipeline(MongoAggParser::PipelineContext* /*ctx*/) override {}
    virtual void exitPipeline(MongoAggParser::PipelineContext* /*ctx*/) override {}

    virtual void enterStageObj(MongoAggParser::StageObjContext* /*ctx*/) override {}
    virtual void exitStageObj(MongoAggParser::StageObjContext* /*ctx*/) override {}

    virtual void enterStage(MongoAggParser::StageContext* /*ctx*/) override {}
    virtual void exitStage(MongoAggParser::StageContext* /*ctx*/) override {}

    virtual void enterStageArray(MongoAggParser::StageArrayContext* /*ctx*/) override {}
    virtual void exitStageArray(MongoAggParser::StageArrayContext* /*ctx*/) override {}

    virtual void enterCollArg(MongoAggParser::CollArgContext* /*ctx*/) override {}
    virtual void exitCollArg(MongoAggParser::CollArgContext* /*ctx*/) override {}

    virtual void enterPipelineArg(MongoAggParser::PipelineArgContext* /*ctx*/) override {}
    virtual void exitPipelineArg(MongoAggParser::PipelineArgContext* /*ctx*/) override {}

    virtual void enterProjectStage(MongoAggParser::ProjectStageContext* /*ctx*/) override {}
    virtual void exitProjectStage(MongoAggParser::ProjectStageContext* /*ctx*/) override {}

    virtual void enterCountStage(MongoAggParser::CountStageContext* /*ctx*/) override {}
    virtual void exitCountStage(MongoAggParser::CountStageContext* /*ctx*/) override {}

    virtual void enterLimitStage(MongoAggParser::LimitStageContext* /*ctx*/) override {}
    virtual void exitLimitStage(MongoAggParser::LimitStageContext* /*ctx*/) override {}

    virtual void enterSkipStage(MongoAggParser::SkipStageContext* /*ctx*/) override {}
    virtual void exitSkipStage(MongoAggParser::SkipStageContext* /*ctx*/) override {}


    virtual void enterEveryRule(antlr4::ParserRuleContext* /*ctx*/) override {}
    virtual void exitEveryRule(antlr4::ParserRuleContext* /*ctx*/) override {}
    virtual void visitTerminal(antlr4::tree::TerminalNode* /*node*/) override {}
    virtual void visitErrorNode(antlr4::tree::ErrorNode* /*node*/) override {}
};
