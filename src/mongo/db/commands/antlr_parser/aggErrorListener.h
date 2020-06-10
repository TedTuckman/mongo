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
// #include "third_party/antlr4/runtime/Cpp/runtime/src/BaseErrorListener.h"
#pragma GCC diagnostic pop
namespace mongo {

class AggErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;
    // void reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t
    // stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs)
    // override;

    // void reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex,
    // size_t stopIndex, const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs)
    // override;

    // void reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex,
    // size_t stopIndex, size_t prediction, atn::ATNConfigSet *configs) override;
};

}  // namespace mongo
