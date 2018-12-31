#include "dicom_pch.h"
#include "dicom/io/file/detail/FileOutputStream.h"

namespace dicom::io::file::detail {

    FileOutputStream::FileOutputStream(const std::string_view& filename) {
        if (fopen_s(&m_file, filename.data(), "wb") != 0) {
            return;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FileOutputStream::~FileOutputStream() {
        fclose(m_file);
    }

}