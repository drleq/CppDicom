#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/detail/string_iterator.h"
#include "dicom/data/detail/string_to_double.h"

namespace dicom::data {

    class DS : public VR
    {
    public:
        using iterator = detail::string_iterator<double, detail::string_to_double, detail::trim_left>;

        //----------------------------------------------------------------------------------------------------

        DS();
        DS(const char* value);
        DS(const std::string_view& value);
        DS(std::string&& value);
        DS(double value);
        DS(const std::vector<double>& values);
        DS(std::initializer_list<double> values);
        DS(const DS& other);
        DS(DS&& other);
        virtual ~DS();

        DS& operator = (const DS& other);
        DS& operator = (DS&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<DS>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] size_t ParsedCount() const {
            if (Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed_offsets.size() + 1;
        }

        [[nodiscard]] iterator ParsedBegin() const {
            AssertValidated();
            return iterator(&m_value, &m_parsed_offsets, 0);
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValidated();
            return iterator(&m_value, &m_parsed_offsets, ParsedCount());
        }

        [[nodiscard]] std::vector<double> Parsed() const {
            return std::vector<double>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] double First() const { return At(0); }
        [[nodiscard]] double At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return *(iterator(&m_value, &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
        mutable std::vector<size_t> m_parsed_offsets;
    };

    // STL ADL functions
    inline auto begin(const DS& x) { return x.ParsedBegin(); }
    inline auto end(const DS& x) { return x.ParsedEnd(); }

}