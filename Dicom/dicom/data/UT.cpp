#include "dicom_pch.h"
#include "dicom/data/UT.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"

using namespace std;

namespace dicom::data {

    UT::UT()
      : UT(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    UT::UT(const encoded_string& value)
      : UT(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

	UT::UT(encoded_string&& value)
	  : VR(VRType::UT),
        m_value(forward<encoded_string>(value))
	{}

    //--------------------------------------------------------------------------------------------------------

    UT::UT(const UT& other)
      : VR(other),
        m_value(other.m_value)
    {}

    //--------------------------------------------------------------------------------------------------------

    UT::UT(UT&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	UT::~UT() = default;

    //--------------------------------------------------------------------------------------------------------

    UT& UT::operator = (const UT& other) {
        VR::operator = (other);
        m_value = other.m_value;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UT& UT::operator = (UT&& other) {
        VR::operator = (forward<VR>(other));
        m_value = move(other.m_value);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType UT::Validate() const {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }

		/*** Essential checks ***/
		if (!detail::validate_default_character_repertoire(m_value.Parsed())) { return ValidityType::Invalid; }

        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UT::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UT*>(other);
        return m_value.Compare(typed->m_value);
    }

}