/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_PARSER_H
#define EROS_PARSER_H

#include "eros_fwd.h"

typedef void (*eros_parser_step_t)(eros_parser_t*, char);

struct eros_parser_t
{
  eros_parser_step_t step;

  eros_value_t* result;

  /** current column being parsed **/
  int column;

  /** current line being parsed **/
  int line;
};

eros_parser_t* eros_parser_new(void);

void eros_parser_delete(eros_parser_t* parser);

eros_value_t* eros_parser_parse(eros_context_t* context, char* input);

void eros_parser_step_module(eros_parser_t*, char);
void eros_parser_step_assignment(eros_parser_t*, char);
void eros_parser_step_slot(eros_parser_t*, char);
void eros_parser_step_type(eros_parser_t*, char);
void eros_parser_step_identifier(eros_parser_t*, char);

#endif // EROS_PARSER_H
