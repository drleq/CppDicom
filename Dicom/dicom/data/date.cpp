#include "dicom_pch.h"
#include "dicom/data/date.h"

namespace {
    [[nodiscard]] bool is_valid_date(dicom::data::DatePrecision precision, uint16_t year, uint8_t month, uint8_t day) {
        std::tm tm = { 0 };
        tm.tm_isdst = 0;
        switch (precision) {
        case dicom::data::DatePrecision::Days:   tm.tm_mday = day;
        case dicom::data::DatePrecision::Months: tm.tm_mon = month - 1;
        case dicom::data::DatePrecision::Years:  tm.tm_year = int(year) - 1900;
        }

        std::tm copy = tm;
        time_t tmp = mktime(&tm);
        if (tmp == -1) { return false; }

        return (tm.tm_year == copy.tm_year) &&
               (tm.tm_mon  == copy.tm_mon) &&
               (tm.tm_mday == copy.tm_mday);
    }

    //---------------------------------------------------------------------------------------------

    template <typename T>
    [[nodiscard]] int32_t compare_values(T a, T b) {
        if (a == b) { return 0; }
        return (a < b) ? -1 : 1;
    }
}

namespace dicom::data {

    date::date()
      : m_precision(DatePrecision::Years),
        m_year(0),
        m_month(0),
        m_day(0),
        m_is_valid(false)
    {}

    //---------------------------------------------------------------------------------------------

    date::date(uint16_t year, uint8_t month, uint8_t day)
      : date(DatePrecision::Days, year, month, day)
    {}

    //---------------------------------------------------------------------------------------------

    date::date(DatePrecision precision, uint16_t year, uint8_t month, uint8_t day)
      : m_precision(precision),
        m_year(year),
        m_month(month),
        m_day(day)
    {
        m_is_valid = is_valid_date(precision, year, month, day);
    }

    //---------------------------------------------------------------------------------------------

    int32_t date::Compare(const date& other) const {
        DatePrecision other_precision = other.m_precision;
        int result;

        DatePrecision cmp_precision = std::min(m_precision, other_precision);

        result = compare_values(m_year, other.m_year);
        if (result != 0) { return result; }

        if (cmp_precision >= DatePrecision::Months) {
            result = compare_values(m_month, other.m_month);
            if (result != 0) { return result; }
        }

        if (cmp_precision >= DatePrecision::Days) {
            result = compare_values(m_day, other.m_day);
            if (result != 0) { return result; }
        }

        return int32_t(m_precision) - int32_t(other_precision);
    }

}