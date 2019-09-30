#include "dicomnet_pch.h"
#include "dicom/net/detail/write_data_element.h"

#include "dicom/data/VR.h"
#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/detail/write_vr.h"

namespace dicom::net::detail {

    void write_data_element(
        io::part10::detail::OutputContext& ctx,
        const tag_number& tag,
        const data::VR* attribute
    ) {
        auto& stream = ctx.Stream();

        ctx.WriteTagNumber(tag);

        // Write a dummy length value.
        auto length_position = stream->Tell();
        ctx.WriteImplicitTagLength(0);

        // Write the attribute data, recording how many bytes it consumes.
        auto attribute_start_position = stream->Tell();
        io::part10::detail::write_vr(&ctx, attribute);
        auto attribute_end_position = stream->Tell();

        // Update the length value.
        auto bytes_written = attribute_end_position - attribute_start_position;
        stream->Seek(length_position, std::ios::beg);
        ctx.WriteImplicitTagLength(bytes_written);
        stream->Seek(0, std::ios::end);
    }

}