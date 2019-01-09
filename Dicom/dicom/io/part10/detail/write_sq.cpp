#include "dicom_pch.h"
#include "dicom/io/part10/detail/write_sq.h"

#include "dicom/data/SQ.h"
#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/detail/write_sq_item.h"

namespace {
    constexpr dicom::tag_number Item = 0xFFFEE000;
    constexpr dicom::tag_number SequenceDeliminationItem = 0xFFFEE0DD;
    constexpr uint32_t ZeroLength = 0;
}

namespace dicom::io::part10::detail {

    void write_sq(OutputContext* ctx, const data::SQ* sq, bool unknown_length) {
        // Check for implicit private SQ -> write out undefined length

        auto& stream = ctx->Stream();
        
        for (auto& item : sq->Items()) {
            if (!*stream || ctx->Failed()) { return; }

            // Start the next item.
            ctx->WriteTagNumber(Item);

            // Write a dummy length value.
            auto length_position = stream->Tell();
            ctx->WriteSQLength(ZeroLength);

            // Write the item.
            auto start_position = stream->Tell();
            write_sq_item(ctx, item, false);
            auto end_position = stream->Tell();

            // Update the length value.
            stream->Seek(length_position, std::ios::beg);
            ctx->WriteSQLength(end_position - start_position);
            stream->Seek(0, std::ios::end);
        }

        if (!*stream || ctx->Failed()) { return; }

        if (unknown_length) {
            // Close the sequence.
            ctx->WriteTagNumber(SequenceDeliminationItem);
            ctx->WriteSQLength(ZeroLength);
        }
    }

}