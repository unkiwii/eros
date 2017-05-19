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
#include "eros_source.h"
#include "eros_token.h"
#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test_lexer()
{
  char* test = "Number a = 123.";
  eros_source_t* source = eros_source_from_string(test);
  eros_lexer_t* lexer = eros_lexer_new(source);

  #define SIZE 9
  eros_token_t* expected[SIZE] = {
    eros_token_new(EROS_TK_IDENTIFIER, "Number"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_NUMBER, "123"),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_EOF)
  };

  eros_token_t* actual[SIZE];

  int count = 0;
  do {
    actual[count] = eros_lexer_next_token(lexer);
  } while (!eros_token_is_eof(actual[count++]));

  eros_assert_eq_length("tokens", count, SIZE);

  for (int i = 0; i < SIZE; i++) {
    eros_assert_eq_char_ptr("token", actual[i]->value, expected[i]->value);
  }

  eros_lexer_delete(lexer);
}
