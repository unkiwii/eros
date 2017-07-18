/*
Copyright (c) 2016-2017 Lucas Gabriel Sánchez

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
