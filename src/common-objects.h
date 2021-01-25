#ifndef WIFI_DATA_LOGGER2_COMMON_OBJECTS_H
#define WIFI_DATA_LOGGER2_COMMON_OBJECTS_H

#include <ESP8266WebServer.h>
#include "services/WiFiService.h"
#include "services/EEPROMConfigService.h"
#include "services/MeasurementRemoteService.h"
#include "config/LoggingConfig.h"
#include "config/RemoteServiceConfig.h"
#include "config/WiFiConfig.h"
#include "console-logger/ConsoleLogger.h"
#include "logging-record/LoggingRecord.h"

// This objects should be used only in scope where it is not possible to access them, like in global functions.
extern ConsoleLogger consoleLogger;
extern DeviceConfig deviceConfig;
extern EEPROMConfigService eepromConfigService;
extern long last_t;
extern LoggingRecord lastLoggingRecord;

#endif //WIFI_DATA_LOGGER2_COMMON_OBJECTS_H
