#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT OB : public VR
	{
	public:
        using value_type = int8_t;
        using buffer_type = buffer<int8_t>;

        //----------------------------------------------------------------------------------------------------

        OB();
        OB(const buffer<int8_t>& binary_value);
		OB(buffer<int8_t>&& binary_value);
        OB(const OB& other);
        OB(OB&& other);
		virtual ~OB();

        OB& operator = (const OB& other);
        OB& operator = (OB&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OB>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<int8_t>& Value() const { return m_value; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

	private:
		buffer<int8_t> m_value;
	};

}