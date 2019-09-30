#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT UV : public VR
    {
    public:
        using value_type = uint64_t;
        using buffer_type = buffer<uint64_t>;

        //----------------------------------------------------------------------------------------------------

        UV();
        UV(const buffer<uint64_t>& binary_value);
        UV(buffer<uint64_t>&& binary_value);
        UV(uint64_t value);
        UV(const std::vector<uint64_t>& values);
        UV(std::initializer_list<uint64_t> values);
        UV(const UV& other);
        UV(UV&& other);
        virtual ~UV();

        UV& operator = (const UV& other);
        UV& operator = (UV&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UV>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<uint64_t>& Value() const { return m_value; }
        [[nodiscard]] uint64_t First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------
		
        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        buffer<uint64_t> m_value;
    };

}