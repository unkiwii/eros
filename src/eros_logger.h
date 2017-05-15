/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO. */

#ifndef EROS_LOGGER_H
#define EROS_LOGGER_H

#define LOGD(...) eros_log_debug(__FILE__, __LINE__, __VA_ARGS__);
#define LOGI(...) eros_log_info(__FILE__, __LINE__, __VA_ARGS__);
#define LOGW(...) eros_log_warn(__FILE__, __LINE__, __VA_ARGS__);
#define LOGE(...) eros_log_error(__FILE__, __LINE__, __VA_ARGS__);

enum {
  EROS_LOG_LEVEL_DEBUG,
  EROS_LOG_LEVEL_INFO,
  EROS_LOG_LEVEL_WARN,
  EROS_LOG_LEVEL_ERROR
};

void eros_log_init(int level, const char* filename, int eros_log_flag);
void eros_log_deinit();

void eros_log_debug(const char* file, int line, const char* fmt, ...);
void eros_log_info(const char* file, int line, const char* fmt, ...);
void eros_log_warn(const char* file, int line, const char* fmt, ...);
void eros_log_error(const char* file, int line, const char* fmt, ...);

#endif // EROS_LOGGER_H
