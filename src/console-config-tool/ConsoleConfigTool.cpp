#include <utils/EEPROMUtils.h>
#include <EEPROM.h>
#include "ConsoleConfigTool.h"

ConsoleConfigTool::ConsoleConfigTool(EEPROMConfigService &eepromConfigService,
                                     DeviceConfig &deviceConfig,
                                     ConsoleLogger &consoleLogger) : eepromConfigService(
        eepromConfigService), deviceConfig(deviceConfig), consoleLogger(consoleLogger) {}

void ConsoleConfigTool::printMenu(bool show_exit) const {
    Serial.print("7. Transmition period: ");
    Serial.println(deviceConfig.loggingConfig.transmissionPeriod);
    Serial.print("8. ADC auto GAINS channel 1: ");
    Serial.println(deviceConfig.loggingConfig.autoGain[0]);
    if (deviceConfig.loggingConfig.autoGain[0] == false) Serial.println("9. ADC GAINS channel 1 - DISABLED");
    else {
        Serial.print("9. ADC GAINS channel 1: ");
        Serial.println(deviceConfig.loggingConfig.gIndx[0]);
    }
    Serial.print("10. ADC auto GAINS channel 2: ");
    Serial.println(deviceConfig.loggingConfig.autoGain[1]);
    if (deviceConfig.loggingConfig.autoGain[1] == false) Serial.println("11. ADC GAINS channel 2 - DISABLED");
    else {
        Serial.print("11. ADC GAINS channel 2: ");
        Serial.println(deviceConfig.loggingConfig.gIndx[1]);
    }
    Serial.print("12. Log level: ");
    Serial.println(consoleLogger.getLogLevel());
    Serial.print("13. Data logging status: ");
    Serial.println(deviceConfig.loggingConfig.isEnabled() ? "enabled" : "disabled");
    if (show_exit) Serial.print("14. Exit");
    Serial.println();
    Serial.println();
}

void ConsoleConfigTool::configPeriod() {
    Serial.print("Enter transmission period: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.transmissionPeriod = str.toInt();
    eepromConfigService.writeLoggingConfigTransmissionPeriod(deviceConfig.loggingConfig.transmissionPeriod);
    Serial.print("New Transmission period = ");
    Serial.println(deviceConfig.loggingConfig.transmissionPeriod);
}

void ConsoleConfigTool::configAutoGain1() {
    Serial.print("Enter auto GAINS channel 1: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.autoGain[0] = str.toInt();
    eepromConfigService.writeLoggingConfigAutoGain_0(deviceConfig.loggingConfig.autoGain[0]);
    Serial.print("New Auto GAINS channel 1 = ");
    Serial.println(deviceConfig.loggingConfig.autoGain[0]);
}

void ConsoleConfigTool::configAutoGain2() {
    Serial.print("Enter auto GAINS channel 2: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.autoGain[1] = str.toInt();
    eepromConfigService.writeLoggingConfigAutoGain_1(deviceConfig.loggingConfig.autoGain[1]);
    Serial.print("New Auto GAINS channel 2 = ");
    Serial.println(deviceConfig.loggingConfig.autoGain[1]);
}

void ConsoleConfigTool::configGain1() {
    printGainOptions();
    Serial.print("Enter GAINS channel 1: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.gIndx[0] = str.toInt();
    eepromConfigService.writeLoggingConfigGain_0(deviceConfig.loggingConfig.gIndx[0]);
    Serial.print("New Gain channel 1 = ");
    Serial.println(deviceConfig.loggingConfig.gIndx[0]);
}

void ConsoleConfigTool::configGain2() {
    printGainOptions();
    Serial.print("Enter GAINS channel 2: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.gIndx[1] = str.toInt();
    eepromConfigService.writeLoggingConfigGain_1(deviceConfig.loggingConfig.gIndx[1]);
    Serial.print("New Gain channel 2 = ");
    Serial.println(deviceConfig.loggingConfig.gIndx[1]);
}

void ConsoleConfigTool::configLogLevel() {
    Serial.print("Enter log level: ");
    String str = consoleUtils.serialReadInputString();
    int log_level = str.toInt();
    consoleLogger.setLogLevel(log_level);
    eepromConfigService.writeLogLevel(consoleLogger.getLogLevel());
    Serial.print("New Log level = ");
    Serial.println(log_level);
}

void ConsoleConfigTool::configLoggingStatus() {
    Serial.print("Enter logging status: ");
    String str = consoleUtils.serialReadInputString();
    deviceConfig.loggingConfig.loggingStatus = str.toInt();
    eepromConfigService.writeLoggingStatus(deviceConfig.loggingConfig.loggingStatus);
    Serial.print("New Logging status = ");
    Serial.println(deviceConfig.loggingConfig.isEnabled() ? "enabled" : "disabled");
}

void ConsoleConfigTool::setConfigParams() {
    Serial.println("Setting config params");
    int i;
    do {
        Serial.println();
        printMenu(true);
        Serial.print("Enter your choice: ");
        String s = consoleUtils.serialReadInputString();
        i = s.toInt();
        Serial.println();
        switch (i) {
            case 7:
                configPeriod();
                break;
            case 8:
                configAutoGain1();
                break;
            case 9:
                configGain1();
                break;
            case 10:
                configAutoGain2();
                break;
            case 11:
                configGain2();
                break;
            case 12:
                configLogLevel();
                break;
            case 13:
                configLoggingStatus();
                break;
            default: Serial.println(String("Wrong choice: ") + i);
        }
        Serial.println();
    } while (i != 14);
}


void ConsoleConfigTool::printGainOptions() {
    Serial.println("1. Gain 2/3x, +/- 6.144V, 1 bit = 0.1875mV");
    Serial.println("2. Gain 1x, +/- 4.096V, 1 bit = 0.125mV");
    Serial.println("3. Gain 2x, +/- 2.048V, 1 bit = 0.0625mV");
    Serial.println("4. Gain 4x, +/- 1.024V, 1 bit = 0.03125mV");
    Serial.println("5. Gain 8x, +/- 0.512V, 1 bit = 0.015625mV");
    Serial.println("6. Gain 16x, +/- 0.256V, 1 bit = 0.0078125mV");
}