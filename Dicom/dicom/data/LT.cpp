#include "dicom_pch.h"
#include "dicom/data/LT.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

using namespace std;

namespace dicom::data {

    LT::LT()
      : LT(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    LT::LT(const encoded_string& value)
      : LT(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    LT::LT(encoded_string&& value)
      : VR(VRType::LT),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    LT::LT(const LT& other)
      : VR(other),
        m_value(other.m_value)
    {}

    //--------------------------------------------------------------------------------------------------------

    LT::LT(LT&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	LT::~LT() = default;

    //--------------------------------------------------------------------------------------------------------

    LT& LT::operator = (const LT& other) {
        VR::operator = (other);
        m_value = other.m_value;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    LT& LT::operator = (LT&& other) {
        VR::operator = (forward<VR>(other));
        m_value = move(other.m_value);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType LT::Validate() const {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }
        auto& parsed = m_value.Parsed();

		/*** Essential checks ***/
		if (!detail::validate_default_character_repertoire(parsed)) { return ValidityType::Invalid; }

        /*** Strict checks ***/
        // Value is not allowed to exceed 10240 characters
        if (string_converter::detail::utf8_strlen(parsed) > 10240) { return ValidityType::Acceptable; }

		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t LT::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const LT*>(other);
        return m_value.Compare(typed->m_value);
    }

}