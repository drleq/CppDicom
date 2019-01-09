#pragma once

#include "dicom/io/ILoadResult.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/io/part10/InputStream.h"
#include "dicom/io/part10/PixelDataRange.h"

namespace dicom::io::part10 {

    class DICOM_EXPORT FileLoadResult : public ILoadResult
    {
    public:
        FileLoadResult(
            ReOpenStreamFunction file_stream_factory,
            data::AttributeSetPtr metadata,
            std::vector<PixelDataRange> pixel_data_ranges
        );
        virtual ~FileLoadResult();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const data::AttributeSetPtr& Metadata() const override final { return m_metadata; }
        [[nodiscard]] size_t FrameCount() const override final { return m_pixel_data_ranges.size(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool StreamPixelData(size_t frame_index, HandleBulkDataCallback callback) const override final;
        [[nodiscard]] data::buffer<int8_t> GetPixelData(size_t frame_index) const override final;

    private:
        ReOpenStreamFunction m_file_stream_factory;
        data::AttributeSetPtr m_metadata;
        std::vector<PixelDataRange> m_pixel_data_ranges;

        const TransferSyntax* m_transfer_syntax;
        data::VRType m_pixel_data_type;
    };

}