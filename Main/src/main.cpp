#include <Arduino.h>
#include <LCD.h>

// Pin definitions
#define TFT_CS     5
#define TFT_DC     26
#define TFT_RST    27

// Initialize Display
MyPhone::LCD Display = MyPhone::LCD(TFT_CS,TFT_DC,TFT_RST);

void setup() {
  Serial.begin(921600);

  Display.DisplayText("Hi from Main");
  
}

void loop() {
  // Nothing to do
}
