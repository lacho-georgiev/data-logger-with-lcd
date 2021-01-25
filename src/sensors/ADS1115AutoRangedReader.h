#ifndef WIFI_DATA_LOGGER2_ADS1115AUTORANGEDREADER_H
#define WIFI_DATA_LOGGER2_ADS1115AUTORANGEDREADER_H

#include <Adafruit_ADS1015.h>
#include "console-logger/ConsoleLogger.h"
#include "config/LoggingConfig.h"

class ADS1115AutoRangedReader {
private:
    Adafruit_ADS1115 ads;
    LoggingConfig &loggingConfig;
    const ConsoleLogger &consoleLogger;

public:
    ADS1115AutoRangedReader(LoggingConfig &loggingConfig, const ConsoleLogger &consoleLogger);

    float readAdcAutoRangedValue(int ch);
    void begin();

private:
    float read_adc_value(int ch);
    static float convert_adc_value_to_voltage(float adc, int gain);
};

#endif //WIFI_DATA_LOGGER2_ADS1115AUTORANGEDREADER_H
