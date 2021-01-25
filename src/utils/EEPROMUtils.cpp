#include "EEPROMUtils.h"

#include <EEPROM.h>

void EEPROMUtils::writeString(int add, String data) const {
    int _size = data.length();
    int i;
    for (i = 0; i < _size; i++) {
        EEPROM.write(add + i, data[i]);
    }
    EEPROM.write(add + _size, '\0');   //Add termination null character for String Data
}

String EEPROMUtils::readString(int add) const {
    char data[100]; //Max 100 Bytes
    int len = 0;
    unsigned char k;
    k = EEPROM.read(add);
    while (k != '\0' && len < 500)   //Read until null character
    {
        k = EEPROM.read(add + len);
        data[len] = k;
        len++;
    }
    data[len] = '\0';
    return String(data);
}
