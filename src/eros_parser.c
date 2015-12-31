#include "eros_parser.h"

eros_parser* eros_parser_new(void)
{
  eros_parser* parser = malloc(sizeof(eros_parser));

  parser->Comment = mpc_new("comment");
  parser->Eros = mpc_new("eros");
  parser->Expression = mpc_new("expression");
  parser->String = mpc_new("string");
  parser->Number = mpc_new("number");
  parser->Symbol = mpc_new("symbol");
  parser->Assignment = mpc_new("assignment");

  mpca_lang(MPCA_LANG_WHITESPACE_SENSITIVE,
    " comment : /# [^\\r\\n]*/;                           \
      number  : /-?[0-9]+/;                               \
      string  : /\"(\\\\.|[^\"])*\"/;                     \
                                                          \
      eros    : /^/ <expression>* /$/;                    \
                                                          \
    ",
    parser->Comment, parser->Eros, parser->Expression,
    parser->String, parser->Number, parser->Symbol,
    parser->Assignment);

  return parser;
}

void eros_parser_delete(eros_parser* parser)
{
}

eros_value* eros_parser_read_number(mpc_ast_t* ast)
{
  return NULL;
}

eros_value* eros_parser_read_string(mpc_ast_t* ast)
{
  return NULL;
}

eros_value* eros_parser_read(mpc_ast_t* ast)
{
  return NULL;
}

eros_value* eros_parser_parse(eros_context* context, char* data)
{
  return NULL;
}
