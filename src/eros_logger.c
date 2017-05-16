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
