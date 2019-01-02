#include "dicom_pch.h"
#include "dicom/data/DA.h"

#include <sstream>
#include <iomanip>

#include "dicom/data/detail/atoi.h"
#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/validate_separator_locations.h"

namespace {
    [[nodiscard]] bool is_valid_dicom_value(const char* start) {
        return std::all_of(start, start+8, isdigit);
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid_acr_nema_300_value(const char* start) {
        auto v = start;

        if (!std::all_of(v+0, v+4, isdigit)) { return false; }
        if (v[4] != '.') { return false; }
        if (!std::all_of(v+5, v+7, isdigit)) { return false; }
        if (v[7] != '.') { return false; }
        if (!std::all_of(v+8, v+10, isdigit)) { return false; }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] std::string to_iso_string(const dicom::data::date& value) {
        std::ostringstream ss;
        ss << std::setfill('0');
        ss << std::setw(4) << static_cast<uint32_t>(value.Year());
        ss << std::setw(2) << static_cast<uint32_t>(value.Month());
        ss                 << static_cast<uint32_t>(value.Day());
        return ss.str();
    }
}

namespace dicom::data {

    DA::DA()
      : DA(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const char* value)
      : DA(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const std::string_view& value)
      : DA(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::DA(std::string&& value)
      : VR(VRType::DA),
        m_value(std::forward<std::string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const std::vector<std::string_view>& values)
      : VR(VRType::DA)
    {
        detail::combine_strings(values, &m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    DA::DA(std::initializer_list<std::string_view> values)
      : VR(VRType::DA)
    {
        detail::combine_strings(values, &m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const date& value)
      : VR(VRType::DA)
    {
        if (value.IsValid()) {
            m_value = to_iso_string(value);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const std::vector<date>& values)
      : VR(VRType::DA)
    {
        bool valid = std::all_of(values.begin(), values.end(), [](auto& v) { return v.IsValid(); });
        if (valid) {
            // This is possible without temporary strings but given the infrequent use of this method
            // the optimization isn't worth the effort.
            std::vector<std::string> tmp;
            for (auto& value : values) {
                tmp.emplace_back(to_iso_string(value));
            }

            detail::combine_strings(tmp, &m_value);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    DA::DA(std::initializer_list<date> values)
      : VR(VRType::DA)
    {
        bool valid = std::all_of(values.begin(), values.end(), [](auto& v) { return v.IsValid(); });
        if (valid) {
            // This is possible without temporary strings but given the infrequent use of this method
            // the optimization isn't worth the effort.
            std::vector<std::string> tmp;
            for (auto& value : values) {
                tmp.emplace_back(to_iso_string(value));
            }

            detail::combine_strings(tmp, &m_value);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    DA::DA(const DA& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed(other.m_parsed)
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::DA(DA&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed(std::move(other.m_parsed))
    {}

    //--------------------------------------------------------------------------------------------------------

    DA::~DA() = default;

    //--------------------------------------------------------------------------------------------------------

    DA& DA::operator = (const DA& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed = other.m_parsed;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    DA& DA::operator = (DA&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed = std::move(other.m_parsed);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType DA::Validate() const {
		/*  - DICOM official
			YYYYMMDD

			- ACR-NEMA 300 (deprecated)
			YYYY.MM.DD
		*/

        // Get the offsets for multiplicity markers
        std::vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);


		/*** Essential checks ***/
        size_t start_index = 0;
        size_t end_index = 0;
        for (size_t i = 0; i <= parsed_offsets.size(); ++i, start_index = end_index + 1) {
            if (i == parsed_offsets.size()) {
                end_index = m_value.size();
            } else {
                end_index = parsed_offsets[i];
            }

            // Perform a basic check against the value length
            size_t len = end_index - start_index;
            bool valid = (len == 8) || (len == 10);
            if (!valid) { return ValidityType::Invalid; }

            bool is_acr_nema = (len == 10);
            auto v = m_value.c_str() + start_index;
            uint16_t y = 0;
            uint8_t m = 0;
            uint8_t d = 0;

            if (is_acr_nema) {
                if (!is_valid_acr_nema_300_value(v)) { return ValidityType::Invalid; }
                y = detail::unchecked_atoi<uint16_t>(v + 0);
                m = detail::unchecked_atoi<uint8_t>(v + 5);
                d = detail::unchecked_atoi<uint8_t>(v + 8);
            } else {
                if (!is_valid_dicom_value(v)) { return ValidityType::Invalid; }
                auto ymd = detail::unchecked_atoi<uint32_t>(v);
                y = uint16_t(ymd / 10000);
                m = uint8_t((ymd / 100) % 100);
                d = uint8_t(ymd % 100);
            }

            date tmp(DatePrecision::Days, y, m, d);
            if (!tmp.IsValid()) { return ValidityType::Invalid; }
            m_parsed.emplace_back(std::move(tmp));
        }


        /*** Strict checks ***/
        if (!detail::validate_separator_locations(m_value, parsed_offsets, 8)) {
            return ValidityType::Acceptable;
        }

		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t DA::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const DA*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value.compare(typed->m_value);
        }

        size_t compare_length = std::min(m_parsed.size(), typed->m_parsed.size());
        for (size_t i = 0; i < compare_length; ++i) {
            result = m_parsed[i].Compare(typed->m_parsed[i]);
            if (result != 0) { return result; }
        }

        if (m_parsed.size() != typed->m_parsed.size()) {
            return m_parsed.size() < typed->m_parsed.size();
        }
        return 0;
    }

}