#include "dicom_pch.h"
#include "dicom/data/ST.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

using namespace std;

namespace dicom::data {

    ST::ST()
      : ST(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    ST::ST(const encoded_string& value)
      : ST(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    ST::ST(encoded_string&& value)
      : VR(VRType::ST),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    ST::ST(const ST& other)
      : VR(other),
        m_value(other.m_value)
    {}

    //--------------------------------------------------------------------------------------------------------

    ST::ST(ST&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	ST::~ST() = default;

    //--------------------------------------------------------------------------------------------------------

    ST& ST::operator = (const ST& other) {
        VR::operator = (other);
        m_value = other.m_value;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ST& ST::operator = (ST&& other) {
        VR::operator = (forward<VR>(other));
        m_value = move(other.m_value);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType ST::Validate() const {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }
        auto& parsed = m_value.Parsed();

		/*** Essential checks ***/
		if (!detail::validate_default_character_repertoire(parsed)) { return ValidityType::Invalid; }

        /*** Strict checks ***/
        // Value is not allowed to exceed 1024 characters
        if (string_converter::detail::utf8_strlen(parsed) > 1024) { return ValidityType::Acceptable; }

		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t ST::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const ST*>(other);
        return m_value.Compare(typed->m_value);
    }

}