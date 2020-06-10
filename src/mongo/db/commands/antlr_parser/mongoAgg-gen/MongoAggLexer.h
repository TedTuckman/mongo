
// Generated from MongoAgg.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


class MongoAggLexer : public antlr4::Lexer {
public:
    enum {
        T__0 = 1,
        T__1 = 2,
        T__2 = 3,
        T__3 = 4,
        T__4 = 5,
        T__5 = 6,
        WHITESPACE = 7,
        NUMBER = 8,
        AGGCMDSTR = 9,
        PIPELSTR = 10,
        STRING = 11,
        QSTRING = 12,
        COLLSTR = 13,
        PROJECT = 14,
        COUNT = 15,
        LIMIT = 16,
        SKIPSTR = 17
    };

    MongoAggLexer(antlr4::CharStream* input);
    ~MongoAggLexer();

    virtual std::string getGrammarFileName() const override;
    virtual const std::vector<std::string>& getRuleNames() const override;

    virtual const std::vector<std::string>& getChannelNames() const override;
    virtual const std::vector<std::string>& getModeNames() const override;
    virtual const std::vector<std::string>& getTokenNames()
        const override;  // deprecated, use vocabulary instead
    virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

    virtual const std::vector<uint16_t> getSerializedATN() const override;
    virtual const antlr4::atn::ATN& getATN() const override;

    virtual void action(antlr4::RuleContext* context,
                        size_t ruleIndex,
                        size_t actionIndex) override;

private:
    static std::vector<antlr4::dfa::DFA> _decisionToDFA;
    static antlr4::atn::PredictionContextCache _sharedContextCache;
    static std::vector<std::string> _ruleNames;
    static std::vector<std::string> _tokenNames;
    static std::vector<std::string> _channelNames;
    static std::vector<std::string> _modeNames;

    static std::vector<std::string> _literalNames;
    static std::vector<std::string> _symbolicNames;
    static antlr4::dfa::Vocabulary _vocabulary;
    static antlr4::atn::ATN _atn;
    static std::vector<uint16_t> _serializedATN;


    // Individual action functions triggered by action() above.
    void WHITESPACEAction(antlr4::RuleContext* context, size_t actionIndex);

    // Individual semantic predicate functions triggered by sempred() above.

    struct Initializer {
        Initializer();
    };
    static Initializer _init;
};
