#pragma once

#include "dicom/data/VR.h"

namespace dicom::data {

    class AE : public VR
    {
    public:
        AE();
        AE(const char* value);
        AE(const std::string_view& value);
        AE(std::string&& value);
        AE(const AE& other);
        AE(AE&& other);
        virtual ~AE();

        AE& operator = (const AE& other);
        AE& operator = (AE&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<AE>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

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