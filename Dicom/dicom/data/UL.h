#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class UL : public VR
    {
    public:
        using value_type = uint32_t;
        using buffer_type = buffer<uint32_t>;

        //----------------------------------------------------------------------------------------------------

        UL();
        UL(const buffer<uint32_t>& binary_value);
        UL(buffer<uint32_t>&& binary_value);
        UL(uint32_t value);
        UL(const std::vector<uint32_t>& values);
        UL(std::initializer_list<uint32_t> values);
        UL(const UL& other);
        UL(UL&& other);
        virtual ~UL();

        UL& operator = (const UL& other);
        UL& operator = (UL&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UL>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<uint32_t>& Value() const { return m_value; }
        [[nodiscard]] uint32_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------
		
        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<uint32_t> m_value;
    };

}