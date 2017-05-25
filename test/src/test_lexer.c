/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_lexer.h"
#include "eros_mem.h"
#include "eros_token.h"
#include "test.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_lexer_case(char* text, eros_token_t* token, ...)
{
  printf("  lexing '%s'\n", text);

  eros_source_t* source = eros_source_from_string(text);
  eros_lexer_t* lexer = eros_lexer_new(source);

  va_list arg;
  va_start(arg, token);
  eros_token_t* next = token;
  eros_token_t* lex_output = NULL;
  int count = 0;
  while (next) {
    lex_output = eros_lexer_next_token(lexer);
    eros_assert_eq_char_ptr(text, lex_output->value, next->value);
    eros_token_delete(lex_output);
    count++;
    next = va_arg(arg, eros_token_t*);
  }
  va_end(arg);

  eros_lexer_delete(lexer);
  eros_source_delete(source);
}

void test_lexer()
{
  test_lexer_case("",
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case(" =:=.,[]{}()1a",
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_SET),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_COMMA),
    eros_token_simple(EROS_TK_LBRACKET),
    eros_token_simple(EROS_TK_RBRACKET),
    eros_token_simple(EROS_TK_LBRACE),
    eros_token_simple(EROS_TK_RBRACE),
    eros_token_simple(EROS_TK_LPAREN),
    eros_token_simple(EROS_TK_RPAREN),
    eros_token_new(EROS_TK_NUMBER, "1"),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("==:=:==",
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_SET),
    eros_token_simple(EROS_TK_SET),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("Number a := 123.",
    eros_token_new(EROS_TK_IDENTIFIER, "Number"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_SET),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_NUMBER, "123"),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("name := a.",
    eros_token_new(EROS_TK_IDENTIFIER, "name"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_SET),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );
}
