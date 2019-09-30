#include "dicomnet_pch.h"
#include "dicom/net/detail/encode_command_set.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/MemoryOutputStream.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/net/detail/write_data_element.h"
#include "dicom/net/Tags.h"

namespace dicom::net::detail {

    DataStoragePtr encode_command_set(const data::AttributeSet& command_set) {
        auto stream = std::make_shared<io::part10::MemoryOutputStream>();
        io::part10::detail::OutputContext ctx{
            stream,
            &io::transfer_syntax::ImplicitLittle,
            data::StringEncodingType::ISO_IEC_646
        };

        // Write a dummy CommandGroupLength.
        ctx.WriteTagNumber(tags::CommandGroupLength);
        ctx.WriteImplicitTagLength(4);
        stream->WriteValue(0U);

        // Output all attributes in the command set
        auto start_pos = stream->Tell();
        for (auto [tag, attrib] : command_set) {
            net::detail::write_data_element(ctx, tag, attrib);
        }
        auto end_pos = stream->Tell();

        // Update the CommandGroupLength
        stream->Seek(8, std::ios_base::beg);
        stream->WriteValue(static_cast<uint32_t>(end_pos - start_pos));

        return std::make_shared<SharedValueDataStorage>(stream->Detach());
    }

}