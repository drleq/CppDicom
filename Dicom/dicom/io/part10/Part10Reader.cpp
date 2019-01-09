#include "dicom_pch.h"
#include "dicom/io/part10/Part10Reader.h"

#include <filesystem>

#include "dicom/io/part10/detail/derive_pixel_data_ranges.h"
#include "dicom/io/part10/detail/read_file_meta_information.h"
#include "dicom/io/part10/detail/read_attributes.h"
#include "dicom/io/part10/detail/verify_header.h"
#include "dicom/io/part10/Part10LoadResult.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/data/UI.h"
#include "dicom/Tags.h"

using namespace std;

namespace dicom::io::part10 {

    LoadResultPtr Part10Reader::Read(
        const InputStreamPtr& stream,
        const DataDictionaryPtr& data_dictionary,
        AttributeFilter attribute_filter,
        PrivateAttributeFilter private_attribute_filter
    ) {
        // Verify the stream is OK
        if (!stream || !stream->Good()) { return nullptr; }

        // Verify the header
        if (!detail::verify_header(stream)) { return nullptr; }

        // Read the File Meta Information section (group 0x0002)
        auto metadata = make_shared<data::AttributeSet>();
        if (!detail::read_file_meta_information(stream, data_dictionary, metadata.get())) {
            return nullptr;
        }


        // If the TransferSyntaxUID is missing then we cannot determine the encoding mode.
        auto transfer_syntax_uid = metadata->Get<data::UI>(tags::TransferSyntaxUID);
        if (transfer_syntax_uid == nullptr) { return nullptr; }

        // If the TransferSyntaxUID is unknown then we cannot determine the encoding mode.
        auto transfer_syntax = get_transfer_syntax(transfer_syntax_uid->Value());
        if (transfer_syntax == nullptr) { return nullptr; }

        // Read the rest of the file. Initially use the default string converter.
        detail::InputContext context(
            stream,
            data_dictionary,
            transfer_syntax,
            attribute_filter,
            private_attribute_filter
        );

        // Read the remaining attributes
        vector<PixelDataRange> pixel_ranges;
        if (!detail::read_attributes(context, metadata.get(), &pixel_ranges)) {
            return nullptr;
        }
        
        return make_shared<Part10LoadResult>(stream->CreateReOpenFunction(), metadata, pixel_ranges);
    }

}