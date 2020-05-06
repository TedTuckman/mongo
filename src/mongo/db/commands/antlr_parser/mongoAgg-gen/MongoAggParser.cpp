
// Generated from MongoAgg.g4 by ANTLR 4.8


#include "MongoAggListener.h"
#include "MongoAggVisitor.h"

#include "MongoAggParser.h"


using namespace antlrcpp;
using namespace antlr4;

MongoAggParser::MongoAggParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MongoAggParser::~MongoAggParser() {
  delete _interpreter;
}

std::string MongoAggParser::getGrammarFileName() const {
  return "MongoAgg.g4";
}

const std::vector<std::string>& MongoAggParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MongoAggParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AggregateContext ------------------------------------------------------------------

MongoAggParser::AggregateContext::AggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::AggregateContext::AGGCMDSTR() {
  return getToken(MongoAggParser::AGGCMDSTR, 0);
}

MongoAggParser::StringContext* MongoAggParser::AggregateContext::string() {
  return getRuleContext<MongoAggParser::StringContext>(0);
}

MongoAggParser::PipelineArgContext* MongoAggParser::AggregateContext::pipelineArg() {
  return getRuleContext<MongoAggParser::PipelineArgContext>(0);
}


size_t MongoAggParser::AggregateContext::getRuleIndex() const {
  return MongoAggParser::RuleAggregate;
}

void MongoAggParser::AggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate(this);
}

void MongoAggParser::AggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate(this);
}


