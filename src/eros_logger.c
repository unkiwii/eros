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

#ifdef DEBUG
int eros_log_level = EROS_LOG_LEVEL_DEBUG;
#else
int eros_log_level = EROS_LOG_LEVEL_WARN;
#endif

char eros_log_message[512];
int eros_log_message_size = 0;

void eros_log_print(int level, const char* tag, const char* fmt, va_list args)
{
  if (level < eros_log_level) {
    return;
  }

  if (eros_log_message_size == 0) {
    eros_log_message_size = sizeof(eros_log_message) * sizeof(char);
  }

  int start = sprintf(eros_log_message, "[%s] ", tag);
  vsnprintf(eros_log_message + start, eros_log_message_size - start, fmt, args);

  puts(eros_log_message);
}

void eros_log_init(int level)
{
  eros_log_level = level;
  //TODO: use file as output
}

void eros_log_debug(const char* tag, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log_print(EROS_LOG_LEVEL_DEBUG, tag, fmt, args);
  va_end(args);
}

void eros_log_info(const char* tag, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log_print(EROS_LOG_LEVEL_INFO, tag, fmt, args);
  va_end(args);
}

void eros_log_warn(const char* tag, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log_print(EROS_LOG_LEVEL_WARN, tag, fmt, args);
  va_end(args);
}

void eros_log_error(const char* tag, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  eros_log_print(EROS_LOG_LEVEL_ERROR, tag, fmt, args);
  va_end(args);
}
