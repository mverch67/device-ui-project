#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

// static const uint8_t LED_BUILTIN = -1;

#define SD_SPI_FREQUENCY 75000000U

static const uint8_t RELAY_PIN = 40;

static const uint8_t SPI_MOSI = 47;
static const uint8_t SPI_SCK = 48;
static const uint8_t SPI_MISO = 41;
static const uint8_t SPI_CS = 42;
static const uint8_t SDCARD_CS = SPI_CS;

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t SDA = 19;
static const uint8_t SCL = 45;

static const uint8_t SS = 39;
static const uint8_t MOSI = 47;
static const uint8_t MISO = 41;
static const uint8_t SCK = 48;

static const uint8_t A0 = 1;
static const uint8_t A1 = 2;
static const uint8_t A2 = 3;
static const uint8_t A3 = 4;
static const uint8_t A4 = 5;
static const uint8_t A5 = 6;
static const uint8_t A6 = 7;
static const uint8_t A7 = 8;
static const uint8_t A8 = 9;
static const uint8_t A9 = 10;
static const uint8_t A10 = 11;
static const uint8_t A11 = 12;
static const uint8_t A12 = 13;
static const uint8_t A13 = 14;
static const uint8_t A14 = 15;
static const uint8_t A15 = 16;
static const uint8_t A16 = 17;
static const uint8_t A17 = 18;
static const uint8_t A18 = 19;
static const uint8_t A19 = 20;

static const uint8_t T1 = 1;
static const uint8_t T2 = 2;
static const uint8_t T3 = 3;
static const uint8_t T4 = 4;
static const uint8_t T5 = 5;
static const uint8_t T6 = 6;
static const uint8_t T7 = 7;
static const uint8_t T8 = 8;
static const uint8_t T9 = 9;
static const uint8_t T10 = 10;
static const uint8_t T11 = 11;
static const uint8_t T12 = 12;
static const uint8_t T13 = 13;
static const uint8_t T14 = 14;

#endif /* Pins_Arduino_h */