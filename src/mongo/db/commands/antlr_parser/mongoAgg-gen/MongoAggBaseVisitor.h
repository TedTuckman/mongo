
// Generated from MongoAgg.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MongoAggVisitor.h"


/**
 * This class provides an empty implementation of MongoAggVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MongoAggBaseVisitor : public MongoAggVisitor {
public:

  virtual antlrcpp::Any visitAggregate(MongoAggParser::AggregateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(MongoAggParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyValPair(MongoAggParser::KeyValPairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldName(MongoAggParser::FieldNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(MongoAggParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(MongoAggParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPipeline(MongoAggParser::PipelineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStageObj(MongoAggParser::StageObjContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStage(MongoAggParser::StageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStageArray(MongoAggParser::StageArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollArg(MongoAggParser::CollArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPipelineArg(MongoAggParser::PipelineArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProjectStage(MongoAggParser::ProjectStageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCountStage(MongoAggParser::CountStageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimitStage(MongoAggParser::LimitStageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSkipStage(MongoAggParser::SkipStageContext *ctx) override {
    return visitChildren(ctx);
  }


};

