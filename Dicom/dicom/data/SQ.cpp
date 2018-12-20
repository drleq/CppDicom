#include "dicom_pch.h"
#include "dicom/data/SQ.h"

namespace dicom::data {

    SQ::SQ()
      : SQ(container_type())
    {}

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(const container_type& items)
      : VR(VRType::SQ)
    {
        m_items.reserve(items.size());
        for (auto& item : items) {
            m_items.emplace_back(std::make_unique<AttributeSet>(item->Copy()));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(container_type&& items)
      : VR(VRType::SQ),
	    m_items(std::forward<container_type>(items))
    {}

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(const item_type& item)
      : VR(VRType::SQ),
        m_items(1)
    {
        m_items.emplace_back(std::make_unique<AttributeSet>(item->Copy()));
    }

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(item_type&& item)
      : VR(VRType::SQ),
        m_items(1)
    {
        m_items.emplace_back(std::forward<item_type>(item));
    }

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(const SQ& other)
      : VR(other)
    {
        m_items.reserve(other.Size());
        for (auto& item : other.m_items) {
            m_items.emplace_back(std::make_unique<AttributeSet>(item->Copy()));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SQ::SQ(SQ&& other)
      : VR(std::forward<VR>(other)),
        m_items(std::move(other.m_items))
    {}

    //--------------------------------------------------------------------------------------------------------

    SQ::~SQ() = default;

    //--------------------------------------------------------------------------------------------------------

    SQ& SQ::operator = (const SQ& other) {
        VR::operator = (other);

        container_type items;
        items.reserve(other.m_items.size());
        for (auto& item : other.m_items) {
            items.emplace_back(std::make_unique<AttributeSet>(item->Copy()));
        }
        
        m_items = std::move(items);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    SQ& SQ::operator = (SQ&& other) {
        VR::operator = (std::forward<VR>(other));
        m_items = std::move(other.m_items);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType SQ::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t SQ::Compare(const VR*) const { throw std::logic_error("Cannot compare sequences"); }

    //--------------------------------------------------------------------------------------------------------

    bool SQ::operator == (const VR*) const { throw std::logic_error("Cannot compare sequences"); }
    bool SQ::operator != (const VR*) const { throw std::logic_error("Cannot compare sequences"); }
    bool SQ::operator <  (const VR*) const { throw std::logic_error("Cannot compare sequences"); }
    bool SQ::operator <= (const VR*) const { throw std::logic_error("Cannot compare sequences"); }
    bool SQ::operator >  (const VR*) const { throw std::logic_error("Cannot compare sequences"); }
    bool SQ::operator >= (const VR*) const { throw std::logic_error("Cannot compare sequences"); }

}