#pragma once

#include "dicom/io/file/OutputStream.h"

namespace dicom::io::file::detail {

    DICOM_EXPORT void write_header(const OutputStreamPtr& stream);

}