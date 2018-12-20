#include "dicom_pch.h"
#include "dicom/data/CS.h"

#include <numeric>

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/string_trim.h"
#include "dicom/data/detail/validate_separator_locations.h"
#include "dicom/data/detail/combine_strings.h"

using namespace std;

namespace dicom::data {

    CS::CS()
      : CS(string())
    {}

    //--------------------------------------------------------------------------------------------------------

    CS::CS(const char* value)
      : CS(string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    CS::CS(const string_view& value)
      : CS(string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    CS::CS(string&& value)
      : VR(VRType::CS),
        m_value(forward<string>(value))
    {
        detail::string_trim(m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    CS::CS(const vector<string_view>& values)
      : VR(VRType::CS)
    {
        detail::combine_strings(values, &m_value);
    }

	//--------------------------------------------------------------------------------------------------------

	CS::CS(initializer_list<string_view> values)
	  : VR(VRType::CS)
	{
        detail::combine_strings(values, &m_value);
	}

    //--------------------------------------------------------------------------------------------------------

    CS::CS(const CS& other) = default;
    CS::CS(CS&& other) = default;

    CS& CS::operator = (const CS& other) = default;
    CS& CS::operator = (CS&& other) = default;

    //--------------------------------------------------------------------------------------------------------

    CS::~CS() = default;

    //--------------------------------------------------------------------------------------------------------

    ValidityType CS::Validate() const {
        // Get the offsets for multiplicity markers
        vector<size_t> parsed_offsets;
        detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar);


        /*** Essential checks ***/
        // Check for invalid characters
        bool valid = all_of(
            m_value.begin(),
            m_value.end(),
            [=](char c) {
                return isupper(c) || isdigit(c) || (c == ' ') || (c == '_') || (c == detail::MultiplicityChar);
            }
        );
        if (!valid) { return ValidityType::Invalid; }

        m_parsed_offsets.swap(parsed_offsets);


		/*** Strict checks ***/
        // Values are not allowed to exceed 16 characters
        if (!detail::validate_separator_locations(m_value, m_parsed_offsets, 16)) {
            return ValidityType::Acceptable;
        }


		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t CS::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const CS*>(other);
        return m_value.compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool CS::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const CS*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool CS::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const CS*>(other);
        return m_value != typed->m_value;
    }

}