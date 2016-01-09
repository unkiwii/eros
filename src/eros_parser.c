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

#include "eros_context.h"
#include "eros_defines.h"
#include "eros_parser.h"
#include "eros_value.h"

eros_parser* eros_parser_new(void)
{
  eros_parser* parser = malloc(sizeof(eros_parser));

  parser->value = NULL;
  parser->column = 1;
  parser->line = 1;

  return parser;
}

void eros_parser_delete(eros_parser* parser)
{
  UNUSED(parser);
}

eros_value* eros_parser_parse(eros_context* context, char* input)
{
  eros_parser* parser = eros_context_getparser(context);

  parser->step = eros_parser_step_module;
  parser->value = eros_value_module("<main>");  //TODO: get name from some place

  long long int idx = 0;
  char rune = 0;

  do {
    rune = input[idx++];
    parser->step(parser, rune);
    parser->column++;
  } while (rune != 0);

  return parser->value;
}

void eros_parser_step_module(eros_parser* parser, char rune)
{
  UNUSED(parser);
}

void eros_parser_step_expression(eros_parser* parser, char rune)
{
  UNUSED(parser);
}

void eros_parser_step_assignment(eros_parser* parser, char rune)
{
  UNUSED(parser);
}

void eros_parser_step_slot(eros_parser* parser, char rune)
{
  UNUSED(parser);
}

void eros_parser_step_type(eros_parser* parser, char rune)
{
  UNUSED(parser);
}

void eros_parser_step_identifier(eros_parser* parser, char rune)
{
  UNUSED(parser);
}
