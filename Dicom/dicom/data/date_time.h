#pragma once

#include "dicom/data/date.h"
#include "dicom/data/time.h"

namespace dicom::data {

    enum class DateTimePrecision : uint8_t
    {
        Years = 0,
        Months = 1,
        Days = 2,
        Hours = 3,
        Minutes = 4,
        Seconds = 5,
        Milliseconds = 6
    };

    class DICOM_EXPORT date_time
    {
    public:
        date_time();
        date_time(DateTimePrecision precision, const date& _date, const time& _time);
        date_time(
            DateTimePrecision precision,
            uint16_t year,
            uint8_t month = 1,
            uint8_t day = 1,
            uint8_t hour = 0,
            uint8_t minute = 0,
            uint8_t second = 0,
            uint32_t millisecond = 0
        );

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] const date& Date() const { return m_date; }
        [[nodiscard]] const time& Time() const { return m_time; }

        [[nodiscard]] DateTimePrecision Precision() const { return m_precision; }
        [[nodiscard]] uint16_t Year() const { return m_date.Year(); }
        [[nodiscard]] uint8_t Month() const { return m_date.Month(); }
        [[nodiscard]] uint8_t Day() const { return m_date.Day(); }
        [[nodiscard]] uint8_t Hour() const { return m_time.Hour(); }
        [[nodiscard]] uint8_t Minute() const { return m_time.Minute(); }
        [[nodiscard]] uint8_t Second() const { return m_time.Second(); }
        [[nodiscard]] uint32_t Millisecond() const { return m_time.Millisecond(); }

        [[nodiscard]] bool IsValid() const { return m_is_valid; }

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const date_time& other) const;

        [[nodiscard]] bool operator == (const date_time& other) const { return Compare(other) == 0; }
        [[nodiscard]] bool operator != (const date_time& other) const { return Compare(other) != 0; }
        [[nodiscard]] bool operator <  (const date_time& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const date_time& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const date_time& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const date_time& other) const { return Compare(other) >= 0; }

    private:
        DateTimePrecision m_precision;
        date m_date;
        time m_time;
        bool m_is_valid;
    };

}