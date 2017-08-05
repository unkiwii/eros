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

#ifndef PROMPT_WIN_H
#define PROMPT_WIN_H

#include "eros_mem.h"

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2048

static char _readline_in[BUFFER_SIZE];

/* readline for windows */
char* readline(char* prompt)
{
  fputs(prompt, stdout);
  fgets(_readline_in, BUFFER_SIZE, stdin);
  char* cpy = eros_strdup(_readline_in);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* ignored) {
  (void*)ignored;
}

void clear_history(void) {
  //TODO: clear it
}

#endif // PROMPT_WIN_H
