#ifndef WIFI_DATA_LOGGER2_LOGGINGCONFIG_H
#define WIFI_DATA_LOGGER2_LOGGINGCONFIG_H

#include <Adafruit_ADS1015.h>

struct LoggingConfig {
    uint16_t transmissionPeriod = 10;
    int loggingStatus = 0;

    static const int GAINS_SIZE = 6;
    adsGain_t GAINS[GAINS_SIZE] = {GAIN_TWOTHIRDS, GAIN_ONE, GAIN_TWO, GAIN_FOUR, GAIN_EIGHT, GAIN_SIXTEEN};
    bool autoGain[2] = {true, true};
    int gIndx[2] = {GAINS_SIZE - 1, GAINS_SIZE - 1};
    int avgIterNum = 5;

public:
    bool isEnabled() const {
        return loggingStatus == LOGGING_ENABLED;
    }

    void enableLogging() {
        loggingStatus = LOGGING_ENABLED;
    }
    void disableLogging() {
        loggingStatus = LOGGING_DISABLED;
    }

private:
    int LOGGING_DISABLED = 0;
    int LOGGING_ENABLED = 1;
};


#endif //WIFI_DATA_LOGGER2_LOGGINGCONFIG_H
