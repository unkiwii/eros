#include <stdio.h>
#include "nlrepl.h"

int nl_repl(nlinput* input)
{
  puts("repl");
  for (int i = 0; i < input->files_count; i++) {
    printf("  file: %s\n", input->files[i]);
  }
  return 0;
}
