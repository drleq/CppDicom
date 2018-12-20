#pragma once

#include "dicom/data/VR.h"

namespace dicom::data {

	class UI : public VR
	{
	public:
        UI();
        UI(const char* value);
		UI(const std::string_view& value);
        UI(std::string&& value);
        UI(const UI& other);
        UI(UI&& other);
		virtual ~UI();

        UI& operator = (const UI& other);
        UI& operator = (UI&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<UI>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------
		
        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

	private:
		std::string m_value;
	};

}