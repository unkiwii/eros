grammar newlang;

// starting point for parsing a file
compilationUnit
    : (NL? importDeclaration)* (NL? statement)* NL*
    ;

importDeclaration
    : IMPORT SPACE (folder* NAME) (FILE_EXTENSION | LIBRARY_EXTENSION) NL
    ;

folder
    : NAME FOLDER_SEPARATOR
    | FOLDER_UP FOLDER_SEPARATOR
    ;

statement
    : blockStatement NL
    | typeDeclaration NL
    ;

variableDeclaration
    : TYPE_NAME SPACE NAME SPACE ASSIGNATION SPACE (value END | blockValue)
    ;

block
    : OPEN_BLOCK SPACE (blockHeader BLOCK_HEADER_SEPARATOR (SPACE | NL))? blockBody (SPACE | NL) CLOSE_BLOCK
    ;

blockDeclaration
    : block END
    ;

blockHeader
    : (blockReturnType SPACE)? (blockArguments SPACE)?
    ;

// maybe there is a better way to write the classical operators
paramBlockName
    : (NAME | '<' '='? | '>' '='? | '=' | '|' | '&' | '+' | '-' | '*' | '/' ) COLON?
    ;

blockArgument
    : paramBlockName SPACE TYPE_NAME SPACE NAME
    ;

blockArguments
    : blockArgument (BLOCK_ARGUMENT_SEPARATOR blockArgument)*
    | NAME
    ;

blockBody
    : (NL? blockStatement)+
    ;

// blockStatement needs to know about IDENT and DEDENT (like Python) for now
// just aloud 0 to any number of spaces at the start of any block statement
blockStatement
    : SPACE* variableDeclaration
    | SPACE* blockDeclaration
    | SPACE* blockEvaluation END
    ;

blockReturnType
    : TYPE_NAME
    ;

argsBlockEvaluation
    : paramBlockName SPACE value
    ;

simpleBlockEvaluation
    : NAME
    | argsBlockEvaluation (SPACE argsBlockEvaluation)*
    ;

blockEvaluation
    : LPAREN blockEvaluation RPAREN blockEvaluation
    | (TYPE_NAME | NAME | SELF | block) SPACE simpleBlockEvaluation
    | simpleBlockEvaluation
    ;

typeDeclaration
    : 'type'
    ;

value
    : STRING
    | NUMBER
    | BOOLEAN
    | NAME
    | TYPE_NAME
    ;

blockValue
    : blockEvaluation END
    | blockDeclaration
    ;

// -------------------------- LEXER -------------------------------------------

// Keywords

IMPORT      : 'import' ;
SELF        : 'self' ;
TYPE        : 'type' ;
ABSTRACT    : 'abstract' ;
EXTENDS     : 'extends' ;
STATIC      : 'static' ;
PRIMITIVE   : 'primitive' ;

// Literals

NULL : 'null' ;

BOOLEAN
    : 'true'
    | 'false'
    ;

STRING
    : '"' .*? '"'
    ;

COMMENT
    : '#' .*? NL -> skip
    ;

NUMBER
    : '-'? INT ',' [0-9]+ // 1,35 0,3 -4,5
    | '-'? INT            // -3 45
    ;

fragment INT : '0' | [1-9] [0-9]* ; // no leading zeros

// Specials

NL : '\n' ;

SPACE : ' ' ;
ASSIGNATION : ':=' ;
END : '.' ;

FILE_EXTENSION : '.nl' ;
LIBRARY_EXTENSION : '.nlib' ;

FOLDER_UP : '..' ;
FOLDER_SEPARATOR : '/' ;

OPEN_BLOCK : '[' ;
CLOSE_BLOCK : ']' ;

BLOCK_HEADER_SEPARATOR : '|' ;
COLON : ':' ;
BLOCK_ARGUMENT_SEPARATOR : ', ' ;
LPAREN : '(' ;
RPAREN : ')' ;

// -------------------------- NAMES -------------------------------------

NAME
    : LOWER_CASE (LOWER_CASE | UPPER_CASE | INT)*
    ;

TYPE_NAME
    : UPPER_CASE (LOWER_CASE | UPPER_CASE | INT)*
    ;

LOWER_CASE
    : [a-z]
    ;

UPPER_CASE
    : [A-Z]
    ;

// vim: set filetype=antlr:
