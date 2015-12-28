#include "nlinput.h"
#include "nlcompile.h"
#include "nlrepl.h"

int main(int argc, char** argv)
{
  nlinput* input = nlinput_new();

  nlinput_parse(input, argc, argv);

  int exit_code = 0;
  if (input->compile_flag) {
    exit_code = nl_compile(input);
  } else {
    exit_code = nl_repl(input);
  }

  nlinput_del(input);

  return exit_code;
}
