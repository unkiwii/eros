#include "eros_token.h"
#include "eros_mem.h"

#include <stdlib.h>
#include <string.h>

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

void eros_token_delete_simples(void) {
  for (int i = 0; i < EROS_TOKEN_SIMPLE_COUNT; ++i) {
    free(simple_tokens[i]);
    simple_tokens[i] = NULL;
  }
}

eros_token_type* eros_token_type_by_code(eros_token_type_code code)
{
  int index = 0;
  eros_token_type* t;
  do {
    t = &token_types[index];
    if (t->code == code) {
      return t;
    }
    index++;
  } while (t->code != _EROS_TK_LAST_);  /* simple types have a value */

  return NULL;
}

int eros_token_simple_index(eros_token_type_code code)
{
  int index = 0;
  const eros_token_type* t;
  do {
    t = &token_types[index];
    if (t->code == code) {
      return index;
    }
    index++;
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

const char* eros_token_type_name(eros_token_t* token)
{
  if (!token) {
    return "<NULL>";
  }

  eros_token_type* type = token->type;
  if (type) {
    return type->name;
  }

  return "<INVALID>";
}

const char* eros_token_value(eros_token_t* token)
{
  if (!token) {
    return "null";
  }

  return token->value;
}

bool _will_clean_simples = false;
eros_token_t* eros_token_simple(eros_token_type_code code)
{
  if (!_will_clean_simples) {
    _will_clean_simples = true;
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

bool eros_token_is_simple_type(eros_token_type* type)
{
  /* simple token types have a value, complex ones do not (by definition) */
  return type->value != NULL;
}

bool eros_token_is_simple(eros_token_t* token)
{
  if (!token) {
    /* a null token is not simple */
    return false;
  }

  return eros_token_is_simple_type(token->type);
}

bool eros_token_is_eof(eros_token_t* token)
{
  if (!token) {
    /* a null token is not eof */
    return false;
  }

  return token->type->code == EROS_TK_EOF;
}

bool eros_token_is_identifier(eros_token_t* token, const char* identifier)
{
  if (!token) {
    return false;
  }

  return token->type->code == EROS_TK_IDENTIFIER
      && strncmp(token->value, identifier, strlen(identifier)) == 0;
}

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
