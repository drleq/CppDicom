#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT SV : public VR
    {
    public:
        using value_type = int64_t;
        using buffer_type = buffer<int64_t>;

        //----------------------------------------------------------------------------------------------------

        SV();
        SV(const buffer<int64_t>& binary_value);
        SV(buffer<int64_t>&& binary_value);
        SV(int64_t value);
        SV(const std::vector<int64_t>& values);
        SV(std::initializer_list<int64_t> values);
        SV(const SV& other);
        SV(SV&& other);
        virtual ~SV();

        SV& operator = (const SV& other);
        SV& operator = (SV&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<SV>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<int64_t>& Value() const { return m_value; }
        [[nodiscard]] int64_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<int64_t> m_value;
    };

}