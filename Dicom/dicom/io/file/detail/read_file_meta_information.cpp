#include "dicom_pch.h"
#include "dicom/io/file/detail/read_file_meta_information.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/Tags.h"

#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_data_element.h"

namespace dicom::io::file::detail {

    bool read_file_meta_information(
        const InputStreamPtr& stream,
        const DataDictionaryPtr& data_dictionary,
        data::AttributeSet* dest
    ) {
        // The FileMetaInformation group is always explicit little endian with default string encoding.
        InputContext ctx(stream, data_dictionary, &transfer_syntax::ExplicitLittle);

        while (*stream && !ctx.Failed()) {
            // Peek the tag group
            auto group = stream->ReadValue<tag_group>();
            stream->Seek(-(int)sizeof(tag_group), std::ios::cur);

            // Stop if we reach the end of the group
            if (group != tags::FileMetaInformationGroupLength.Group()) { break; }

            // Read the next data element
            tag_number tag;
            auto vr = read_data_element(ctx, dest, &tag);
            if (vr == nullptr) { continue; }
            dest->Add(tag, std::move(vr));
        }

        return stream->Good() && !ctx.Failed();
    }

}