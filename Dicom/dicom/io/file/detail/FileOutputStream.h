#pragma once

#include "dicom/io/file/detail/OutputStream.h"

namespace dicom::io::file::detail {

    class DICOM_EXPORT FileOutputStream : public OutputStream
    {
    public:
        FileOutputStream(const std::string_view& filename);
        virtual ~FileOutputStream();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Good() const override final { return ferror(m_file) == 0; }
        [[nodiscard]] std::streampos Tell() const override final { return ftell(m_file); }

        //----------------------------------------------------------------------------------------------------

        void Seek(std::streamoff offset, std::ios::seekdir dir) override final {
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch" // enumeration value ‘_S_ios_seekdir_end’ not handled in switch
#endif
            switch (dir) {
            case std::ios::beg: fseek(m_file, static_cast<long>(offset), SEEK_SET); break;
            case std::ios::cur: fseek(m_file, static_cast<long>(offset), SEEK_CUR); break;
            case std::ios::end: fseek(m_file, static_cast<long>(offset), SEEK_END); break;
            }
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Write(const void* src, std::streamsize length) override final {
            fwrite(src, 1, static_cast<size_t>(length), m_file);
            return Good();
        }

    private:
        FILE* m_file;
    };

}