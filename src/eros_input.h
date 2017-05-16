/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_INPUT_H
#define EROS_INPUT_H

#include "eros_defines.h"

struct eros_input_t
{
  /**
   * -d [FILE], optional: to log to stderr or FILE
   */
  flag_t log_flag;
  char* log_filename;

  /**
   * -c, optional: to compile, is absent go into repl mode
   */
  flag_t compile_flag;

  /**
   * the rest of the arguments are treated as files to load or compile
   */
  char** files;
  files_count_t files_count;
};

eros_input_t* eros_input_new(int argc, char** argv);

void eros_input_delete(eros_input_t* input);

#endif // EROS_INPUT_H
