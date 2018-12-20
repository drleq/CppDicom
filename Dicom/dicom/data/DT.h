#pragma once

#include "dicom/data/VR.h"
#include "dicom/data/date_time.h"
#include "dicom/data/time_offset.h"

namespace dicom::data {

    class DT : public VR
    {
    public:
        DT();
        DT(const char* value);
        DT(const std::string_view& value);
        DT(std::string&& value);
        DT(const date_time& datetime);
        DT(const date_time& datetime, const time_offset& offset);
        DT(const DT& other);
        DT(DT&& other);
        virtual ~DT();

        DT& operator = (const DT& other);
        DT& operator = (DT&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<DT>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const std::string& Value() const { return m_value; }

        [[nodiscard]] const date_time& ParsedDateTime() const {
            AssertValidated();
            return m_parsed_date_time;
        }
        [[nodiscard]] const time_offset& ParsedOffset() const {
            AssertValidated();
            return m_parsed_offset;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        std::string m_value;
        mutable date_time m_parsed_date_time;
        mutable time_offset m_parsed_offset;
    };

}