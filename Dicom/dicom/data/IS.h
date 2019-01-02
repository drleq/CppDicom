#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/detail/string_iterator.h"
#include "dicom/data/detail/string_to_int32.h"

namespace dicom::data {

	class DICOM_EXPORT IS : public VR
	{
	public:
        using iterator = detail::string_iterator<int32_t, detail::string_to_int<int32_t>, detail::trim_left>;

        //----------------------------------------------------------------------------------------------------

        IS();
        IS(const char* value);
		IS(const std::string_view& value);
        IS(std::string&& value);
        IS(int32_t value);
        IS(const std::vector<int32_t>& value);
        IS(std::initializer_list<int32_t> values);
        IS(const IS& other);
        IS(IS&& other);
		virtual ~IS();

        IS& operator = (const IS& other);
        IS& operator = (IS&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<IS>(*this); }

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

        [[nodiscard]] std::vector<int32_t> Parsed() const {
            return std::vector<int32_t>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] int32_t First() const { return At(0); }
        [[nodiscard]] int32_t At(size_t index) const {
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
    inline auto begin(const IS& x) { return x.ParsedBegin(); }
    inline auto end(const IS& x) { return x.ParsedEnd(); }

}