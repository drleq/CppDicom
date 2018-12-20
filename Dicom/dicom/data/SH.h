#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/encoded_string.h"
#include "dicom/data/detail/string_iterator.h"

namespace dicom::data {

    class SH : public VR
    {
    public:
        using iterator = detail::substring_iterator<detail::trim_left_right>;

        //----------------------------------------------------------------------------------------------------

        SH();
        SH(const encoded_string& value);
        SH(encoded_string&& value);
        SH(const std::vector<encoded_string>& values);
        SH(std::initializer_list<encoded_string> values);
        SH(const SH& other);
        SH(SH&& other);
        virtual ~SH();

        SH& operator = (const SH& other);
        SH& operator = (SH&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<SH>(*this); }

        [[nodiscard]] const encoded_string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& ParsedValue() const {
            AssertValidated();
            return m_value.Parsed();
        }

        [[nodiscard]] size_t ParsedCount() const {
            if (Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed_offsets.size() + 1;
        }

        [[nodiscard]] iterator ParsedBegin() const {
            AssertValidated();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, 0);
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValidated();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, ParsedCount());
        }

        [[nodiscard]] std::vector<std::string_view> Parsed() const {
            return std::vector<std::string_view>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] std::string_view First() const { return At(0); }

        [[nodiscard]] std::string_view At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return *(iterator(&m_value.Parsed(), &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        encoded_string m_value;
        mutable std::vector<size_t> m_parsed_offsets;
    };

}