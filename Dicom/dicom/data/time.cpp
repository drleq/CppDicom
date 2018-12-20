#include "dicom_pch.h"
#include "dicom/data/time.h"

namespace {
    [[nodiscard]] bool is_valid_time(uint8_t hour, uint8_t minute, uint8_t second, uint32_t millisecond) {
        return (hour <= 23) &&
               (minute <= 59) &&
               (second <= 60) && // To account for leap seconds
               (millisecond <= 999999);
    }

    //---------------------------------------------------------------------------------------------

    template <typename T>
    [[nodiscard]] int32_t compare_values(T a, T b) {
        if (a == b) { return 0; }
        return (a < b) ? -1 : 1;
    }
}

namespace dicom::data {

    time::time()
      : m_precision(TimePrecision::Hours),
        m_hour(0),
        m_minute(0),
        m_second(0),
        m_millisecond(0),
        m_is_valid(false)
    {}

    //---------------------------------------------------------------------------------------------

    time::time(
        TimePrecision precision,
        uint8_t hour,
        uint8_t minute,
        uint8_t second,
        uint32_t millisecond
    ) : m_precision(precision),
        m_hour(hour),
        m_minute(minute),
        m_second(second),
        m_millisecond(millisecond)
    {
        m_is_valid = is_valid_time(hour, minute, second, millisecond);
    }

    //---------------------------------------------------------------------------------------------

    int32_t time::Compare(const time& other) const {
        TimePrecision other_precision = other.m_precision;
        int result;

        TimePrecision cmp_precision = std::min(m_precision, other_precision);

        result = compare_values(m_hour, other.m_hour);
        if (result != 0) { return result; }

        if (cmp_precision >= TimePrecision::Minutes) {
            result = compare_values(m_minute, other.m_minute);
            if (result != 0) { return result; }
        }

        if (cmp_precision >= TimePrecision::Seconds) {
            result = compare_values(m_second, other.m_second);
            if (result != 0) { return result; }
        }

        if (cmp_precision >= TimePrecision::Milliseconds) {
            result = compare_values(m_millisecond, other.m_millisecond);
            if (result != 0) { return result; }
        }

        return int32_t(m_precision) - int32_t(other_precision);
    }

}