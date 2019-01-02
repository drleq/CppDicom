#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT OW : public VR
	{
	public:
        using value_type = int16_t;
        using buffer_type = buffer<int16_t>;

        //----------------------------------------------------------------------------------------------------

        OW();
        OW(const buffer<int16_t>& binary_value);
		OW(buffer<int16_t>&& binary_value);
        OW(const OW& other);
        OW(OW&& other);
		virtual ~OW();

        OW& operator = (const OW& other);
        OW& operator = (OW&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OW>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<int16_t>& Value() const { return m_value; }
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