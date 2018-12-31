#pragma once

#include "dicom/data/encoded_string.h"
#include "dicom/data/ValidityType.h"
#include "dicom/data/detail/string_iterator.h"

namespace dicom::data {

    class DICOM_EXPORT ComponentGroup
    {
    public:
        using iterator = detail::substring_iterator<detail::trim_right>;

        //----------------------------------------------------------------------------------------------------

        ComponentGroup();
        ComponentGroup(const encoded_string& value);
        ComponentGroup(encoded_string&& value);
        ComponentGroup(const std::array<encoded_string, 5>& values);
        ComponentGroup(std::initializer_list<encoded_string> values);
        ComponentGroup(const ComponentGroup& other);
        ComponentGroup(ComponentGroup&& other);
        ~ComponentGroup();

        ComponentGroup& operator = (const ComponentGroup& other);
        ComponentGroup& operator = (ComponentGroup&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const { return m_value.Empty(); }
        [[nodiscard]] const encoded_string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] size_t ParsedCount() const {
            if (m_value.Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed_offsets.size() + 1;
        }

        [[nodiscard]] iterator ParsedBegin() const {
            AssertValid();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, 0);
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValid();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, ParsedCount());
        }

        [[nodiscard]] std::vector<std::string_view> Parsed() const {
            return std::vector<std::string_view>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] std::string_view First() const { return At(0); }
        [[nodiscard]] std::string_view At(size_t index) const {
            AssertValid();
            AssertNotEmpty();
            return *(iterator(&m_value.Parsed(), &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] std::string_view FamilyName() const;
        [[nodiscard]] std::string_view GivenName() const;
        [[nodiscard]] std::string_view MiddleName() const;
        [[nodiscard]] std::string_view Prefix() const;
        [[nodiscard]] std::string_view Suffix() const;

        [[nodiscard]] ValidityType Validity() const { return m_validity; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const ComponentGroup& other) const;
        [[nodiscard]] bool operator == (const ComponentGroup& other) const;
        [[nodiscard]] bool operator != (const ComponentGroup& other) const;

    private:
        ValidityType m_validity;
        encoded_string m_value;
        std::vector<size_t> m_parsed_offsets;

        ValidityType Validate();

        void AssertValid() const {
            if (m_validity != ValidityType::Acceptable && m_validity != ValidityType::Valid) {
                throw std::runtime_error("Parsed value is not valid");
            }
        }
        void AssertNotEmpty() const {
            if (m_value.Empty()) { throw std::out_of_range("Index is out of range"); }
        }
    };

}