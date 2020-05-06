// A simple grammar for the aggregation framework. WIP

grammar MongoAgg;

// TODO: Add other fields in aggregate command
/* aggregate : '{' AGGCMDSTR ':' string ',' PIPELSTR ':' pipeline '}'; */
aggregate : '{' AGGCMDSTR ':' string ',' pipelineArg '}';
object    : '{' keyValPair (',' keyValPair)* '}' | '{' '}';
/* object    : '{' fieldName ':' value '}'; */
keyValPair: fieldName ':' value;
fieldName : STRING | string;
/* string    : '"' STRING '"'; */
string    : QSTRING;
value     : string | object | NUMBER; // TODO: Add Array
pipeline  : stageArray | '[' ']';
stageObj  : '{' stage '}';
stage     : projectStage | countStage | limitStage | skipStage;
stageArray: '[' stageObj (',' stageObj)* ']';
collArg   : COLLSTR ':' string;
pipelineArg: PIPELSTR ':' pipeline;

WHITESPACE  : (' ' | '\t' | '\r' | '\n')+ {skip();} ;
ANYCHAR   : .;
ALPHANUM  : LETTER | DIGIT | '.';
NUMBER    : '-'? INT ('.' [0-9] +)?;
INT       : '0' | [1-9] [0-9]*;
AGGCMDSTR : 'a' 'g' 'g' 'r' 'e' 'g' 'a' 't' 'e';
PIPELSTR  : 'p' 'i' 'p' 'e' 'l' 'i' 'n' 'e';
LETTER    : [a-zA-Z];
DIGIT     : [0-9];
HEX       : ('%' [a-fA-F0-9] [a-fA-F0-9])+ ; // hexadecimal
STRING    : ([a-zA-Z~] |HEX) ([a-zA-Z0-9.-] | HEX)*; // lexer rule can use other lexer rule
QSTRING   : '"' STRING '"';
COLLSTR   : 'c' 'o' 'l' 'l';

// Stages
PROJECT   :  '$' 'p' 'r' 'o' 'j' 'e' 'c' 't';
projectStage: PROJECT ':' object;
COUNT     :  '$' 'c' 'o' 'u' 'n' 't';
countStage: COUNT ':' string;
LIMIT     : '$' 'l' 'i' 'm' 'i' 't';
limitStage: LIMIT ':' NUMBER; // TODO should be gt 0
SKIPSTR   : '$' 's' 'k' 'i' 'p'; // SKIP is reserved
skipStage : SKIPSTR ':' NUMBER; // TODO should be gt 0
/* UNIONSTR  : '$' 'u' 'n' 'i' 'o' 'n'; */
/* unionStage: UNIONSTR ':' '{' unionArgs '}' | UNIONSTR ':' collArg; */
/* unionArgs : collArg ',' pipelineArg | pipelineArg ',' collArg; */

