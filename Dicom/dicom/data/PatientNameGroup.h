#pragma once

#include "dicom/data/ComponentGroup.h"
#include "dicom/data/ValidityType.h"
#include "dicom/data/detail/string_iterator.h"

namespace dicom::data {

    class PatientNameGroup
    {
    public:
        struct string_to_component_group {
            static ComponentGroup Convert(const std::string_view& str) {
                return ComponentGroup(str);
            }
        };
        using iterator = detail::string_iterator<ComponentGroup, string_to_component_group, detail::trim_none>;

        //----------------------------------------------------------------------------------------------------

        PatientNameGroup();
        PatientNameGroup(const encoded_string& value);
        PatientNameGroup(encoded_string&& value);
        
        PatientNameGroup(const std::array<ComponentGroup, 3>& values);
        PatientNameGroup(std::initializer_list<ComponentGroup> values);

        PatientNameGroup(const PatientNameGroup& other);
        PatientNameGroup(PatientNameGroup&& other);
        virtual ~PatientNameGroup();

        PatientNameGroup& operator = (const PatientNameGroup& other);
        PatientNameGroup& operator = (PatientNameGroup&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const { return m_value.Empty(); }
        [[nodiscard]] const encoded_string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] size_t ParsedCount() const {
            if (Validity() == ValidityType::Invalid || Empty()) { return 0; }
            return m_parsed_offsets.size() + 1;
        }

        [[nodiscard]] iterator ParsedBegin() const { return iterator(&m_value.Parsed(), &m_parsed_offsets, 0); }
        [[nodiscard]] iterator ParsedEnd() const { return iterator(&m_value.Parsed(), &m_parsed_offsets, ParsedCount()); }

        [[nodiscard]] std::vector<ComponentGroup> Parsed() const {
            return std::vector<ComponentGroup>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] ComponentGroup First() const { return *ParsedBegin(); }

        [[nodiscard]] ComponentGroup At(size_t index) const {
            return *(iterator(&m_value.Parsed(), &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] ComponentGroup Alphabetic() const;
        [[nodiscard]] ComponentGroup Ideographic() const;
        [[nodiscard]] ComponentGroup Phonetic() const;

        [[nodiscard]] ValidityType Validity() const { return m_validity; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const PatientNameGroup& other) const;
        [[nodiscard]] bool operator == (const PatientNameGroup& other) const;
        [[nodiscard]] bool operator != (const PatientNameGroup& other) const;

        [[nodiscard]] bool operator <  (const PatientNameGroup& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const PatientNameGroup& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const PatientNameGroup& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const PatientNameGroup& other) const { return Compare(other) >= 0; }

    private:
        ValidityType m_validity;
        encoded_string m_value;
        std::vector<size_t> m_parsed_offsets;

        ValidityType Validate();
    };

}