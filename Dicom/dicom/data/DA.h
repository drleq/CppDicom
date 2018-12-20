#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/date.h"

namespace dicom::data {

    class DA : public VR
    {
    public:
        using container_type = std::vector<date>;
        using iterator = container_type::const_iterator;

        //----------------------------------------------------------------------------------------------------

        DA();
        DA(const char* value);
        DA(const std::string_view& value);
        DA(std::string&& value);
        DA(const std::vector<std::string_view>& values);
        DA(std::initializer_list<std::string_view> values);

        DA(const date& value);
        DA(const std::vector<date>& values);
        DA(std::initializer_list<date> values);

        DA(const DA& other);
        DA(DA&& other);
        virtual ~DA();

        DA& operator = (const DA& other);
        DA& operator = (DA&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<DA>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] size_t ParsedCount() const {
            if (Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed.size();
        }

        [[nodiscard]] iterator ParsedBegin() const {
            AssertValidated();
            return m_parsed.cbegin();
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValidated();
            return m_parsed.cend();
        }

        [[nodiscard]] const std::vector<date>& Parsed() const {
            AssertValidated();
            return m_parsed;
        }

        [[nodiscard]] const date& First() const { return At(0); }
        [[nodiscard]] const date& At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return m_parsed[index];
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
        mutable container_type m_parsed;
    };

}