#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

	class DICOM_EXPORT UN : public VR
	{
	public:
        using value_type = int8_t;
        using buffer_type = buffer<int8_t>;

        //----------------------------------------------------------------------------------------------------

        UN();
        UN(const buffer<int8_t>& binary_value);
		UN(buffer<int8_t>&& binary_value);
        UN(const UN& other);
        UN(UN&& other);
		virtual ~UN();

        UN& operator = (const UN& other);
        UN& operator = (UN&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UN>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<int8_t>& Value() const { return m_value; }

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