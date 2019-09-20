#pragma once

#include "dicom/io/part10/InputStream.h"

namespace dicom::io::part10 {

    struct DICOM_EXPORT MemoryInputView {
        MemoryInputView(const uint8_t* data, std::streamsize length)
          : Data(data),
            Length(length)
        {}

        const uint8_t* Data;
        std::streamsize Length;
    };

    class DICOM_EXPORT MemoryInputStream :
        public InputStream
    {
    public:
        MemoryInputStream(std::shared_ptr<MemoryInputView> view);
        virtual ~MemoryInputStream();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Good() const override final { return (m_offset >= 0) && (m_offset <= Length()); }
        [[nodiscard]] std::streampos Tell() const override final { return m_offset; }

        //----------------------------------------------------------------------------------------------------

        void Seek(std::streamoff offset, std::ios::seekdir dir) override final {
            switch (dir) {
            case std::ios::beg: m_offset = offset; break;
            case std::ios::cur: m_offset += offset; break;
            case std::ios::end: m_offset = Length() + offset; break;
            }
        }

        //----------------------------------------------------------------------------------------------------

        bool Read(void* dest, std::streamsize length) override final {
            if (Length() - m_offset < length) {
                m_offset += length;
                return false;
            }

            memcpy(dest, &m_view->Data[m_offset], length);
            m_offset += length;
            return true;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] data::buffer<char> ReadBinary(std::streamsize length) override final {
            data::buffer<char> tmp(static_cast<size_t>(length));
            Read(tmp, length);
            return tmp;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] ReOpenStreamFunction CreateReOpenFunction() const override final;

    private:
        std::shared_ptr<MemoryInputView> m_view;
        std::streampos m_offset;
    };

}