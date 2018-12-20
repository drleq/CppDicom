#pragma once

namespace dicom::io {

    // bool (const int8_t* data, size_t data_length)
    using HandleBulkDataCallback = std::function<bool (const int8_t*, size_t)>;

}