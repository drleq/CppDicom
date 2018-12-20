#include "dicom_pch.h"
#include "dicom/data/DS.h"

#include <cmath>
#include <iomanip>
#include <sstream>

#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"
#include "dicom/data/detail/validate_separator_locations.h"

namespace {
    using namespace dicom::data::detail;

    // Define a checked iterator to help validate the value string
    using checked_iterator = string_iterator<double, string_to_double, trim_left>;

    // Helper to output a double as a 16 character string. There is no single mechanism to force a limit
    // of 16 characters and still guarantee valid formatting. Instead, we start at a precision of 16 and
    // reduce it until we fit within the 16 character limit.
    void output_double_as_string(double value, std::ostringstream& dest) {
        std::stringstream tmp;
        int precision = 16;

        do {
            tmp << std::setprecision(precision);
            tmp << value;
            if (tmp.tellp() <= 16) {
                dest << tmp.rdbuf();
                return;
            }

            tmp.clear();
            tmp.str("");
        } while (--precision > 0);

        // We should never get here unless something terrible has happened. Just output the number
        // in any form rather than fail.
        dest << std::setprecision(12) << value;
    }
}

namespace dicom::data {

    DS::DS()
      : DS(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    DS::DS(const char* value) 
      : DS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DS::DS(const std::string_view& value) 
      : DS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    DS::DS(std::string&& value) 
      : VR(VRType::DS),
        m_value(std::forward<std::string>(value))
    {
        detail::string_trim(m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    DS::DS(double value)
      : VR(VRType::DS)
    {
        std::ostringstream ss;
        output_double_as_string(value, ss);
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    DS::DS(const std::vector<double>& values)
      : VR(VRType::DS)
    {
        std::ostringstream ss;
        for (auto it = values.begin(); it != values.end();) {
            output_double_as_string(*it, ss);
            if (++it != values.end()) { ss << detail::MultiplicityChar; }
        }
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    DS::DS(std::initializer_list<double> values)
      : VR(VRType::DS)
    {
        std::ostringstream ss;
        for (auto it = values.begin(); it != values.end();) {
            output_double_as_string(*it, ss);
            if (++it != values.end()) { ss << detail::MultiplicityChar; }
        }
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    DS::DS(const DS& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    DS::DS(DS&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed_offsets(std::move(other.m_parsed_offsets))
    {}

    //--------------------------------------------------------------------------------------------------------

    DS::~DS() = default;

    //--------------------------------------------------------------------------------------------------------

    DS& DS::operator = (const DS& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    DS& DS::operator = (DS&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed_offsets = std::move(other.m_parsed_offsets);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType DS::Validate() const {
        // Get the offsets for multiplicity markers
        std::vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);


        /*** Essential checks ***/
        // Use a checked iterator to validate the values
        checked_iterator it(&m_value, &parsed_offsets, 0);
        checked_iterator end_it(&m_value, &parsed_offsets, parsed_offsets.size() + 1);
        for (; it != end_it; ++it) {
            errno = 0;
            double dummy = *it;
            (void)dummy;
            if (errno != 0) {
                // This will trigger if m_value is empty. Check for that.
                if (m_value.empty()) { return ValidityType::Valid; }
                return ValidityType::Invalid;
            }
        }

        m_parsed_offsets.swap(parsed_offsets);


        /*** Strict checks ***/
        if (!detail::validate_separator_locations(m_value, m_parsed_offsets, 16)) {
            return ValidityType::Acceptable;
        }


		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t DS::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const DS*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value.compare(typed->m_value);
        }

        bool empty = Empty();
        bool typed_empty = typed->Empty();
        if (empty != typed_empty) { return empty ? -1 : 1; }
        if (empty) { return 0; }
        
        auto cmp_len = std::min(m_parsed_offsets.size(), typed->m_parsed_offsets.size());
        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= cmp_len; ++i, ++it, ++typed_it) {
            auto diff = (*it) - (*typed_it);
            if (std::abs(diff) <= std::numeric_limits<double>::epsilon()) { continue; }
            return (diff < 0.0f) ? -1 : 1;
        }

        return int32_t(m_parsed_offsets.size()) - int32_t(typed->m_parsed_offsets.size());
    }

    //--------------------------------------------------------------------------------------------------------

    bool DS::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const DS*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value == typed->m_value;
        }

        if (m_parsed_offsets.size() != typed->m_parsed_offsets.size()) { return false; }
        if (Empty() != typed->Empty()) { return false; }
        if (Empty()) { return true; }

        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= m_parsed_offsets.size(); ++i, ++it, ++typed_it) {
            auto diff = (*it) - (*typed_it);
            if (std::fabs(diff) > std::numeric_limits<double>::epsilon()) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool DS::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const DS*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value != typed->m_value;
        }

        if (m_parsed_offsets.size() != typed->m_parsed_offsets.size()) { return true; }
        if (Empty() != typed->Empty()) { return true; }
        if (Empty()) { return false; }

        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= m_parsed_offsets.size(); ++i, ++it, ++typed_it) {
            auto diff = (*it) - (*typed_it);
            if (std::fabs(diff) > std::numeric_limits<double>::epsilon()) { return true; }
        }

        return false;
    }

}