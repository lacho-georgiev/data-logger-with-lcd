#ifndef WIFI_DATA_LOGGER_CONSOLELOGGER_H
#define WIFI_DATA_LOGGER_CONSOLELOGGER_H

#include <Arduino.h>

class ConsoleLogger {
public:
    static const int LOG_LEVEL_TRACE = 5;
    static const int LOG_LEVEL_DEBUG = 4;
    static const int LOG_LEVEL_INFO = 3;
    static const int LOG_LEVEL_WARNING = 2;
    static const int LOG_LEVEL_ERROR = 1;

private:
    int log_level = LOG_LEVEL_INFO;

public:
    void error(const String message) const;
    void warning(const String message) const;
    void info(const String message) const;
    void debug(const String message) const;
    void trace(const String message) const;

    int getLogLevel() const;

    void setLogLevel(const int logLevel);

};


#endif //WIFI_DATA_LOGGER_CONSOLELOGGER_H
