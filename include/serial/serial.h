#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <SerialPort.h>
#include <iostream>

class Serial {
    public:
    Serial ();
    readSerial ();

    private:
    serialConfiguration ();
    void isAvailable ();
}

#endif