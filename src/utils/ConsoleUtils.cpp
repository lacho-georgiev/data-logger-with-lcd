#include "ConsoleUtils.h"

String ConsoleUtils::serialReadInputString() const {
    String s;

    while (true) {
        if (Serial.available()) {
            int inByte = Serial.read();
            if (inByte == '\n') break;
            s += (char) inByte;
        }
    }

    return s;
}
