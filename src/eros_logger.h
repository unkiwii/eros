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

#ifndef EROS_LOGGER_H
#define EROS_LOGGER_H

#include "eros_defines.h"

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

void eros_log_init(log_level_t level, const char* filename, flag_t eros_log_flag);
void eros_log_deinit();

void eros_log_debug(const char* file, file_line_t line, const char* fmt, ...);
void eros_log_info(const char* file, file_line_t line, const char* fmt, ...);
void eros_log_warn(const char* file, file_line_t line, const char* fmt, ...);
void eros_log_error(const char* file, file_line_t line, const char* fmt, ...);

#endif // EROS_LOGGER_H
