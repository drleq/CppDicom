#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/encoded_string.h"

namespace dicom::data {

	class LT : public VR
	{
	public:
        LT();
        LT(const encoded_string& value);
        LT(encoded_string&& value);
        LT(const LT& other);
        LT(LT&& other);
		virtual ~LT();

        LT& operator = (const LT& other);
        LT& operator = (LT&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<LT>(*this); }

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