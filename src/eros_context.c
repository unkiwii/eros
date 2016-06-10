/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#include <stdlib.h>
#include <string.h>

#include "eros_context.h"
#include "eros_parser.h"
#include "eros_value.h"

eros_context_t* eros_context_new(void)
{
  eros_context_t* context = malloc(sizeof(eros_context_t));

  context->parser = eros_parser_new();
  context->parent = NULL;
  context->symbols_count = 0;
  context->symbols = NULL;
  context->values = NULL;
  context->is_alive = 1;
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
    context->error = malloc(strlen(error) + 1);
    strcpy(context->error, error);
  }
}
