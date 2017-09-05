#include "eros_input.h"
#include "eros_logger.h"
#include "eros_mem.h"

#include <stdlib.h>
#include <string.h>

eros_input_t* eros_input_new(int argc, char** argv)
{
  eros_input_t* input = (eros_input_t*) malloc(sizeof(eros_input_t));
  input->files = NULL;
  input->files_count = 0;
  input->compile_flag = 0;
  input->log_flag = 0;
  input->log_filename = NULL;

  for (int i = 1; i < argc; i++) {
    LOGD("arg %s", argv[i]);
    if (strcmp(argv[i], "-c") == 0) {
      input->compile_flag = 1;
    } else if (strcmp(argv[i], "-d") == 0) {
      input->log_flag = 1;
      if (argc > (i + 1)) {
        input->log_filename = eros_strdup(argv[++i]);
      }
    } else {
      input->files_count++;
      input->files = realloc(input->files, sizeof(char*) * input->files_count);
      input->files[input->files_count - 1] = eros_strdup(argv[i]);
    }
  }

  return input;
}

void eros_input_delete(eros_input_t* input)
{
  if (!input) {
    return;
  }

  for (int i = 0; i < input->files_count; i++) {
    free(input->files[i]);
  }
  free(input->files);

  if (input->log_filename) {
    free(input->log_filename);
  }

  free(input);
}

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
