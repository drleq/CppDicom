#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class SL : public VR
    {
    public:
        using value_type = int32_t;
        using buffer_type = buffer<int32_t>;

        //----------------------------------------------------------------------------------------------------

        SL();
        SL(const buffer<int32_t>& binary_value);
        SL(buffer<int32_t>&& binary_value);
        SL(int32_t value);
        SL(const std::vector<int32_t>& values);
        SL(std::initializer_list<int32_t> values);
        SL(const SL& other);
        SL(SL&& other);
        virtual ~SL();

        SL& operator = (const SL& other);
        SL& operator = (SL&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<SL>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<int32_t>& Value() const { return m_value; }
        [[nodiscard]] int32_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<int32_t> m_value;
    };

}