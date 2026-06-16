#include "serial/serial.h"

#include <cstdlib>
#include <iostream>
#include <libserial/SerialStream.h>
#include <unistd.h>

using namespace LibSerial;

Serial::Serial (const char* SERIAL_PORT_1) {
    SerialStream serial_stream;
    try {
        serial_stream.Open (SERIAL_PORT_1);
    } catch (const OpenFailed&) {
        std::cerr << "The serial port did not open correctly." << std::endl;
        return EXIT_FAILURE;
    }

    serialConfiguration ();
}

void Serial : serialConfiguration () {
    // Set the baud rate of the serial port.
    serial_stream.SetBaudRate (BaudRate::BAUD_115200);

    // Set the number of data bits.
    serial_stream.SetCharacterSize (CharacterSize::CHAR_SIZE_8);

    // Turn off hardware flow control.
    serial_stream.SetFlowControl (FlowControl::FLOW_CONTROL_NONE);

    // Disable parity.
    serial_stream.SetParity (Parity::PARITY_NONE);

    // Set the number of stop bits.
    serial_stream.SetStopBits (StopBits::STOP_BITS_1);
}

void Serial::isAvailable () {
    while (serial_stream.rdbuf ()->in_avail () == 0) {
        usleep (1000);
    }
}

int Serial::readSerial () {
    isAvailable ();
    while (serial_stream.IsDataAvailable ()) {
        char data_byte;

        serial_stream.get (data_byte);
        std::cout << data_byte;

        usleep (1000);
    }

    return EXIT_SUCCESS;
}