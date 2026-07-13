#include "serial_wrapper/serial_wrapper.h"

#include <iostream>
#include <string>

SerialWrapper::SerialWrapper(std::string port, int speed)
: my_serial(std::move(port), speed, serial_cpp::Timeout::simpleTimeout(1000)) {
    if (!isOpen()) {
        return;
    }

    serialConfiguration();
}

void SerialWrapper::serialConfiguration() {
    my_serial.setTimeout(serial_cpp::Timeout::max(), 250, 0, 250, 0);
}

int SerialWrapper::readSerial() {
    if (!isOpen()) {
        return -1;
    }

    constexpr size_t kBufferSize = 256;
    std::string result = my_serial.read(kBufferSize);
    if (!result.empty()) {
        std::cout << result;
        return static_cast<int>(result.size());
    }

    return 0;
}

bool SerialWrapper::isOpen() {
    if (my_serial.isOpen()) {
        return true;
    } else {
        return false;
    }
}