#include <Arduino.h>
#include <cstring>

void setup() {
  Serial.begin(921600);
  
  // UART1 GPIO21 (RX) and GPIO19 (TX)
  Serial1.begin(9600, SERIAL_8N1, 21, 19);
}

void loop() {
    static bool receiving = false;
    static char key[4] = "";
    static uint8_t idx = 0;

    while (Serial1.available()) {
        char c = Serial1.read();

        if (c == '[') {
            // Receiving has started
            receiving = true;
            idx = 0;
            key[0] = '\0';
        } 
        else if (c == ']' && receiving) {
            // Receiving has ended
            key[idx] = '\0';
            Serial.print("Received key: ");
            Serial.println(key);
        } 
        else if (receiving) {
            // New Character
            if (idx < 3) {
                key[idx++] = c;
            }
        }
    }
}