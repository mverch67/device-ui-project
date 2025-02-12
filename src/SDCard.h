#pragma once

#include "Arduino.h"

#ifndef ARCH_PORTDUINO
#include "SD.h"
extern void setupSDCard();
#else
void setupSDCard() {}
#endif

#ifndef HAS_SDCARD
#define HAS_SDCARD 0
#endif
