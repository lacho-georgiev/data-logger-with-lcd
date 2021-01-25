#ifndef WIFI_DATA_LOGGER2_LOGGINGRECORD_H
#define WIFI_DATA_LOGGER2_LOGGINGRECORD_H

#include <Arduino.h>

struct LoggingRecord {
    float temperature = 0;
    float voltage1 = 0;
    float voltage2 = 0;

public:
    String toString() const {
        return String(temperature) + "," + String(voltage1, 6) + "," + String(voltage2, 6);
    }
};


#endif //WIFI_DATA_LOGGER2_LOGGINGRECORD_H
