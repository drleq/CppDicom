#include "dicom_pch.h"
#include "dicom/data/DT.h"

#include <sstream>
#include <iomanip>

#include "dicom/data/detail/atoi.h"

namespace {
    void output_datetime_to_string(const dicom::data::date_time& datetime, std::ostringstream& dest) {
        auto& date = datetime.Date();
        auto& time = datetime.Time();

        int parts = static_cast<int>(datetime.Precision());

        dest << std::setfill('0');

                          dest << std::setw(4) << (uint32_t)date.Year();
        if (parts >= 1) { dest << std::setw(2) << (uint32_t)date.Month(); }
        if (parts >= 2) { dest << std::setw(2) << (uint32_t)date.Day(); }
        if (parts >= 3) { dest << std::setw(2) << (uint32_t)time.Hour(); }
        if (parts >= 4) { dest << std::setw(2) << (uint32_t)time.Minute(); }
        if (parts >= 5) { dest << std::setw(2) << (uint32_t)time.Second(); }
        if (parts == 6) {
            dest << '.' << std::setw(0) << time.Millisecond();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void output_offset_to_string(const dicom::data::time_offset& offset, std::ostringstream& dest) {
        dest << std::setw(0) << (offset.IsNegative() ? '-' : '+');
        dest << std::setfill('0') << std::setw(2);
        dest << (uint32_t)offset.Hour() << (uint32_t)offset.Minute();
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid_value(const std::string& value, bool& has_offset) {
        size_t len = value.size();
        auto v = value.c_str();

        // Search for '-' or '+' to indicate an offset value
        auto offset_it = std::find_if(
            value.begin(),
            value.end(),
            [](char c) { return (c == '-') || (c == '+'); }
        );

        // Check that the starting offset character is in the expected location
        has_offset = (offset_it != value.end());
        if (has_offset) {
            size_t offset_start = std::distance(value.begin(), offset_it);
            if (offset_start != len - 5) { return false; }
            len -= 5;
        }


        // Perform a basic check on the number of characters
        if (len < 16) {
            // No fractional digits - 4, 6, 8, 10, 12, 14
            if ((len & 1) || (len < 4)) { return false; }
        } else {
            // Fractional digits - [16..21]
            if (len > 21) { return false; }
        }


        // Check the non fractional part only contains digits
        if (!std::all_of(v, v + std::min<size_t>(14, len), isdigit)) { return false; }

        if (len >= 16) {
            // Check the fractional delimiter
            if (v[14] != '.') { return false; }
            // Check the fractional part only contains digits
            if (!std::all_of(v+15, v+len, isdigit)) { return false; }
        }

        if (has_offset) {
            // Check the offset only contains digits
            if (!std::all_of(v+len+1, v+len+5, isdigit)) { return false; }
        }

        return true;
    }
}

namespace dicom::data {

    DT::DT()
      : DT(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::DT(const char* value)
      : DT(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::DT(const std::string_view& value)
      : DT(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::DT(std::string&& value)
      : VR(VRType::DT),
        m_value(std::forward<std::string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::DT(const date_time& date_time)
      : VR(VRType::DT)
    {
        if (date_time.IsValid()) {
            std::ostringstream ss;
            output_datetime_to_string(date_time, ss);
            m_value = ss.str();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    DT::DT(const date_time& date_time, const time_offset& offset)
      : VR(VRType::DT)
    {
        if (date_time.IsValid() && offset.IsValid()) {
            std::ostringstream ss;
            output_datetime_to_string(date_time, ss);
            output_offset_to_string(offset, ss);
            m_value = ss.str();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    DT::DT(const DT& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_date_time(other.m_parsed_date_time),
        m_parsed_offset(other.m_parsed_offset)
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::DT(DT&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed_date_time(std::move(other.m_parsed_date_time)),
        m_parsed_offset(std::move(other.m_parsed_offset))
    {}

    //--------------------------------------------------------------------------------------------------------

    DT::~DT() = default;

    //--------------------------------------------------------------------------------------------------------

    DT& DT::operator = (const DT& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_date_time = other.m_parsed_date_time;
        m_parsed_offset = other.m_parsed_offset;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    DT& DT::operator = (DT&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed_date_time = std::move(other.m_parsed_date_time);
        m_parsed_offset = std::move(other.m_parsed_offset);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType DT::Validate() const {
        /* yyyy
           yyyyMM
           yyyyMMdd
           yyyyMMddHH
           yyyyMMddHHmm
           yyyyMMddHHmmss
           yyyyMMddHHmmss.f
           yyyyMMddHHmmss.ff
           yyyyMMddHHmmss.fff
           yyyyMMddHHmmss.ffff
           yyyyMMddHHmmss.fffff
           yyyyMMddHHmmss.ffffff

           + each with optional offset [-|+]zzxx
        */

		/*** Essential checks ***/
		// Validate the structure of the value
		bool has_offset;
		if (!is_valid_value(m_value, has_offset)) { return ValidityType::Invalid; }
		
		auto v = m_value.c_str();
		auto len = m_value.size();
		if (has_offset) { len -= 5; }

        // Attempt to extract the actual values
        DateTimePrecision precision = DateTimePrecision::Years;
        if (len >= 16) {
            precision = DateTimePrecision::Milliseconds;
        } else if (len > 4 && len < 14) {
            // Months, days, hours, minutes, seconds
            precision = static_cast<DateTimePrecision>((len - 4) / 2);
        }

        uint16_t year = 0;
        uint8_t month = 1;
        uint8_t day = 1;
        uint8_t hour = 0;
        uint8_t minute = 0;
        uint8_t second = 0;
        uint32_t fractional = 0;
        
        uint64_t non_frac = detail::unchecked_atoi<uint64_t>(v);
		if (len >= 16) { fractional = detail::unchecked_atoi<uint32_t>(v+15); }
        if (len >= 14) { second = uint8_t(non_frac % 100); non_frac /= 100; }
        if (len >= 12) { minute = uint8_t(non_frac % 100); non_frac /= 100; }
        if (len >= 10) { hour   = uint8_t(non_frac % 100); non_frac /= 100; }
        if (len >=  8) { day    = uint8_t(non_frac % 100); non_frac /= 100; }
        if (len >=  6) { month  = uint8_t(non_frac % 100); non_frac /= 100; }
        year = uint16_t(non_frac);

        uint8_t off_hour = 0;
        uint8_t off_minute = 0;
        bool off_backward = false;
        if (has_offset) {
            uint32_t zx = detail::unchecked_atoi<uint32_t>(v+len+1);
            off_minute = uint8_t(zx % 100);
            off_hour   = uint8_t(zx / 100);
			if (v[len] == '-') { off_backward = true; }
        }


        // Validate the value
        date_time tmp_dt(precision, year, month, day, hour, minute, second, fractional);
        time_offset tmp_off(off_hour, off_minute, off_backward);
        if (!tmp_dt.IsValid() || !tmp_off.IsValid()) { return ValidityType::Invalid; }

        m_parsed_date_time = std::move(tmp_dt);
        m_parsed_offset = std::move(tmp_off);


        /*** Strict checks ***/


		return ValidityType::Valid;
    }
	
    //--------------------------------------------------------------------------------------------------------

    int32_t DT::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const DT*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value.compare(typed->m_value);
        }
        
        result = m_parsed_date_time.Compare(typed->m_parsed_date_time);
        if (result != 0) { return result; }

        return m_parsed_offset.Compare(typed->m_parsed_offset);
    }

}