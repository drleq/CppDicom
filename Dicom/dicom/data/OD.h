#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class OD : public VR
	{
	public:
        using value_type = double;
        using buffer_type = buffer<double>;

        //----------------------------------------------------------------------------------------------------

        OD();
        OD(const buffer<double>& binary_value);
		OD(buffer<double>&& binary_value);
        OD(const OD& other);
        OD(OD&& other);
		virtual ~OD();

        OD& operator = (const OD& other);
        OD& operator = (OD&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<OD>(*this); }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] const buffer<double>& Value() const { return m_value; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;
		
	private:
		buffer<double> m_value;
	};

}