#include "ADS1115AutoRangedReader.h"

ADS1115AutoRangedReader::ADS1115AutoRangedReader(LoggingConfig &loggingConfig, const ConsoleLogger &consoleLogger)
        : loggingConfig(loggingConfig), consoleLogger(consoleLogger) {}

float ADS1115AutoRangedReader::readAdcAutoRangedValue(const int ch) {
    float adc;
    while (true) // this function constantly adjusts the GAINS to an optimum level
    {
        int gidx = loggingConfig.gIndx[ch];
        if (gidx < 0 || gidx > LoggingConfig::GAINS_SIZE) {
            loggingConfig.gIndx[ch] = LoggingConfig::GAINS_SIZE - 1;
        }
        adsGain_t gain = loggingConfig.GAINS[gidx];
        ads.setGain(gain);
        adc = read_adc_value(ch);
        consoleLogger.debug(String("Gain index: ") + gidx + String("ADC value: ") + adc);

        if (abs(int(adc)) >= 30000 && gidx > 0) {
            consoleLogger.debug(String("Gain reduced to ") + gidx);
            loggingConfig.gIndx[ch]--;
            ads.setGain(gain);
        } else if (abs(int(adc)) <= 7000 && gidx < LoggingConfig::GAINS_SIZE - 1) {
            consoleLogger.debug(String("Gain increased to ") + gidx);
            loggingConfig.gIndx[ch]++;
            ads.setGain(gain);
        } else {
            break;
        }
    }

    return convert_adc_value_to_voltage(adc, loggingConfig.gIndx[ch]);
}

float ADS1115AutoRangedReader::read_adc_value(const int ch) {
    if (ch != 0 && ch != 1) {
        consoleLogger.error("Could not resolve channel");
        return 0;
    }
    float sum = 0.0f;

    consoleLogger.debug(String("loggingConfig.avgIterNum=")+loggingConfig.avgIterNum);
    for (int i = 0; i < loggingConfig.avgIterNum; i++) {
        float value;
        if (ch == 0) {
            value = ads.readADC_Differential_0_1();
        } else {
            value = ads.readADC_Differential_2_3();
        }

        sum = sum + value;
        delay(1);
    }
    float average = sum / float(loggingConfig.avgIterNum) * 1.0f;
    return average;
}

void ADS1115AutoRangedReader::begin() {
    ads.begin();
}

float ADS1115AutoRangedReader::convert_adc_value_to_voltage(const float adc, const int gain) {
    float V;
    switch (gain) {
        case 0:  // default 2/3x GAINS setting for +/- 6.144 V
            V = adc * 0.0001875f;
            break;
        case 1:  // 1x GAINS setting for +/- 4.096 V
            V = adc * 0.000125f;
            break;
        case 2:  // 2x GAINS setting for +/- 2.048 V
            V = adc * 0.0000625f;
            break;
        case 3:  // 4x GAINS setting for +/- 1.024 V
            V = adc * 0.00003125f;
            break;
        case 4:  // 8x GAINS setting for +/- 0.512 V
            V = adc * 0.000015625f;
            break;
        case 5:  // 16x GAINS setting for +/- 0.256 V
            V = adc * 0.0000078125f;
            break;

        default:
            V = 0.0;
    }

    return V;
}

