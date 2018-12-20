#include "dicom_pch.h"
#include "dicom/data/TM.h"

#include <sstream>
#include <iomanip>

#include "dicom/data/detail/atoi.h"

namespace {
    constexpr uint32_t FractionalScale[7] = {
        1,
        100000,
        10000,
        1000,
        100,
        10,
        1
    };

    //--------------------------------------------------------------------------------------------------------

    void output_duration_to_string(const dicom::data::time& duration, std::ostringstream& dest) {
        int parts = static_cast<int>(duration.Precision()); // 0 = hours, 1 = minutes, 2 = seconds, 3 = milliseconds

        dest << std::setfill('0');

        dest << std::setw(2) << duration.Hour();
        if (parts >= 1) { dest << std::setw(2) << duration.Minute(); }
        if (parts >= 2) { dest << std::setw(2) << duration.Second(); }
        if (parts == 3) {
            dest << '.' << std::setw(0) << duration.Millisecond();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid_acr_nema_300_value(const std::string& value) {
		auto len = value.size();
		auto s = value.c_str();

		// Check hh
		bool valid = std::all_of(s, s+1, isdigit);
		if (!valid) { return false; }

		// Check :mm
		if (len >= 5) {
			valid = (s[2] == ':') && std::all_of(s+3, s+4, isdigit);
			if (!valid) { return false; }
		}

		// Check :ss
		if (len >= 8) {
			valid = (s[5] == ':') && std::all_of(s+6, s+7, isdigit);
			if (!valid) { return false; }
		}

		// Check .ffffff
		if (len >= 10) {
			valid = (s[8] == '.') && std::all_of(s+9, s+len, isdigit);
			if (!valid) { return false; }
		}

		return true;
	}

	//--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid_dicom_value(const std::string& value) {
		auto len = value.size();
		auto s = value.c_str();

		// Check hhmmss
		bool valid = std::all_of(s, s + std::min<size_t>(6, len), isdigit);
		if (!valid) { return false; }

		// Check .ffffff
		if (len >= 8) {
			valid = s[6] == '.';
			if (!valid) { return false; }

			valid = std::all_of(s+7, s+len, isdigit);
			if (!valid) { return false; }
		}
		
		return true;
	}
}

namespace dicom::data {

    TM::TM()
      : TM(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const char* value)
      : TM(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const std::string_view& value)
      : TM(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(std::string&& value)
      : VR(VRType::TM),
        m_value(std::forward<std::string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const time& duration)
      : VR(VRType::TM)
    {
        if (duration.IsValid()) {
            std::ostringstream ss;
            output_duration_to_string(duration, ss);
            m_value = ss.str();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const TM& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed(other.m_parsed)
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(TM&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed(std::move(other.m_parsed))
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::~TM() = default;

    //--------------------------------------------------------------------------------------------------------

    TM& TM::operator = (const TM& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed = other.m_parsed;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    TM& TM::operator = (TM&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(m_value);
        m_parsed = std::move(m_parsed);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType TM::Validate() const {
		/*  - DICOM official
			hh
			hhmm
			hhmmss
			hhmmss.f
			hhmmss.ff
			hhmmss.fff
			hhmmss.ffff
			hhmmss.fffff
			hhmmss.ffffff
			- ACR-NEMA 300 (deprecated)
			hh:mm
			hh:mm:ss
			hh:mm:ss.f
			hh:mm:ss.ff
			hh:mm:ss.fff
			hh:mm:ss.ffff
			hh:mm:ss.fffff
			hh:mm:ss.ffffff
		*/

		/*** Essential checks ***/
		// Perform a basic check on the length of the value
		auto len = m_value.size();
		bool is_valid_length = len == 2 || (len >= 4 && len <= 15);
		if (!is_valid_length) { return ValidityType::Invalid; }
		
		// Guess if the value is ACR-NEMA
		bool is_acr_nema = m_value.find(':') != std::string::npos;
		auto v = m_value.c_str();
        TimePrecision p = TimePrecision::Hours;
		uint8_t h = 0;
        uint8_t m = 0;
        uint8_t s = 0;
		uint32_t f = 0;

		// Extract the hours, minutes, seconds and fractional seconds.
		if (is_acr_nema) {
			if (!is_valid_acr_nema_300_value(m_value)) { return ValidityType::Invalid; }

            if (len >= 2) {
                p = TimePrecision::Hours;
                h = detail::unchecked_atoi<uint8_t>(v+0);
            }
            if (len >= 5) {
                p = TimePrecision::Minutes;
                m = detail::unchecked_atoi<uint8_t>(v+3);
            }
            if (len >= 8) {
                p = TimePrecision::Seconds;
                s = detail::unchecked_atoi<uint8_t>(v+6);
            }
			if (len >= 10) {
                p = TimePrecision::Milliseconds;
                f = detail::unchecked_atoi<uint32_t>(v+9);
                f *= FractionalScale[len - 9];
            }
		} else {
			if (!is_valid_dicom_value(m_value)) { return ValidityType::Invalid; }

            p = static_cast<TimePrecision>(std::min<size_t>(6, len) / 2);
            
            uint32_t hms = detail::unchecked_atoi<uint32_t>(v+0);
            s = uint8_t(hms % 100);
			m = uint8_t((hms / 100) % 100);
			h = uint8_t( hms / 10000);
			if (len >= 8) {
                p = TimePrecision::Milliseconds;
                f = detail::unchecked_atoi<uint32_t>(v+7);
                f *= FractionalScale[len - 7];
            }
		}

		// Validate the range of the value
        time tmp(p, h, m, s, f);
        if (!tmp.IsValid()) { return ValidityType::Invalid; }
		m_parsed = std::move(tmp);

        
		/*** Strict checks ***/
		if (!is_valid_dicom_value(m_value)) { return ValidityType::Acceptable; }

		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t TM::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const TM*>(other);
        if (!m_parsed.IsValid() || !typed->m_parsed.IsValid()) {
            return m_value.compare(typed->m_value);
        }

        return m_parsed.Compare(typed->m_parsed);
    }

}