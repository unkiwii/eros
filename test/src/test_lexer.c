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

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_lexer_case(char* text, eros_token_t* token, ...)
{
  eros_source_t* source = eros_source_from_string(text);
  eros_lexer_t* lexer = eros_lexer_new(source);

  eros_token_t** expected = NULL;
  int expected_count = 0;

  va_list arg;
  va_start(arg, token);
  eros_token_t* next = token;
  while (next) {
    expected_count++;
    expected = (eros_token_t**) realloc(expected, sizeof(eros_token_t*) * expected_count);
    expected[expected_count - 1] = next;
    next = va_arg(arg, eros_token_t*);
  }
  va_end(arg);

  eros_token_t** actual = calloc(expected_count, sizeof(eros_token_t*));

  int actual_count = 0;
  do {
    actual[actual_count] = eros_lexer_next_token(lexer);
    printf("   got: '%s'\n", actual[actual_count]->value);
  } while (!eros_token_is_eof(actual[actual_count++]) && actual_count <= expected_count);

  eros_assert_eq_length("tokens", actual_count, expected_count);

  int count = actual_count > expected_count ? expected_count : actual_count;
  for (int i = 0; i < count; i++) {
    eros_assert_eq_char_ptr("token", actual[i]->value, expected[i]->value);
  }

  for (int i = 0; i < actual_count; i++) {
    if (actual[i]) {
      printf("freeing: '%s'\n", actual[i]->value);
      printf("i: %d\n", i);
      free(actual[i]);
      actual[i] = NULL;
    }
  }
  free(actual);
  free(expected);

  eros_lexer_delete(lexer);
}

void test_lexer()
{
  char* t;

  t = "Number a = 123.";
  printf("  lexing '%s'\n", t);
  test_lexer_case(t,
    eros_token_new(EROS_TK_IDENTIFIER, "Number"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_NUMBER, "123"),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  t = "name = a.";
  printf("  lexing '%s'\n", t);
  test_lexer_case(t,
    eros_token_new(EROS_TK_IDENTIFIER, "name"),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_simple(EROS_TK_EQUAL),
    eros_token_simple(EROS_TK_SPACE),
    eros_token_new(EROS_TK_IDENTIFIER, "a"),
    eros_token_simple(EROS_TK_DOT),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );
}
