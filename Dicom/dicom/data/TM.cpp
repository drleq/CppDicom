#include "dicom_pch.h"
#include "dicom/data/TM.h"

#include <sstream>
#include <iomanip>

#include "dicom/data/detail/atoi.h"
#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"

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

        dest << std::setw(2) << static_cast<uint16_t>(duration.Hour());
        if (parts >= 1) { dest << std::setw(2) << static_cast<uint16_t>(duration.Minute()); }
        if (parts >= 2) { dest << std::setw(2) << static_cast<uint16_t>(duration.Second()); }
        if (parts == 3) {
            dest << '.' << std::setw(0) << duration.Millisecond();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid_acr_nema_300_value(const std::string_view& value) {
		auto len = value.size();
		auto s = value.data();

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

    [[nodiscard]] bool is_valid_dicom_value(const std::string_view& value) {
		auto len = value.size();
		auto s = value.data();

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

    TM::TM(const std::vector<std::string>& values)
      : VR(VRType::TM)
    {
        detail::combine_strings(values, &m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(std::initializer_list<std::string_view> values)
      : VR(VRType::TM)
    {
        detail::combine_strings(values, &m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const time& duration)
      : VR(VRType::TM)
    {
        std::ostringstream ss;
        output_duration_to_string(duration, ss);
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const std::vector<time>& values)
      : VR(VRType::TM)
    {
        bool needs_multiplicity = false;
        std::ostringstream ss;
        for (auto& duration : values) {
            if (needs_multiplicity) {
                ss << detail::MultiplicityChar;
            } else {
                needs_multiplicity = true;
            }

            output_duration_to_string(duration, ss);
        }

        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(std::initializer_list<time> values)
      : VR(VRType::TM)
    {
        bool needs_multiplicity = false;
        std::ostringstream ss;
        for (auto& duration : values) {
            if (needs_multiplicity) {
                ss << detail::MultiplicityChar;
            } else {
                needs_multiplicity = true;
            }

            output_duration_to_string(duration, ss);
        }

        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    TM::TM(const TM& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_times(other.m_parsed_times)
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::TM(TM&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed_times(std::move(other.m_parsed_times))
    {}

    //--------------------------------------------------------------------------------------------------------

    TM::~TM() = default;

    //--------------------------------------------------------------------------------------------------------

    TM& TM::operator = (const TM& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_times = other.m_parsed_times;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    TM& TM::operator = (TM&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(m_value);
        m_parsed_times = std::move(m_parsed_times);
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

        if (m_value.empty()) {
            return ValidityType::Valid;
        }

        // Get the offsets for multiplicity markers
        std::vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);


		/*** Essential checks ***/
        using subvalue_iterator = detail::substring_iterator<detail::trim_none>;
        auto values_it = subvalue_iterator(&m_value, &parsed_offsets, 0);
        auto values_end = subvalue_iterator(&m_value, &parsed_offsets, parsed_offsets.size() + 1);

        std::vector<time> parsed_times;
        parsed_times.reserve(parsed_offsets.size() + 1);

		// Perform a basic check on the length of the value
        for (; values_it != values_end; ++values_it) {
            auto value = *values_it;
            auto len = value.size();
            bool is_valid_length = len == 2 || (len >= 4 && len <= 15);
            if (!is_valid_length) { return ValidityType::Invalid; }
            
            // Guess if the value is ACR-NEMA
            bool is_acr_nema = value.find(':') != std::string::npos;
            TimePrecision p = TimePrecision::Hours;
            uint8_t h = 0;
            uint8_t m = 0;
            uint8_t s = 0;
            uint32_t f = 0;

            // Extract the hours, minutes, seconds and fractional seconds.
            if (is_acr_nema) {
                if (!is_valid_acr_nema_300_value(value)) { return ValidityType::Invalid; }

                if (len >= 2) {
                    p = TimePrecision::Hours;
                    h = detail::unchecked_atoi<uint8_t>(value.substr(0, 2));
                }
                if (len >= 5) {
                    p = TimePrecision::Minutes;
                    m = detail::unchecked_atoi<uint8_t>(value.substr(3, 2));
                }
                if (len >= 8) {
                    p = TimePrecision::Seconds;
                    s = detail::unchecked_atoi<uint8_t>(value.substr(6, 2));
                }
                if (len >= 10) {
                    p = TimePrecision::Milliseconds;
                    f = detail::unchecked_atoi<uint32_t>(value.substr(9));
                    f *= FractionalScale[len - 9];
                }
            } else {
                if (!is_valid_dicom_value(value)) { return ValidityType::Invalid; }

                if (len >= 2) {
                    p = TimePrecision::Hours;
                    h = detail::unchecked_atoi<uint8_t>(value.substr(0, 2));
                }
                if (len >= 4) {
                    p = TimePrecision::Minutes;
                    m = detail::unchecked_atoi<uint8_t>(value.substr(2, 2));
                }
                if (len >= 6) {
                    p = TimePrecision::Seconds;
                    s = detail::unchecked_atoi<uint8_t>(value.substr(4, 2));
                }
                if (len >= 8) {
                    p = TimePrecision::Milliseconds;
                    f = detail::unchecked_atoi<uint32_t>(value.substr(7));
                    f *= FractionalScale[len - 7];
                }
            }

            // Validate the range of the value
            time tmp(p, h, m, s, f);
            if (!tmp.IsValid()) { return ValidityType::Invalid; }
            parsed_times.push_back(tmp);
        }

		m_parsed_times = std::move(parsed_times);

        
		/*** Strict checks ***/
        bool is_valid_dicom = std::any_of(
            subvalue_iterator(&m_value, &parsed_offsets, 0),
            values_end,
            is_valid_dicom_value
        );
        if (!is_valid_dicom) {
            return ValidityType::Acceptable;
        }

		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t TM::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const TM*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value.compare(typed->m_value);
        }

        bool empty = Empty();
        bool typed_empty = Empty();
        if (empty != typed_empty) { return empty ? -1 : 1; }
        if (empty) { return 0; }

        auto cmp_len = std::min(m_parsed_times.size(), typed->m_parsed_times.size());
        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i < cmp_len; ++i, ++it, ++typed_it) {
            result = (*it).Compare(*typed_it);
            if (result != 0) { return result; }
        }

        return int32_t(m_parsed_times.size()) - int32_t(typed->m_parsed_times.size());
    }

}