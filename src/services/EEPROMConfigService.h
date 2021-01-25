#ifndef WIFI_DATA_LOGGER2_EEPROMCONFIGSERVICE_H
#define WIFI_DATA_LOGGER2_EEPROMCONFIGSERVICE_H

#include "config/DeviceConfig.h"
#include "console-logger/ConsoleLogger.h"
#include "../utils/EEPROMUtils.h"

class EEPROMConfigService {
private:
    int WIFI_SSID_ADDR;
    int TRANSMISSION_PERIOD_ADDR;
    int AUTO_GAIN_0_ADDR;
    int AUTO_GAIN_1_ADDR;
    int GAIN_0_ADDR;
    int GAIN_1_ADDR;
    int LOG_LEVEL_ADDR;
    int LOGGING_STATUS_ADDR;

    DeviceConfig &deviceConfig;
    ConsoleLogger &consoleLogger;
    EEPROMUtils eepromUtils;

public:
    EEPROMConfigService(DeviceConfig &deviceConfig, ConsoleLogger &consoleLogger);

    void loadConfigParams();

    void writeLoggingConfigTransmissionPeriod(uint16_t transmissionPeriod) const;

    void writeLoggingConfigAutoGain_0(bool autoGain) const;

    void writeLoggingConfigAutoGain_1(bool autoGain) const;

    void writeLoggingConfigGain_0(int gain) const;

    void writeLoggingConfigGain_1(int gain) const;

    void writeLogLevel(int logLevel) const;

    void writeLoggingStatus(int loggingStatus) const;

private:
    void initAddresses();
};


#endif //WIFI_DATA_LOGGER2_EEPROMCONFIGSERVICE_H
