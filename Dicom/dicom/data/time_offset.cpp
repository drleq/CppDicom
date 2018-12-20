#include "dicom_pch.h"
#include "dicom/data/time_offset.h"

namespace {
    template <typename T>
    [[nodiscard]] int32_t compare_values(T a, T b) {
        if (a == b) { return 0; }
        return (a < b) ? -1 : 1;
    }
}

namespace dicom::data {

    time_offset::time_offset()
      : m_hour(0),
        m_minute(0),
        m_is_negative(false),
        m_is_valid(false)
    {}

    //---------------------------------------------------------------------------------------------

    time_offset::time_offset(uint8_t hour, uint8_t minute, bool is_negative /*= false*/)
      : m_hour(hour),
        m_minute(minute),
        m_is_negative(is_negative)
    {
        m_is_valid = (hour <= 23) && (minute <= 59);
    }

    //---------------------------------------------------------------------------------------------

    int32_t time_offset::Compare(const time_offset& other) const {
        if (m_is_negative != other.m_is_negative) {
            return m_is_negative ? -1 : 1;
        }

        int32_t result = compare_values(m_hour, other.m_hour);
        if (result != 0) { return result; }

        return compare_values(m_minute, other.m_minute);
    }

}