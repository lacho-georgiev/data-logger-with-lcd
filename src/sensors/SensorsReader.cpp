#include "SensorsReader.h"

#define ONE_WIRE_BUS_PIN 2

SensorsReader::SensorsReader(LoggingConfig &loggingConfig,
                             const ConsoleLogger &consoleLogger)
        : loggingConfig(loggingConfig),
          consoleLogger(consoleLogger),
          ads(loggingConfig, consoleLogger),
          oneWire(ONE_WIRE_BUS_PIN),
          sensors(&oneWire) {}

LoggingRecord SensorsReader::readSensorsValue() {
    LoggingRecord loggingRecord;
    sensors.requestTemperatures();

    loggingRecord.temperature = sensors.getTempCByIndex(0);

    loggingRecord.voltage1 = ads.readAdcAutoRangedValue(0);
    loggingRecord.voltage2 = ads.readAdcAutoRangedValue(1);

    return loggingRecord;
}

void SensorsReader::begin() {
    sensors.begin();
    ads.begin();
}
