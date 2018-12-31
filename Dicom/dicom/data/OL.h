#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT OL : public VR
	{
	public:
        using value_type = int32_t;
        using buffer_type = buffer<int32_t>;

        //----------------------------------------------------------------------------------------------------

        OL();
        OL(const buffer<int32_t>& binary_value);
		OL(buffer<int32_t>&& binary_value);
        OL(const OL& other);
        OL(OL&& other);
		virtual ~OL();

        OL& operator = (const OL& other);
        OL& operator = (OL&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OL>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<int32_t>& Value() const { return m_value; }
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