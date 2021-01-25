#include "DateTimeUtils.h"

String int_to_string2(int i) {
    if (i >= 0 && i <= 9) {
        String s = "0";
        s += String(i, DEC);
        return s;
    } else {
        return String(i, DEC);
    }
}

String date_utils::date_to_string(DateTime _now) {
    String str = int_to_string2(_now.year()) + '-' + int_to_string2(_now.month()) + '-' + int_to_string2(_now.day()) +
                 " " + int_to_string2(_now.hour()) + ':' + int_to_string2(_now.minute()) + ':' +
                 int_to_string2(_now.second());
    return str;
}
