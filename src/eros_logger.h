/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#ifndef EROS_LOGGER_H
#define EROS_LOGGER_H

#include <stdarg.h>

enum {
  EROS_LOG_LEVEL_DEBUG,
  EROS_LOG_LEVEL_INFO,
  EROS_LOG_LEVEL_WARN,
  EROS_LOG_LEVEL_ERROR
};

void eros_log_init(int level);

void eros_log_debug(const char* tag, const char* fmt, ...);
void eros_log_info(const char* tag, const char* fmt, ...);
void eros_log_warn(const char* tag, const char* fmt, ...);
void eros_log_error(const char* tag, const char* fmt, ...);

#endif // EROS_LOGGER_H
