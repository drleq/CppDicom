#pragma once

namespace dicom::io::file::detail {

    class DICOM_EXPORT OutputStream
    {
    public:
        OutputStream(const OutputStream&) = delete;
        OutputStream& operator = (const OutputStream&) = delete;

        virtual ~OutputStream() = default;

        //----------------------------------------------------------------------------------------------------

        virtual bool Write(const void* src, std::streamsize length) = 0;
        [[nodiscard]] virtual std::streampos Tell() const = 0;
        virtual void Seek(std::streamoff offset, std::ios::seekdir dir) = 0;
        [[nodiscard]] virtual bool Good() const = 0;

        [[nodiscard]] explicit operator bool () const { return Good(); }

        //----------------------------------------------------------------------------------------------------

        template <typename T>
        void WriteValue(T val) {
            Write(&val, sizeof(T));
        }

    protected:
        OutputStream() = default;
    };

    using OutputStreamPtr = std::shared_ptr<OutputStream>;

}