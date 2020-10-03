#ifndef EROS_CONTEXT_H
#define EROS_CONTEXT_H

#include "eros_defines.h"

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

  /** is this context alive? (see error) **/
  bool is_alive;

  /** why is not alive anymore **/
  char* error;
};

eros_context_t* eros_context_new(void);

void eros_context_delete(eros_context_t*);

eros_parser_t* eros_context_getparser(eros_context_t*);

void eros_context_seterror(eros_context_t*, char* error);

#endif // EROS_CONTEXT_H

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
