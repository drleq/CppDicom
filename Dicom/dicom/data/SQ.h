#pragma once

#include "dicom/data/AttributeSet.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT SQ : public VR
    {
    public:
		using item_type = std::unique_ptr<AttributeSet>;
		using container_type = std::vector<item_type>;

        //----------------------------------------------------------------------------------------------------

        SQ();
        SQ(const container_type& items);
		SQ(container_type&& items);
        SQ(const item_type& item);
        SQ(item_type&& item);
        SQ(const SQ& other);
        SQ(SQ&& other);
        virtual ~SQ();

        SQ& operator = (const SQ& other);
        SQ& operator = (SQ&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_items.empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<SQ>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const container_type& Items() const { return m_items; }
        [[nodiscard]]       container_type& Items()       { return m_items; }

        [[nodiscard]] size_t Size() const { return m_items.size(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;
        [[nodiscard]] bool operator <  (const VR* other) const override final;
        [[nodiscard]] bool operator <= (const VR* other) const override final;
        [[nodiscard]] bool operator >  (const VR* other) const override final;
        [[nodiscard]] bool operator >= (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;
        
    private:
        container_type m_items;
    };

    // STL ADL functions
    inline auto begin(SQ& x) { return x.Items().begin(); }
    inline auto end(SQ& x) { return x.Items().end(); }

    inline auto begin(const SQ& x) { return x.Items().begin(); }
    inline auto end(const SQ& x) { return x.Items().end(); }

}