#pragma once

namespace dicom::data {

    enum class TimePrecision : uint8_t
    {
        Hours = 0,
        Minutes = 1,
        Seconds = 2,
        Milliseconds = 3
    };

    class time
    {
    public:
        time();
        time(
            TimePrecision precision,
            uint8_t hour,
            uint8_t minute = 0,
            uint8_t second = 0,
            uint32_t millisecond = 0
        );

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] TimePrecision Precision() const { return m_precision; }
        [[nodiscard]] uint8_t Hour() const { return m_hour; }
        [[nodiscard]] uint8_t Minute() const { return m_minute; }
        [[nodiscard]] uint8_t Second() const { return m_second; }
        [[nodiscard]] uint32_t Millisecond() const { return m_millisecond; }

        [[nodiscard]] bool IsValid() const { return m_is_valid; }

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] std::string AsString() const;

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const time& other) const;

        [[nodiscard]] bool operator == (const time& other) const { return Compare(other) == 0; }
        [[nodiscard]] bool operator != (const time& other) const { return Compare(other) != 0; }
        [[nodiscard]] bool operator <  (const time& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const time& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const time& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const time& other) const { return Compare(other) >= 0; }

    private:
        TimePrecision m_precision;
        uint8_t m_hour;
        uint8_t m_minute;
        uint8_t m_second;
        uint32_t m_millisecond;
        bool m_is_valid;
    };

}