#ifndef EROS_PARSER_H
#define EROS_PARSER_H

#include "eros_fwd.h"
#include "mpc.h"

struct eros_parser
{
  mpc_parser_t* Comment;
  mpc_parser_t* Number;
  mpc_parser_t* String;

  mpc_parser_t* Identifier;
  mpc_parser_t* Type;
  mpc_parser_t* Slot;
  mpc_parser_t* Assignment;

  mpc_parser_t* Expression;

  mpc_parser_t* Eros;
};

eros_parser* eros_parser_new(void);

void eros_parser_delete(eros_parser* parser);

eros_value* eros_parser_read_number(mpc_ast_t* ast);

eros_value* eros_parser_read_string(mpc_ast_t* ast);

eros_value* eros_parser_read(mpc_ast_t* ast);

eros_value* eros_parser_parse(eros_context* context, char* data);

#endif // EROS_PARSER_H
