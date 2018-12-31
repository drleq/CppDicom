#pragma once

#include "dicom/tag_number.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT AT : public VR
    {
    public:
        using container_type = std::vector<tag_number>;

        //----------------------------------------------------------------------------------------------------

        AT();
        AT(tag_number value);
        AT(tag_group group, tag_element element);
        AT(const container_type& values);
        AT(container_type&& values);
		AT(std::initializer_list<tag_number> values);
        AT(const AT& other);
        AT(AT&& other);
        virtual ~AT();

        AT& operator = (const AT& other);
        AT& operator = (AT&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_values.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<AT>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const container_type& Value() const { return m_values; }
        [[nodiscard]] const tag_number& First() const {
            AssertNotEmpty();
            return m_values[0];
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;

    private:
        container_type m_values;
    };

    // STL ADL functions
    inline auto begin(const AT& x) { return x.Value().begin(); }
    inline auto end(const AT& x) { return x.Value().end(); }

}