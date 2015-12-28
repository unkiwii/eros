#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct linput
{
  /** list of files to compile or load to interpreter **/
  char** files;

  /** number of files **/
  int files_count;

  /** compile or run repl **/
  int compile_flag;
} linput;

linput* linput_new(void)
{
  linput* input = malloc(sizeof(linput));
  input->files = NULL;
  input->files_count = 0;
  input->compile_flag = 0;
  return input;
}

void linput_del(linput* input)
{
  for (int i = 0; i < input->files_count; i++) {
    free(input->files[i]);
  }
  free(input->files);
  free(input);
}

void linput_parse(linput* input, int argc, char** argv)
{
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      input->compile_flag = 1;
    } else {
      //TODO: parse input files
    }
  }
}

int newlang_compile(linput* input)
{
  puts("compile");
  return 0;
}

int newlang_repl(linput* input)
{
  puts("repl");
  return 0;
}

int main(int argc, char** argv)
{
  linput* input = linput_new();

  linput_parse(input, argc, argv);

  int exit_code = 0;
  if (input->compile_flag) {
    exit_code = newlang_compile(input);
  } else {
    exit_code = newlang_repl(input);
  }

  linput_del(input);

  return exit_code;
}
