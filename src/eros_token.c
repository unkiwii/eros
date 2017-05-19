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

char* eros_token_simple_value(eros_token_type type)
{
  switch (type) {

    case EROS_TK_EOF:       return "eof";
    case EROS_TK_SPACE:     return " ";
    case EROS_TK_EQUAL:     return "=";
    case EROS_TK_SET:       return ":=";
    case EROS_TK_DOT:       return ".";
    case EROS_TK_COMMA:     return ",";
    case EROS_TK_LBRACKET:  return "[";
    case EROS_TK_RBRACKET:  return "]";
    case EROS_TK_LPAREN:    return "(";
    case EROS_TK_RPAREN:    return ")";
    case EROS_TK_LBRACE:    return "{";
    case EROS_TK_RBRACE:    return "}";

    default:
      return NULL;
  }
}

const char* eros_token_type_name(eros_token_type type)
{
  switch (type) {

    case EROS_TK_EOF:       return "<eof>";
    case EROS_TK_SPACE:     return "<space>";
    case EROS_TK_EQUAL:     return "<equal>";
    case EROS_TK_SET:       return "<set>";
    case EROS_TK_DOT:       return "<dot>";
    case EROS_TK_COMMA:     return "<comma>";
    case EROS_TK_LBRACKET:  return "<lbracket>";
    case EROS_TK_RBRACKET:  return "<rbracket>";
    case EROS_TK_LPAREN:    return "<lparen>";
    case EROS_TK_RPAREN:    return "<rparen>";
    case EROS_TK_LBRACE:    return "<lbrace>";
    case EROS_TK_RBRACE:    return "<rbrace>";

    case EROS_TK_NUMBER:      return "<number>";
    case EROS_TK_IDENTIFIER:  return "<identifier>";
    case EROS_TK_STRING:      return "<string>";

    case EROS_TK_ILLEGAL:     return "<illegal>";

    default:
      return "<invalid>";
  }
}

eros_token_t* eros_token_simple(eros_token_type type)
{
  int index = eros_token_simple_index(type);
  if (index < 0) {
    return eros_token_illegal_new('\255');
  }

  loaded_token_t* entry = &eros_simple_tokens[index];
  if (!entry->isLoaded) {
    entry->isLoaded = 1;
    entry->token.type = type;
    entry->token.value = eros_token_simple_value(type);
  }

  return &(entry->token);
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

  if (eros_token_is_simple(token)) {
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

BOOL eros_token_is_simple(eros_token_t* token)
{
  if (!token) {
    return FALSE;
  }

  return eros_token_simple_index(token->type) >= 0;
}

BOOL eros_token_is_eof(eros_token_t* token)
{
  if (!token) {
    return FALSE;
  }

  return token->type == EROS_TK_EOF;
}
