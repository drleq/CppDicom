#pragma once

namespace dicom::data {

    enum class DatePrecision : uint8_t
    {
        Years = 0,
        Months = 1,
        Days = 2
    };

    class DICOM_EXPORT date
    {
    public:
        date();
        date(uint16_t year, uint8_t month, uint8_t day);
        date(DatePrecision precision, uint16_t year, uint8_t month, uint8_t day);

        [[nodiscard]] DatePrecision Precision() const { return m_precision; }
        [[nodiscard]] uint16_t Year() const { return m_year; }
        [[nodiscard]] uint8_t Month() const { return m_month; }
        [[nodiscard]] uint8_t Day() const { return m_day; }

        [[nodiscard]] bool IsValid() const { return m_is_valid; }

        [[nodiscard]] int32_t Compare(const date& other) const;

        [[nodiscard]] bool operator == (const date& other) const { return Compare(other) == 0; }
        [[nodiscard]] bool operator != (const date& other) const { return Compare(other) != 0; }
        [[nodiscard]] bool operator <  (const date& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const date& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const date& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const date& other) const { return Compare(other) >= 0; }

    private:
        DatePrecision m_precision;
        uint16_t m_year;
        uint8_t m_month;
        uint8_t m_day;
        bool m_is_valid;
    };

}