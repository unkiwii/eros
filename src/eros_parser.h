#ifndef EROS_PARSER_H
#define EROS_PARSER_H

#include "eros_fwd.h"
#include "mpc.h"

struct eros_parser
{
  mpc_parser_t* Comment;    /* #\s[^\r\n]*                        */
  mpc_parser_t* Eros;       /* Expression*                        */
  mpc_parser_t* Expression; /* Variable | Function | Application  */
  mpc_parser_t* String;     /* "*"                                */
  mpc_parser_t* Number;     /* -?[0-9]+                           */
  mpc_parser_t* Symbol;     /* [a-zA-Z0-9_+-*\/=<>!:?]+           */
  mpc_parser_t* Assignment; /* Symbol = Expression                */
};

eros_parser* eros_parser_new(void);

void eros_parser_delete(eros_parser* parser);

eros_value* eros_parser_read_number(mpc_ast_t* ast);

eros_value* eros_parser_read_string(mpc_ast_t* ast);

eros_value* eros_parser_read(mpc_ast_t* ast);

eros_value* eros_parser_parse(eros_context* context, char* data);

#endif // EROS_PARSER_H
