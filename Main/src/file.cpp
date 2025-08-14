#include <Arduino.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"


// Pin definitions
#define SD_CS     25
#define SD_MOSI    23
#define SD_MISO    19
#define SD_SCK     18

// CS (Chip Select), MOSI, MISO, SCK

void setup() {
    // Initialize SPI bus with your wiring
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI,SD_CS);
    
    Serial.begin(921600);
}

void loop() {
    if(!SD.begin(SD_CS, SPI)){
        Serial.println("Card Mount Failed");
    }else{
        Serial.println("Mounted");
    }

    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
    }

    Serial.print("SD Card Type: ");
    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);

    delay(1000);
}
