#include "dicom_pch.h"
#include "dicom/io/part10/detail/create_deferred_vr.h"

#include "dicom/io/Deferred.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/read_vr.h"

namespace dicom::io::part10::detail {

    std::unique_ptr<data::VR> create_deferred_vr(
        InputContext& context,
        std::streamsize length,
        data::VRType vr_type
    ) {
        auto& stream = context.Stream();
        auto stream_factory = stream->CreateReOpenFunction();

        // Locally capture the current stream state
        auto current_position = stream->Tell();

        // Locally capture the current context state
        auto data_dictionary = context.DataDictionary();
        auto endian = context.Endian();
        auto encoding = context.Encoding();
        auto string_encoding = context.GetStringEncoding();

        // Create the callback, capturing the required state by value
        LoadDeferredVRCallback load_vr_callback = [=]() -> std::unique_ptr<data::VR> {
            auto temp_stream = stream_factory();

            // Seek the appropriate location.
            temp_stream->Seek(current_position, std::ios::beg);
            if (!temp_stream->Good()) { return nullptr; }

            // Create an InputContext with the same configuration as the original
            InputContext ctx(temp_stream, data_dictionary, endian, encoding, string_encoding);
            
            // Decode the VR
            return read_vr(ctx, length, vr_type);
        };

        if ((vr_type == data::VRType::SQ) &&
            (context.Encoding() == TagEncodingType::Implicit) &&
            (length == 0xFFFFFFFF)
        ) {
            // Implicitly encoded SQ tags of unknown length cannot be trivially skipped. Read the VR and discard it.
            [[maybe_unused]] auto dummy = read_vr(context, length, vr_type);
        } else {
            stream->Seek(length, std::ios::cur);
        }

        // Return the deferred VR
        return std::make_unique<Deferred>(load_vr_callback);
    }

}