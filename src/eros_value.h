#ifndef EROS_VALUE_H
#define EROS_VALUE_H

#include "eros_defines.h"

/** types of values in the language **/
enum {
  EROS_VALUE_MODULE,
  EROS_VALUE_ERROR
};

char* eros_value_name(int type);

struct eros_value_t
{
  /* type of the value (number, string, type, etc) */
  int type;

  //TODO: put all 'values' inside an union
  char* str;
};

void eros_value_delete(eros_value_t* value);

eros_value_t* eros_value_module(char* name);
eros_value_t* eros_value_error(char* data);

#endif // EROS_VALUE_H

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

