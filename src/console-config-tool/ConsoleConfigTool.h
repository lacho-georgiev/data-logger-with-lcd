#ifndef WIFI_DATA_LOGGER2_CONSOLECONFIGTOOL_H
#define WIFI_DATA_LOGGER2_CONSOLECONFIGTOOL_H

#include <Arduino.h>
#include "utils/ConsoleUtils.h"
#include "services/EEPROMConfigService.h"

class ConsoleConfigTool {
private:
    EEPROMConfigService &eepromConfigService;
    DeviceConfig &deviceConfig;
    ConsoleLogger &consoleLogger;
    ConsoleUtils consoleUtils;

public:
    ConsoleConfigTool(EEPROMConfigService &eepromConfigService, DeviceConfig &deviceConfig, ConsoleLogger &consoleLogger);
    void printMenu(bool show_exit) const;
    void setConfigParams();

private:
    void configPeriod();
    void configAutoGain1();
    void configAutoGain2();
    void configGain1();
    void configGain2();
    void configLogLevel();
    void configLoggingStatus();

    static void printGainOptions();
};


#endif //WIFI_DATA_LOGGER2_CONSOLECONFIGTOOL_H
