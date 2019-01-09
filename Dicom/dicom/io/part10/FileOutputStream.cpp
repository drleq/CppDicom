#include "dicom_pch.h"
#include "dicom/io/part10/FileOutputStream.h"

namespace dicom::io::part10 {

    FileOutputStream::FileOutputStream(const std::string_view& filename) {
#ifdef __GNUG__
        m_file = fopen(filename.data(), "wb");
        if (m_file == nullptr) {
            return;
        }
#endif
#ifdef _MSC_VER
        if (fopen_s(&m_file, filename.data(), "wb") != 0) {
            return;
        }
#endif
    }

    //--------------------------------------------------------------------------------------------------------

    FileOutputStream::~FileOutputStream() {
        fclose(m_file);
    }

}