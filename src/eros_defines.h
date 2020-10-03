#ifndef EROS_DEFINES_H
#define EROS_DEFINES_H

#ifndef bool
  #define bool char
  #define true ((char)1)
  #define false ((char)0)
#endif

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
  #define PROGRAM_AUTHOR "Lucas Gabriel Sánchez"
#endif

#ifndef PROGRAM_AUTHOR_EMAIL
  #define PROGRAM_AUTHOR_EMAIL "unkiwii@gmail.com"
#endif

#ifndef COMPILE_YEAR
  #define COMPILE_YEAR "2017"
#endif

#ifndef COMPILE_MONTH
  #define COMPILE_MONTH "Ago"
#endif

#ifndef COMPILE_DAY
  #define COMPILE_DAY "10"
#endif

#ifndef COMPILE_DATE
  #define COMPILE_DATE COMPILE_MONTH " " COMPILE_DAY ", " COMPILE_YEAR
#endif

typedef long long int file_size_t;
typedef int file_line_t;
typedef int error_code_t;
typedef bool flag_t;
typedef long long int files_count_t;
typedef long long int symbols_count_t;
typedef long long int children_count_t;
typedef int source_position_t;
typedef long long int source_size_t;
typedef int log_level_t;
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

struct eros_token_t;
typedef struct eros_token_t eros_token_t;

struct eros_ast_node_t;
typedef struct eros_ast_node_t eros_ast_node_t;

#endif // EROS_DEFINES_H

/*
Copyright (c) 2014-2017 Lucas Gabriel Sánchez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
