#include "dicom_pch.h"
#include "dicom/io/part10/detail/verify_header.h"

namespace dicom::io::part10::detail {

    bool verify_header(const InputStreamPtr& stream) {
        // Modern DICOM files will contain a 132 byte header (128 bytes of meaningless space and 4 bytes
        // for 'DICM'). Older DICOM files may not contain the header at all. If we find the header we
        // should seek past it; if not then we simply assume it wasn't present.

        if (stream->Length() < 132) {
            return stream->Good();
        }

        stream->Seek(128, std::ios::beg);

        // The next four bytes should read 'DICM' if viewed in a hex editor.
        constexpr uint32_t DICM = 0x4D434944;
        if (stream->ReadValue<uint32_t>() == DICM) {
            return stream->Good();
        }

        // Header does not match. Assume it wasn't present.
        stream->Seek(0, std::ios::beg);
        return stream->Good();
    }

}