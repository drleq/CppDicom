#include "dicom_pch.h"
#include "dicom/data/PatientNameGroup.h"

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/string_trim.h"

using namespace std;

namespace {
    using namespace dicom::data;

    constexpr char PatientNameGroupSeparator = 0x3D;

    //--------------------------------------------------------------------------------------------------------

    template <typename Iter>
    [[nodiscard]] bool combine_parts(Iter first, Iter last, encoded_string* combined) {
        if (first == last) {
            *combined = encoded_string();
            return true;
        }

        // Find the last non-empty value so we can minimize the size.
        int last_non_empty = -1;
        int i = 0;
        for (Iter it = first; it != last; ++it, ++i) {
            if (!it->Empty()) { last_non_empty = i; }
        }

        if (last_non_empty == -1) {
            // All strings are empty. Simply return empty.
            *combined = encoded_string(std::string(), first->Value().Encoding());
            return true;
        }
        Iter end = first + last_non_empty + 1;

        vector<encoded_string> parts;
        for (auto it = first; it != end; ++it) {
            parts.emplace_back(it->Value());
        }
        return detail::combine_strings(parts, PatientNameGroupSeparator, combined);
    }
}

namespace dicom::data {

    PatientNameGroup::PatientNameGroup()
      : PatientNameGroup(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(const encoded_string& value)
      : PatientNameGroup(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(encoded_string&& value)
      : m_value(forward<encoded_string>(value))
    {
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(const array<ComponentGroup, 3>& values) {
        if (!combine_parts(values.cbegin(), values.cend(), &m_value)) {
            throw string_invalid_error();
        }
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(initializer_list<ComponentGroup> values) {
        if (!combine_parts(values.begin(), values.end(), &m_value)) {
            throw string_invalid_error();
        }
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(const PatientNameGroup& other)
      : m_validity(other.m_validity),
        m_value(other.m_value),
        m_parsed_offsets(other.m_parsed_offsets)
    {}

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::PatientNameGroup(PatientNameGroup&& other)
      : m_validity(other.m_validity),
        m_value(move(other.m_value)),
        m_parsed_offsets(move(other.m_parsed_offsets))
    {
        other.m_validity = ValidityType::Deinitialized;
    }

    //--------------------------------------------------------------------------------------------------------

    PatientNameGroup::~PatientNameGroup() = default;

    //--------------------------------------------------------------------------------------------------------

    ValidityType PatientNameGroup::Validate() {
        // Split the value in to components
        vector<size_t> parsed_offsets;
        if (!detail::locate_separators(parsed_offsets, m_value, PatientNameGroupSeparator)) {
            return ValidityType::Invalid;
        }


        /*** Essential checks ***/
        if (parsed_offsets.size() > 5) { return ValidityType::Invalid; }

        // Check each component for invalid characters
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

    ComponentGroup PatientNameGroup::Alphabetic() const {
        if (Validity() == ValidityType::Invalid) { return ComponentGroup(); }
        return At(0);
    }

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup PatientNameGroup::Ideographic() const {
        if (m_parsed_offsets.size() < 1) { return ComponentGroup(); }
        return At(1);
    }

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup PatientNameGroup::Phonetic() const {
        if (m_parsed_offsets.size() < 2) { return ComponentGroup(); }
        return At(2);
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t PatientNameGroup::Compare(const PatientNameGroup& other) const {
        if (m_parsed_offsets.empty() || other.m_parsed_offsets.empty()) {
            return m_value.Compare(other.m_value);
        }

        auto cmp_len = min(m_parsed_offsets.size(), other.m_parsed_offsets.size());
        auto it = ParsedBegin();
        auto typed_it = other.ParsedBegin();
        for (size_t i = 0; i < cmp_len; ++i, ++it, ++typed_it) {
            auto diff = (*it).Compare(*typed_it);
            if (diff) { return diff; }
        }

        return int32_t(m_parsed_offsets.size()) - int32_t(other.m_parsed_offsets.size());
    }

    //--------------------------------------------------------------------------------------------------------

    bool PatientNameGroup::operator == (const PatientNameGroup& other) const {
        if (m_parsed_offsets.empty() || other.m_parsed_offsets.empty()) {
            return m_value.Compare(other.m_value) == 0;
        }

        if (m_parsed_offsets.size() != other.m_parsed_offsets.size()) { return false; }

        auto it = ParsedBegin();
        auto typed_it = other.ParsedBegin();
        for (size_t i = 0; i < m_parsed_offsets.size(); i++) {
            auto diff = (*it) != (*typed_it);
            if (diff) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool PatientNameGroup::operator != (const PatientNameGroup& other) const {
        if (m_parsed_offsets.empty() || other.m_parsed_offsets.empty()) {
            return m_value.Compare(other.m_value) != 0;
        }

        if (m_parsed_offsets.size() != other.m_parsed_offsets.size()) { return true; }

        auto it = ParsedBegin();
        auto typed_it = other.ParsedBegin();
        for (size_t i = 0; i < m_parsed_offsets.size(); i++) {
            auto diff = (*it) != (*typed_it);
            if (diff) { return true; }
        }

        return false;
    }

}