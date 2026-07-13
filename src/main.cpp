#include <unistd.h>

#include <memory>
#include <string>

#include "serial_wrapper/serial_wrapper.h"

constexpr const char* SERIAL_PORT_1 = "/dev/ttyACM0";

int main() {
    std::unique_ptr<SerialWrapper> m_serial = std::make_unique<SerialWrapper>(SERIAL_PORT_1, 15200);

    while (true) {
        m_serial->readSerial();
    }

    return EXIT_SUCCESS;
}