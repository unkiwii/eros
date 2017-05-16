/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_DEFINES_H
#define EROS_DEFINES_H

#ifndef PROGRAM_NAME
  #define PROGRAM_NAME "eros"
#endif

#ifndef PROGRAM_VERSION
  #ifdef COMPILE_HASH
    #define PROGRAM_VERSION "0.0.1 (" COMPILE_HASH ")"
  #else
    #define PROGRAM_VERSION "0.0.1"
  #endif
#endif

#ifndef PROGRAM_AUTHOR
  #define PROGRAM_AUTHOR "Lucas Gabriel Sanchez"
#endif

#ifndef PROGRAM_AUTHOR_EMAIL
  #define PROGRAM_AUTHOR_EMAIL "unkiwii@gmail.com"
#endif

#ifndef COMPILE_YEAR
  #define COMPILE_YEAR "2016"
#endif

#ifndef COMPILE_MONTH
  #define COMPILE_MONTH "Dec"
#endif

#ifndef COMPILE_DAY
  #define COMPILE_DAY "31"
#endif

#ifndef COMPILE_DATE
  #define COMPILE_DATE COMPILE_MONTH " " COMPILE_DAY ", " COMPILE_YEAR
#endif

typedef long long int file_size_t;
typedef int file_line_t;
typedef int error_code_t;
typedef char flag_t;
typedef long long int files_count_t;
typedef long long int symbols_count_t;
typedef int source_row_t;
typedef int source_col_t;
typedef long long int source_size_t;
typedef int log_level_t;
typedef char* token_t;  //TODO change to list of tokens
typedef long int token_count_t;  //TODO change to list of tokens
typedef int status_code_t;

struct eros_parser_t;
typedef struct eros_parser_t eros_parser_t;

struct eros_lexer_t;
typedef struct eros_lexer_t eros_lexer_t;

struct eros_source_t;
typedef struct eros_source_t eros_source_t;

struct eros_context_t;
typedef struct eros_context_t eros_context_t;

struct eros_value_t;
typedef struct eros_value_t eros_value_t;

struct eros_input_t;
typedef struct eros_input_t eros_input_t;

#endif // EROS_DEFINES_H
