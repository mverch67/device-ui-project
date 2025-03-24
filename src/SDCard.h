#pragma once

#include "Arduino.h"

#ifndef ARCH_PORTDUINO
extern void setupSDCard();
#else
void setupSDCard() {}
#endif
