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

#include "eros_assert.h"
#include "eros_lexer.h"
#include "eros_mem.h"
#include "eros_token.h"

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
    if (eros_assert_not_null("eros_lexer_next_token(lexer)", lex_output)) {
      eros_assert_eq_char_ptr(text, lex_output->value, next->value);
      count++;
    }
    eros_token_delete(next);
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

  test_lexer_case("1234567890",
    eros_token_new(EROS_TK_NUMBER, "1234567890"),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("identifier",
    eros_token_new(EROS_TK_IDENTIFIER, "identifier"),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("\"hola\"",
    eros_token_new(EROS_TK_STRING, "hola"),
    eros_token_simple(EROS_TK_EOF),
    NULL
  );

  test_lexer_case("\"\"",
    eros_token_new(EROS_TK_STRING, ""),
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
