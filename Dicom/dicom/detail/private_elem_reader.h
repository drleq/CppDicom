#pragma once

#include "dicom/data/AttributeSet.h"

namespace dicom::detail {

    template <typename T>
    class private_elem_reader
    {
    public:
        private_elem_reader() : m_attribute_set(nullptr), m_tag(nullptr) {}
        private_elem_reader(const data::AttributeSet* as, const private_tag& tag)
          : m_attribute_set(as), m_tag(&tag)
        {}

        [[nodiscard]] explicit operator bool () const {
            auto attrib = m_attribute_set->Get(*m_tag);
            return (attrib != nullptr) && (attrib->IsValid());
        }

        [[nodiscard]] operator const T* () const { return m_attribute_set->Get<T>(*m_tag); }
        [[nodiscard]] const T* operator -> () const { return m_attribute_set->Get<T>(*m_tag); }

    private:
        const data::AttributeSet* m_attribute_set;
        const private_tag* m_tag;
    };

}