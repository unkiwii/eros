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
#include "eros_source.h"
#include "eros_mem.h"
#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* expected[512];
int expected_length;

void expect(char* str)
{
  expected_length = 0;

  char* tk = eros_strdup(str);

  char* next = strtok(tk, " ");
  if (next) {
    expected[expected_length++] = next;
  }

  while ((next = strtok(NULL, " ")) != NULL) {
    expected[expected_length++] = " ";
    expected[expected_length++] = next;
  }

  free(tk);
}

void test_lexer()
{
  char* test = "Number a = 123.";
  eros_source_t* source = eros_source_from_string(test);
  eros_lexer_t* lexer = eros_lexer_new(source);

  expect(test);

  /* eros_assert_eq_length("tokens", lexer->token_count, expected_length); */
  /* eros_assert_eq_carr("token", lexer->token_count, lexer->tokens, expected); */

  eros_lexer_delete(lexer);
}
