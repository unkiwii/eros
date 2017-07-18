/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

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

#endif  /* EROS_TOKEN_H */
