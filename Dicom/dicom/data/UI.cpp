#include "dicom_pch.h"
#include "dicom/data/UI.h"

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
        /*** Essential checks ***/
        // Empty values are not allowed
        if (m_value.empty()) { return ValidityType::Invalid; }

        // Check for invalid characters
        bool valid = std::all_of(
            m_value.cbegin(),
            m_value.cend(),
            [](char c) { return isdigit(c) || c == '.'; }
        );
        if (!valid) { return ValidityType::Invalid; }

        // Check for missing digits (two periods in a row)
        if (m_value.find("..") != std::string::npos) { return ValidityType::Invalid; }


        /*** Strict checks ***/
        // Value is not allowed to exceed 64 characters
        if (m_value.size() > 64) { return ValidityType::Acceptable; }

        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UI::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UI*>(other);
        return m_value.compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool UI::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UI*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UI::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UI*>(other);
        return m_value != typed->m_value;
    }

}