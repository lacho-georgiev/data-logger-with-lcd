#include <Arduino.h>
#include <RTClib.h>
#include <EEPROM.h>
#include <utils/DateTimeUtils.h>
#include "sensors/SensorsReader.h"
#include "services/EEPROMConfigService.h"
#include "console-config-tool/ConsoleConfigTool.h"
#include <LiquidCrystal_I2C.h>

#define CONFIG_BUTTON_PIN 15

DeviceConfig deviceConfig;
ConsoleLogger consoleLogger;
EEPROMConfigService eepromConfigService(deviceConfig, consoleLogger);
ConsoleConfigTool consoleConfigTool(eepromConfigService, deviceConfig, consoleLogger);

LoggingRecord lastLoggingRecord;
SensorsReader sensorsReader(deviceConfig.loggingConfig, consoleLogger);
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

long last_t;

void setup() {
    delay(1000);
    Serial.begin(115200);

    EEPROM.begin();
    eepromConfigService.loadConfigParams();

    pinMode(CONFIG_BUTTON_PIN, INPUT);

    Serial.println();
    for (int i = 2; i >= 0; i--) {
        Serial.print("Press and hold Config button to setup - ");
        Serial.print(i);
        Serial.println(" s");
        delay(1000);
        if (digitalRead(CONFIG_BUTTON_PIN)) {
            consoleConfigTool.setConfigParams();
            break;
        }
    }

    consoleConfigTool.printMenu(false);

    sensorsReader.begin();

    Serial.println("timestamp,temperature,voltage1,voltage2");

    rtc.begin();
    DateTime now = rtc.now();
    last_t = now.unixtime();
    lcd.init();                      // initialize the lcd
    lcd.backlight();
    lcd.clear();
    lcd.home();
   // lcd.off();
    lcd.print('a');
//    lcd.write('A');
//    lcd.write('B');
    lcd.flush();
}

void loop() {

    DateTime now = rtc.now();
    long now_t = now.unixtime();

    if ((now_t - last_t >= deviceConfig.loggingConfig.transmissionPeriod) && deviceConfig.loggingConfig.isEnabled()) {

        lastLoggingRecord = sensorsReader.readSensorsValue();
        // measurementRemoteService.sendMeasurement(now, lastLoggingRecord);

        Serial.print(now_t);
        Serial.print(",");
        Serial.print(lastLoggingRecord.toString());
        Serial.print(",");
        Serial.print(deviceConfig.loggingConfig.gIndx[0]);
        Serial.print(",");
        Serial.print(deviceConfig.loggingConfig.gIndx[1]);
        Serial.println(8);

        last_t = now_t;
        consoleLogger.debug(String("date: ") + date_utils::date_to_string(now));
        lcd.write('A');
    } else if (!deviceConfig.loggingConfig.isEnabled() && (now_t - last_t >= 5)) {
        consoleLogger.info("LOGGING DISABLED"); // printing IDLE in 5 sec
        last_t = now_t;
    } if (now_t < last_t) {
        consoleLogger.error("Last time is in future");
        last_t = now_t;
    }
}
