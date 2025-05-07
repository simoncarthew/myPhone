#ifndef MODEM_H
#define MODEM_H

#define TINY_GSM_MODEM_A7672X

#include <TinyGsmClient.h>
#include <Arduino.h>
#include <string>

namespace MyPhone{

class Modem{
    public:

    // Constructor and Destructor
    Modem(int RX_PIN = 16, int TX_PIN = 17, int MODEM_BAUD = 115200, int UART_NO = 2);
    ~Modem();

    // Public Methods
    bool Begin(bool restart = false);
    String CheckSignal(); 
    bool CheckStatus();

    // Public Variables
    TinyGsm Module;

    private:
    HardwareSerial SerialAT;
};

}

#endif