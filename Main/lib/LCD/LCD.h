#ifndef LCD_H
#define LCD_H

// Includes
// #include <Adafruit_GFX.h>
// #include <Adafruit_ST7789.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <string>
#include <utility>
#include <vector>

namespace MyPhone{

class LCD {
public:
    // Constructor and Destructor
    LCD(int CS_PIN, int DC_PIN, int RST_PIN, short ScreenWidth = 320, short ScreenHeight = 240);
    ~LCD();

    // Class Methods
    void DisplayText(const std::string& Text, const uint8_t& TextSize = 2, const short& X_Pos = 0, const short& Y_pos = 0);
    

    // Class Variables
    short ScreenWidth;
    short ScreenHeight;
    TFT_eSPI Screen;
};


}

#endif
