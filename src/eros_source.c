/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_defines.h"
#include "eros_logger.h"
#include "eros_mem.h"
#include "eros_source.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eros_source_t* eros_source_from_file(char* filename)
{
  FILE* file = fopen(filename, "rb");
  if (!file) {
    LOGE("Can't open file %s\n", filename);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  file_size_t filesize = ftell(file);

  if (filesize < 0) {
    LOGE("Can't get size of file %s\n", filename);
    fclose(file);
    return NULL;
  }

  fseek(file, 0, SEEK_SET);

  eros_source_t* source = (eros_source_t*) malloc(sizeof(eros_source_t));
  source->filename = filename;
  source->size = filesize;
  source->data = (char*) calloc(filesize, sizeof(char*));

  file_size_t readsize = fread(source->data, sizeof(char), filesize, file);
  fclose(file);

  if (readsize < filesize) {
    LOGE("Couldn't read file %s completely\n", filename);
    eros_source_delete(source);
    return NULL;
  }

  return source;
}

eros_source_t* eros_source_from_string(char* str)
{
  eros_source_t* source = (eros_source_t*) malloc(sizeof(eros_source_t));
  source->filename = NULL;
  source->size = strlen(str);
  source->data = eros_strdup(str);
  return source;
}

void eros_source_delete(eros_source_t* source)
{
  if (!source) {
    return;
  }

  if (source->data) {
    free(source->data);
  }

  free(source);
}

char eros_source_read(eros_source_t* source, source_size_t at)
{
  if (at >= source->size) {
    return 0;
  }

  return source->data[at];
}

char* eros_source_read_interval(eros_source_t* source, source_size_t from, source_size_t to)
{
  if (from >= source->size || to >= source->size) {
    return NULL;
  }

  return eros_strcpy(source->data, from, to);
}
