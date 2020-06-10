// A simple grammar for the aggregation framework. WIP

grammar MongoAgg;

// TODO: Add other fields in aggregate command
/* aggregate : '{' AGGCMDSTR ':' string ',' PIPELSTR ':' pipeline '}'; */
aggregate : '{' AGGCMDSTR ':' string ',' pipelineArg '}';
object    : '{' keyValPair (',' keyValPair)* '}' | '{' '}';
keyValPair: fieldName ':' value;
fieldName : STRING | string;
string    : QSTRING;
value     : string | object | NUMBER; // TODO: Add Array
pipeline  : stageArray | '[' ']';
stageObj  : '{' stage '}';
stage     : projectStage | countStage | limitStage | skipStage;
stageArray: '[' stageObj (',' stageObj)* ']';
collArg   : COLLSTR ':' string;
pipelineArg: PIPELSTR ':' pipeline;

WHITESPACE  : (' ' | '\t' | '\r' | '\n')+ {skip();} ;
/* ALPHANUM  : LETTER | DIGIT | '.'; */
NUMBER    : '-'? INT ('.' DIGIT +)?;
fragment INT: '0' | ('1'..'9') DIGIT*;
AGGCMDSTR : 'aggregate';
PIPELSTR  : 'pipeline';
fragment LETTER: [a-zA-Z];
fragment DIGIT : ('0'..'9');
/* HEX       : ('%' [a-fA-F0-9] [a-fA-F0-9])+ ; // hexadecimal */
// TODO: For some reason these don't match multi work strings. Fix
/* STRING    : ([a-zA-Z~] |HEX) ([a-zA-Z0-9.-] | HEX)*; // lexer rule can use other lexer rule */
STRING    : (LETTER | DIGIT ) (LETTER | DIGIT)*; // TODO: Adopt above rule to match symbols
QSTRING   : '"' STRING '"';
COLLSTR   : 'coll';

// Stages
PROJECT   : '$project';
projectStage: PROJECT ':' object;
COUNT     : '$count';
countStage: COUNT ':' string;
LIMIT     : '$limit';
limitStage: LIMIT ':' NUMBER; // TODO should be gt 0
SKIPSTR   : '$skip'; // SKIP is reserved
skipStage : SKIPSTR ':' NUMBER; // TODO should be gt 0
/* UNIONSTR  : '$' 'u' 'n' 'i' 'o' 'n'; */
/* unionStage: UNIONSTR ':' '{' unionArgs '}' | UNIONSTR ':' collArg; */
/* unionArgs : collArg ',' pipelineArg | pipelineArg ',' collArg; */

