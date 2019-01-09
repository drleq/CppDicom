#include "dicom_pch.h"
#include "dicom/io/part10/detail/read_pixel_data.h"

#include "dicom/io/part10/detail/discover_pixel_data_fragments.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/PixelDataRange.h"

using namespace dicom::data;

namespace dicom::io::part10::detail {

    buffer<int8_t> read_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    ) {
        if (!reverse_endian) {
            auto tmp = ctx->Stream()->ReadBinary(range.Length());
            if (!ctx->Stream()->Good()) { return buffer<int8_t>(); }
            return buffer<int8_t>(std::move(tmp));
        }

        // If we must reverse the endianness then we are forced to take a local copy.  ReadBinary can
        // return a memory-mapped view of the original data, which we don't want to modify.
        buffer<int8_t> tmp(range.Length());
        if (!ctx->Stream()->Read(tmp, range.Length())) { return buffer<int8_t>(); }
        apply_endian<sizeof(uint16_t)>::Apply(tmp, tmp.ByteLength() / sizeof(uint16_t));
        return tmp;
    }

    //--------------------------------------------------------------------------------------------------------

    buffer<int8_t> read_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    ) {
        auto& stream = ctx->Stream();
        auto start_position = stream->Tell();

        // Skip through the file to determine the fragment information.
        size_t real_length;
        auto fragments = detail::discover_pixel_data_fragments(ctx, range.Length(), &real_length);
        if (fragments.empty()) { return buffer<int8_t>(); }

        stream->Seek(start_position, std::ios::beg);
        if (!(*stream)) { return buffer<int8_t>(); }


        if (fragments.size() == 1 && !reverse_endian) {
            // For a single fragment without endian reversal we can just map the binary directly.
            stream->Seek(sizeof(FragmentInfo), std::ios::cur);
            auto tmp = stream->ReadBinary(fragments.front().m_byte_length);
            return buffer<int8_t>(std::move(tmp));
        }


        // Read the fragments
        buffer<int8_t> tmp(real_length);
        int8_t* tmp_ptr = tmp.Get();

        for (auto frag_it = fragments.begin(); frag_it != fragments.end(); ++frag_it) {
            // Skip the fragment header
            stream->Seek(sizeof(FragmentInfo), std::ios::cur);

            // Read the actual data
            if (!stream->Read(tmp_ptr, frag_it->m_byte_length)) { return buffer<int8_t>(); }
            tmp_ptr += frag_it->m_byte_length;
        }

        if (reverse_endian) {
            apply_endian<sizeof(uint16_t)>::Apply(tmp, tmp.ByteLength() / sizeof(uint16_t));
        }

        return tmp;
    }

    //--------------------------------------------------------------------------------------------------------

    bool stream_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    ) {
        constexpr size_t BufferLength = 1024 * 64;
        auto tmp = std::make_unique<int8_t[]>(BufferLength);
        size_t remaining = range.Length();

        auto& stream = ctx->Stream();

        while (remaining > 0 && *stream) {
            size_t read_len = std::min(BufferLength, remaining);
            if (!stream->Read(tmp.get(), read_len)) { return false; }

            if (reverse_endian) {
                apply_endian<sizeof(uint16_t)>::Apply(tmp.get(), read_len / sizeof(uint16_t));
            }

            if (!callback(tmp.get(), read_len)) { return false; }
            remaining -= read_len;
        }

        return stream->Good() && remaining == 0;
    }

    //--------------------------------------------------------------------------------------------------------

    bool stream_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    ) {
        auto& stream = ctx->Stream();
        auto start_position = stream->Tell();

        // Skip through the file to determine the fragment information.
        size_t real_length;
        auto fragments = detail::discover_pixel_data_fragments(ctx, range.Length(), &real_length);
        if (fragments.empty()) { return false; }

        stream->Seek(start_position, std::ios::beg);
        if (!(*stream)) { return false; }

        constexpr size_t BufferLength = 1024 * 64;
        auto tmp = std::make_unique<int8_t[]>(BufferLength);

        for (auto frag_it = fragments.begin(); frag_it != fragments.end(); ++frag_it) {
            // Skip the fragment header
            stream->Seek(sizeof(FragmentInfo), std::ios::cur);

            // Read the actual data
            size_t remaining = frag_it->m_byte_length;
            while (remaining > 0 && *stream) {
                size_t read_len = std::min(BufferLength, remaining);
                if (!stream->Read(tmp.get(), read_len)) { return false; }

                if (reverse_endian) {
                    // FIXME: Are fragments word aligned?
                    apply_endian<sizeof(uint16_t)>::Apply(tmp.get(), read_len / sizeof(uint16_t));
                }

                if (!callback(tmp.get(), read_len)) { return false; }
                remaining -= read_len;
            }

            if (!stream->Good() || (remaining != 0)) { return false; }
        }

        return true;
    }

}