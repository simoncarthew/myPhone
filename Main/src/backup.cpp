

#include <Arduino.h>

#define SerialMon Serial
#define MODEM_RX         16
#define MODEM_TX         17
#define MODEM_BAUD       115200

#define TINY_GSM_MODEM_A7672X
#include <TinyGsmClient.h>

HardwareSerial SerialAT(2);  // UART2
TinyGsm modem(SerialAT);

void setup() {
  SerialMon.begin(921600);
  delay(10);

  SerialMon.println("Booting...");

  SerialAT.begin(MODEM_BAUD, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(3000);

  SerialMon.println("Initializing modem...");
  modem.restart();
  delay(8000);  // Give time for reboot

  // Check modem info
  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem Info: ");
  SerialMon.println(modemInfo);
}

void loop() {
  // Send AT
  modem.sendAT("AT");
  if (modem.waitResponse(1000L) == 1) {
    SerialMon.println("Modem responded to AT command.");
  } else {
    SerialMon.println("No response to AT command.");
  }

  // Send +CSQ
  modem.sendAT("+CSQ");
  if (modem.waitResponse(1000L, "+CSQ:") == 1) {
    // Read the full response string
    String csqResponse = SerialAT.readStringUntil('\n');
    SerialMon.print("Signal Quality: ");
    SerialMon.println(csqResponse);
  } else {
    SerialMon.println("Failed to get signal quality.");
  }

  delay(5000);  // Wait before next query
}
