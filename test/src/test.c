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

#define INITIAL_STATUS 65000
static int failed = INITIAL_STATUS;

void fail(const char* format, ...)
{
  va_list args;
  va_start(args, format);
  printf("    ERROR: ");
  vprintf(format, args);
  va_end(args);

  failed += 1;
}

BOOL eros_assert_null(const char* name, void* ptr)
{
  if (ptr) {
    fail("expected %s to be null, but found %p\n", name, ptr);
    return FALSE;
  }
  return TRUE;
}

BOOL eros_assert_not_null(const char* name, void* ptr)
{
  if (!ptr) {
    fail("expected %s to have a value, but found %p\n", name, ptr);
    return FALSE;
  }
  return TRUE;
}

BOOL eros_assert_eq_length(const char* name, int actual, int expected)
{
  if (actual != expected) {
    fail("expected %d %s, but found %d\n", expected, name, actual);
    return FALSE;
  }
  return TRUE;
}

BOOL eros_assert_eq_char_arr(const char* name, int length, char** actual, char** expected)
{
  for (int i = 0; i < length; i++) {
    if (strcmp(actual[i], expected[i]) != 0) {
      fail("expected %s '%s' but found '%s'\n", name, expected[i], actual[i]);
      return FALSE;
    }
  }
  return TRUE;
}

BOOL eros_assert_eq_char_ptr(const char* name, char* actual, char* expected)
{
  if (strcmp(actual, expected) != 0) {
    fail("expected '%s', but found '%s' in '%s'\n", expected, actual, name);
    return FALSE;
  }
  return TRUE;
}

typedef void (*eros_test)();

void test(const char* name, eros_test t)
{
  failed = INITIAL_STATUS;
  printf("%s\n", name);
  t();
  int total = failed - INITIAL_STATUS;
  if (total != 0) {
    printf("%d test%s failed\n", total, total == 1 ? "" : "s");
    exit(failed);
  }
}

int main(int argc, char** argv)
{
  printf("\nPerforming tests...\n");

  test("lexer", test_lexer);
  //TODO add more tests here

  printf("All tests are ok\n");
  return 0;
}
