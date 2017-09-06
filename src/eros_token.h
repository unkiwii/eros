#ifndef EROS_TOKEN_H
#define EROS_TOKEN_H

#include "eros_defines.h"

typedef enum eros_token_type_code_t {
  EROS_TK_EOF,

  EROS_TK_SPACE,      /*            */
  EROS_TK_NUMERAL,    /* #          */
  EROS_TK_EQUAL,      /* =          */
  EROS_TK_SET,        /* :=         */
  EROS_TK_DOT,        /* .          */
  EROS_TK_COMMA,      /* ,          */
  EROS_TK_LBRACKET,   /* [          */
  EROS_TK_RBRACKET,   /* ]          */
  EROS_TK_LPAREN,     /* (          */
  EROS_TK_RPAREN,     /* )          */
  EROS_TK_LBRACE,     /* {          */
  EROS_TK_RBRACE,     /* }          */
  _EROS_TK_SIMPLE_COUNT_,  /* not a token type code, just to mark the end of simple tokens */

  EROS_TK_NUMBER,     /* 1234567890 */
  EROS_TK_IDENTIFIER, /* identifier */
  EROS_TK_STRING,     /* '...'      */

  EROS_TK_ILLEGAL,

  _EROS_TK_LAST_  /* not a token type code, just to mark the end of this enum */
} eros_token_type_code;

#define EROS_TOKEN_SIMPLE_COUNT ((int)_EROS_TK_SIMPLE_COUNT_)

typedef struct eros_token_type
{
  eros_token_type_code code;

  /* for debug or logging purposes */
  const char* name;

  /* value for simple tokens */
  char* value;
} eros_token_type;

struct eros_token_t
{
  /** the type of this token **/
  eros_token_type* type;

  /** the value of this token (for identifiers, number, etc) **/
  char* value;
};

eros_token_t* eros_token_simple(eros_token_type_code);
eros_token_t* eros_token_illegal(char ch);
eros_token_t* eros_token_new(eros_token_type_code, const char* value);
void eros_token_delete(eros_token_t*);

const char* eros_token_type_name(eros_token_t*);
const char* eros_token_value(eros_token_t*);

BOOL eros_token_is_simple(eros_token_t*);
BOOL eros_token_is_eof(eros_token_t*);
BOOL eros_token_is_identifier(eros_token_t*, const char* identifier);

#endif  /* EROS_TOKEN_H */

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
