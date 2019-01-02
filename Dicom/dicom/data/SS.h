#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT SS : public VR
    {
    public:
        using value_type = int16_t;
        using buffer_type = buffer<int16_t>;

        //----------------------------------------------------------------------------------------------------

        SS();
        SS(const buffer<int16_t>& binary_value);
        SS(buffer<int16_t>&& binary_value);
        SS(int16_t value);
        SS(const std::vector<int16_t>& values);
        SS(std::initializer_list<int16_t> values);
        SS(const SS& other);
        SS(SS&& other);
        virtual ~SS();

        SS& operator = (const SS& other);
        SS& operator = (SS&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<SS>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<int16_t>& Value() const { return m_value; }
        [[nodiscard]] int16_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<int16_t> m_value;
    };

}