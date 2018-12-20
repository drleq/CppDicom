#pragma once

#include "dicom/data/encoded_string.h"
#include "dicom/data/PatientNameGroup.h"
#include "dicom/data/VR.h"
#include "dicom/data/detail/string_iterator.h"

namespace dicom::data {

	class PN : public VR
	{
	public:
        struct string_to_patient_group_name {
            static PatientNameGroup Convert(const std::string_view& str) {
                return PatientNameGroup(str);
            }
        };

        using iterator = detail::string_iterator<PatientNameGroup, string_to_patient_group_name, detail::trim_none>;

        //----------------------------------------------------------------------------------------------------

        PN();
        PN(const encoded_string& value);
        PN(encoded_string&& value);

        PN(const PatientNameGroup& value);
        PN(const std::vector<PatientNameGroup>& values);
        PN(std::initializer_list<PatientNameGroup> values);

        PN(const PN& other);
        PN(PN&& other);
		virtual ~PN();

        PN& operator = (const PN& other);
        PN& operator = (PN&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<PN>(*this); }

        [[nodiscard]] const encoded_string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] std::string ParsedValue() const {
            AssertValidated();
            return m_value.Parsed();
        }

        [[nodiscard]] size_t ParsedCount() const {
            if (Empty() || Validity() == ValidityType::Invalid) { return 0; }
            return m_parsed_offsets.size() + 1;
        }

        [[nodiscard]] iterator ParsedBegin() const {
            AssertValidated();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, 0);
        }
        [[nodiscard]] iterator ParsedEnd() const {
            AssertValidated();
            return iterator(&m_value.Parsed(), &m_parsed_offsets, ParsedCount());
        }

        [[nodiscard]] std::vector<PatientNameGroup> Parsed() const {
            return std::vector<PatientNameGroup>(ParsedBegin(), ParsedEnd());
        }

        [[nodiscard]] PatientNameGroup First() const { return At(0); }

        [[nodiscard]] PatientNameGroup At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return *(iterator(&m_value.Parsed(), &m_parsed_offsets, index));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;


    protected:
        ValidityType Validate() const override final;

	private:
        encoded_string m_value;
		mutable std::vector<size_t> m_parsed_offsets;
	};

}