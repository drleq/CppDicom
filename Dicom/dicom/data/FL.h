#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class FL : public VR
    {
    public:
        using value_type = float;
        using buffer_type = buffer<float>;

        //----------------------------------------------------------------------------------------------------

        FL();
        FL(const buffer<float>& binary_value);
        FL(buffer<float>&& binary_value);
        FL(float value);
        FL(const std::vector<float>& values);
        FL(std::initializer_list<float> values);
        FL(const FL& other);
        FL(FL&& other);
        virtual ~FL();

        FL& operator = (const FL& other);
        FL& operator = (FL&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<FL>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<float>& Value() const { return m_value; }
        [[nodiscard]] float First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<float> m_value;
    };

}