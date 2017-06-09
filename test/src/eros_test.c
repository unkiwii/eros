/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_test.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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
