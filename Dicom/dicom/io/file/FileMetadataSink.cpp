#include "dicom_pch.h"
#include "dicom/io/file/FileMetadataSink.h"

#include "dicom/io/file/detail/FileOutputStream.h"
#include "dicom/io/file/detail/OutputContext.h"
#include "dicom/io/file/detail/write_attributes.h"
#include "dicom/io/file/detail/write_file_meta_information.h"
#include "dicom/io/file/detail/write_header.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/data/CS.h"
#include "dicom/data/IS.h"
#include "dicom/data/US.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/multiframe/PrivateTags.h"
#include "dicom/Tags.h"

using namespace std;

namespace {
    using namespace dicom::data;
    using namespace dicom::io;
    using namespace dicom::io::file;
    using namespace dicom::io::file::detail;
    using namespace dicom::multiframe;

    constexpr int32_t ZeroLength = 0;
    constexpr size_t ByteSwapBufferLength = 4096;

    //--------------------------------------------------------------------------------------------------------

    bool get_frame_count(
        const AttributeSet* metadata,
        size_t* start_frame_index,
        size_t* frame_count
    ) {
        *start_frame_index = 0;
        *frame_count = 1;

        auto frame_index00 = metadata->Get<IS>(private_tags::FrameIndexTag);
        if (frame_index00) {
            // This is a single frame extracted from a larger multi-frame instance.
            *start_frame_index = frame_index00->First();
            return true;
        }

        // The NumberOfFrames attribute is present in both the MultiFrameModule and the
        // MultiFrameFunctionalGroupsModule.
        auto number_of_frames00 = metadata->Get<IS>(dicom::tags::NumberOfFrames);
        if (number_of_frames00) {
            if (!number_of_frames00->IsValid() || number_of_frames00->Empty()) {
                return false;
            }
            *frame_count = number_of_frames00->First();
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_native_pixel_data(
        WritePixelDataCallback write_callback,
        WritePixelDataFunction write_func,
        size_t start_frame_index,
        size_t frame_count
    ) {
        // Native is simply the concatenation of each frame.
        for (size_t i = 0; i < frame_count; ++i) {
            if (!write_callback(start_frame_index + i, write_func)) {
                return false;
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_encapsulated_pixel_data(
        OutputContext* ctx,
        WritePixelDataCallback write_callback,
        WritePixelDataFunction write_func,
        size_t start_frame_index,
        size_t frame_count
    ) {
        // Encapsulated pixel data contains a number of fragments per frame, with each fragment represented
        // by an item in a sequence. The first item in the sequence is the Basic Offset Table describing the
        // offsets for the first fragment for each frame.
        // For simplicity we only create one fragment per frame. This gives us a deterministic size for the
        // Basic Offset Table, which greatly simplifies writing the data out in a single pass.
        constexpr dicom::tag_number Item = 0xFFFEE000;
        constexpr dicom::tag_number SequenceDeliminationItem = 0xFFFEE0DD;

        auto& stream = ctx->Stream();
        ctx->WriteTagNumber(Item);

        streamoff basic_offset_table_position = 0;
        size_t basic_offset_table_length = 0;
        vector<uint32_t> offsets;

        if (frame_count == 1) {
            // For a single frame the Basic Offset Table has zero size. The first frame is implicitly at
            // an offset of zero.
            stream->WriteValue(uint32_t(0));
            offsets.resize(1);
        } else {
            // For multiple frames the Basic Offset Table includes the first frame offset, even though it is
            // zero.
            basic_offset_table_length = frame_count * sizeof(uint32_t);
            stream->WriteValue(uint32_t(basic_offset_table_length));

            // Reserve space for the Basic Offset Table.
            basic_offset_table_position = stream->Tell();
            offsets.resize(frame_count, 0);
            stream->Write(offsets.data(), basic_offset_table_length);
        }

        auto first_frame_position = stream->Tell();
        for (size_t i = 0; i < frame_count; ++i) {
            // Remember the fragment offset
            offsets[i] = uint32_t(stream->Tell() - first_frame_position);

            ctx->WriteTagNumber(Item);

            // Write a dummy length.
            auto length_position = stream->Tell();
            ctx->WriteSQLength(ZeroLength);

            // Write the pixel data.
            auto start_position = stream->Tell();
            if (!write_callback(start_frame_index + i, write_func)) {
                return false;
            }
            auto end_position = stream->Tell();

            // Update the dummy length.
            stream->Seek(length_position, ios::beg);
            ctx->WriteSQLength(end_position - start_position);
            stream->Seek(0, std::ios::end);
        }

        // Update the Basic Offset Table.
        if (offsets.size() != 1) {
            stream->Seek(basic_offset_table_position, ios::beg);
            stream->Write(offsets.data(), basic_offset_table_length);
            stream->Seek(0, ios::end);
        }

        // Close the sequence.
        ctx->WriteTagNumber(SequenceDeliminationItem);
        ctx->WriteSQLength(ZeroLength);

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool get_pixel_data_type(
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

    //--------------------------------------------------------------------------------------------------------

    bool write_byte_swapped_func(
        const OutputStreamPtr& stream,
        uint16_t* byte_swap_buffer,
        const void* data,
        size_t length
    ) {
        if (length % sizeof(uint16_t) != 0) {
            // For this situation we enforce a multiple of a whole pixel value.
            return false;
        } 

        const uint8_t* data_ptr = static_cast<const uint8_t*>(data);
        size_t remaining = length;

        while (remaining != 0) {
            // Copy the next block.
            size_t len = std::min(remaining, ByteSwapBufferLength * sizeof(uint16_t));
            memcpy(byte_swap_buffer, data_ptr, len);
            data_ptr += len;
            remaining -= len;

            // Byte-swap each word.
            apply_endian<sizeof(uint16_t)>::Apply(byte_swap_buffer, len / sizeof(uint16_t));

            // Write the block.
            if (!stream->Write(byte_swap_buffer, len)) {
                return false;
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_pixel_data(
        OutputContext* ctx,
        const AttributeSet* metadata,
        const TransferSyntax* transfer_syntax,
        WritePixelDataCallback write_pixel_data_callback
    ) {
        auto& stream = ctx->Stream();

        VRType pixel_data_type;
        if (!get_pixel_data_type(metadata, transfer_syntax, &pixel_data_type)) {
            // Unable to determine the type of VR for pixel data. Fail.
            return false;
        }

        if ((pixel_data_type == VRType::OB) && (transfer_syntax->TagEncoding == TagEncodingType::Implicit)) {
            // Implicit encoding does not convey the type of pixel data. OB is disallowed in this case,
            // but OW is considered OK. (See PS 3.5-2011 Section 8.2, Native or Encapsulated Format Encoding).
            return false;
        }

        size_t start_frame_index;
        size_t frame_count;
        if (!get_frame_count(metadata, &start_frame_index, &frame_count)) {
            // Unable to determine the number of frames in the instance. Fail.
            return false;
        }

        ctx->WriteTagNumber(dicom::tags::PixelData);


        // Write the VR type. Set a dummy length.
        streamoff length_position;
        if (ctx->Encoding() == TagEncodingType::Explicit) {
            stream->WriteValue(pixel_data_type);
            length_position = stream->Tell();
            ctx->WriteExplicitTagLength(pixel_data_type, 0);
        } else {
            length_position = stream->Tell();
            ctx->WriteImplicitTagLength(0);
        }

        auto start_position = stream->Tell();

        unique_ptr<uint16_t[]> byte_swap_buffer;
        WritePixelDataFunction write_pixel_data_func;

        if (transfer_syntax->Endian == EndianType::Little || transfer_syntax->PixelDataEncoding == PixelDataEncodingType::Encapsulated) {
            // Bind to stream->Write() to allow direct pixel data output.
            write_pixel_data_func = std::bind(
                &OutputStream::Write,
                stream.get(),
                std::placeholders::_1,
                std::placeholders::_2
            );
        } else {
            // Bind to write_byte_swapped_func() so we can adjust the endian-ness on the fly.
            byte_swap_buffer.reset(new uint16_t[ByteSwapBufferLength]);
            write_pixel_data_func = std::bind(
                write_byte_swapped_func,
                stream,
                byte_swap_buffer.get(),
                std::placeholders::_1,
                std::placeholders::_2
            );
        }

        bool ok;
        if (transfer_syntax->PixelDataEncoding == PixelDataEncodingType::Native) {
            ok = write_native_pixel_data(
                write_pixel_data_callback,
                write_pixel_data_func,
                start_frame_index,
                frame_count
            );
        } else {
            ok = write_encapsulated_pixel_data(
                ctx,
                write_pixel_data_callback,
                write_pixel_data_func,
                start_frame_index,
                frame_count
            );
        }
        if (!ok) {
            return false;
        }

        auto end_position = stream->Tell();

        auto bytes_written = end_position - start_position;
        if (transfer_syntax->PixelDataEncoding == PixelDataEncodingType::Encapsulated) {
            // Encapsulated pixel data should always have unknown length. write_encapsulated_pixel_data()
            // will have closed the sequence for us.
            bytes_written = 0xFFFFFFFF;
        }

        // Update the dummy length value.
        stream->Seek(length_position, ios::beg);
        if (ctx->Encoding() == TagEncodingType::Explicit) {
            ctx->WriteExplicitTagLength(pixel_data_type, bytes_written);
        } else {
            ctx->WriteImplicitTagLength(bytes_written);
        }
        stream->Seek(0, std::ios::end);

        return true;
    }
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::io::file {

    FileMetadataSink::FileMetadataSink() = default;

    //--------------------------------------------------------------------------------------------------------

    FileMetadataSink::~FileMetadataSink() = default;

    //--------------------------------------------------------------------------------------------------------

    bool FileMetadataSink::Save(
        const string& location,
        const TransferSyntax* transfer_syntax,
        const data::AttributeSetConstPtr& metadata,
        WritePixelDataCallback write_pixel_data_callback
    ) const {
        // Open the file for writing
        detail::OutputStreamPtr stream = make_shared<detail::FileOutputStream>(location);

        // Write the header
        detail::write_header(stream);

        // Write the File Meta Information section (group 0x0002)
        if (!detail::write_file_meta_information(stream, transfer_syntax, metadata.get())) {
            return false;
        }

        // Create the output context for this file. We don't care about the string converter.
        detail::OutputContext context(stream, transfer_syntax, StringEncodingType::ISO_IEC_646);

        // Write the remaining attributes (except the pixel data).
        if (!detail::write_attributes(&context, metadata.get())) {
            return false;
        }

        if (write_pixel_data_callback) {
            if (!write_pixel_data(&context, metadata.get(), transfer_syntax, write_pixel_data_callback)) {
                return false;
            }
        }

        return true;
    }

}