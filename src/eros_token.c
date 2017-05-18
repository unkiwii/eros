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

typedef struct loaded_token_t
{
  /** is loaded or not? **/
  char isLoaded;

  /** the token itself **/
  eros_token_t token;
} loaded_token_t;

loaded_token_t eros_simple_tokens[12];

int eros_token_simple_index(eros_token_type type)
{
  switch (type) {

    case EROS_TK_EOF:       return 0;
    case EROS_TK_SPACE:     return 1;
    case EROS_TK_EQUAL:     return 2;
    case EROS_TK_SET:       return 3;
    case EROS_TK_DOT:       return 4;
    case EROS_TK_COMMA:     return 5;
    case EROS_TK_LBRACKET:  return 6;
    case EROS_TK_RBRACKET:  return 7;
    case EROS_TK_LPAREN:    return 8;
    case EROS_TK_RPAREN:    return 9;
    case EROS_TK_LBRACE:    return 10;
    case EROS_TK_RBRACE:    return 11;

    default:
      return -1;
  }
}

eros_token_t* eros_token_simple(eros_token_type type)
{
  int index = eros_token_simple_index(type);
  if (index < 0) {
    return eros_token_illegal_new('\255');
  }

  loaded_token_t entry = eros_simple_tokens[index];
  if (!entry.isLoaded) {
    entry.isLoaded = 1;
    entry.token.type = type;
    entry.token.value = NULL;
  }

  return &(eros_simple_tokens[index].token);
}

eros_token_t* eros_token_illegal_new(char ch)
{
  eros_token_t* token = (eros_token_t*) malloc(sizeof(eros_token_t));
  token->type = EROS_TK_ILLEGAL;
  token->value = (char*) malloc(sizeof(char) * 2);
  token->value[0] = ch;
  token->value[1] = '\0';
  return token;
}

eros_token_t* eros_token_new(eros_token_type type, const char* value)
{
  eros_token_t* token = (eros_token_t*) malloc(sizeof(eros_token_t));
  token->type = type;
  token->value = eros_strdup(value);
  return token;
}

void eros_token_delete(eros_token_t* token)
{
  if (!token) {
    return;
  }

  int index = eros_token_simple_index(token->type);
  if (index > 0) {
    /* we don't free simple tokens */
    return;
  }

  if (token->value) {
    free(token->value);
    token->value = NULL;
  }

  free(token);
  token = NULL;
}
