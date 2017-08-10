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

#ifndef EROS_SOURCE_H
#define EROS_SOURCE_H

#include "eros_defines.h"

struct eros_source_t
{
  /* file name from there this was loaded (NULL when loaded from string) */
  const char* filename;

  /* contents of the loaded file or string */
  char* data;

  /* size of loaded data, from file or string */
  source_size_t size;
};

eros_source_t* eros_source_from_file(const char* filename);
eros_source_t* eros_source_from_string(const char* str);

void eros_source_delete(eros_source_t* source);

char eros_source_read(eros_source_t* source, source_size_t at);
char* eros_source_read_interval(eros_source_t* source, source_size_t from, source_size_t to);

#endif // EROS_SOURCE_H
