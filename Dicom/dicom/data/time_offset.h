#pragma once

namespace dicom::data {

    class time_offset
    {
    public:
        time_offset();
        time_offset(uint8_t hour, uint8_t minute, bool is_negative = false);

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] uint8_t Hour() const { return m_hour; }
        [[nodiscard]] uint8_t Minute() const { return m_minute; }
        [[nodiscard]] bool IsNegative() const { return m_is_negative; }

        [[nodiscard]] bool IsValid() const { return m_is_valid; }

        //-----------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const time_offset& other) const;

        [[nodiscard]] bool operator == (const time_offset& other) const { return Compare(other) == 0; }
        [[nodiscard]] bool operator != (const time_offset& other) const { return Compare(other) != 0; }
        [[nodiscard]] bool operator <  (const time_offset& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const time_offset& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const time_offset& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const time_offset& other) const { return Compare(other) >= 0; }

    private:
        uint8_t m_hour;
        uint8_t m_minute;
        bool m_is_negative;
        bool m_is_valid;
    };

}