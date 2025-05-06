#include "LCD.h"

namespace MyPhone{

// Constructor
LCD::LCD(int CS_PIN, int DC_PIN, int RST_PIN, short ScreenWidth, short ScreenHeight) : Screen(), ScreenWidth(ScreenWidth), ScreenHeight(ScreenHeight){

    Screen.init();
    Screen.setRotation(3);
    Screen.fillScreen(TFT_BLACK);
}

// Destructor
LCD::~LCD() {
    // Cleanup code
}

// Public Method
void LCD::DisplayText(const std::string& Text, const uint8_t& TextSize, const short& X_Pos, const short& Y_Pos){
    Screen.fillScreen(TFT_BLACK);
    Screen.setTextColor(TFT_WHITE);
    Screen.setTextSize(TextSize);
    Screen.setCursor(X_Pos, Y_Pos);
    Screen.println(Text.c_str());
}

// Private Method

}