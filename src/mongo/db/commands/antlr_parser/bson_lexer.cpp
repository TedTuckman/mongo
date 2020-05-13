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

#include "mongo/db/query/parser/bson_lexer.h"
#include "mongo/db/query/parser/mql_parser_gen.hpp"
#include "mongo/util/string_map.h"

namespace mongo {

// Mapping of reserved keywords to Bison token.
StringMap<MQLBisonParser::token_type> tokenLookup = {
    {"$unionWith", MQLBisonParser::token::UNION_WITH},
    {"pipeline", MQLBisonParser::token::PIPELINE_ARG},
    {"coll", MQLBisonParser::token::COLL_ARG},
};

std::map<MQLBisonParser::token_type, std::string> reverseLookup = {
    {MQLBisonParser::token::UNION_WITH, "$unionWith"},
    {MQLBisonParser::token::PIPELINE_ARG, "pipeline"},
    {MQLBisonParser::token::COLL_ARG, "coll"},
};

void BSONLexer::startOrderedObj() {
    using kvPair = std::pair<MQLBisonParser::symbol_type, MQLBisonParser::symbol_type>;
    struct symbolCompare {
        bool operator()(const kvPair& elem1, const kvPair& elem2) const {
            return reverseLookup[static_cast<MQLBisonParser::token::yytokentype>(
                       elem1.first.type_get())] <
                reverseLookup[static_cast<MQLBisonParser::token::yytokentype>(elem2.first.type_get())];
        }
    };
    std::list<kvPair> sortedTokens;

    // Scan the set of tokens starting at _position until END_OBJ is found.
    auto currentPosition = _position;
    while (_tokens[currentPosition].type_get() != MQLBisonParser::token::END_OBJECT) {
        // TODO What if we encounter another START_OBJECT?
        invariant(_tokens[currentPosition].type_get() != MQLBisonParser::token::START_OBJECT);
        invariant(size_t(currentPosition) < _tokens.size());

        // currentPosition is key, +1 is value.
        // auto key = _tokens[currentPosition++];
        // sortedTokens.insert({std::move(key), std::move(_tokens[currentPosition++])});
        if (_tokens[currentPosition + 1].type_get() == MQLBisonParser::token::START_OBJECT || _tokens[currentPosition + 1].type_get() == MQLBisonParser::token::START_ARRAY) {
            
        } else {
            // SCALAR
            sortedTokens.push_back(std::make_pair(std::move(_tokens[currentPosition]), std::move(_tokens[currentPosition + 1])));
            // _tokens.erase(_tokens.begin() + currentPosition);
            currentPosition += 2;
        }
    }
    sortedTokens.sort(symbolCompare());

    currentPosition = _position;

    // for (auto&& moveIt = std::make_move_iterator(sortedTokens.begin()); moveIt != std::make_move_iterator(sortedTokens.end()); moveIt++) {
    for (auto&& kv : sortedTokens) {
        // _tokens.insert(_tokens.begin() + currentPosition++, std::move(kv.first));
        // _tokens.insert(_tokens.begin() + currentPosition++, std::move(kv.second));
        // _tokens[currentPosition++] = MQLBisonParser::symbol_type(kv.first.type_get(), kv.first.value, kv.first.location);
        _tokens[currentPosition++].move(kv.first);
        _tokens[currentPosition++].move(kv.second);
    }
}

void BSONLexer::tokenize(BSONElement elem, bool includeFieldName) {
    std::cout << "NICKZ tokenizing elem: " << elem << " with fieldName? " << includeFieldName
              << std::endl;

    if (includeFieldName) {
        if (tokenLookup.find(elem.fieldNameStringData()) != tokenLookup.end()) {
            _tokens.emplace_back(tokenLookup[elem.fieldNameStringData()], getNextLoc());
        } else {
            _tokens.emplace_back(MQLBisonParser::make_STRING(elem.fieldName(), getNextLoc()));
        }
    }

    if (elem.type() == BSONType::Object) {
        _tokens.emplace_back(MQLBisonParser::token::START_OBJECT, getNextLoc());
        // TODO Make this better?
        for (auto&& nestedElem : elem.embeddedObject()) {
            tokenize(nestedElem, true);
        }
        _tokens.emplace_back(MQLBisonParser::token::END_OBJECT, getNextLoc());
    } else if (elem.type() == BSONType::Array) {
        _tokens.emplace_back(MQLBisonParser::token::START_ARRAY, getNextLoc());
        for (auto&& nestedElem : elem.Array()) {
            // For arrays, do not tokenize the field names.
            tokenize(nestedElem, false);
        }
        _tokens.emplace_back(MQLBisonParser::token::END_ARRAY, getNextLoc());
    } else {
        // Scalar. Need to grow this out to support the various BSON types.
        invariant(elem.type() == BSONType::String);
        _tokens.emplace_back(MQLBisonParser::make_STRING(elem.String(), getNextLoc()));
    }
}

BSONLexer::BSONLexer(std::vector<BSONElement> pipeline)
    : _input(std::move(pipeline)) {
    _tokens.emplace_back(MQLBisonParser::token::START_ARRAY, getNextLoc());
    for (auto&& elem : _input) {
        // Don't include field names for stages of the pipeline (aka indexes of the pipeline array).
        tokenize(elem, false);
    }
    _tokens.emplace_back(MQLBisonParser::token::END_ARRAY, getNextLoc());

    // Final token must indicate EOF.
    _tokens.emplace_back(MQLBisonParser::make_END_OF_FILE(getNextLoc()));

    // Reset the position to use in yylex().
    _position = 0;
};

MQLBisonParser::symbol_type yylex(BSONLexer& driver) {
    return driver.getNext();
}

}  // namespace mongo
