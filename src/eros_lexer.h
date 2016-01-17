/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_LEXER_H
#define EROS_LEXER_H

#include "eros_source.h"

typedef struct eros_lexer_t
{
  eros_source_t* source;

  size_t row;
  size_t col;

} eros_lexer_t;

eros_lexer_t* eros_lexer_new(eros_source_t*);

void eros_lexer_delete(eros_lexer_t*);

#endif // EROS_LEXER_H
