#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <serial_cpp/serial.h>

#include <string>

class SerialWrapper {
    public:
    explicit SerialWrapper(std::string port, int speed);
    ~SerialWrapper() = default;
    serial_cpp::Serial my_serial;

    int readSerial();

    private:
    void serialConfiguration();
    bool isOpen();
};

#endif