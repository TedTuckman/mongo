
// Generated from MongoAgg.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MongoAggParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MongoAggParser.
 */
class  MongoAggListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAggregate(MongoAggParser::AggregateContext *ctx) = 0;
  virtual void exitAggregate(MongoAggParser::AggregateContext *ctx) = 0;

  virtual void enterObject(MongoAggParser::ObjectContext *ctx) = 0;
  virtual void exitObject(MongoAggParser::ObjectContext *ctx) = 0;

  virtual void enterKeyValPair(MongoAggParser::KeyValPairContext *ctx) = 0;
  virtual void exitKeyValPair(MongoAggParser::KeyValPairContext *ctx) = 0;

  virtual void enterFieldName(MongoAggParser::FieldNameContext *ctx) = 0;
  virtual void exitFieldName(MongoAggParser::FieldNameContext *ctx) = 0;

  virtual void enterString(MongoAggParser::StringContext *ctx) = 0;
  virtual void exitString(MongoAggParser::StringContext *ctx) = 0;

  virtual void enterValue(MongoAggParser::ValueContext *ctx) = 0;
  virtual void exitValue(MongoAggParser::ValueContext *ctx) = 0;

  virtual void enterPipeline(MongoAggParser::PipelineContext *ctx) = 0;
  virtual void exitPipeline(MongoAggParser::PipelineContext *ctx) = 0;

  virtual void enterStageObj(MongoAggParser::StageObjContext *ctx) = 0;
  virtual void exitStageObj(MongoAggParser::StageObjContext *ctx) = 0;

  virtual void enterStage(MongoAggParser::StageContext *ctx) = 0;
  virtual void exitStage(MongoAggParser::StageContext *ctx) = 0;

  virtual void enterStageArray(MongoAggParser::StageArrayContext *ctx) = 0;
  virtual void exitStageArray(MongoAggParser::StageArrayContext *ctx) = 0;

  virtual void enterCollArg(MongoAggParser::CollArgContext *ctx) = 0;
  virtual void exitCollArg(MongoAggParser::CollArgContext *ctx) = 0;

  virtual void enterPipelineArg(MongoAggParser::PipelineArgContext *ctx) = 0;
  virtual void exitPipelineArg(MongoAggParser::PipelineArgContext *ctx) = 0;

  virtual void enterProjectStage(MongoAggParser::ProjectStageContext *ctx) = 0;
  virtual void exitProjectStage(MongoAggParser::ProjectStageContext *ctx) = 0;

  virtual void enterCountStage(MongoAggParser::CountStageContext *ctx) = 0;
  virtual void exitCountStage(MongoAggParser::CountStageContext *ctx) = 0;

  virtual void enterLimitStage(MongoAggParser::LimitStageContext *ctx) = 0;
  virtual void exitLimitStage(MongoAggParser::LimitStageContext *ctx) = 0;

  virtual void enterSkipStage(MongoAggParser::SkipStageContext *ctx) = 0;
  virtual void exitSkipStage(MongoAggParser::SkipStageContext *ctx) = 0;


};

