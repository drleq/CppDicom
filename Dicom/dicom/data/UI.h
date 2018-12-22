#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/detail/string_iterator.h"

namespace dicom::data {

	class UI : public VR
	{
	public:
        using iterator = detail::substring_iterator<detail::trim_none>;

        //----------------------------------------------------------------------------------------------------

        UI();
        UI(const char* value);
		UI(const std::string_view& value);
        UI(std::string&& value);
        UI(const std::vector<std::string_view>& values);
		UI(std::initializer_list<std::string_view> values);
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

        [[nodiscard]] size_t ParsedCount() const {
            if (Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed_offsets.size() + 1;
        }
        
        [[nodiscard]] iterator ParsedBegin() const {
            AssertValidated();
            return iterator(&m_value, &m_parsed_offsets, 0);
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValidated();
            return iterator(&m_value, &m_parsed_offsets, ParsedCount());
        }

        [[nodiscard]] std::vector<std::string_view> Parsed() const {
            return std::vector<std::string_view>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] std::string_view First() const { return At(0); }
        [[nodiscard]] std::string_view At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return *(iterator(&m_value, &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------
		
        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

	private:
		std::string m_value;
        mutable std::vector<size_t> m_parsed_offsets;
	};

    // STL ADL functions
    inline auto begin(const UI& x) { return x.ParsedBegin(); }
    inline auto end(const UI& x) { return x.ParsedEnd(); }

}