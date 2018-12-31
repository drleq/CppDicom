#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT OF : public VR
	{
	public:
        using value_type = float;
        using buffer_type = buffer<float>;

        //----------------------------------------------------------------------------------------------------

        OF();
        OF(const buffer<float>& binary_value);
		OF(buffer<float>&& binary_value);
        OF(const OF& other);
        OF(OF&& other);
		virtual ~OF();

        OF& operator = (const OF& other);
        OF& operator = (OF&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OF>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<float>& Value() const { return m_value; }
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