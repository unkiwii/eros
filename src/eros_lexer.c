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
#include "eros_lexer.h"
#include "eros_mem.h"
#include "eros_token.h"

#include <stdlib.h>
#include <stdio.h>

char eros_lexer_is_letter(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char eros_lexer_is_digit(char ch)
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

char eros_lexer_peek_char(eros_lexer_t* lexer)
{
  if (lexer->end_position >= lexer->source->size) {
    return 0;
  }

  return eros_source_read(lexer->source, lexer->end_position);
}

char* eros_lexer_read_string(eros_lexer_t* lexer)
{
  //TODO
  return NULL;
}

char* eros_lexer_read_identifier(eros_lexer_t* lexer)
{
  int start_position = lexer->current_position;
  while (eros_lexer_is_letter(lexer->current_char)) {
    eros_lexer_read_char(lexer);
  }

  char* interval = eros_source_read_interval(lexer->source, start_position, lexer->current_position);
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
  eros_lexer_unread_char(lexer);
  return interval;
}

eros_token_t* eros_lexer_next_token(eros_lexer_t* lexer)
{
  eros_token_t* token;
  eros_lexer_read_char(lexer);

  switch (lexer->current_char) {

    case 0:
      token = eros_token_simple(EROS_TK_EOF);
      break;

    case ' ':
      token = eros_token_simple(EROS_TK_SPACE);
      break;

    case '#':
      token = eros_token_simple(EROS_TK_NUMERAL);
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

    case ':':
      if (eros_lexer_peek_char(lexer) == '=') {
        token = eros_token_simple(EROS_TK_SET);
      } else {
        token = eros_token_illegal(lexer->current_char);
      }
      break;

    case '\'':
      token = eros_token_new(EROS_TK_STRING, eros_lexer_read_string(lexer));
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

  return token;
}

eros_lexer_t* eros_lexer_new(eros_source_t* source)
{
  eros_lexer_t* lexer = (eros_lexer_t*) malloc(sizeof(eros_lexer_t));

  lexer->source = source;
  lexer->current_position = 0;
  lexer->end_position = 0;
  lexer->current_char = 0;

  return lexer;
}

void eros_lexer_delete(eros_lexer_t* lexer)
{
  if (!lexer) {
    return;
  }

  if (lexer->source) {
    eros_source_delete(lexer->source);
    lexer->source = NULL;
  }

  free(lexer);
}
