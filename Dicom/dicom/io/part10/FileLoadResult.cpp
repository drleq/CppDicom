#include "dicom_pch.h"
#include "dicom/io/part10/FileLoadResult.h"

#include "dicom/io/part10/detail/derive_pixel_data_vrtype.h"
#include "dicom/io/part10/detail/discover_pixel_data_fragments.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/read_pixel_data.h"
#include "dicom/io/part10/FileInputStream.h"

#include "dicom/data/UI.h"
#include "dicom/data/US.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/Tags.h"

using namespace std;
using namespace dicom::data;

namespace dicom::io::part10 {

    FileLoadResult::FileLoadResult(
        ReOpenStreamFunction file_stream_factory,
        data::AttributeSetPtr metadata,
        vector<PixelDataRange> pixel_data_ranges
    ) : m_file_stream_factory(move(file_stream_factory)),
        m_metadata(move(metadata)),
        m_pixel_data_ranges(move(pixel_data_ranges)),
        m_transfer_syntax(nullptr),
        m_pixel_data_type(VRType::UN)
    {
        // Get the Transfer Syntax
        auto transfer_syntax_vr00 = m_metadata->Get<data::UI>(tags::TransferSyntaxUID);
        if (transfer_syntax_vr00 == nullptr) { return; }

        m_transfer_syntax = get_transfer_syntax(transfer_syntax_vr00->Value());
        if (m_transfer_syntax == nullptr) { return; }

        // Get the pixel data type
        if (!detail::derive_pixel_data_vrtype(m_metadata.get(), m_transfer_syntax, &m_pixel_data_type)) {
            m_pixel_data_type = VRType::UN;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FileLoadResult::~FileLoadResult() = default;

    //--------------------------------------------------------------------------------------------------------

    bool FileLoadResult::StreamPixelData(size_t frame_index, HandleBulkDataCallback callback) const {
        // Verify the frame index is valid
        if (frame_index >= m_pixel_data_ranges.size()) { return false; }

        // Re-open the stream.
        auto stream = m_file_stream_factory();
        if (!stream) { return false; }

        // Verify the file is large enough
        auto& range = m_pixel_data_ranges[frame_index];
        if ((range.StartOffset() + range.Length()) > static_cast<size_t>(stream->Length())) { return false; }


        bool should_reverse_endian = (m_pixel_data_type == VRType::OW) && (m_transfer_syntax->Endian == EndianType::Big);

        // Seek to the location of the pixel data
        stream->Seek(range.StartOffset(), ios::beg);

        // We don't care about the data dictionary or string converter here.
        detail::InputContext context(stream, nullptr, m_transfer_syntax);

        // Stream the file to the callback
        switch (range.EncodingType()) {
        case PixelDataEncodingType::Native:
            return detail::stream_pixel_data_native(&context, should_reverse_endian, range, callback);

        case PixelDataEncodingType::Encapsulated:
            return detail::stream_pixel_data_encapsulated(&context, should_reverse_endian, range, callback);

        default:
            return false;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    data::buffer<int8_t> FileLoadResult::GetPixelData(size_t frame_index) const {
        // Verify the frame index is valid
        if (frame_index >= m_pixel_data_ranges.size()) { return buffer<int8_t>(); }

        // Re-open the stream.
        auto stream = m_file_stream_factory();
        if (!stream) { return nullptr; }

        // Verify the file is large enough
        auto& range = m_pixel_data_ranges[frame_index];
        if ((range.StartOffset() + range.Length()) > static_cast<size_t>(stream->Length())) { return buffer<int8_t>(); }

        bool should_reverse_endian = (m_pixel_data_type == VRType::OW) && (m_transfer_syntax->Endian == EndianType::Big);

        // Seek to the location of the pixel data
        stream->Seek(range.StartOffset(), ios::beg);

        // We don't care about the data dictionary or string converter here.
        detail::InputContext context(stream, nullptr, m_transfer_syntax);

        // Read all the pixel data
        switch (range.EncodingType()) {
        case PixelDataEncodingType::Native:
            return detail::read_pixel_data_native(&context, should_reverse_endian, range);

        case PixelDataEncodingType::Encapsulated:
            return detail::read_pixel_data_encapsulated(&context, should_reverse_endian, range);

        default:
            return nullptr;
        }
    }

}