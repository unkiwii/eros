#include "eros_defines.h"
#include "eros_lexer.h"
#include "eros_mem.h"
#include "eros_token.h"

#include <stdlib.h>
#include <stdio.h>

BOOL eros_lexer_is_letter(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

BOOL eros_lexer_is_digit(char ch)
{
  return ch >= '0' && ch <= '9';
}

void eros_lexer_read_char(eros_lexer_t* lexer)
{
  if (lexer->end_position >= lexer->source->size) {
    lexer->current_char = 0;
  } else {
    lexer->current_char = eros_source_read(lexer->source, lexer->end_position);
  }

  lexer->current_position = lexer->end_position;
  lexer->end_position++;
}

void eros_lexer_unread_char(eros_lexer_t* lexer)
{
  if (lexer->current_position <= 0) {
    lexer->current_char = 0;
  } else {
    lexer->current_position--;
    lexer->end_position--;
    lexer->current_char = eros_source_read(lexer->source, lexer->end_position);
  }
}

void eros_lexer_skip_line(eros_lexer_t* lexer)
{
  do {
    eros_lexer_read_char(lexer);
  } while (lexer->current_char != 0 && lexer->current_char != '\n');
}

char eros_lexer_peek_char(eros_lexer_t* lexer)
{
  if (lexer->end_position >= lexer->source->size) {
    return 0;
  }

  return eros_source_read(lexer->source, lexer->end_position);
}

char* eros_lexer_read_string(eros_lexer_t* lexer)
{
  //TODO: recognize escaped characters

  int start_position = lexer->current_position;
  do {
    eros_lexer_read_char(lexer);
  } while (lexer->current_char != '"' && lexer->current_char != 0);

  int end_position = lexer->current_position - 1;

  /* check for empty string */
  if (start_position == end_position) {
    return "";
  }

  return eros_source_read_interval(lexer->source, start_position, lexer->current_position);
}

char* eros_lexer_read_identifier(eros_lexer_t* lexer)
{
  int start_position = lexer->current_position;
  do {
    eros_lexer_read_char(lexer);
  } while (eros_lexer_is_letter(lexer->current_char));

  char* interval = eros_source_read_interval(lexer->source, start_position, lexer->current_position);

  /* unread char (we read one past the end of the identifier) */
  eros_lexer_unread_char(lexer);

  return interval;
}

char* eros_lexer_read_number(eros_lexer_t* lexer)
{
  int start_position = lexer->current_position;
  while (eros_lexer_is_digit(lexer->current_char)) {
    eros_lexer_read_char(lexer);
  }

  char* interval = eros_source_read_interval(lexer->source, start_position, lexer->current_position);

  /* unread char (we read one past the end of the number) */
  eros_lexer_unread_char(lexer);

  return interval;
}

eros_token_t* eros_lexer_next_token(eros_lexer_t* lexer)
{
  eros_token_t* token = NULL;
  eros_lexer_read_char(lexer);

  /* printf("    current_char = '%c'\n", lexer->current_char); */

  switch (lexer->current_char) {

    case 0:
      token = eros_token_simple(EROS_TK_EOF);
      break;

    case ' ':
      token = eros_token_simple(EROS_TK_SPACE);
      break;

    case '=':
      token = eros_token_simple(EROS_TK_EQUAL);
      break;

    case '.':
      token = eros_token_simple(EROS_TK_DOT);
      break;

    case ',':
      token = eros_token_simple(EROS_TK_COMMA);
      break;

    case '[':
      token = eros_token_simple(EROS_TK_LBRACKET);
      break;

    case ']':
      token = eros_token_simple(EROS_TK_RBRACKET);
      break;

    case '(':
      token = eros_token_simple(EROS_TK_LPAREN);
      break;

    case ')':
      token = eros_token_simple(EROS_TK_RPAREN);
      break;

    case '{':
      token = eros_token_simple(EROS_TK_LBRACE);
      break;

    case '}':
      token = eros_token_simple(EROS_TK_RBRACE);
      break;

    case '#':
      eros_lexer_skip_line(lexer);
      token = eros_lexer_next_token(lexer);
      break;

    case ':':
      if (eros_lexer_peek_char(lexer) == '=') {
        eros_lexer_read_char(lexer);  /* consume the '=' char */
        token = eros_token_simple(EROS_TK_SET);
      } else {
        token = eros_token_illegal(lexer->current_char);
      }
      break;

    case '\"':
      eros_lexer_read_char(lexer);  /* skip the '"' char */
      char* str = eros_lexer_read_string(lexer);
      token = eros_token_new(EROS_TK_STRING, str);
      if (str && *str) {
        free(str);
      }
      break;

    /** number or identifier **/
    default:
      if (eros_lexer_is_letter(lexer->current_char)) {
        char* identifier = eros_lexer_read_identifier(lexer);
        token = eros_token_new(EROS_TK_IDENTIFIER, identifier);
        free(identifier);
      } else if (eros_lexer_is_digit(lexer->current_char)) {
        char* number = eros_lexer_read_number(lexer);
        token = eros_token_new(EROS_TK_NUMBER, number);
        free(number);
      } else {
        token = eros_token_illegal(lexer->current_char);
      }
      break;
  }

  /* printf("    \\__ token = %s '%s'\n", token->type->name, token->value); */

  if (lexer->current_token) {
    eros_token_delete(lexer->current_token);
  }
  lexer->current_token = token;

  return token;
}

eros_token_t* eros_lexer_peek_token(eros_lexer_t* lexer)
{
  return lexer->current_token;
}

eros_lexer_t* eros_lexer_new(eros_source_t* source)
{
  eros_lexer_t* lexer = (eros_lexer_t*) malloc(sizeof(eros_lexer_t));

  lexer->source = source;
  lexer->current_position = 0;
  lexer->end_position = 0;
  lexer->current_char = 0;
  lexer->current_token = NULL;

  return lexer;
}

void eros_lexer_delete(eros_lexer_t* lexer)
{
  if (!lexer) {
    return;
  }

  if (lexer->current_token) {
    eros_token_delete(lexer->current_token);
    lexer->current_token = NULL;
  }

  /* we do not create the source, then we don't have to free it */
  lexer->source = NULL;

  free(lexer);
  lexer = NULL;
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
