#include <EEPROM.h>
#include "EEPROMConfigService.h"

EEPROMConfigService::EEPROMConfigService(DeviceConfig &deviceConfig, ConsoleLogger &consoleLogger) : deviceConfig(deviceConfig), consoleLogger(consoleLogger) {
    initAddresses();
}

void EEPROMConfigService::loadConfigParams() {
    EEPROM.get(TRANSMISSION_PERIOD_ADDR, deviceConfig.loggingConfig.transmissionPeriod);
    EEPROM.get(AUTO_GAIN_0_ADDR, deviceConfig.loggingConfig.autoGain[0]);
    EEPROM.get(AUTO_GAIN_1_ADDR, deviceConfig.loggingConfig.autoGain[1]);
    EEPROM.get(GAIN_0_ADDR, deviceConfig.loggingConfig.gIndx[0]);
    EEPROM.get(GAIN_1_ADDR, deviceConfig.loggingConfig.gIndx[1]);
    int log_level;
    EEPROM.get(LOG_LEVEL_ADDR, log_level);
    consoleLogger.setLogLevel(log_level);
    EEPROM.get(LOGGING_STATUS_ADDR, deviceConfig.loggingConfig.loggingStatus);
}

void EEPROMConfigService::initAddresses() {
    int eeAddress = 0;

    TRANSMISSION_PERIOD_ADDR = eeAddress;
    eeAddress += sizeof(uint16_t);

    AUTO_GAIN_0_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

    AUTO_GAIN_1_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

    GAIN_0_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

    GAIN_1_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

    LOG_LEVEL_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

    LOGGING_STATUS_ADDR = eeAddress;
    eeAddress += sizeof(uint8_t);

}

void EEPROMConfigService::writeLoggingConfigTransmissionPeriod(uint16_t transmissionPeriod) const {
    EEPROM.put(TRANSMISSION_PERIOD_ADDR, transmissionPeriod);
}

void EEPROMConfigService::writeLoggingConfigAutoGain_0(bool autoGain) const {
    EEPROM.put(AUTO_GAIN_0_ADDR, autoGain);
}

void EEPROMConfigService::writeLoggingConfigAutoGain_1(bool autoGain) const {
    EEPROM.put(AUTO_GAIN_1_ADDR, autoGain);
}

void EEPROMConfigService::writeLoggingConfigGain_0(int gain) const {
    EEPROM.put(GAIN_0_ADDR, gain);
}

void EEPROMConfigService::writeLoggingConfigGain_1(int gain) const {
    EEPROM.put(GAIN_1_ADDR, gain);
}

void EEPROMConfigService::writeLogLevel(int logLevel) const {
    EEPROM.put(LOG_LEVEL_ADDR, logLevel);
}

void EEPROMConfigService::writeLoggingStatus(int loggingStatus) const {
    EEPROM.put(LOGGING_STATUS_ADDR, loggingStatus);
}
