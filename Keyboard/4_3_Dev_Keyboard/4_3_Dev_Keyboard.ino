#include <SoftwareSerial.h>

// SERIAL OUTPUT
SoftwareSerial espSerial(10, 11);

// KEYBOARD SIZE
const int no_columns = 3;
const int no_rows = 4;

// PINS
const int colPins[no_columns] = {7, 6, 5};
const int rowPins[no_rows] = {A1, A2, A3, A4};

// Key labels (optional for display)
const char* keyMap[no_rows][no_columns] = {
  {"11", "12", "13"},
  {"21", "22", "23"},
  {"31", "32", "33"},
  {"41", "42", "43"}
};

void setup() {
  // INITIALIZE COLUMN PINS
  for (int i = 0; i < no_columns; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }

  // INITIALIZE ROW PINS
  for (int i = 0; i < no_rows; i++) {
    pinMode(rowPins[i], INPUT_PULLUP);
  }

  Serial.begin(921600);
  espSerial.begin(9600); 
}

void loop() {
  // SCAN COLUMNS
  for (int col = 0; col < no_columns; col++) {
    // SET OBSERVED COLUMN LOW
    for (int i = 0; i < no_columns; i++) {
      digitalWrite(colPins[i], i == col ? LOW : HIGH);
    }

    // SCAN ROWS
    for (int row = 0; row < no_rows; row++) {
      if (digitalRead(rowPins[row]) == LOW) {
        const char* key = keyMap[row][col];
        espSerial.print("[");
        espSerial.print(key);
        espSerial.print("]");
        delay(300);
      }
    }
  }

  delay(25);
}