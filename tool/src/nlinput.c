#include <stdlib.h>
#include <string.h>
#include "nlinput.h"

nlinput* nlinput_new(void)
{
  nlinput* input = malloc(sizeof(nlinput));
  input->files = NULL;
  input->files_count = 0;
  input->compile_flag = 0;
  return input;
}

void nlinput_del(nlinput* input)
{
  for (int i = 0; i < input->files_count; i++) {
    free(input->files[i]);
  }
  free(input->files);
  free(input);
}

void nlinput_parse(nlinput* input, int argc, char** argv)
{
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      input->compile_flag = 1;
    } else {
      //TODO: parse input files
    }
  }
}
