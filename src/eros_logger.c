/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#include "eros_logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#ifdef DEBUG
int eros_log_level = EROS_LOG_LEVEL_DEBUG;
#else
int eros_log_level = EROS_LOG_LEVEL_WARN;
#endif

char eros_log_message[512];
int eros_log_message_size = 0;

char* eros_log_filename = NULL;

void eros_log_print(const char* message)
{
  if (eros_log_filename) {
    FILE* f = fopen(eros_log_filename, "a+");
    fprintf(f, "%s\n", message);
    fclose(f);
  } else {
    printf("%s\n", message);
  }
}

void eros_log_print_time(const char* strtime, const char* message)
{
  if (eros_log_filename) {
    FILE* f = fopen(eros_log_filename, "a+");
    fprintf(f, "%s %s\n", strtime, message);
    fclose(f);
  } else {
    printf("%s %s\n", strtime, message);
  }
}

void eros_log(int level, const char* file, int line, const char* fmt, va_list args)
{
  if (level < eros_log_level) {
    return;
  }

  if (eros_log_message_size == 0) {
    eros_log_message_size = sizeof(eros_log_message) * sizeof(char);
  }

  vsnprintf(eros_log_message, eros_log_message_size, fmt, args);

  time_t timer;
  time(&timer);
  char* strtime = calloc(128, sizeof(char*));
  strftime(strtime, 128, "%a %b %d %H:%M:%S %Y", localtime(&timer));
  eros_log_print_time(strtime, eros_log_message);
  free(strtime);
}

void eros_log_init(int level, const char* filename)
{
  eros_log_level = level;

  size_t len = strlen(filename);
  eros_log_filename = (char*) calloc(len, sizeof(char*));
  strncpy(eros_log_filename, filename, len);
}

void eros_log_deinit()
{
  eros_log_print("");
  if (eros_log_filename) {
    free(eros_log_filename);
    eros_log_filename = NULL;
  }
}

void eros_log_debug(const char* file, int line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_DEBUG, file, line, fmt, args);
  va_end(args);
}

void eros_log_info(const char* file, int line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_INFO, file, line, fmt, args);
  va_end(args);
}

void eros_log_warn(const char* file, int line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_WARN, file, line, fmt, args);
  va_end(args);
}

void eros_log_error(const char* file, int line, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log(EROS_LOG_LEVEL_ERROR, file, line, fmt, args);
  va_end(args);
}
