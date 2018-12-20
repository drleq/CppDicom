#include "dicom_pch.h"
#include "dicom/data/date_time.h"

namespace {
    using namespace dicom::data;

    [[nodiscard]] bool is_valid_date_time(
        DateTimePrecision precision,
        const date& _date,
        const dicom::data::time& _time
    ) {
        if (!_date.IsValid() || !_time.IsValid()) {
            return false;
        }

        std::tm tm = { 0 };
        tm.tm_mday = 1;
        tm.tm_isdst = 0;
        switch (precision) {
        case DateTimePrecision::Milliseconds:
        case DateTimePrecision::Seconds: tm.tm_sec  = _time.Second();
        case DateTimePrecision::Minutes: tm.tm_min  = _time.Minute();
        case DateTimePrecision::Hours:   tm.tm_hour = _time.Hour();
        case DateTimePrecision::Days:    tm.tm_mday = _date.Day();
        case DateTimePrecision::Months:  tm.tm_mon  = _date.Month() - 1;
        case DateTimePrecision::Years:   tm.tm_year = _date.Year() - 1900;
        }

        std::tm copy = tm;
        time_t tmp = mktime(&copy);
        if (tmp == -1) { return false; }

        return (tm.tm_year == copy.tm_year) &&
               (tm.tm_mon  == copy.tm_mon ) &&
               (tm.tm_mday == copy.tm_mday) &&
               (tm.tm_hour == copy.tm_hour) &&
               (tm.tm_min  == copy.tm_min ) &&
               (tm.tm_sec  == copy.tm_sec );
    }

    //---------------------------------------------------------------------------------------------

    [[nodiscard]] DatePrecision to_date_precision(DateTimePrecision precision) {
        switch (precision) {
        case DateTimePrecision::Years:  return DatePrecision::Years;
        case DateTimePrecision::Months: return DatePrecision::Months;
        case DateTimePrecision::Days:   return DatePrecision::Days;
        default:
            return DatePrecision::Days;
        }
    }

    //---------------------------------------------------------------------------------------------

    [[nodiscard]] TimePrecision to_time_precision(DateTimePrecision precision) {
        switch (precision) {
        case DateTimePrecision::Milliseconds: return TimePrecision::Milliseconds;
        case DateTimePrecision::Seconds:      return TimePrecision::Seconds;
        case DateTimePrecision::Minutes:      return TimePrecision::Minutes;
        case DateTimePrecision::Hours:        return TimePrecision::Hours;
        default:
            return TimePrecision::Hours;
        }
    }
}

namespace dicom::data {

    date_time::date_time()
      : m_is_valid(false)
    {}

    //---------------------------------------------------------------------------------------------

    date_time::date_time(DateTimePrecision precision, const date& _date, const time& _time)
      : m_precision(precision),
        m_date(_date),
        m_time(_time)
    {
        m_is_valid = is_valid_date_time(precision, _date, _time);
    }

    //---------------------------------------------------------------------------------------------

    date_time::date_time(
        DateTimePrecision precision,
        uint16_t year,
        uint8_t month /*= 1*/,
        uint8_t day /*= 1*/,
        uint8_t hour /*= 0*/,
        uint8_t minute /*= 0*/,
        uint8_t second /*= 0*/,
        uint32_t millisecond /*= 0*/
    ) : date_time(
            precision,
            date(to_date_precision(precision), year, month, day),
            time(to_time_precision(precision), hour, minute, second, millisecond)
        )
    {}

    //---------------------------------------------------------------------------------------------

    int32_t date_time::Compare(const date_time& other) const {
        int32_t result = m_date.Compare(other.m_date);
        if (result != 0) { return result; }

        return m_time.Compare(other.m_time);
    }

}