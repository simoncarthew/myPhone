#include <Arduino.h>
#include <LCD.h>
#include <ScrollAbleList.h>
#include <vector>
#include <string>

// Pin definitions
#define TFT_CS     5
#define TFT_DC     26
#define TFT_RST    27

// MyPhone::LCD lcd(TFT_CS, TFT_DC, TFT_RST);
// MyPhone::ScrollAbleList* MusicMenu;


TFT_eSPI tft = TFT_eSPI();  // Invoke TFT
TFT_eSprite sprite = TFT_eSprite(&tft);  // Sprite tied to main screen

void setup() {
    Serial.begin(921600);
    // TFT_eSPI tft = TFT_eSPI();  // Invoke TFT
    // TFT_eSprite sprite = TFT_eSprite(&tft);  // Sprite tied to main screen

    std::vector<std::string> songs = {"BEAT IT", "POKER FACE", "PAYPHONE", "MARGARINE", "TOOTHPASTE", "CRYING", "FOUND IT", "POKER LEG", "PAY WALLET"};
    std::vector<std::string> artists = {"MJ", "Gaga", "Maroon 5", "MJ", "Gaga", "Maroon 5", "MJ", "Gaga", "Maroon 5"};

    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);

    sprite.setColorDepth(8);
    sprite.createSprite(240, 320);  // Match screen size or smaller
    sprite.fillSprite(TFT_BLACK);
    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(2);
    sprite.setCursor(10, 10);
    sprite.println("Sprite test");

    sprite.pushSprite(0, 0);  // Draw sprite to screen at top-left

    // MusicMenu = new MyPhone::ScrollAbleList(lcd, songs, artists);
    // MusicMenu->Display();
    // delay(1000);

    // MusicMenu->Scroll(true);
    // MusicMenu->Display();
    // delay(1000);
    // MusicMenu->Scroll(true);
    // MusicMenu->Display();
    // delay(1000);
    // MusicMenu->Scroll(true);
    // MusicMenu->Display();
    // delay(1000);
    // MusicMenu->Scroll(true);
    // MusicMenu->Display();
    // delay(1000);
    // MusicMenu->Scroll(true);
    // MusicMenu->Display();
    // delay(1000);
    

    // tft.init();               // Initialize the TFT display
    // tft.setRotation(3);       // Set the rotation (0-3) to match your display's orientation
    // tft.fillScreen(TFT_BLACK); // Fill screen with black
    // tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Set text color to white with black background
    // tft.setTextSize(2);       // Set text size
    // tft.setCursor(0, 120);    // Set the starting position of the text
}

void loop() {
    // tft.setCursor(0, 120);
    // tft.fillScreen(TFT_BLACK);
    // tft.println("I Like CHeese!");
    // delay(1000);
    // tft.setCursor(0, 120);
    // tft.fillScreen(TFT_BLACK);
    // tft.println("Not Like me you dont.");
    delay(1000);
}
