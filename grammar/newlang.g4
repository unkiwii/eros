grammar newlang;

// starting point for parsing a file
compilationUnit
    : (NL? importDeclaration)* (NL? statement)*
    ;

importDeclaration
    : IMPORT SPACE (folder* NAME) (FILE_EXTENSION | LIBRARY_EXTENSION) NL
    ;

folder
    : NAME FOLDER_SEPARATOR
    | FOLDER_UP FOLDER_SEPARATOR
    ;

statement
    : variableDeclaration NL
    | blockDeclaration NL
    | blockEvaluation NL
    | typeDeclaration NL
    ;

variableDeclaration
    : TYPE_NAME SPACE NAME SPACE ASSIGNATION SPACE (value END | blockValue)
    ;

blockDeclaration
    : OPEN_BLOCK SPACE (blockHeader BLOCK_HEADER_SEPARATOR (SPACE | NL))? blockBody (SPACE | NL) CLOSE_BLOCK END
    ;

blockHeader
    : (blockReturnType SPACE)? (blockArguments SPACE)?
    ;

blockArgument
    : NAME BLOCK_ARGUMENT_NAME_FINALIZER? SPACE TYPE_NAME SPACE NAME
    ;

blockArguments
    : blockArgument (BLOCK_ARGUMENT_SEPARATOR blockArgument)*
    | NAME
    ;

blockBody
    : (NL? blockStatement)+
    ;

blockStatement
    : variableDeclaration
    | blockDeclaration
    | blockEvaluation
    ;

blockReturnType
    : TYPE_NAME
    ;

blockEvaluation
    : 'eval' END
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
    : blockEvaluation
    | blockDeclaration
    ;

// -------------------------- LEXER -------------------------------------------

// Keywords

SELF        : 'self' ;
TYPE        : 'type' ;
IMPORT      : 'import' ;
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
BLOCK_ARGUMENT_NAME_FINALIZER : ':' ;
BLOCK_ARGUMENT_SEPARATOR : ', ' ;

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
