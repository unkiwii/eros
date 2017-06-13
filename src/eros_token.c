/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_token.h"
#include "eros_mem.h"

#include <stdlib.h>

static eros_token_type token_types[] = {
  /** NOTE: keep simple types always on top */
  { .code = EROS_TK_EOF,         .name = "<eof>",         .value = "eof" },
  { .code = EROS_TK_SPACE,       .name = "<space>",       .value = " "   },
  { .code = EROS_TK_NUMERAL,     .name = "<numeral>",     .value = "#"   },
  { .code = EROS_TK_EQUAL,       .name = "<equal>",       .value = "="   },
  { .code = EROS_TK_SET,         .name = "<set>",         .value = ":="  },
  { .code = EROS_TK_DOT,         .name = "<dot>",         .value = "."   },
  { .code = EROS_TK_COMMA,       .name = "<comma>",       .value = ","   },
  { .code = EROS_TK_LBRACKET,    .name = "<lbracket>",    .value = "["   },
  { .code = EROS_TK_RBRACKET,    .name = "<rbracket>",    .value = "]"   },
  { .code = EROS_TK_LPAREN,      .name = "<lparen>",      .value = "("   },
  { .code = EROS_TK_RPAREN,      .name = "<rparen>",      .value = ")"   },
  { .code = EROS_TK_LBRACE,      .name = "<lbrace>",      .value = "{"   },
  { .code = EROS_TK_RBRACE,      .name = "<rbrace>",      .value = "}"   },

  { .code = EROS_TK_NUMBER,      .name = "<number>",      .value = NULL  },
  { .code = EROS_TK_IDENTIFIER,  .name = "<identifier>",  .value = NULL  },
  { .code = EROS_TK_STRING,      .name = "<string>",      .value = NULL  },

  { .code = EROS_TK_ILLEGAL,     .name = "<illegal>",     .value = NULL  },

  { .code = _EROS_TK_LAST_,      .name = NULL,            .value = NULL  }
};

static eros_token_t* simple_tokens[EROS_TOKEN_SIMPLE_COUNT] = { NULL };

void eros_token_delete_simples() {
  for (int i = 0; i <= EROS_TOKEN_SIMPLE_COUNT; ++i) {
    free(simple_tokens[i]);
  }
}

eros_token_type* eros_token_type_by_code(eros_token_type_code code)
{
  int index = 0;
  eros_token_type* t;
  do {
    t = &token_types[index++];
    if (t->code == code) {
      return t;
    }
  } while (t->code != _EROS_TK_LAST_);  /* simple types have a value */

  return NULL;
}

int eros_token_simple_index(eros_token_type_code code)
{
  int index = 0;
  const eros_token_type* t;
  do {
    t = &token_types[index++];
    if (t->code == code) {
      return index;
    }
  } while (t->value != NULL);  /* simple types have a value */

  return -1;
}

const char* eros_token_simple_value(eros_token_type_code code)
{
  eros_token_type* type = eros_token_type_by_code(code);
  if (type) {
    return type->value;
  }

  return NULL;
}

const char* eros_token_type_name(eros_token_type_code code)
{
  eros_token_type* type = eros_token_type_by_code(code);
  if (type) {
    return type->name;
  }

  return "<INVALID>";
}

BOOL _will_clean_simples = FALSE;
eros_token_t* eros_token_simple(eros_token_type_code code)
{
  if (!_will_clean_simples) {
    _will_clean_simples = TRUE;
    atexit(eros_token_delete_simples);
  }

  int index = eros_token_simple_index(code);
  if (index < 0) {
    return eros_token_illegal('\255');
  }

  eros_token_t* token = simple_tokens[index];
  if (!token) {
    token = simple_tokens[index] = (eros_token_t*) malloc(sizeof(eros_token_t));
    token->type = eros_token_type_by_code(code);
    token->value = token->type->value;
  }

  return token;
}

eros_token_t* eros_token_illegal(char ch)
{
  if (!ch) {
    return NULL;
  }

  eros_token_t* token = (eros_token_t*) malloc(sizeof(eros_token_t));
  token->type = eros_token_type_by_code(EROS_TK_ILLEGAL);
  token->value = (char*) malloc(sizeof(char) * 2);
  token->value[0] = ch;
  token->value[1] = '\0';
  return token;
}

eros_token_t* eros_token_new(eros_token_type_code code, const char* value)
{
  if (!value) {
    return NULL;
  }

  eros_token_t* token = (eros_token_t*) malloc(sizeof(eros_token_t));
  token->type = eros_token_type_by_code(code);
  token->value = eros_strdup(value);
  return token;
}

void eros_token_delete(eros_token_t* token)
{
  if (!token) {
    return;
  }

  if (eros_token_is_simple(token)) {
    /* don't delete simple tokens, that is made at the end of the application */
    return;
  }

  if (token->value) {
    free(token->value);
    token->value = NULL;
  }

  free(token);
  token = NULL;
}

BOOL eros_token_is_simple_type(eros_token_type* type)
{
  /* simple token types have a value, complex ones do not (by definition) */
  return type->value != NULL;
}

BOOL eros_token_is_simple(eros_token_t* token)
{
  if (!token) {
    /* a null token is not simple */
    return FALSE;
  }

  return eros_token_is_simple_type(token->type);
}

BOOL eros_token_is_eof(eros_token_t* token)
{
  if (!token) {
    /* a null token is not eof */
    return FALSE;
  }

  return token->type->code == EROS_TK_EOF;
}
