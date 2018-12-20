#pragma once

#include "dicom/data/buffer.h"

namespace dicom::io::file::detail {

    class InputStream;
    using InputStreamPtr = std::shared_ptr<InputStream>;

    using ReOpenStreamFunction = std::function<InputStreamPtr ()>;

    class InputStream
    {
    public:
        InputStream(const InputStream&) = delete;
        InputStream& operator = (const InputStream&) = delete;

        virtual ~InputStream() = default;

        //----------------------------------------------------------------------------------------------------

        virtual bool Read(void* dest, std::streamsize length) = 0;
        [[nodiscard]] virtual std::streampos Tell() const = 0;
        virtual void Seek(std::streamoff offset, std::ios_base::seekdir dir) = 0;
        [[nodiscard]] virtual bool Good() const = 0;

        [[nodiscard]] bool Empty() const { return Tell() >= m_length; }
        [[nodiscard]] explicit operator bool () const { return !Empty() && Good(); }
        [[nodiscard]] std::streamoff Length() const { return m_length; }

        //----------------------------------------------------------------------------------------------------

        template <typename T>
        [[nodiscard]] T ReadValue() {
            T val;
            Read(&val, sizeof(T));
            return val;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] virtual data::buffer<char> ReadBinary(std::streamsize length) = 0;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] virtual ReOpenStreamFunction CreateReOpenFunction() const = 0;

    protected:
        InputStream() : m_length(0) {}

        void Initialize(int64_t length) {
            m_length = length;
        }

    private:
        int64_t m_length;
    };

}