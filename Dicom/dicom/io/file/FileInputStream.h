#pragma once

#include "dicom/io/file/InputStream.h"

namespace dicom::io::file {

    class DICOM_EXPORT FileInputStream : public InputStream
    {
    public:
        FileInputStream(const std::string_view& filename);
        virtual ~FileInputStream();

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

        bool Read(void* dest, std::streamsize length) override final {
            [[maybe_unused]] size_t bytes_read;
            bytes_read = fread(dest, 1, static_cast<size_t>(length), m_file);
            return Good();
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] data::buffer<char> ReadBinary(std::streamsize length) override final {
            data::buffer<char> tmp(static_cast<size_t>(length));

            [[maybe_unused]] size_t bytes_read;
            bytes_read = fread(tmp, 1, static_cast<size_t>(length), m_file);
            
            return tmp;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] ReOpenStreamFunction CreateReOpenFunction() const override final;

    private:
        std::string_view m_filename;
        FILE* m_file;

        mutable std::shared_ptr<std::string> m_filename_for_reopen;
    };

}