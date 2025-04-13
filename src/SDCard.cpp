#ifndef ARCH_PORTDUINO

#include "SDCard.h"
#include "Log.h"
#include "SPI.h"

#ifdef HAS_SD_MMC
#include "SD_MMC.h"
fs::SDMMCFS &sd = SD_MMC;
static SPIClass &SDHandler = SPI;
#else
#include "SD.h"
#ifdef SDCARD_USE_SPI1
SPIClass SPI1(HSPI);
static SPIClass &SDHandler = SPI1;
#else
static SPIClass &SDHandler = SPI;
#endif

fs::SDFS &sd = SD;
#endif

#ifndef SD_SPI_FREQUENCY
#define SD_SPI_FREQUENCY 50000000U
#endif

void setupSDCard()
{
#ifdef HAS_SDCARD
#ifdef HAS_SD_MMC
    sd.setPins(SD_SCLK_PIN, SD_MOSI_PIN, SD_MISO_PIN);
    if (!sd.begin("/sdcard", true)) {
        ILOG_DEBUG("No SD_MMC card detected");
        return;
    }
#else
    SDHandler.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if (!sd.begin(SDCARD_CS, SDHandler, SD_SPI_FREQUENCY)) {
        ILOG_DEBUG("No SD card detected");
        return;
    }
#endif
    uint8_t cardType = sd.cardType();
    if (cardType == CARD_NONE) {
        ILOG_DEBUG("No SD card attached");
        return;
    }
    ILOG_DEBUG("SD_MMC Card Type: ");
    if (cardType == CARD_MMC) {
        ILOG_DEBUG("MMC");
    } else if (cardType == CARD_SD) {
        ILOG_DEBUG("SDSC");
    } else if (cardType == CARD_SDHC) {
        ILOG_DEBUG("SDHC");
    } else {
        ILOG_DEBUG("UNKNOWN");
    }

    uint64_t cardSize = sd.cardSize() / (1024 * 1024);
    ILOG_DEBUG("SD Card Size: %lu MB", (uint32_t)cardSize);
    ILOG_DEBUG("Total space: %lu MB", (uint32_t)(sd.totalBytes() / (1024 * 1024)));
    ILOG_DEBUG("Used space: %lu MB", (uint32_t)(sd.usedBytes() / (1024 * 1024)));
#endif
}

#endif