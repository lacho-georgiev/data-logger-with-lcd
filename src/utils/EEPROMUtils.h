#ifndef WIFI_DATA_LOGGER2_EEPROMUTILS_H
#define WIFI_DATA_LOGGER2_EEPROMUTILS_H

#include <Arduino.h>

class EEPROMUtils {
public:
    void writeString(int add, String data) const;
    String readString(int add) const;
};

#endif //WIFI_DATA_LOGGER2_EEPROMUTILS_H
