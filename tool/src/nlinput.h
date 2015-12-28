#ifndef NL_INPUT_H
#define NL_INPUT_H

typedef struct nlinput
{
  /** list of files to compile or load to interpreter **/
  char** files;

  /** number of files **/
  int files_count;

  /** compile or run repl **/
  int compile_flag;
} nlinput;

nlinput* nlinput_new(void);

void nlinput_del(nlinput* input);

void nlinput_parse(nlinput* input, int argc, char** argv);

#endif // NL_INPUT_H
