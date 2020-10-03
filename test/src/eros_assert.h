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

#ifndef EROS_ASSERT_H
#define EROS_ASSERT_H

#include "eros_defines.h"

bool eros_assert_null(const char* name, void* ptr);
bool eros_assert_not_null(const char* name, void* ptr);
bool eros_assert_eq_length(const char* name, int actual, int expected);
bool eros_assert_eq_char_arr(const char* name, int size, char** actual, char** expected);
bool eros_assert_eq_char_ptr(const char* name, char* actual, char* expected);

#endif // EROS_ASSERT_H
