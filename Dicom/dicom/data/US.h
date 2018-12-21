#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class US : public VR
    {
    public:
        using value_type = uint16_t;
        using buffer_type = buffer<uint16_t>;

        //----------------------------------------------------------------------------------------------------

        US();
        US(const buffer<uint16_t>& binary_value);
        US(buffer<uint16_t>&& binary_value);
        US(uint16_t value);
        US(const std::vector<uint16_t>& values);
        US(std::initializer_list<uint16_t> values);
        US(const US& other);
        US(US&& other);
        virtual ~US();

        US& operator = (const US& other);
        US& operator = (US&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<US>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<uint16_t>& Value() const { return m_value; }
        [[nodiscard]] uint16_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<uint16_t> m_value;
    };

}