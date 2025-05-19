#include "Log.h"
#include "stdarg.h"
#include <ctime>
#include <stdio.h>

#define CL_LIGHTRED "\033[01;31m" //!< Light red.
#define CL_RED "\033[22;31m"      //!< Red.
#define CL_YELLOW "\033[01;33m"   //!< Yellow.
#define CL_WHITE "\033[01;37m"    //!< White.
#define CL_GRAY "\033[22;37m"     //!< Gray.
#define NORMAL "\x1B[0m"          //!< Normal.

#if defined(ARCH_ESP32)
// simply forward all logs into the esp log forwarder
#define LOG_FWD(LVL, TAG, FMT, ARG) esp_log_writev(LVL, TAG, FMT, ARG)
#define LOG_CRLF(LVL, TAG) esp_log_write(LVL, TAG, "\n")
#define VA_START(LVL, ARG, FMT) va_start(ARG, FMT)
#elif defined(ARCH_PORTDUINO)
#define VA_START(LVL, ARG, FMT)                                                                                                  \
    printf("%s | %s %d ", LVL, getTime(), int(millis() / 1000));                                                                 \
    va_start(ARG, FMT)
#define LOG_FWD(LVL, TAG, FMT, ARG) vprintf(FMT, ARG)
#define LOG_CRLF(LVL, TAG) printf(NORMAL "\n")
#define esp_log_level_set(...)
#endif

extern "C" unsigned long millis(void);

static time_t rawtime;
struct tm *timeinfo;
char buffer[20];

Log logger;

char *getTime()
{
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%H:%M:%S ", timeinfo);
    return buffer;
}

void Log::setDebugLevel(esp_log_level_t lvl)
{
    esp_log_level_set("*", lvl);
}

void Log::log_debug(const char *format, ...)
{
    va_list arg;
    VA_START("DEBUG", arg, format);
    LOG_FWD(ESP_LOG_DEBUG, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_DEBUG, "TFT");
}

void Log::log_info(const char *format, ...)
{
    va_list arg;
    VA_START(CL_WHITE "INFO ", arg, format);
    LOG_FWD(ESP_LOG_INFO, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_INFO, "TFT");
}

void Log::log_warn(const char *format, ...)
{
    va_list arg;
    VA_START(CL_YELLOW "WARN ", arg, format);
    LOG_FWD(ESP_LOG_WARN, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_WARN, "TFT");
}

void Log::log_error(const char *format, ...)
{
    va_list arg;
    VA_START(CL_RED "ERROR", arg, format);
    LOG_FWD(ESP_LOG_ERROR, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_ERROR, "TFT");
}

void Log::log_crit(const char *format, ...)
{
    va_list arg;
    VA_START(CL_LIGHTRED "CRIT ", arg, format);
    LOG_FWD(ESP_LOG_ERROR, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_ERROR, "TFT");
}

void Log::log_trace(const char *format, ...)
{
    va_list arg;
    VA_START(CL_GRAY "TRACE", arg, format);
    LOG_FWD(ESP_LOG_VERBOSE, "TFT", format, arg);
    va_end(arg);
    LOG_CRLF(ESP_LOG_VERBOSE, "TFT");
}
