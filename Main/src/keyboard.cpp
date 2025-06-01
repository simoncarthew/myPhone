#include <Arduino.h>

// Column pins (outputs)
const int colPins[2] = {A1, A2};

// Row pins (inputs with pull-ups)
const int rowPins[2] = {A3, A4};

// Key labels (optional for display)
const char* keyMap[2][2] = {
  {"K11", "K12"},
  {"K21", "K22"}
};

void setup() {
  // Set up column pins as outputs, initialize HIGH
  for (int i = 0; i < 2; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }

  // Set up row pins as inputs with pull-ups
  for (int i = 0; i < 2; i++) {
    pinMode(rowPins[i], INPUT_PULLUP);
  }

  Serial.begin(921600);
}

void loop() {
  // Scan each column
  for (int col = 0; col < 2; col++) {
    // Set current column LOW, others HIGH
    for (int i = 0; i < 2; i++) {
      digitalWrite(colPins[i], i == col ? LOW : HIGH);
    }

    // Check each row
    for (int row = 0; row < 2; row++) {
      if (digitalRead(rowPins[row]) == LOW) {
        // Button at (row, col) is pressed
        Serial.print("Key pressed: ");
        Serial.println(keyMap[row][col]);
        delay(300);  // debounce delay
      }
    }
  }

  delay(50); // Short delay to reduce scan noise
}


// void setup() {
//   Serial.begin(921600);
//   while (!Serial);

//   pinMode(A1, OUTPUT);
//   digitalWrite(A1, LOW);  

//   pinMode(A3, INPUT_PULLUP);
// }

// void loop() {
//   if (digitalRead(A3) == LOW) {
//     Serial.println("Button pressed between A1 and A3");
//   }

//   delay(50);
// }
