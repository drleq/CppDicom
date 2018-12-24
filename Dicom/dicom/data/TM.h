#pragma once

#include "dicom/data/detail/string_iterator.h"
#include "dicom/data/VR.h"
#include "dicom/data/time.h"

namespace dicom::data {

    class TM : public VR
    {
    public:
        TM();
        TM(const char* value);
        TM(const std::string_view& value);
        TM(std::string&& value);
        TM(const std::vector<std::string>& values);
        TM(std::initializer_list<std::string_view> values);
        TM(const time& duration);
        TM(const std::vector<time>& values);
        TM(std::initializer_list<time> values);
        TM(const TM& other);
        TM(TM&& other);
        virtual ~TM();

        TM& operator = (const TM& other);
        TM& operator = (TM&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<TM>(*this); }
        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] size_t ParsedCount() const {
            return m_parsed_times.size();
        }

        [[nodiscard]] auto ParsedBegin() const {
            AssertValidated();
            return m_parsed_times.cbegin();
        }
        [[nodiscard]] auto ParsedEnd() const {
            AssertValidated();
            return m_parsed_times.cend();
        }

        [[nodiscard]] const std::vector<time>& Parsed() const {
            AssertValidated();
            return m_parsed_times;
        }

        [[nodiscard]] const time& First() const { return At(0); }
        [[nodiscard]] const time& At(size_t index) const {
            AssertValidated();
            AssertNotEmpty();
            return m_parsed_times.at(index);
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
        mutable std::vector<time> m_parsed_times;
    };

}