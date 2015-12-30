#ifndef PROMPT_WIN_H
#define PROMPT_WIN_H

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2048

static char _readline_in[BUFFER_SIZE];

/* readline for windows */
char* readline(char* prompt)
{
  fputs(prompt, stdout);
  fgets(_readline_in, BUFFER_SIZE, stdin);
  char* cpy = malloc(strlen(_readline_in) + 1);
  strcpy(cpy, _readline_in);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* ignored) {
  (void*)ignored;
}

#endif // PROMPT_WIN_H
