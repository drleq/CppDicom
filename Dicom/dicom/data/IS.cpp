#include "dicom_pch.h"
#include "dicom/data/IS.h"

#include "dicom/data/detail/atoi.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"
#include "dicom/data/detail/validate_separator_locations.h"

#include <sstream>

namespace {
    using namespace dicom::data::detail;

    // Define a checked iterator to help validate the value string
    using checked_iterator = string_iterator<int32_t, checked_string_to_int<int32_t>, trim_left>;
}

namespace dicom::data {

    IS::IS()
      : IS(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

	IS::IS(const char* value)
      : IS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

	IS::IS(const std::string_view& value)
      : IS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    IS::IS(std::string&& value)
      : VR(VRType::IS),
        m_value(std::forward<std::string>(value))
    {
        detail::string_trim(m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    IS::IS(int32_t value)
      : VR(VRType::IS),
        m_value(std::to_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    IS::IS(const std::vector<int32_t>& value)
      : VR(VRType::IS)
    {
        std::ostringstream ss;
        for (size_t i = 0; i < value.size(); i++) {
            ss << value[i];
            if (i != value.size() - 1) { ss << detail::MultiplicityChar; }
        }
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    IS::IS(std::initializer_list<int32_t> values)
      : VR(VRType::IS)
    {
        std::ostringstream ss;

        size_t i = 0;
        for (int32_t v : values) {
            ss << v;
            if (i != values.size() - 1) { ss << detail::MultiplicityChar; }
            ++i;
        }
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    IS::IS(const IS& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    IS::IS(IS&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value)),
        m_parsed_offsets(std::move(other.m_parsed_offsets))
    {}

	//--------------------------------------------------------------------------------------------------------

	IS::~IS() = default;

    //--------------------------------------------------------------------------------------------------------

    IS& IS::operator = (const IS& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    IS& IS::operator = (IS&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed_offsets = std::move(other.m_parsed_offsets);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType IS::Validate() const {
        // Get the offsets for multiplicity markers
        std::vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);


		/*** Essential checks ***/
        // Use a checked iterator to validate the values
        checked_iterator it(&m_value, &parsed_offsets, 0);
        checked_iterator end_it(&m_value, &parsed_offsets, parsed_offsets.size() + 1);
        for (; it != end_it; ++it) {
            errno = 0;
            int dummy = *it;
            (void)dummy;
            if (errno != 0) {
                // This will trigger if m_value is empty. Check for that.
                if (parsed_offsets.empty()) {
                    auto offset = m_value.find_first_not_of(' ');
                    if (offset == std::string::npos) { return ValidityType::Valid; }
                }
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

    int32_t IS::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const IS*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value.compare(typed->m_value);
        }

        bool empty = Empty();
        bool typed_empty = Empty();
        if (empty != typed_empty) { return empty ? -1 : 1; }
        if (empty) { return 0; }

        auto cmp_len = std::min(m_parsed_offsets.size(), typed->m_parsed_offsets.size());
        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= cmp_len; ++i, ++it, ++typed_it) {
            auto diff = (*it) - (*typed_it);
            if (diff) { return diff; }
        }

        return int32_t(m_parsed_offsets.size()) - int32_t(typed->m_parsed_offsets.size());
    }

    //--------------------------------------------------------------------------------------------------------

    bool IS::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const IS*>(other);
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
            if (diff) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool IS::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const IS*>(other);
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
            if (diff) { return true; }
        }

        return false;
    }

}