#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT OV : public VR
	{
	public:
        using value_type = int64_t;
        using buffer_type = buffer<int64_t>;

        //----------------------------------------------------------------------------------------------------

        OV();
        OV(const buffer<int64_t>& binary_value);
		OV(buffer<int64_t>&& binary_value);
        OV(const OV& other);
        OV(OV&& other);
		virtual ~OV();

        OV& operator = (const OV& other);
        OV& operator = (OV&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OV>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<int64_t>& Value() const { return m_value; }
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