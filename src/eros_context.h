/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#ifndef EROS_CONTEXT_H
#define EROS_CONTEXT_H

#include "eros_fwd.h"

typedef long long int symbols_count_t;

struct eros_context_t
{
  /** the parser is here to be used by any builtin needing it **/
  eros_parser_t* parser;

  /** parent context, if null this would be the global context **/
  eros_context_t* parent;

  /** quantity of symbols in this context **/
  symbols_count_t symbols_count;

  /** list of symbols defined in this context **/
  char** symbols;

  /** list of values associated to symbols by index **/
  eros_value_t** values;
};

eros_context_t* eros_context_new(void);

void eros_context_delete(eros_context_t*);

eros_parser_t* eros_context_getparser(eros_context_t*);

#endif // EROS_CONTEXT_H
