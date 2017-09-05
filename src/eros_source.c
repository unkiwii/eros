#include "eros_defines.h"
#include "eros_logger.h"
#include "eros_mem.h"
#include "eros_source.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eros_source_t* eros_source_from_file(const char* filename)
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

eros_source_t* eros_source_from_string(const char* str)
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
    source->data = NULL;
  }

  free(source);
  source = NULL;
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
  if (from >= source->size || to > source->size) {
    return NULL;
  }

  return eros_strcpy(source->data, from, to);
}

/*
Copyright (c) 2014-2017 Lucas Gabriel Sánchez

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
