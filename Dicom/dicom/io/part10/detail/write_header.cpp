#include "dicom_pch.h"
#include "dicom/io/part10/detail/write_header.h"

namespace dicom::io::part10::detail {

    void write_header(const OutputStreamPtr& stream) {
        // The first 128 bytes are zeros.
        uint8_t tmp[128];
        memset(tmp, 0, sizeof(tmp));
        stream->Write(tmp, sizeof(tmp));

        // The next four bytes should read 'DICM' if viewed in a hex editor.
        constexpr uint32_t DICM = 0x4D434944;
        stream->WriteValue(DICM);
    }

}