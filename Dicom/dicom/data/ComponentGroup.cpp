#include "dicom_pch.h"
#include "dicom/data/ComponentGroup.h"

#include "dicom/data/detail/combine_strings.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/locate_separators.h"
#include "dicom/data/detail/validate_separator_locations.h"

using namespace std;

namespace {
    using namespace dicom::data;

    constexpr char ComponentGroupSeparator = 0x5E;
    constexpr wchar_t PatientNameGroupSeparator = 0x3D;
    constexpr wchar_t MultiplicitySeparator = dicom::data::detail::MultiplicityChar;

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
            *combined = encoded_string(std::string(), first->Encoding());
            return true;
        }
        Iter end = first + last_non_empty + 1;

        vector<encoded_string> parts(first, end);
        return detail::combine_strings(parts, ComponentGroupSeparator, combined);
    }
}

namespace dicom::data {

    ComponentGroup::ComponentGroup()
      : ComponentGroup(encoded_string())
    {}

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(const encoded_string& value)
      : ComponentGroup(encoded_string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(encoded_string&& value)
      : m_value(forward<encoded_string>(value))
    {
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(const array<encoded_string, 5>& values) {
        if (!combine_parts(values.cbegin(), values.cend(), &m_value)) {
            throw string_invalid_error();
        }
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(initializer_list<encoded_string> values) {
        if (!combine_parts(values.begin(), values.end(), &m_value)) {
            throw string_invalid_error();
        }
        m_validity = Validate();
    }

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(const ComponentGroup& other) = default;
    ComponentGroup& ComponentGroup::operator = (const ComponentGroup& other) = default;

    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::ComponentGroup(ComponentGroup&& other) {
        *this = std::forward<ComponentGroup>(other);
    }
    //--------------------------------------------------------------------------------------------------------

    ComponentGroup& ComponentGroup::operator = (ComponentGroup&& other) {
        m_validity = other.m_validity;
        m_value = std::move(other.m_value);
        m_parsed_offsets = std::move(other.m_parsed_offsets);
        other.m_validity = ValidityType::Deinitialized;
        return *this;
    }
    
    //--------------------------------------------------------------------------------------------------------

    ComponentGroup::~ComponentGroup() = default;
    
    //--------------------------------------------------------------------------------------------------------

    ValidityType ComponentGroup::Validate() {
        if (m_value.Validity() == ValidityType::Invalid) {
            return ValidityType::Invalid;
        }

        // Split the value in to components
        vector<size_t> parsed_offsets;
        if (!detail::locate_separators(parsed_offsets, m_value, ComponentGroupSeparator)) {
            return ValidityType::Invalid;
        }


        /*** Essential checks ***/
        if (parsed_offsets.size() > 5) { return ValidityType::Invalid; }

        // Check each component for invalid characters
        auto& parsed = m_value.Parsed();
        bool invalid = std::any_of(
            parsed.cbegin(),
            parsed.cend(),
            [=](wchar_t c) {
                return (c == 0x0A) || (c == 0x0C) || (c == 0x0D) ||
                    (c == PatientNameGroupSeparator) ||
                    (c == MultiplicitySeparator);
            }
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

    string_view ComponentGroup::FamilyName() const {
        if (Validity() == ValidityType::Invalid) { return string_view(); }
        return At(0);
    }

    //--------------------------------------------------------------------------------------------------------

    string_view ComponentGroup::GivenName() const {
        if (m_parsed_offsets.size() < 1) { return string_view(); }
        return At(1);
    }

    //--------------------------------------------------------------------------------------------------------

    string_view ComponentGroup::MiddleName() const {
        if (m_parsed_offsets.size() < 2) { return string_view(); }
        return At(2);
    }

    //--------------------------------------------------------------------------------------------------------

    string_view ComponentGroup::Prefix() const {
        if (m_parsed_offsets.size() < 3) { return string_view(); }
        return At(3);
    }

    //--------------------------------------------------------------------------------------------------------

    string_view ComponentGroup::Suffix() const {
        if (m_parsed_offsets.size() < 4) { return string_view(); }
        return At(4);
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t ComponentGroup::Compare(const ComponentGroup& other) const {
        return m_value.Compare(other.m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool ComponentGroup::operator == (const ComponentGroup& other) const {
        return m_value == other.m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool ComponentGroup::operator != (const ComponentGroup& other) const {
        return m_value != other.m_value;
    }

}