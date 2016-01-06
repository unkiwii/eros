#include "eros_defines.h"
#include "eros_parser.h"
#include "eros_grammar.h"

eros_parser* eros_parser_new(void)
{
  eros_parser* parser = malloc(sizeof(eros_parser));

  parser->Comment = mpc_new("comment");
  parser->Number = mpc_new("number");
  parser->String = mpc_new("string");

  parser->Identifier = mpc_new("identifier");
  parser->Type = mpc_new("type");
  parser->Slot = mpc_new("slot");
  parser->Assignment = mpc_new("assignment");

  parser->Expression = mpc_new("expression");

  parser->Eros = mpc_new("eros");

  mpc_err_t* err = mpca_lang(MPCA_LANG_WHITESPACE_SENSITIVE,
      eros_grammar,
      parser->Comment,
      parser->Number,
      parser->String,
      parser->Identifier,
      parser->Type,
      parser->Slot,
      parser->Assignment,
      parser->Expression,
      parser->Eros,
      NULL);

  if (err) {
    mpc_err_print(err);
    mpc_err_delete(err);
    return NULL;
  }

  return parser;
}

void eros_parser_delete(eros_parser* parser)
{
  UNUSED(parser);
}

eros_value* eros_parser_read_number(mpc_ast_t* ast)
{
  UNUSED(ast);
  return NULL;
}

eros_value* eros_parser_read_string(mpc_ast_t* ast)
{
  UNUSED(ast);
  return NULL;
}

eros_value* eros_parser_read(mpc_ast_t* ast)
{
  UNUSED(ast);
  return NULL;
}

eros_value* eros_parser_parse(eros_context* context, char* data)
{
  UNUSED(context);
  UNUSED(data);
  return NULL;
}
