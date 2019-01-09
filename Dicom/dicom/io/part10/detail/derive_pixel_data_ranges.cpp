#include "dicom_pch.h"
#include "dicom/io/part10/detail/derive_pixel_data_ranges.h"

#include "dicom/data/IS.h"
#include "dicom/data/UI.h"
#include "dicom/data/UL.h"
#include "dicom/Tags.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/io/part10/detail/read_vr_type_and_length.h"
#include "dicom/io/TransferSyntax.h"

using namespace dicom;
using namespace dicom::data;
using namespace dicom::detail;

namespace {
    using namespace dicom::io;
    using namespace dicom::io::part10;
    using namespace dicom::io::part10::detail;

    constexpr tag_number Item = 0xFFFEE000;
    constexpr tag_number SequenceDeliminationItem = 0xFFFEE0DD;
    constexpr size_t FragmentHeaderSize = sizeof(tag_number) + sizeof(uint32_t);

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_valid(const VR* vr) {
        auto validity = vr->Validity();
        return (validity == ValidityType::Valid) || (validity == ValidityType::Acceptable);
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool get_frame_count(const AttributeSet* metadata, size_t* frame_count) {
        *frame_count = 0;

        // The NumberOfFrames attribute is present in both the MultiFrameModule and the
        // MultiFrameFunctionalGroupsModule.
        auto number_of_frames00 = metadata->Get<IS>(tags::NumberOfFrames);
        if (number_of_frames00) {
            if (!is_valid(number_of_frames00) || number_of_frames00->Empty()) {
                return false;
            }
            *frame_count = number_of_frames00->First();
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_native_encoding(const AttributeSet* metadata) {
        auto transfer_syntax_uid = metadata->Get<UI>(tags::TransferSyntaxUID);
        auto transfer_syntax = dicom::io::get_transfer_syntax(transfer_syntax_uid->Value());
        return transfer_syntax->PixelDataEncoding == dicom::io::PixelDataEncodingType::Native;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool derive_native_pixel_data_ranges(
        size_t start_position,
        size_t pixel_data_length,
        size_t frame_count,
        std::vector<PixelDataRange>* ranges
    ) {
        // Verify the length is an exact multiple of the frame count.
        if ((pixel_data_length % frame_count) != 0) { return false; }

        ranges->reserve(frame_count);

        // Derive the ranges.
        auto per_frame_length = pixel_data_length / frame_count;
        for (size_t i = 0; i < frame_count; i++) {
            ranges->emplace_back(
                start_position + (i * per_frame_length),
                per_frame_length,
                PixelDataEncodingType::Native
            );
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool derive_encapsulated_pixel_data_ranges(
        InputContext& context,
        size_t frame_count,
        std::vector<PixelDataRange>* ranges
    ) {
        auto& stream = context.Stream();

        // While encapsulated pixel data consists of many fragments, where each frame can cover many fragments,
        // the Basic Offset Table will give us enough information to figure out the start and end ranges for the
        // fragments within each frame. Reading the range in will include the fragment headers but that can be
        // dealt with later.
        //
        // While the Basic Offset Table must be present, it is allowed to be empty.  Strictly, this is only
        // allowed if there is a single frame but some DICOM libraries will leave it empty with multi-frame
        // data.  We attempt to tolerate this case by assuming each encapsulated fragment represents a single
        // image but if the fragment count doesn't match the expected frame count we are forced to trigger a
        // failure.

        // Get the Basic Offset Table.
        std::unique_ptr<UL> offsets_vr;
        tag_number item_tag = context.ReadTagNumber();
        std::streamsize item_length = context.ReadSQLength();
        if (!stream->Good() || stream->Empty()) { return false; }

        if (item_tag != Item) { return false; }
        if (item_length == 0) {
            // If the Basic Offset Table is empty then only one frame is allowed. (PS3.5 Section A.4)
            offsets_vr = std::make_unique<UL>(0);
        } else {
            offsets_vr = context.ReadBinary<UL>(item_length);
        }

        ranges->reserve(frame_count);

        if (offsets_vr->Length() == frame_count) {
            // Offset count matches the expected frame count.  Just use the Basic Offset Table to extract
            // the pixel data ranges.

            auto& offsets_buf = offsets_vr->Value();
            size_t start_position = static_cast<size_t>(stream->Tell());

            for (size_t i = 0; i < frame_count; i++) {
                size_t offset, length;

                offset = start_position + offsets_buf[i];

                if (i == frame_count - 1) {
                    length = static_cast<size_t>(stream->Length()) - offset;
                } else {
                    length = offsets_buf[i+1] - offsets_buf[i];
                }

                ranges->emplace_back(offset, length, PixelDataEncodingType::Encapsulated);
            }

        } else if (item_length == 0) {
            // Offset counts don't match the expected frame count and the Basic Offset Table is empty.
            // Derive the pixel data ranges from the fragment sequence under the assumption that one fragment
            // maps to one frame.

            size_t start_position = static_cast<size_t>(stream->Tell()); 
            size_t offset = 0;

            while (*stream && !context.Failed()) {
                auto tag = context.ReadTagNumber();
                auto tag_length = static_cast<uint32_t>(context.ReadSQLength());

                if (tag == SequenceDeliminationItem) {
                    break;
                }
                if (tag != Item) {
                    // Error in the fragment sequence.
                    return false;
                }

                ranges->emplace_back(
                    start_position + offset,
                    tag_length + FragmentHeaderSize, // Length includes the fragment header
                    PixelDataEncodingType::Encapsulated
                );

                stream->Seek(tag_length, std::ios::cur);
                offset += FragmentHeaderSize + tag_length;
            }

            // Verify the number of fragments matches the expected number of frames.
            if (ranges->size() != frame_count) {
                ranges->clear();
                context.SetFailed();
            }
        }

        return stream->Good() && !context.Failed();
    }
}

namespace dicom::io::part10::detail {

    bool derive_pixel_data_ranges(
        InputContext& context,
        const data::AttributeSet* metadata,
        std::vector<PixelDataRange>* ranges
    ) {
        auto& stream = context.Stream();

        VRType vr_type;
        std::streamsize pixel_data_length;
        read_vr_type_and_length(
            context,
            metadata,
            tags::PixelData,
            stream->Length(),
            &vr_type,
            &pixel_data_length
        );
        size_t start_position = static_cast<size_t>(stream->Tell());

        // No pixel data available.
        if (pixel_data_length <= 0) { return true; }

        // Get the frame count
        size_t frame_count;
        if (!get_frame_count(metadata, &frame_count)) { return false; }

        bool is_native = is_native_encoding(metadata);

        bool ok;
        if (frame_count == 0) {
            // Not a multi-frame image. There is only one range.
            ranges->emplace_back(
                start_position,
                static_cast<size_t>(pixel_data_length),
                is_native ? PixelDataEncodingType::Native : PixelDataEncodingType::Encapsulated
            );
            ok = true;
        } else if (is_native) {
            ok = derive_native_pixel_data_ranges(
                start_position,
                static_cast<size_t>(pixel_data_length),
                frame_count,
                ranges
            );
        } else {
            ok = derive_encapsulated_pixel_data_ranges(context, frame_count, ranges);
        }

        if (ok) {
            auto& last_range = ranges->back();
            auto new_position = last_range.StartOffset() + last_range.Length();
            if (last_range.EncodingType() == PixelDataEncodingType::Encapsulated) {
                // Account for expected close item.
                new_position += FragmentHeaderSize;
            }

            // Some datasets have an incorrect PixelData length that is exactly 4 bytes beyond the
            // end of the stream.  It does not seem related to the scanner so it must be a bug with
            // a certain DICOM library (not this one thankfully).  In this case we should just
            // tolerate the error and adjust the range.
            if (new_position == static_cast<size_t>(stream->Length()) + 4) {
                last_range = PixelDataRange(
                    last_range.StartOffset(),
                    last_range.Length() - 4,
                    last_range.EncodingType()
                );
                new_position = static_cast<size_t>(stream->Length());
            }

            stream->Seek(new_position, std::ios::beg);
        }
        return ok;
    }

}