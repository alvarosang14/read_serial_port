#include <cstdlib>
#include <memory>
#include <unistd.h>

#include "serial/serial.h"
constexpr const char* const SERIAL_PORT_1 = "/dev/ttyACM0";

int main () {
    std::unique_ptr<Serial> m_serial = Serial(SERIAL_PORT_1);
    
    while (1) {
        m_serial->readSerial();
    }
}