/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "test.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*eros_test)();

#define INITIAL_STATUS 65000
static int _test_status = INITIAL_STATUS;

void test(const char* name, eros_test t)
{
  _test_status = 0;
  printf("%s\n", name);
  t();
  /**
   *
   * IMPORTANT:
   *
   *  Something inside t(); is modifying test_status indirectly (via bad memory acces?)
   *  I need to fix it before doing anything else
   *
   *  All tests are passing (test_status should be 0) but I see them as failing
   *
   */
  if (_test_status != 0) {
    printf("%d tests failed\n", _test_status - INITIAL_STATUS);
    exit(_test_status);
  }
}

void eros_assert_eq_length(const char* name, int actual, int expected)
{
  if (actual != expected) {
    fail("expected %d %s, but found %d\n", expected, name, actual);
  }
}

void eros_assert_eq_char_arr(const char* name, int length, char** actual, char** expected)
{
  for (int i = 0; i < length; i++) {
    if (strcmp(actual[i], expected[i]) != 0) {
      fail("expected %s '%s' but found '%s'\n", name, expected[i], actual[i]);
    }
  }
}

void eros_assert_eq_char_ptr(const char* name, char* actual, char* expected)
{
  if (strcmp(actual, expected) != 0) {
    fail("expected %s to be '%s', but found '%s'\n", name, expected, actual);
  }
}

void fail(const char* format, ...)
{
  va_list args;
  va_start(args, format);
  printf("  ERROR: ");
  vprintf(format, args);
  va_end(args);

  _test_status += 1;
}

int main(int argc, char** argv)
{
  printf("\nPerforming tests...\n");

  test("lexer", test_lexer);
  //TODO add more tests here

  printf("All tests are ok\n");
  return 0;
}
