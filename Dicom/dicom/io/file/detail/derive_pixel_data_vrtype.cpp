#include "dicom_pch.h"
#include "dicom/io/file/detail/derive_pixel_data_vrtype.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/data/US.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/Tags.h"

using namespace dicom::data;
using namespace dicom::io;

namespace dicom::io::file::detail {

    bool derive_pixel_data_vrtype(
        const AttributeSet* metadata,
        const TransferSyntax* transfer_syntax,
        VRType* type
    ) {
        if (transfer_syntax->PixelDataEncoding == PixelDataEncodingType::Encapsulated) {
            // Encapsulated pixel data is always considered to be OB, endian agnostic.
            *type = VRType::OB;
            return true;
        }

        dicom::detail::elem_reader<US> bits_allocated(metadata, dicom::tags::BitsAllocated);
        if (!bits_allocated || bits_allocated->Empty()) {
            // BitsAllocated must exist for pixel data.
            return false;
        }

        uint16_t val = bits_allocated->First();
        if (val == 0 || val > 16) {
            // BitsAllocated must be from 1 to 16 bits.
            return false;
        }

        if (val > 8) {
            // 9-16 bits stored. Use OW.
            *type = VRType::OW;
            return true;
        }

        // 1-8 bits stored. Use OB.
        *type = VRType::OB;
        return true;
    }

}