#include <Arduino.h>
#include <Modem.h>

MyPhone::Modem modem = MyPhone::Modem();
const int buttonPin = 14;
int buttonState;

void setup() {
  Serial.begin(921600);
  while (!Serial);
  pinMode(buttonPin, INPUT_PULLUP);

  if (!modem.Begin(true)) {
    Serial.println("Modem failed to initialize.");
  }
}

void loop() {
  // Send AT
  // bool status = modem.CheckStatus();
  // if (status) {
  //   Serial.println("Modem responded to AT command.");
  // } else {
  //   Serial.println("No response to AT command.");
  // }

  // Send +CSQ
  // Serial.println("Signal Strength: " + modem.CheckSignal());
  modem.Module.testAT();

  // Take Button input
  // int buttonState = HIGH;
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {  // LOW means pressed (due to pull-up)
    Serial.println("Button Pressed!");
    // modem.Module.sendSMS("+27614263946","Hi from phone");
    modem.Module.callNumber("+27833852911");
  }
  

  delay(100);  // Wait before next query
}
