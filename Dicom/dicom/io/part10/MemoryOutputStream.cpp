#include "dicom_pch.h"
#include "dicom/io/part10/MemoryOutputStream.h"

namespace dicom::io::part10 {

    MemoryOutputStream::MemoryOutputStream(size_t initial_capacity /*= 1024*/)
      : m_offset(0),
        m_length(0)
    {
        m_data.reserve(initial_capacity);
    }

    //--------------------------------------------------------------------------------------------------------

    MemoryOutputStream::~MemoryOutputStream() = default;

    //--------------------------------------------------------------------------------------------------------

    std::vector<uint8_t>&& MemoryOutputStream::Detach() {
        m_data.shrink_to_fit();
        return std::move(m_data);
    }

}