#include "dicom_pch.h"
#include "dicom/data/PN.h"

#include <numeric>

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"

using namespace std;

namespace {
    using namespace dicom::data;

    template <typename TIter>
    [[nodiscard]] bool combine_values(TIter begin, TIter end, encoded_string* dest) {
        vector<encoded_string> parts;
        for (auto it = begin; it != end; ++it) {
            parts.emplace_back(it->Value());
        }
        return detail::combine_strings(parts, dest);
    }
}

namespace dicom::data {

    PN::PN()
      : PN(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::PN(const encoded_string& value)
      : PN(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::PN(encoded_string&& value)
      : VR(VRType::PN),
        m_value(forward<encoded_string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::PN(const PatientNameGroup& value)
      : VR(VRType::PN),
        m_value(value.Value())
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::PN(const vector<PatientNameGroup>& values)
      : VR(VRType::PN)
    {
        if (!combine_values(values.begin(), values.end(), &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    PN::PN(initializer_list<PatientNameGroup> values)
      : VR(VRType::PN)
    {
        if (!combine_values(values.begin(), values.end(), &m_value)) {
            throw string_invalid_error();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    PN::PN(const PN& other)
      : VR(other),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::PN(PN&& other)
      : VR(forward<VR>(other)),
        m_value(move(other.m_value)),
        m_parsed_offsets(move(other.m_parsed_offsets))
    {}

    //--------------------------------------------------------------------------------------------------------

    PN::~PN() = default;

    //--------------------------------------------------------------------------------------------------------

    PN& PN::operator = (const PN& other) {
        VR::operator = (other);
        m_value = other.m_value;
        m_parsed_offsets = other.m_parsed_offsets;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    PN& PN::operator = (PN&& other) {
        VR::operator = (forward<VR>(other));
        m_value = move(other.m_value);
        m_parsed_offsets = move(other.m_parsed_offsets);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType PN::Validate() const {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }

        // Get the offsets for multiplicity markers
        vector<size_t> parsed_offsets;
        if (!detail::locate_separators(parsed_offsets, m_value, detail::MultiplicityChar)) {
            return ValidityType::Invalid;
        }

        /*** Essential checks ***/
        ValidityType overall_validity = ValidityType::Valid;
        iterator it(&m_value.Parsed(), &parsed_offsets, 0);
        iterator end_it(&m_value.Parsed(), &parsed_offsets, parsed_offsets.size() + 1);
        for (; it != end_it; ++it) {
            auto validity = (*it).Validity();
            switch (validity) {
            case ValidityType::Acceptable:
                overall_validity = ValidityType::Acceptable;
                break;

            case ValidityType::Valid:
                break;

            case ValidityType::Uninitialized:
            case ValidityType::Deinitialized:
            case ValidityType::Invalid:
            default:
                return ValidityType::Invalid;
            }
        }

        m_parsed_offsets.swap(parsed_offsets);


        /*** Strict checks ***/
        if (overall_validity == ValidityType::Acceptable) { return ValidityType::Acceptable; }


        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t PN::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const PN*>(other);
        return m_value.Compare(typed->m_value);
    }

}