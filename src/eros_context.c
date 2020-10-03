#include "eros_context.h"
#include "eros_mem.h"
#include "eros_parser.h"
#include "eros_value.h"

#include <stdlib.h>
#include <string.h>

eros_context_t* eros_context_new(void)
{
  eros_context_t* context = malloc(sizeof(eros_context_t));

  context->parser = eros_parser_new();
  context->parent = NULL;
  context->symbols_count = 0;
  context->symbols = NULL;
  context->values = NULL;
  context->is_alive = true;
  context->error = NULL;

  return context;
}

void eros_context_delete(eros_context_t* context)
{
  if (context->parser) {
    eros_parser_delete(context->parser);
    context->parser = NULL;
  }

  symbols_count_t len = context->symbols_count;
  for (symbols_count_t i = 0; i < len; i++) {
    free(context->symbols[i]);
    eros_value_delete(context->values[i]);
  }

  if (context->error) {
    free(context->error);
    context->error = NULL;
  }

  if (context->symbols) {
    free(context->symbols);
    context->symbols = NULL;
  }

  if (context->values) {
    free(context->values);
    context->values = NULL;
  }

  free(context);
}

eros_parser_t* eros_context_getparser(eros_context_t* context)
{
  if (context->parser) {
    return context->parser;
  }

  if (context->parent) {
    return eros_context_getparser(context->parent);
  }

  return NULL;
}

void eros_context_seterror(eros_context_t* context, char* error)
{
  if (context->error) {
    free(context->error);
  }

  if (error) {
    context->error = eros_strdup(error);
  }
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
