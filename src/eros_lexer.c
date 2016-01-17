/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_lexer.h"
#include "eros_defines.h"

eros_lexer_t* eros_lexer_new(eros_source_t* source)
{
  eros_lexer_t* lexer = malloc(sizeof(eros_lexer_t));
  lexer->source = source;
  lexer->row = 0;
  lexer->col = 0;
  //TODO: add more properties here

  return lexer;
}

void eros_lexer_delete(eros_lexer_t* lexer)
{
  //TODO: add more "frees" here
  free(lexer);
}
