#include "dicom_pch.h"
#include "dicom/io/file/detail/write_data_element.h"

#include "dicom/data/VR.h"
#include "dicom/io/Deferred.h"
#include "dicom/io/file/detail/OutputContext.h"
#include "dicom/io/file/detail/write_vr.h"

namespace dicom::io::file::detail {

    void write_data_element(
        OutputContext* ctx,
        tag_number tag,
        const data::VR* attribute
    ) {
        if (attribute->Type() == data::VRType::Deferred) {
            // Ignore deferred values. We cannot guarantee efficiency.
            return;
        }

        auto& stream = ctx->Stream();

        // Write the tag number
        ctx->WriteTagNumber(tag);

        // Write the VR type if appropriate.
        if (ctx->Encoding() == TagEncodingType::Explicit) {
            stream->WriteValue(attribute->Type());
        }

        // Write a dummy length value.
        auto length_position = stream->Tell();
        if (ctx->Encoding() == TagEncodingType::Explicit) {
            ctx->WriteExplicitTagLength(attribute->Type(), 0);
        } else {
            ctx->WriteImplicitTagLength(0);
        }

        // Write the attribute data, recording how many bytes it consumes.
        auto attribute_start_position = stream->Tell();
        write_vr(ctx, attribute);
        auto attribute_end_position = stream->Tell();

        // Update the length value.
        auto bytes_written = attribute_end_position - attribute_start_position;
        stream->Seek(length_position, std::ios::beg);
        if (ctx->Encoding() == TagEncodingType::Explicit) {
            ctx->WriteExplicitTagLength(attribute->Type(), bytes_written);
        } else {
            ctx->WriteImplicitTagLength(bytes_written);
        }
        stream->Seek(0, std::ios::end);
    }

}