antlrcpp::Any MongoAggParser::AggregateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitAggregate(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::AggregateContext* MongoAggParser::aggregate() {
  AggregateContext *_localctx = _tracker.createInstance<AggregateContext>(_ctx, getState());
  enterRule(_localctx, 0, MongoAggParser::RuleAggregate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(MongoAggParser::T__0);
    setState(33);
    match(MongoAggParser::AGGCMDSTR);
    setState(34);
    match(MongoAggParser::T__1);
    setState(35);
    string();
    setState(36);
    match(MongoAggParser::T__2);
    setState(37);
    pipelineArg();
    setState(38);
    match(MongoAggParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

MongoAggParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MongoAggParser::KeyValPairContext *> MongoAggParser::ObjectContext::keyValPair() {
  return getRuleContexts<MongoAggParser::KeyValPairContext>();
}

MongoAggParser::KeyValPairContext* MongoAggParser::ObjectContext::keyValPair(size_t i) {
  return getRuleContext<MongoAggParser::KeyValPairContext>(i);
}


size_t MongoAggParser::ObjectContext::getRuleIndex() const {
  return MongoAggParser::RuleObject;
}

void MongoAggParser::ObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject(this);
}

void MongoAggParser::ObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject(this);
}


antlrcpp::Any MongoAggParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::ObjectContext* MongoAggParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 2, MongoAggParser::RuleObject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(40);
      match(MongoAggParser::T__0);
      setState(41);
      keyValPair();
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MongoAggParser::T__2) {
        setState(42);
        match(MongoAggParser::T__2);
        setState(43);
        keyValPair();
        setState(48);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(49);
      match(MongoAggParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      match(MongoAggParser::T__0);
      setState(52);
      match(MongoAggParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyValPairContext ------------------------------------------------------------------

MongoAggParser::KeyValPairContext::KeyValPairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MongoAggParser::FieldNameContext* MongoAggParser::KeyValPairContext::fieldName() {
  return getRuleContext<MongoAggParser::FieldNameContext>(0);
}

MongoAggParser::ValueContext* MongoAggParser::KeyValPairContext::value() {
  return getRuleContext<MongoAggParser::ValueContext>(0);
}


size_t MongoAggParser::KeyValPairContext::getRuleIndex() const {
  return MongoAggParser::RuleKeyValPair;
}

void MongoAggParser::KeyValPairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValPair(this);
}

void MongoAggParser::KeyValPairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValPair(this);
}


antlrcpp::Any MongoAggParser::KeyValPairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitKeyValPair(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::KeyValPairContext* MongoAggParser::keyValPair() {
  KeyValPairContext *_localctx = _tracker.createInstance<KeyValPairContext>(_ctx, getState());
  enterRule(_localctx, 4, MongoAggParser::RuleKeyValPair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    fieldName();
    setState(56);
    match(MongoAggParser::T__1);
    setState(57);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldNameContext ------------------------------------------------------------------

MongoAggParser::FieldNameContext::FieldNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::FieldNameContext::STRING() {
  return getToken(MongoAggParser::STRING, 0);
}

MongoAggParser::StringContext* MongoAggParser::FieldNameContext::string() {
  return getRuleContext<MongoAggParser::StringContext>(0);
}


size_t MongoAggParser::FieldNameContext::getRuleIndex() const {
  return MongoAggParser::RuleFieldName;
}

void MongoAggParser::FieldNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldName(this);
}

void MongoAggParser::FieldNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldName(this);
}


antlrcpp::Any MongoAggParser::FieldNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitFieldName(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::FieldNameContext* MongoAggParser::fieldName() {
  FieldNameContext *_localctx = _tracker.createInstance<FieldNameContext>(_ctx, getState());
  enterRule(_localctx, 6, MongoAggParser::RuleFieldName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MongoAggParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        match(MongoAggParser::STRING);
        break;
      }

      case MongoAggParser::QSTRING: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        string();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

MongoAggParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::StringContext::QSTRING() {
  return getToken(MongoAggParser::QSTRING, 0);
}


size_t MongoAggParser::StringContext::getRuleIndex() const {
  return MongoAggParser::RuleString;
}

void MongoAggParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void MongoAggParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any MongoAggParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::StringContext* MongoAggParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 8, MongoAggParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(MongoAggParser::QSTRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

MongoAggParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MongoAggParser::StringContext* MongoAggParser::ValueContext::string() {
  return getRuleContext<MongoAggParser::StringContext>(0);
}

MongoAggParser::ObjectContext* MongoAggParser::ValueContext::object() {
  return getRuleContext<MongoAggParser::ObjectContext>(0);
}

tree::TerminalNode* MongoAggParser::ValueContext::NUMBER() {
  return getToken(MongoAggParser::NUMBER, 0);
}


size_t MongoAggParser::ValueContext::getRuleIndex() const {
  return MongoAggParser::RuleValue;
}

void MongoAggParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void MongoAggParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


antlrcpp::Any MongoAggParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::ValueContext* MongoAggParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 10, MongoAggParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MongoAggParser::QSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(65);
        string();
        break;
      }

      case MongoAggParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(66);
        object();
        break;
      }

      case MongoAggParser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(67);
        match(MongoAggParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PipelineContext ------------------------------------------------------------------

MongoAggParser::PipelineContext::PipelineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MongoAggParser::StageArrayContext* MongoAggParser::PipelineContext::stageArray() {
  return getRuleContext<MongoAggParser::StageArrayContext>(0);
}


size_t MongoAggParser::PipelineContext::getRuleIndex() const {
  return MongoAggParser::RulePipeline;
}

void MongoAggParser::PipelineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPipeline(this);
}

void MongoAggParser::PipelineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPipeline(this);
}


antlrcpp::Any MongoAggParser::PipelineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitPipeline(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::PipelineContext* MongoAggParser::pipeline() {
  PipelineContext *_localctx = _tracker.createInstance<PipelineContext>(_ctx, getState());
  enterRule(_localctx, 12, MongoAggParser::RulePipeline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      stageArray();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(71);
      match(MongoAggParser::T__4);
      setState(72);
      match(MongoAggParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StageObjContext ------------------------------------------------------------------

MongoAggParser::StageObjContext::StageObjContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MongoAggParser::StageContext* MongoAggParser::StageObjContext::stage() {
  return getRuleContext<MongoAggParser::StageContext>(0);
}


size_t MongoAggParser::StageObjContext::getRuleIndex() const {
  return MongoAggParser::RuleStageObj;
}

void MongoAggParser::StageObjContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStageObj(this);
}

void MongoAggParser::StageObjContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStageObj(this);
}


antlrcpp::Any MongoAggParser::StageObjContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitStageObj(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::StageObjContext* MongoAggParser::stageObj() {
  StageObjContext *_localctx = _tracker.createInstance<StageObjContext>(_ctx, getState());
  enterRule(_localctx, 14, MongoAggParser::RuleStageObj);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(MongoAggParser::T__0);
    setState(76);
    stage();
    setState(77);
    match(MongoAggParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StageContext ------------------------------------------------------------------

MongoAggParser::StageContext::StageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MongoAggParser::ProjectStageContext* MongoAggParser::StageContext::projectStage() {
  return getRuleContext<MongoAggParser::ProjectStageContext>(0);
}

MongoAggParser::CountStageContext* MongoAggParser::StageContext::countStage() {
  return getRuleContext<MongoAggParser::CountStageContext>(0);
}

MongoAggParser::LimitStageContext* MongoAggParser::StageContext::limitStage() {
  return getRuleContext<MongoAggParser::LimitStageContext>(0);
}

MongoAggParser::SkipStageContext* MongoAggParser::StageContext::skipStage() {
  return getRuleContext<MongoAggParser::SkipStageContext>(0);
}


size_t MongoAggParser::StageContext::getRuleIndex() const {
  return MongoAggParser::RuleStage;
}

void MongoAggParser::StageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStage(this);
}

void MongoAggParser::StageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStage(this);
}


antlrcpp::Any MongoAggParser::StageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitStage(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::StageContext* MongoAggParser::stage() {
  StageContext *_localctx = _tracker.createInstance<StageContext>(_ctx, getState());
  enterRule(_localctx, 16, MongoAggParser::RuleStage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MongoAggParser::PROJECT: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        projectStage();
        break;
      }

      case MongoAggParser::COUNT: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        countStage();
        break;
      }

      case MongoAggParser::LIMIT: {
        enterOuterAlt(_localctx, 3);
        setState(81);
        limitStage();
        break;
      }

      case MongoAggParser::SKIPSTR: {
        enterOuterAlt(_localctx, 4);
        setState(82);
        skipStage();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StageArrayContext ------------------------------------------------------------------

MongoAggParser::StageArrayContext::StageArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MongoAggParser::StageObjContext *> MongoAggParser::StageArrayContext::stageObj() {
  return getRuleContexts<MongoAggParser::StageObjContext>();
}

MongoAggParser::StageObjContext* MongoAggParser::StageArrayContext::stageObj(size_t i) {
  return getRuleContext<MongoAggParser::StageObjContext>(i);
}


size_t MongoAggParser::StageArrayContext::getRuleIndex() const {
  return MongoAggParser::RuleStageArray;
}

void MongoAggParser::StageArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStageArray(this);
}

void MongoAggParser::StageArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStageArray(this);
}


antlrcpp::Any MongoAggParser::StageArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitStageArray(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::StageArrayContext* MongoAggParser::stageArray() {
  StageArrayContext *_localctx = _tracker.createInstance<StageArrayContext>(_ctx, getState());
  enterRule(_localctx, 18, MongoAggParser::RuleStageArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(MongoAggParser::T__4);
    setState(86);
    stageObj();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MongoAggParser::T__2) {
      setState(87);
      match(MongoAggParser::T__2);
      setState(88);
      stageObj();
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(94);
    match(MongoAggParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollArgContext ------------------------------------------------------------------

MongoAggParser::CollArgContext::CollArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::CollArgContext::COLLSTR() {
  return getToken(MongoAggParser::COLLSTR, 0);
}

MongoAggParser::StringContext* MongoAggParser::CollArgContext::string() {
  return getRuleContext<MongoAggParser::StringContext>(0);
}


size_t MongoAggParser::CollArgContext::getRuleIndex() const {
  return MongoAggParser::RuleCollArg;
}

void MongoAggParser::CollArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollArg(this);
}

void MongoAggParser::CollArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollArg(this);
}


antlrcpp::Any MongoAggParser::CollArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitCollArg(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::CollArgContext* MongoAggParser::collArg() {
  CollArgContext *_localctx = _tracker.createInstance<CollArgContext>(_ctx, getState());
  enterRule(_localctx, 20, MongoAggParser::RuleCollArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(MongoAggParser::COLLSTR);
    setState(97);
    match(MongoAggParser::T__1);
    setState(98);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PipelineArgContext ------------------------------------------------------------------

MongoAggParser::PipelineArgContext::PipelineArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::PipelineArgContext::PIPELSTR() {
  return getToken(MongoAggParser::PIPELSTR, 0);
}

MongoAggParser::PipelineContext* MongoAggParser::PipelineArgContext::pipeline() {
  return getRuleContext<MongoAggParser::PipelineContext>(0);
}


size_t MongoAggParser::PipelineArgContext::getRuleIndex() const {
  return MongoAggParser::RulePipelineArg;
}

void MongoAggParser::PipelineArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPipelineArg(this);
}

void MongoAggParser::PipelineArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPipelineArg(this);
}


antlrcpp::Any MongoAggParser::PipelineArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitPipelineArg(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::PipelineArgContext* MongoAggParser::pipelineArg() {
  PipelineArgContext *_localctx = _tracker.createInstance<PipelineArgContext>(_ctx, getState());
  enterRule(_localctx, 22, MongoAggParser::RulePipelineArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(MongoAggParser::PIPELSTR);
    setState(101);
    match(MongoAggParser::T__1);
    setState(102);
    pipeline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProjectStageContext ------------------------------------------------------------------

MongoAggParser::ProjectStageContext::ProjectStageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::ProjectStageContext::PROJECT() {
  return getToken(MongoAggParser::PROJECT, 0);
}

MongoAggParser::ObjectContext* MongoAggParser::ProjectStageContext::object() {
  return getRuleContext<MongoAggParser::ObjectContext>(0);
}


size_t MongoAggParser::ProjectStageContext::getRuleIndex() const {
  return MongoAggParser::RuleProjectStage;
}

void MongoAggParser::ProjectStageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProjectStage(this);
}

void MongoAggParser::ProjectStageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProjectStage(this);
}


antlrcpp::Any MongoAggParser::ProjectStageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitProjectStage(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::ProjectStageContext* MongoAggParser::projectStage() {
  ProjectStageContext *_localctx = _tracker.createInstance<ProjectStageContext>(_ctx, getState());
  enterRule(_localctx, 24, MongoAggParser::RuleProjectStage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(MongoAggParser::PROJECT);
    setState(105);
    match(MongoAggParser::T__1);
    setState(106);
    object();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CountStageContext ------------------------------------------------------------------

MongoAggParser::CountStageContext::CountStageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::CountStageContext::COUNT() {
  return getToken(MongoAggParser::COUNT, 0);
}

MongoAggParser::StringContext* MongoAggParser::CountStageContext::string() {
  return getRuleContext<MongoAggParser::StringContext>(0);
}


size_t MongoAggParser::CountStageContext::getRuleIndex() const {
  return MongoAggParser::RuleCountStage;
}

void MongoAggParser::CountStageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCountStage(this);
}

void MongoAggParser::CountStageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCountStage(this);
}


antlrcpp::Any MongoAggParser::CountStageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitCountStage(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::CountStageContext* MongoAggParser::countStage() {
  CountStageContext *_localctx = _tracker.createInstance<CountStageContext>(_ctx, getState());
  enterRule(_localctx, 26, MongoAggParser::RuleCountStage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(MongoAggParser::COUNT);
    setState(109);
    match(MongoAggParser::T__1);
    setState(110);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LimitStageContext ------------------------------------------------------------------

MongoAggParser::LimitStageContext::LimitStageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::LimitStageContext::LIMIT() {
  return getToken(MongoAggParser::LIMIT, 0);
}

tree::TerminalNode* MongoAggParser::LimitStageContext::NUMBER() {
  return getToken(MongoAggParser::NUMBER, 0);
}


size_t MongoAggParser::LimitStageContext::getRuleIndex() const {
  return MongoAggParser::RuleLimitStage;
}

void MongoAggParser::LimitStageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLimitStage(this);
}

void MongoAggParser::LimitStageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLimitStage(this);
}


antlrcpp::Any MongoAggParser::LimitStageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitLimitStage(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::LimitStageContext* MongoAggParser::limitStage() {
  LimitStageContext *_localctx = _tracker.createInstance<LimitStageContext>(_ctx, getState());
  enterRule(_localctx, 28, MongoAggParser::RuleLimitStage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(MongoAggParser::LIMIT);
    setState(113);
    match(MongoAggParser::T__1);
    setState(114);
    match(MongoAggParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkipStageContext ------------------------------------------------------------------

MongoAggParser::SkipStageContext::SkipStageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MongoAggParser::SkipStageContext::SKIPSTR() {
  return getToken(MongoAggParser::SKIPSTR, 0);
}

tree::TerminalNode* MongoAggParser::SkipStageContext::NUMBER() {
  return getToken(MongoAggParser::NUMBER, 0);
}


size_t MongoAggParser::SkipStageContext::getRuleIndex() const {
  return MongoAggParser::RuleSkipStage;
}

void MongoAggParser::SkipStageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkipStage(this);
}

void MongoAggParser::SkipStageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MongoAggListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkipStage(this);
}


antlrcpp::Any MongoAggParser::SkipStageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MongoAggVisitor*>(visitor))
    return parserVisitor->visitSkipStage(this);
  else
    return visitor->visitChildren(this);
}

MongoAggParser::SkipStageContext* MongoAggParser::skipStage() {
  SkipStageContext *_localctx = _tracker.createInstance<SkipStageContext>(_ctx, getState());
  enterRule(_localctx, 30, MongoAggParser::RuleSkipStage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(MongoAggParser::SKIPSTR);
    setState(117);
    match(MongoAggParser::T__1);
    setState(118);
    match(MongoAggParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MongoAggParser::_decisionToDFA;
atn::PredictionContextCache MongoAggParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MongoAggParser::_atn;
std::vector<uint16_t> MongoAggParser::_serializedATN;

std::vector<std::string> MongoAggParser::_ruleNames = {
  "aggregate", "object", "keyValPair", "fieldName", "string", "value", "pipeline", 
  "stageObj", "stage", "stageArray", "collArg", "pipelineArg", "projectStage", 
  "countStage", "limitStage", "skipStage"
};

std::vector<std::string> MongoAggParser::_literalNames = {
  "", "'{'", "':'", "','", "'}'", "'['", "']'"
};

std::vector<std::string> MongoAggParser::_symbolicNames = {
  "", "", "", "", "", "", "", "WHITESPACE", "ANYCHAR", "ALPHANUM", "NUMBER", 
  "INT", "AGGCMDSTR", "PIPELSTR", "LETTER", "DIGIT", "HEX", "STRING", "QSTRING", 
  "COLLSTR", "PROJECT", "COUNT", "LIMIT", "SKIPSTR"
};

dfa::Vocabulary MongoAggParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MongoAggParser::_tokenNames;

MongoAggParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x19, 0x7b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2f, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x32, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x38, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x47, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x4c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x56, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x5c, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0x5f, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x2, 0x2, 0x12, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x2, 0x2, 
    0x2, 0x74, 0x2, 0x22, 0x3, 0x2, 0x2, 0x2, 0x4, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0x46, 0x3, 0x2, 0x2, 0x2, 0xe, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x57, 0x3, 0x2, 0x2, 0x2, 0x16, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x66, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x76, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x3, 0x2, 0x2, 0x23, 
    0x24, 0x7, 0xe, 0x2, 0x2, 0x24, 0x25, 0x7, 0x4, 0x2, 0x2, 0x25, 0x26, 
    0x5, 0xa, 0x6, 0x2, 0x26, 0x27, 0x7, 0x5, 0x2, 0x2, 0x27, 0x28, 0x5, 
    0x18, 0xd, 0x2, 0x28, 0x29, 0x7, 0x6, 0x2, 0x2, 0x29, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x2b, 0x7, 0x3, 0x2, 0x2, 0x2b, 0x30, 0x5, 0x6, 0x4, 
    0x2, 0x2c, 0x2d, 0x7, 0x5, 0x2, 0x2, 0x2d, 0x2f, 0x5, 0x6, 0x4, 0x2, 
    0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 
    0x6, 0x2, 0x2, 0x34, 0x38, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x3, 
    0x2, 0x2, 0x36, 0x38, 0x7, 0x6, 0x2, 0x2, 0x37, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x3a, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3b, 0x7, 0x4, 0x2, 0x2, 0x3b, 
    0x3c, 0x5, 0xc, 0x7, 0x2, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 
    0x7, 0x13, 0x2, 0x2, 0x3e, 0x40, 0x5, 0xa, 0x6, 0x2, 0x3f, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x7, 0x14, 0x2, 0x2, 0x42, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x47, 0x5, 0xa, 0x6, 0x2, 0x44, 0x47, 0x5, 0x4, 0x3, 0x2, 
    0x45, 0x47, 0x7, 0xc, 0x2, 0x2, 0x46, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x49, 0x4a, 0x7, 
    0x7, 0x2, 0x2, 0x4a, 0x4c, 0x7, 0x8, 0x2, 0x2, 0x4b, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x7, 0x3, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0x12, 0xa, 0x2, 
    0x4f, 0x50, 0x7, 0x6, 0x2, 0x2, 0x50, 0x11, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x56, 0x5, 0x1a, 0xe, 0x2, 0x52, 0x56, 0x5, 0x1c, 0xf, 0x2, 0x53, 0x56, 
    0x5, 0x1e, 0x10, 0x2, 0x54, 0x56, 0x5, 0x20, 0x11, 0x2, 0x55, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x55, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x7, 0x2, 0x2, 0x58, 0x5d, 0x5, 0x10, 0x9, 
    0x2, 0x59, 0x5a, 0x7, 0x5, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x10, 0x9, 0x2, 
    0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 
    0x8, 0x2, 0x2, 0x61, 0x15, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x15, 
    0x2, 0x2, 0x63, 0x64, 0x7, 0x4, 0x2, 0x2, 0x64, 0x65, 0x5, 0xa, 0x6, 
    0x2, 0x65, 0x17, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0xf, 0x2, 0x2, 
    0x67, 0x68, 0x7, 0x4, 0x2, 0x2, 0x68, 0x69, 0x5, 0xe, 0x8, 0x2, 0x69, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x16, 0x2, 0x2, 0x6b, 0x6c, 
    0x7, 0x4, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x4, 0x3, 0x2, 0x6d, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x17, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x4, 
    0x2, 0x2, 0x70, 0x71, 0x5, 0xa, 0x6, 0x2, 0x71, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x73, 0x7, 0x18, 0x2, 0x2, 0x73, 0x74, 0x7, 0x4, 0x2, 0x2, 
    0x74, 0x75, 0x7, 0xc, 0x2, 0x2, 0x75, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x19, 0x2, 0x2, 0x77, 0x78, 0x7, 0x4, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0xc, 0x2, 0x2, 0x79, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9, 0x30, 0x37, 
    0x3f, 0x46, 0x4b, 0x55, 0x5d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MongoAggParser::Initializer MongoAggParser::_init;
