#pragma once

#include "dicom/io/part10/OutputStream.h"

namespace dicom::io::part10 {

    class DICOM_EXPORT MemoryOutputStream :
        public OutputStream
    {
    public:
        MemoryOutputStream(size_t initial_capacity = 1024);
        virtual ~MemoryOutputStream();

        std::vector<uint8_t>&& Detach();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Good() const override final { return (m_offset >= 0) && (m_offset <= m_length); }
        [[nodiscard]] std::streampos Tell() const override final { return m_offset; }

        //----------------------------------------------------------------------------------------------------

        void Seek(std::streamoff offset, std::ios::seekdir dir) override final {
            switch (dir) {
            case std::ios::beg: m_offset = offset; break;
            case std::ios::cur: m_offset += offset; break;
            case std::ios::end: m_offset = m_length + offset; break;
            }
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Write(const void* src, std::streamsize length) override final {
            size_t new_length = m_offset + length;
            if (m_data.size() < new_length) {
                m_data.reserve(new_length);
                m_data.resize(new_length);
            }

            memcpy(&m_data[m_offset], src, length);

            m_offset += length;
            if (m_length < m_offset) {
                m_length = m_offset;
            }
            return true;
        }

    private:
        std::vector<uint8_t> m_data;
        std::streamsize m_length;
        std::streampos m_offset;
    };

}