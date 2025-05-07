#include <Modem.h>

namespace MyPhone{
    
    Modem::Modem(int RX_PIN, int TX_PIN, int MODEM_BAUD, int UART_NO) : SerialAT(UART_NO), Module(SerialAT){
    }

    Modem::~Modem(){};

    bool Modem::Begin(bool restart) {
        SerialAT.begin(115200, SERIAL_8N1, 16, 17);
        delay(3000);
    
        if (restart) {
            if (!Module.restart()) {
                return false;
            }
            delay(8000);
        }
    
        return true;
    }

    bool Modem::CheckStatus() {
        Module.sendAT("AT");
        return Module.waitResponse(2000L) == 1;
    }

    String Modem::CheckSignal() {
        String csqResponse;
        Module.sendAT("+CSQ");
        if (Module.waitResponse(2000L, "+CSQ:") == 1) {
            csqResponse = SerialAT.readStringUntil('\n');
        } else {
            csqResponse = "No Response";
        }
        return csqResponse;
    }
}