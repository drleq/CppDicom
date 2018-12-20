#pragma once

#include "dicom/io/file/detail/OutputStream.h"

namespace dicom::io::file::detail {

    void write_header(const OutputStreamPtr& stream);

}