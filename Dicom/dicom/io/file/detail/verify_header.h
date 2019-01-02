#pragma once

#include "dicom/io/file/detail/InputStream.h"

namespace dicom::io::file::detail {

    DICOM_EXPORT [[nodiscard]] bool verify_header(const InputStreamPtr& stream);

}