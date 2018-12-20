#include "dicom_pch.h"
#include "dicom/data/AE.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"

namespace dicom::data {

    AE::AE()
      : AE(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    AE::AE(const char* value)
      : AE(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    AE::AE(const std::string_view& value)
      : AE(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    AE::AE(std::string&& value)
      : VR(VRType::AE),
        m_value(std::forward<std::string>(value))
    {
        detail::string_trim(m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    AE::AE(const AE& other) = default;
    AE::AE(AE&& other) = default;

    AE& AE::operator = (const AE& other) = default;
    AE& AE::operator = (AE&& other) = default;

    //--------------------------------------------------------------------------------------------------------

    AE::~AE() = default;

    //--------------------------------------------------------------------------------------------------------

    ValidityType AE::Validate() const {
        /*** Essential checks ***/
        // Value can not be empty
        if (m_value.empty()) { return ValidityType::Invalid; }

        // Value must be in the default character repertoire
        if (!detail::validate_default_character_repertoire(m_value)) { return ValidityType::Invalid; }

        // Value can not contain the multiplicity character
        if (m_value.find(detail::MultiplicityChar) != std::string::npos) { return ValidityType::Invalid; }


		/*** Strict checks ***/
		// Value can not exceed 16 characters
        if (m_value.size() > 16) { return ValidityType::Acceptable; }


        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t AE::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const AE*>(other);
        return m_value.compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool AE::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const AE*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool AE::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const AE*>(other);
        return m_value != typed->m_value;
    }

}