// make linker happy during pio unit testing

#include "Arduino.h"
#include "DeviceScreen.h"
#include "Log.h"

#ifdef USE_ILOG
#include "ILog.h"

ILog *ILog::_logger = nullptr;
#endif

Log *testLog = new Log;

const char *firmware_version = "2.3.3";

DeviceScreen *screen = nullptr;

#if defined(ARCH_PORTDUINO)
void tft_task_handler(void *)
{
    // linker-error in test build    screen->task_handler();
    delay(5);
}
#endif