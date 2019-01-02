#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/encoded_string.h"

namespace dicom::data {

	class DICOM_EXPORT UT : public VR
	{
	public:
        UT();
        UT(const encoded_string& value);
        UT(encoded_string&& value);
        UT(const UT& other);
        UT(UT&& other);
		virtual ~UT();

        UT& operator = (const UT& other);
        UT& operator = (UT&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UT>(*this); }
        
        [[nodiscard]] const encoded_string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& ParsedValue() const {
            AssertValidated();
            return m_value.Parsed();
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        encoded_string m_value;
	};

}