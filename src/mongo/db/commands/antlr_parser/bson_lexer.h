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

#include <sstream>
#include <string>
#include <vector>

#include "mongo/bson/bsonobj.h"
#include "mongo/db/query/parser/mql_parser_gen.hpp"

namespace mongo {

class BSONLexer {
public:
    BSONLexer(std::vector<BSONElement> input);

    /**
     * Collapses the token currently at _position until the next END_OBJ is encountered.
     */
    void startOrderedObj();

    /**
     * Retrieves the next token in the stream.
     */
    MQLBisonParser::symbol_type getNext() {
        return _tokens[_position++];
    }

private:
    void tokenize(BSONElement elem, bool includeFieldName);

    // This is sort of dumb, but might be OK for BSON.
    MQLBisonParser::location_type getNextLoc() {
        auto loc = MQLBisonParser::location_type{nullptr, _position, _position};
        _position++;
        return loc;
    }

    std::vector<BSONElement> _input;
    int _position = 0;

    // Vector of tokens.
    std::vector<MQLBisonParser::symbol_type> _tokens;
};

MQLBisonParser::symbol_type yylex(mongo::BSONLexer&);

}  // namespace mongo
