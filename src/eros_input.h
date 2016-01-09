/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#ifndef EROS_INPUT_H
#define EROS_INPUT_H

typedef struct eros_input_t
{
  /** list of files to compile or load to interpreter **/
  char** files;

  /** number of files **/
  int files_count;

  /** compile or run repl **/
  int compile_flag;
} eros_input_t;

eros_input_t* eros_input_new(int argc, char** argv);

void eros_input_delete(eros_input_t* input);

#endif // EROS_INPUT_H
