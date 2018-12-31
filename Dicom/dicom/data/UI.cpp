#include "dicom_pch.h"
#include "dicom/data/UI.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/validate_separator_locations.h"
#include "dicom/data/detail/combine_strings.h"

namespace dicom::data {

    UI::UI()
      : UI(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(const char* value)
      : UI(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(const std::string_view& value)
      : UI(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(std::string&& value)
      : VR(VRType::UI),
        m_value(std::forward<std::string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(const std::vector<std::string_view>& values)
      : VR(VRType::UI)
    {
        detail::combine_strings(values, &m_value);
    }

	//--------------------------------------------------------------------------------------------------------

	UI::UI(std::initializer_list<std::string_view> values)
	  : VR(VRType::UI)
	{
        detail::combine_strings(values, &m_value);
	}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(const UI& other)
      : VR(other),
        m_value(other.m_value)
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::UI(UI&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UI::~UI() = default;

    //--------------------------------------------------------------------------------------------------------

    UI& UI::operator = (const UI& other) {
        VR::operator = (other);
        m_value = other.m_value;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UI& UI::operator = (UI&& other) {
        VR::operator = (std::forward<UI>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType UI::Validate() const {
        // Get the offsets for multiplicity markers
        std::vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);

        /*** Essential checks ***/
        // Empty values are not allowed
        if (parsed_offsets.empty()) {
            if (m_value.empty()) { return ValidityType::Invalid; }
        } else {
            size_t offset = 0;
            for (size_t i = 0; i < parsed_offsets.size(); ++i) {
                size_t length = parsed_offsets[i] - offset;
                if (length <= 1) { return ValidityType::Invalid; }
                offset = parsed_offsets[i];
            }
            if (m_value.size() - offset <= 1) { return ValidityType::Invalid; }
        }

        // Check for invalid characters
        bool valid = std::all_of(
            m_value.cbegin(),
            m_value.cend(),
            [](char c) { return isdigit(c) || c == '.' || c == detail::MultiplicityChar; }
        );
        if (!valid) { return ValidityType::Invalid; }

        // Check for missing digits (two periods in a row)
        if (m_value.find("..") != std::string::npos) { return ValidityType::Invalid; }

        m_parsed_offsets.swap(parsed_offsets);


        /*** Strict checks ***/
        // Value is not allowed to exceed 64 characters
        if (!detail::validate_separator_locations(m_value, m_parsed_offsets, 64)) {
            return ValidityType::Acceptable;
        }

        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UI::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UI*>(other);
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
            result = (*it).compare(*typed_it);
            if (result != 0) { return result; }
        }

        return int32_t(m_parsed_offsets.size()) - int32_t(typed->m_parsed_offsets.size());
    }

    //--------------------------------------------------------------------------------------------------------

    bool UI::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UI*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value == typed->m_value;
        }

        if (m_parsed_offsets.size() != typed->m_parsed_offsets.size()) { return false; }
        if (Empty() != typed->Empty()) { return false; }
        if (Empty()) { return true; }

        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= m_parsed_offsets.size(); ++i, ++it, ++typed_it) {
            if ((*it) != (*typed_it)) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UI::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UI*>(other);
        if (!IsValid() || !typed->IsValid()) {
            return m_value != typed->m_value;
        }

        if (m_parsed_offsets.size() != typed->m_parsed_offsets.size()) { return true; }
        if (Empty() != typed->Empty()) { return true; }
        if (Empty()) { return false; }

        auto it = ParsedBegin();
        auto typed_it = typed->ParsedBegin();
        for (size_t i = 0; i <= m_parsed_offsets.size(); ++i, ++it, ++typed_it) {
            if ((*it) != (*typed_it)) { return true; }
        }

        return false;
    }

}