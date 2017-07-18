/*
Copyright (c) 2016-2017 Lucas Gabriel Sánchez

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

#include "eros_defines.h"
#include "eros_logger.h"
#include "eros_mem.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef DEBUG
static log_level_t eros_log_level = EROS_LOG_LEVEL_DEBUG;
#else
static log_level_t eros_log_level = EROS_LOG_LEVEL_WARN;
#endif

static char eros_log_message[512];
static int eros_log_message_size = 0;

static char* eros_log_filename = NULL;
static flag_t eros_log_flag = 0;

void eros_log_print(const char* message)
{
  if (eros_log_filename) {
    FILE* f = fopen(eros_log_filename, "a+");
    fprintf(f, "%s\n", message);
    fclose(f);
  } else {
    fprintf(stderr, "%s\n", message);
  }
}

void eros_log_print_time(const char* strtime, const char* message)
{
  if (eros_log_filename) {
    FILE* f = fopen(eros_log_filename, "a+");
    fprintf(f, "%s %s\n", strtime, message);
    fclose(f);
  } else {
    fprintf(stderr, "%s %s\n", strtime, message);
  }
}

void eros_log(log_level_t level, const char* file, file_line_t line, const char* fmt, va_list args)
{
  if (level < eros_log_level || !eros_log_flag) {
    return;
  }

  if (eros_log_message_size == 0) {
    eros_log_message_size = sizeof(eros_log_message) * sizeof(char);
  }

  vsnprintf(eros_log_message, eros_log_message_size, fmt, args);

  time_t timer;
  time(&timer);
  char* strtime = (char*) calloc(128, sizeof(char*));
  strftime(strtime, 128, "%d/%m/%Y %H:%M:%S", localtime(&timer));
  eros_log_print_time(strtime, eros_log_message);
  free(strtime);
}

void eros_log_init(log_level_t level, const char* filename, flag_t log_flag)
{
  eros_log_flag = log_flag;
  eros_log_level = level;
  if (filename) {
    eros_log_filename = eros_strdup(filename);
  }
}

void eros_log_deinit()
{
  eros_log_print("");
  if (eros_log_filename) {
    free(eros_log_filename);
    eros_log_filename = NULL;
  }
}

void eros_log_debug(const char* file, file_line_t line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_DEBUG, file, line, fmt, args);
  va_end(args);
}

void eros_log_info(const char* file, file_line_t line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_INFO, file, line, fmt, args);
  va_end(args);
}

void eros_log_warn(const char* file, file_line_t line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_WARN, file, line, fmt, args);
  va_end(args);
}

void eros_log_error(const char* file, file_line_t line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_ERROR, file, line, fmt, args);
  va_end(args);
}
