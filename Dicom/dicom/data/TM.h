#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/time.h"

namespace dicom::data {

    class DICOM_EXPORT TM : public VR
    {
    public:
        TM();
        TM(const char* value);
        TM(const std::string_view& value);
        TM(std::string&& value);
        TM(const time& duration);
        TM(const TM& other);
        TM(TM&& other);
        virtual ~TM();

        TM& operator = (const TM& other);
        TM& operator = (TM&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<TM>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }
        
        [[nodiscard]] const time& Parsed() const {
            AssertValidated();
            return m_parsed;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
        mutable time m_parsed;
    };

}