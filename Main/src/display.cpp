#include <Arduino.h>
#include <LCD.h>
#include <ScrollAbleList.h>
#include <vector>
#include <string>

// Pin definitions
#define TFT_CS     5
#define TFT_DC     26
#define TFT_RST    27

MyPhone::LCD lcd(TFT_CS, TFT_DC, TFT_RST);
MyPhone::ScrollAbleList* MusicMenu;

void setup() {
    Serial.begin(921600);

    std::vector<std::string> songs = {"BEAT IT", "POKER FACE", "PAYPHONE", "MARGARINE", "TOOTHPASTE", "CRYING", "FOUND IT", "POKER LEG", "PAY WALLET"};
    std::vector<std::string> artists = {"MJ", "Gaga", "Maroon 5", "MJ", "Gaga", "Maroon 5", "MJ", "Gaga", "Maroon 5"};

    MusicMenu = new MyPhone::ScrollAbleList(lcd, songs, artists);
    MusicMenu->Display();
    delay(1000);

    for (int i = 0; i <= 7; i++){
        MusicMenu->Scroll(true);
        MusicMenu->Display();
        Serial.println("Hi");
        delay(1000);
    }
}

void loop() {
    delay(1000);
}
