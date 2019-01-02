#include "dicom_pch.h"
#include "dicom/io/file/detail/FileInputStream.h"

namespace dicom::io::file::detail {

    FileInputStream::FileInputStream(const std::string_view& filename)
      : m_filename(filename)
    {
#ifdef __GNUG__
        m_file = fopen(filename.data(), "rb");
        if (m_file == nullptr) {
            return;
        }
#endif
#ifdef _MSC_VER
        if (fopen_s(&m_file, filename.data(), "rb") != 0) {
            return;
        }
#endif

        fseek(m_file, 0, SEEK_END);
        Initialize(ftell(m_file));
        fseek(m_file, 0, SEEK_SET);
    }

    //--------------------------------------------------------------------------------------------------------

    FileInputStream::~FileInputStream() {
        fclose(m_file);
    }

    //--------------------------------------------------------------------------------------------------------

    ReOpenStreamFunction FileInputStream::CreateReOpenFunction() const {
        if (!m_filename_for_reopen) {
            m_filename_for_reopen = std::make_shared<std::string>(m_filename);
        }

        return [filename=m_filename_for_reopen]() -> InputStreamPtr {
            return std::make_shared<FileInputStream>(*filename);
        };
    }

}