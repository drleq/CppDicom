#include "dicom_pch.h"
#include "dicom/io/file/detail/FileOutputStream.h"

namespace dicom::io::file::detail {

    FileOutputStream::FileOutputStream(const std::string_view& filename) {
        m_file = std::fopen(filename.data(), "wb");
        if (m_file == nullptr) { return; }
    }

    //--------------------------------------------------------------------------------------------------------

    FileOutputStream::~FileOutputStream() {
        fclose(m_file);
    }

}