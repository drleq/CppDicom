#include "dicom_pch.h"
#include "dicom/data/LO.h"

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/validate_separator_locations.h"

using namespace std;

namespace dicom::data {

    LO::LO()
      : LO(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    LO::LO(const encoded_string& value)
      : LO(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    LO::LO(encoded_string&& value)
      : VR(VRType::LO),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    LO::LO(const vector<encoded_string>& values)
      : VR(VRType::LO)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    LO::LO(initializer_list<encoded_string> values)
      : VR(VRType::LO)
    {
        if (!detail::combine_strings(values, &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    LO::LO(const LO& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    LO::LO(LO&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value)),
        m_parsed_offsets(move(other.m_parsed_offsets))
    {}

	//--------------------------------------------------------------------------------------------------------

	LO::~LO() = default;

    //--------------------------------------------------------------------------------------------------------

    LO& LO::operator = (const LO& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    LO& LO::operator = (LO&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        m_parsed_offsets = std::move(other.m_parsed_offsets);
        return *this;
    }

	//--------------------------------------------------------------------------------------------------------

	ValidityType LO::Validate() const {
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
        // Values are not allowed to exceed 64 characters
        if (!detail::validate_separator_locations(parsed, m_parsed_offsets, 64)) {
            return ValidityType::Acceptable;
        }


		return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t LO::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const LO*>(other);
        return m_value.Compare(typed->m_value);
    }

}