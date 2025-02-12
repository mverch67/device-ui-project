#ifndef ARCH_PORTDUINO

#include "SDCard.h"
#include "Log.h"

#ifndef SD_SPI_FREQUENCY
#define SD_SPI_FREQUENCY 50000000U
#endif

void setupSDCard()
{
#if HAS_SDCARD
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if (!SD.begin(SDCARD_CS, SPI, SD_SPI_FREQUENCY)) {
        ILOG_DEBUG("No SD_MMC card detected");
        return;
    }
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        ILOG_DEBUG("No SD_MMC card attached");
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

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    ILOG_DEBUG("SD Card Size: %lu MB", (uint32_t)cardSize);
    ILOG_DEBUG("Total space: %lu MB", (uint32_t)(SD.totalBytes() / (1024 * 1024)));
    ILOG_DEBUG("Used space: %lu MB", (uint32_t)(SD.usedBytes() / (1024 * 1024)));
#endif
}

#endif