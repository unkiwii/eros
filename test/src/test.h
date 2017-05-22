/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef TEST_LEXER_H
#define TEST_LEXER_H

void eros_assert_eq_length(const char* name, int actual, int expected);
void eros_assert_eq_char_arr(const char* name, int size, char** actual, char** expected);
void eros_assert_eq_char_ptr(const char* name, char* actual, char* expected);

void fail(const char* format, ...);

void test_lexer();

#endif // TEST_LEXER_H
