#include "DeviceScreen.h"
#include "Arduino.h"

DeviceScreen* screen = nullptr;


void setup() {
    Serial.begin(115200);
    delay(2000);

#ifdef KB_POWERON
    digitalWrite(KB_POWERON, HIGH);
    pinMode(KB_POWERON, OUTPUT);
    delay(200); // wait until keyboard mcu startup finished
#endif

  Serial.println("\n*** SquareLine Studio (LovyanGFX TFT) ***");
#ifdef ARDUINO_ARCH_ESP32
  uint64_t chipid;
  chipid = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.printf("  ESP32 Chip ID = %04X", (uint16_t)(chipid >> 32)); //print High 2 bytes
  Serial.printf("%08X\n\r", (uint32_t)chipid); //print Low 4bytes.
  Serial.printf("  Flash size: %8d bytes\n\r", ESP.getFlashChipSize());
  Serial.printf("  Heap size : %8d bytes\n\r", ESP.getHeapSize());
  Serial.printf("  Free heap : %8d bytes\n\r", ESP.getFreeHeap());
  Serial.printf("  PSRAM     : %8d bytes\n\r", ESP.getFreePsram());
  Serial.println("*****************************************\n");
#endif

  screen = &DeviceScreen::create();
  screen->init(nullptr);

#ifdef ARDUINO_ARCH_ESP32
  Serial.printf("Free heap : %8d bytes\n\r", ESP.getFreeHeap());
  Serial.printf("PSRAM     : %8d bytes\n\r", ESP.getFreePsram());
#endif

  Serial.println("Setup done.");
}


/*** main loop ***/
void loop() {
    screen->task_handler();
    delay(20);
}
