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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*eros_test)();

static int test_status;

void test(char* name, eros_test t)
{
  test_status = 0;
  printf("%s\n", name);
  t();
  if (test_status != 0) {
    printf("\n");
    exit(test_status);
  }
}

void eros_assert_eq_length(char* name, int actual, int expected)
{
  if (actual != expected) {
    printf("  ERROR: expected %d %s, but found %d\n", expected, name, actual);
    test_status += 1;
  }
}

void eros_assert_eq_carr(char* name, int length, char** actual, char** expected)
{
  for (int i = 0; i < length; i++) {
    if (strcmp(actual[i], expected[i]) != 0) {
      printf("  ERROR: expected %s '%s' but found '%s'\n", name, expected[i], actual[i]);
      test_status += 1;
    }
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
