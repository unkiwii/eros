/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include <stdio.h>
#include <string.h>

#include "eros_source.h"

eros_source_t* eros_source_from_file(char* filename)
{
  FILE* file = fopen(filename, "rb");
  if (!file) {
    printf("Can't open file %s\n", filename);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long int filesize = ftell(file);

  if (filesize < 0) {
    printf("Can't get size of file %s\n", filename);
    fclose(file);
    return NULL;
  }

  fseek(file, 0, SEEK_SET);

  eros_source_t* source = malloc(sizeof(eros_source_t));
  source->file = filename;
  source->size = filesize;
  source->data = malloc(filesize);

  long int readsize = fread(source->data, sizeof(char), filesize, file);
  fclose(file);

  if (readsize < filesize) {
    printf("Couldn't read file %s completely\n", filename);
    eros_source_delete(source);
    return NULL;
  }

  return source;
}

eros_source_t* eros_source_from_string(char* str)
{
  eros_source_t* source = malloc(sizeof(eros_source_t));
  source->file = NULL;
  source->size = strlen(str);
  source->data = malloc(source->size + 1);
  strcpy(source->data, str);

  return source;
}

void eros_source_delete(eros_source_t* source)
{
  free(source->data);
  free(source);
}
