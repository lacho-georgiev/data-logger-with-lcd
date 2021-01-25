#ifndef WIFI_DATA_LOGGER2_DATETIMEUTILS_H
#define WIFI_DATA_LOGGER2_DATETIMEUTILS_H

#include <Arduino.h>
#include <RTClib.h>

namespace date_utils {
    String date_to_string(DateTime _now);
}

#endif //WIFI_DATA_LOGGER2_DATETIMEUTILS_H
