#pragma once

#include "dicom/io/file/detail/InputStream.h"

namespace dicom::io::file::detail {

    [[nodiscard]] bool verify_header(const InputStreamPtr& stream);

}