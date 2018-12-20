#include "dicom_pch.h"
#include "dicom/data/UC.h"

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"

using namespace std;

namespace dicom::data {

    UC::UC()
      : UC(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    UC::UC(const encoded_string& value)
      : UC(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UC::UC(encoded_string&& value)
      : VR(VRType::UC),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UC::UC(const vector<encoded_string>& values)
      : VR(VRType::UC)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UC::UC(initializer_list<encoded_string> values)
      : VR(VRType::UC)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UC::UC(const UC& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    UC::UC(UC&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value)),
        m_parsed_offsets(move(other.m_parsed_offsets))
    {}

	//--------------------------------------------------------------------------------------------------------

    UC::~UC() = default;

    //--------------------------------------------------------------------------------------------------------

    UC& UC::operator = (const UC& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UC& UC::operator = (UC&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed_offsets = std::move(other.m_parsed_offsets);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType UC::Validate() const {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }


        // Get the offsets for multiplicity markers
        vector<size_t> parsed_offsets;
        if (!detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar)) {
            return ValidityType::Invalid;
        }


		/*** Essential checks ***/
		// Check for invalid characters
        if (!detail::validate_excludes_control_characters(m_value.Parsed())) {
            return ValidityType::Invalid;
        }


        m_parsed_offsets.swap(parsed_offsets);


		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UC::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UC*>(other);
        return m_value.Compare(typed->m_value);
    }

}