#include "eros_context.h"
#include "eros_lexer.h"
#include "eros_logger.h"
#include "eros_parser.h"
#include "eros_token.h"
#include "eros_ast_node.h"

#include <stdio.h>
#include <stdlib.h>

eros_parser_t* eros_parser_new(void)
{
  eros_parser_t* parser = (eros_parser_t*) malloc(sizeof(eros_parser_t));

  parser->step = NULL;
  parser->result = NULL;

  return parser;
}

void eros_parser_delete(eros_parser_t* parser)
{
  if (parser->result) {
    eros_ast_node_delete(parser->result);
    parser->result = NULL;
  }

  free(parser);
}

eros_ast_node_t* eros_parser_parse(eros_context_t* context, const char* text)
{
  eros_source_t* source = eros_source_from_string(text);
  eros_lexer_t* lexer = eros_lexer_new(source);
  eros_parser_t* parser = eros_context_getparser(context);

  parser->result = eros_parser_step(eros_parser_step_module, parser, lexer);

  /* eros_token_t* token = eros_lexer_next_token(lexer); */
  /* if (token != eros_token_simple(EROS_TK_EOF)) { */
  /*   parser->step(parser, lexer, token); */
  /* } */

  /* bool line = false; */
  /* eros_token_t* token = NULL; */
  /* while (eros_token_simple(EROS_TK_EOF) != (token = eros_lexer_next_token(lexer))) { */
  /*   line = true; */
  /*   printf("(\"%s\", %s) ", eros_token_value(token), eros_token_type_name(token)); */
  /*   parser->step(parser, lexer, token); */
  /*   eros_token_delete(token); */
  /* } */
  /* if (line) { */
  /*   printf("\n"); */
  /* } */

  /* for (token_count_t i = 0; i < token_count; i++) { */
  /*   token = tokens[i]; */
  /*   parser->step(parser, token); */
  /*   if (parser->result && parser->result->type == EROS_VALUE_ERROR) { */
  /*     return parser->result; */
  /*   } */
  /* } */

  eros_lexer_delete(lexer);
  eros_source_delete(source);

  return parser->result;
}

eros_ast_node_t* eros_parser_step(eros_parser_step_t step, eros_parser_t* parser, eros_lexer_t* lexer)
{
  parser->step = step;
  return parser->step(parser, lexer);
}

eros_ast_node_t* eros_parser_step_module(eros_parser_t* parser, eros_lexer_t* lexer)
{
  eros_token_t* token = eros_lexer_next_token(lexer);
  LOGD("step_module ('%s', %s)", eros_token_value(token), eros_token_type_name(token));

  if (!eros_token_is_identifier(token, "import")) {
    LOGD("'%s' is not the identifier 'import'", eros_token_value(token));
    return NULL;
  }

  LOGD("FOUND %s", eros_token_value(token));
  return NULL;
}

eros_ast_node_t* eros_parser_step_assignment(eros_parser_t* parser, eros_lexer_t* lexer)
{
  //TODO
  return NULL;
}

eros_ast_node_t* eros_parser_step_slot(eros_parser_t* parser, eros_lexer_t* lexer)
{
  //TODO
  return NULL;
}

eros_ast_node_t* eros_parser_step_type(eros_parser_t* parser, eros_lexer_t* lexer)
{
  //TODO
  return NULL;
}

eros_ast_node_t* eros_parser_step_identifier(eros_parser_t* parser, eros_lexer_t* lexer)
{
  //TODO
  return NULL;
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
