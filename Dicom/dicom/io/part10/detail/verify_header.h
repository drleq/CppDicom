#pragma once

#include "dicom/io/part10/InputStream.h"

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool verify_header(const InputStreamPtr& stream);

}