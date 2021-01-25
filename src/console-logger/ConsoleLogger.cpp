#include "ConsoleLogger.h"

void ConsoleLogger::error(const String message) const {
    if (this->log_level >= this->LOG_LEVEL_ERROR) {
        Serial.print("ERROR: ");
        Serial.println(message);
    }
}

void ConsoleLogger::warning(const String message) const {
    if (this->log_level >= this->LOG_LEVEL_WARNING) {
        Serial.print("WARN: ");
        Serial.println(message);
    }
}

void ConsoleLogger::info(const String message) const {
    if (this->log_level >= this->LOG_LEVEL_INFO) {
        Serial.print("INFO: ");
        Serial.println(message);
    }
}

void ConsoleLogger::debug(const String message) const {
    if (this->log_level >= this->LOG_LEVEL_DEBUG) {
        Serial.print("DEBUG: ");
        Serial.println(message);
    }
}

void ConsoleLogger::trace(const String message) const {
    if (this->log_level >= this->LOG_LEVEL_TRACE) {
        Serial.print("TRACE: ");
        Serial.println(message);
    }
}

int ConsoleLogger::getLogLevel() const {
    return log_level;
}

void ConsoleLogger::setLogLevel(const int logLevel) {
    log_level = logLevel;
}
