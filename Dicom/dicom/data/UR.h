#pragma once

#include "dicom/data/uri.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class UR : public VR
    {
    public:
        UR();
        UR(const uri& value);
        UR(uri&& value);
        UR(const UR& other);
        UR(UR&& other);
        virtual ~UR();

        UR& operator = (const UR& other);
        UR& operator = (UR&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Value().empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UR>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const uri& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        uri m_value;
	};

}