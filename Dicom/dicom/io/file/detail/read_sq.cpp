#include "dicom_pch.h"
#include "dicom/io/file/detail/read_sq.h"

#include "dicom/data/SQ.h"
#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_sq_item.h"

using namespace std;

namespace {
    constexpr dicom::tag_number Item = 0xFFFEE000;
    constexpr dicom::tag_number SequenceDeliminationItem = 0xFFFEE0DD;
}

namespace dicom::io::file::detail {

    unique_ptr<data::SQ> read_sq(InputContext& ctx, streamsize length) {
        // Implicitly encoded SQ attributes with length 0xFFFFFFFF are handled differently. As they have no
        // defined length you are expected to keep reading until either the data runs out or the sequence
        // delimiter is encountered.
        if ((ctx.Encoding() == TagEncodingType::Implicit) && (length == 0xFFFFFFFF)) {
            length = ctx.Stream()->Length() - ctx.Stream()->Tell();
        }

        auto& stream = ctx.Stream();
        auto end_position = stream->Tell() + length;

        data::SQ::container_type items;
        while (stream->Tell() < end_position && !ctx.Failed()) {
            // Read the next tag.
            auto tag = ctx.ReadTagNumber();

            // Read the length of the tag.
            auto item_length = ctx.ReadSQLength();

            // If this is the end of the sequence then stop.
            if (tag == SequenceDeliminationItem) { break; }

            // Only other possibility should be an item.
            if (tag != Item) {
                ctx.SetFailed();
                break;
            }

            // Handle the special case length of 0xFFFFFFFF, meaning all remaining data.
            if (item_length == 0xFFFFFFFF) {
                auto len = end_position - stream->Tell();

                // There is a SequenceDeliminationItem after this one to terminate the sequence. Adjust
                // the length accordingly.
                len = len - sizeof(tag_number) - sizeof(uint32_t);

                // Verify the remaining length is sane.
                if (len < 0) {
                    ctx.SetFailed();
                    break;
                }

                item_length = static_cast<uint32_t>(len);
            }

            items.emplace_back(read_sq_item(ctx, item_length));
        }

        if (*stream && !ctx.Failed()) { return make_unique<data::SQ>(move(items)); }
        return nullptr;
    }

}