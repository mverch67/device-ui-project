#include "Log.h"
#include "stdarg.h"
#include <stdio.h>

#if defined(ARCH_ESP32)
// simply forward all logs into the esp log forwarder
#define LOG_FWD(LVL, TAG, FMT, ARG) esp_log_writev(LVL, TAG, FMT, ARG)
#elif defined(PORTDUINO)
#define LOG_FWD(LVL, TAG, FMT, ARG) vprintf(FMT, ARG)
#define esp_log_level_set(...)
#endif

Log logger;

void Log::setDebugLevel(esp_log_level_t lvl)
{
    esp_log_level_set("*", lvl);
}

void Log::log_debug(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_DEBUG, "TFT", format, arg);
    va_end(arg);
}

void Log::log_info(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_INFO, "TFT", format, arg);
    va_end(arg);
}

void Log::log_warn(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_WARN, "TFT", format, arg);
    va_end(arg);
}

void Log::log_error(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_ERROR, "TFT", format, arg);
    va_end(arg);
}

void Log::log_crit(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_ERROR, "TFT", format, arg);
    va_end(arg);
}

void Log::log_trace(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    LOG_FWD(ESP_LOG_VERBOSE, "TFT", format, arg);
    va_end(arg);
}
