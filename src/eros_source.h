/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_SOURCE_H
#define EROS_SOURCE_H

#include "eros_defines.h"

struct eros_source_t
{
  /* file name from there this was loaded (NULL when loaded from string) */
  char* filename;

  /* contents of the loaded file or string */
  char* data;

  /* size of loaded data, from file or string */
  source_size_t size;
};

eros_source_t* eros_source_from_file(char* filename);
eros_source_t* eros_source_from_string(char* str);

void eros_source_delete(eros_source_t* source);

char eros_source_read(eros_source_t* source, source_size_t at);

#endif // EROS_SOURCE_H
