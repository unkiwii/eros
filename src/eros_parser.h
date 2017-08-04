/*
Copyright (c) 2016-2017 Lucas Gabriel Sánchez

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

#ifndef EROS_PARSER_H
#define EROS_PARSER_H

#include "eros_defines.h"

typedef void (*eros_parser_step_t)(eros_parser_t*, eros_lexer_t*, eros_token_t*);

struct eros_parser_t
{
  /** current step in the parser **/
  eros_parser_step_t step;

  /** result of the parse operation **/
  eros_value_t* result;
};

eros_parser_t* eros_parser_new(void);

void eros_parser_delete(eros_parser_t* parser);

eros_value_t* eros_parser_parse(eros_context_t*, const char* text);

void eros_parser_step_module(eros_parser_t*, eros_lexer_t*, eros_token_t*);
void eros_parser_step_assignment(eros_parser_t*, eros_lexer_t*, eros_token_t*);
void eros_parser_step_slot(eros_parser_t*, eros_lexer_t*, eros_token_t*);
void eros_parser_step_type(eros_parser_t*, eros_lexer_t*, eros_token_t*);
void eros_parser_step_identifier(eros_parser_t*, eros_lexer_t*, eros_token_t*);

#endif // EROS_PARSER_H
