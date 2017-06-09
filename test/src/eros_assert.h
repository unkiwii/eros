/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_ASSERT_H
#define EROS_ASSERT_H

#include "eros_defines.h"

BOOL eros_assert_null(const char* name, void* ptr);
BOOL eros_assert_not_null(const char* name, void* ptr);
BOOL eros_assert_eq_length(const char* name, int actual, int expected);
BOOL eros_assert_eq_char_arr(const char* name, int size, char** actual, char** expected);
BOOL eros_assert_eq_char_ptr(const char* name, char* actual, char* expected);

#endif // EROS_ASSERT_H
