/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.  */

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
