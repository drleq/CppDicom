#include "dicom_pch.h"
#include "dicom/data/SH.h"

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/validate_separator_locations.h"

using namespace std;

namespace dicom::data {

    SH::SH()
      : SH(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    SH::SH(const encoded_string& value)
      : SH(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    SH::SH(encoded_string&& value)
      : VR(VRType::SH),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    SH::SH(const vector<encoded_string>& values)
      : VR(VRType::SH)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SH::SH(initializer_list<encoded_string> values)
      : VR(VRType::SH)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SH::SH(const SH& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    SH::SH(SH&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value)),
        m_parsed_offsets(move(other.m_parsed_offsets))
    {}

	//--------------------------------------------------------------------------------------------------------

	SH::~SH() = default;

    //--------------------------------------------------------------------------------------------------------

    SH& SH::operator = (const SH& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    SH& SH::operator = (SH&& other) {
        VR::operator = (forward<VR>(other));
        m_value = move(other.m_value);
        m_parsed_offsets = move(other.m_parsed_offsets);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType SH::Validate() const {
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
        auto& parsed = m_value.Parsed();
        bool invalid = any_of(
            parsed.cbegin(),
            parsed.cend(),
            [](wchar_t c) { return (c == 0x0A) || (c == 0x0C) || (c == 0x0D); }
        );
        if (invalid) { return ValidityType::Invalid; }

        m_parsed_offsets.swap(parsed_offsets);


        /*** Strict checks ***/
        // Values are not allowed to exceed 16 characters
        if (!detail::validate_separator_locations(parsed, m_parsed_offsets, 16)) {
            return ValidityType::Acceptable;
        }


        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t SH::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const SH*>(other);
        return m_value.Compare(typed->m_value);
    }

}