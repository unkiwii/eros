#include <stdio.h>
#include "nlcompile.h"

int nl_compile(nlinput* input)
{
  puts("compile");
  for (int i = 0; i < input->files_count; i++) {
    printf("  file: %s\n", input->files[i]);
  }
  return 0;
}
