#pragma once

#include "dicom/data/VR.h"

namespace dicom::data {

    class AS : public VR
    {
    public:
        enum UnitType
        {
            Days,
            Weeks,
            Months,
            Years
        };

        //----------------------------------------------------------------------------------------------------

        AS();
        AS(const char* value);
        AS(const std::string_view& value);
        AS(std::string&& value);
        AS(int32_t age, UnitType units);
        AS(const AS& other);
        AS(AS&& other);
        virtual ~AS();

        AS& operator = (const AS& other);
        AS& operator = (AS&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<AS>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        [[nodiscard]] int32_t Age() const;
        [[nodiscard]] UnitType Units() const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
	};

}