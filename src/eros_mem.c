/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include <stdlib.h>
#include <string.h>

#include "eros_mem.h"

char* eros_strdup(const char* s)
{
  size_t length = strlen(s);
  char* r = (char*) calloc(length + 1, sizeof(char*));
  strncpy(r, s, length);
  return r;
}

char* eros_strcpy(const char* source, int from, int to)
{
  if (to <= from) {
    return NULL;
  }

  int length = to - from;
  char* r = (char*) calloc(length + 1, sizeof(char*));
  strncpy(r, source + from, length);
  return r;
}
