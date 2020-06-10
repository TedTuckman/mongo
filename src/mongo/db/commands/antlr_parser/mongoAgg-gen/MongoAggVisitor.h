
// Generated from MongoAgg.g4 by ANTLR 4.8

#pragma once


#include "MongoAggParser.h"
#include "antlr4-runtime.h"


/**
 * This class defines an abstract visitor for a parse tree
 * produced by MongoAggParser.
 */
class MongoAggVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:
    /**
     * Visit parse trees produced by MongoAggParser.
     */
    virtual antlrcpp::Any visitAggregate(MongoAggParser::AggregateContext* context) = 0;

    virtual antlrcpp::Any visitObject(MongoAggParser::ObjectContext* context) = 0;

    virtual antlrcpp::Any visitKeyValPair(MongoAggParser::KeyValPairContext* context) = 0;

    virtual antlrcpp::Any visitFieldName(MongoAggParser::FieldNameContext* context) = 0;

    virtual antlrcpp::Any visitString(MongoAggParser::StringContext* context) = 0;

    virtual antlrcpp::Any visitValue(MongoAggParser::ValueContext* context) = 0;

    virtual antlrcpp::Any visitPipeline(MongoAggParser::PipelineContext* context) = 0;

    virtual antlrcpp::Any visitStageObj(MongoAggParser::StageObjContext* context) = 0;

    virtual antlrcpp::Any visitStage(MongoAggParser::StageContext* context) = 0;

    virtual antlrcpp::Any visitStageArray(MongoAggParser::StageArrayContext* context) = 0;

    virtual antlrcpp::Any visitCollArg(MongoAggParser::CollArgContext* context) = 0;

    virtual antlrcpp::Any visitPipelineArg(MongoAggParser::PipelineArgContext* context) = 0;

    virtual antlrcpp::Any visitProjectStage(MongoAggParser::ProjectStageContext* context) = 0;

    virtual antlrcpp::Any visitCountStage(MongoAggParser::CountStageContext* context) = 0;

    virtual antlrcpp::Any visitLimitStage(MongoAggParser::LimitStageContext* context) = 0;

    virtual antlrcpp::Any visitSkipStage(MongoAggParser::SkipStageContext* context) = 0;
};
