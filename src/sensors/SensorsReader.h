#ifndef WIFI_DATA_LOGGER2_SENSORSREADER_H
#define WIFI_DATA_LOGGER2_SENSORSREADER_H

#include <DallasTemperature.h>
#include <OneWire.h>
#include "logging-record/LoggingRecord.h"
#include "ADS1115AutoRangedReader.h"

class SensorsReader {
private:
    LoggingConfig &loggingConfig;
    const ConsoleLogger &consoleLogger;
    ADS1115AutoRangedReader ads;
    OneWire oneWire;
    DallasTemperature sensors;

public:
    SensorsReader(LoggingConfig &loggingConfig, const ConsoleLogger &consoleLogger);

    LoggingRecord readSensorsValue();
    void begin();

};


#endif //WIFI_DATA_LOGGER2_SENSORSREADER_H
