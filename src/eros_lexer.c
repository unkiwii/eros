/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_defines.h"
#include "eros_lexer.h"
#include "eros_mem.h"

#include <stdlib.h>

void eros_add_token(eros_lexer_t* lexer, token_t token)
{
  int count = lexer->token_count + 1;
  lexer->tokens = (token_t*) realloc(lexer->tokens, sizeof(token_t*) * count);
  lexer->tokens[lexer->token_count] = eros_strdup(token);
  lexer->token_count = count;
}

void eros_lex(eros_lexer_t* lexer)
{
  //TODO
}

eros_lexer_t* eros_lexer_new(eros_source_t* source)
{
  eros_lexer_t* lexer = (eros_lexer_t*) malloc(sizeof(eros_lexer_t));

  lexer->source = source;
  lexer->row = 0;
  lexer->col = 0;
  lexer->tokens = NULL;
  lexer->token_count = 0;
  eros_lex(lexer);

  return lexer;
}

void eros_lexer_delete(eros_lexer_t* lexer)
{
  if (!lexer) {
    return;
  }

  if (lexer->tokens) {
    for (token_count_t i = 0; i < lexer->token_count; i++) {
      free(lexer->tokens[i]);
    }
    free(lexer->tokens);
    lexer->tokens = NULL;
  }

  if (lexer->source) {
    eros_source_delete(lexer->source);
    lexer->source = NULL;
  }

  free(lexer);
}
