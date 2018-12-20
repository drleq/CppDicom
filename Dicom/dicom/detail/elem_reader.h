#pragma once

#include "dicom/data/AttributeSet.h"

namespace dicom::detail {

    /** \brief A wrapper providing read-only access to a specific attribute in an \ref AttributeSet.
     *
     * This class acts as a wrapper for an \ref AttributeSet, allowing strongly typed read-only access to
     * a specific attribute.
     * 
     * \see elem_writer{T}
     * \see ctx_reader{T1,T2}
     * \see sq_reader{T}
     * \see range_reader{T}
     */
    template <typename T>
    class elem_reader
    {
    public:
        elem_reader() : m_attribute_set(nullptr), m_tag(-1) {}
        elem_reader(const data::AttributeSet* as, tag_number tag) : m_attribute_set(as), m_tag(tag) {}

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] explicit operator bool() const {
            auto attrib = m_attribute_set->Get(m_tag);
            return (attrib != nullptr) && (attrib->IsValid());
        }

        [[nodiscard]] operator const T* () const { return m_attribute_set->Get<T>(m_tag); }
        [[nodiscard]] const T* operator -> () const { return m_attribute_set->Get<T>(m_tag); }

    private:
        const data::AttributeSet* m_attribute_set;
        tag_number m_tag;
    };

}