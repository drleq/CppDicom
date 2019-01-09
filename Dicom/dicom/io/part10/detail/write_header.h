#pragma once

#include "dicom/io/part10/OutputStream.h"

namespace dicom::io::part10::detail {

    DICOM_EXPORT void write_header(const OutputStreamPtr& stream);

}