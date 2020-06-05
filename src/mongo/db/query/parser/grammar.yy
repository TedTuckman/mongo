%require "3.5"
%debug
%language "c++"

// Generate header for tokens to be included from lexer.
%defines
// Tell Bison to generate make_* methods for tokens.
%define api.token.constructor
// The mapping of scanner token ID to Bison's internal symbol enum is consistent.
%define api.token.raw
// Instead of specifying a %union directive of possible semantic types, allow Bison to build a sort
// of std::variant structure. This allows symbol declaration with '%type <C++ type> symbol'.
%define api.value.type variant

%define parse.assert
%define api.namespace {mongo}
%define api.parser.class {MQLBisonParser}
// Track locations of symbols.
%locations

// Header only.
%code requires {
    #include <memory>
    #include <boost/intrusive_ptr.hpp>

    #include "mongo/db/query/parser/cst_node.h"
    #include "mongo/util/intrusive_counter.h"

    // Forward declare any parameters needed for lexing/parsing.
    namespace mongo {
      class BSONLexer;
    }

    using CSTPipeline = std::vector<boost::intrusive_ptr<mongo::CSTNode>>;
}

// Cpp only.
%code { 
    #include "mongo/db/query/parser/bson_lexer.h"
}

// Parsing parameters, funneled through yyparse() to yylex().
%param {BSONLexer& driver}
// yyparse() parameter only.
%parse-param {CSTPipeline* cst}

//
// Tokens
//

// Reserved keywords.
%token 
    START_OBJECT
    START_ORDERED_OBJECT
    END_OBJECT
    END_ORDERED_OBJECT
    START_ARRAY
    END_ARRAY
    // Stages
    UNION_WITH
    PIPELINE_ARG
    COLL_ARG

    PROJECT
    END_OF_FILE 0 "EOF"
;

// TODO (not here): Anywhere in the grammar where we accept a string (e.g. {$project: {"coll": 1}})
// we need to allow any of the reserved keywords as well...or just a subset? No $-prefixed? 
%token <std::string> STRING
%token <int> NUMBER_INT
%token <long long> NUMBER_LONG
%token <double> NUMBER_DOUBLE
%token <bool> BOOL
%token <std::vector<BSONElement>> OPAQUE_ARRAY
%token <BSONObj> OPAQUE_OBJECT

//
// Semantic values (aka the C++ types produced by the actions).
//
%type <boost::intrusive_ptr<CSTNode>> stage
%type <boost::intrusive_ptr<CSTNodeUnion>> unionWith
%type <boost::intrusive_ptr<CSTNodeProject>> project
%type <CSTPipeline> pipeline stageList optionalPipeline
%type <StringMap<std::string>> projectElem

//
// Grammar rules
//
%%

// Entry point to pipeline parsing.
entryPoint: pipeline { *cst = std::move($pipeline); }

pipeline:
    // START_ARRAY END_ARRAY { *cst = {}; }
    START_ARRAY stageList END_ARRAY { $pipeline = std::move($stageList); }
;

stageList[result]:
    %empty { }
    | START_OBJECT stage END_OBJECT stageList[stagesArg] { 
      $result = std::move($stagesArg);
      $result.emplace_back(std::move($stage));
    }
;

stage:
    unionWith { $stage = std::move($unionWith); }
    | project { $stage = std::move($project); }
;

//
// $unionWith
//

// $unionWith: "coll"
// $unionWith: {coll: "coll", pipeline: [{$unionWith: "coll2"}]}
// $unionWith: {pipeline: [], coll: "coll"}
// $unionWith: {coll: [], coll: "coll"}
// $unionWith: {coll: "coll"}
unionWith:
    UNION_WITH STRING 
      { 
          $unionWith = make_intrusive<CSTNodeUnion>(std::move($STRING), CSTPipeline()); 
      }
    | UNION_WITH START_ORDERED_OBJECT COLL_ARG STRING optionalPipeline END_ORDERED_OBJECT
      { 
          $unionWith = make_intrusive<CSTNodeUnion>(std::move($STRING), std::move($optionalPipeline)); 
      }
;

//
// $project
// 
// project: PROJECT OPAQUE_OBJECT {
//     $project = make_intrusive<CSTNodeProject>("$project", std::move($OPAQUE_OBJECT));
// };

// Traversal version
project: PROJECT START_OBJECT projectElem END_OBJECT {
  $project = make_intrusive<CSTNodeProject>("$project", std::move($projectElem));
};

projectElem[result]: 
    %empty { }
    | STRING STRING projectElem[arg] { // Only supports projecting strings, sigh
      $result = std::move($arg);
      $result[$1] = $2;
    }
;

//
// Common rules
// 
optionalPipeline:
    %empty       { }
    | PIPELINE_ARG pipeline { $optionalPipeline = std::move($pipeline); }
;

%%

namespace mongo
{
    // Mandatory error function
    void MQLBisonParser::error (const MQLBisonParser::location_type& loc, const std::string& msg) {
      std::cerr << msg << " at loc " << loc << std::endl;
    }
}
