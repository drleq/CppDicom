#include "dicomnet_pch.h"
#include "dicom/net/detail/CommandSetDecoder.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/data/StringEncodingType.h"
#include "dicom/data/UL.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/MemoryInputStream.h"
#include "dicom/net/detail/get_data_dictionary.h"
#include "dicom/net/detail/read_data_element.h"
#include "dicom/net/Tags.h"

namespace {
    constexpr size_t CommandSetLengthLength =
        sizeof(dicom::tag_number) +  // Tag Number
        sizeof(uint32_t) +    // Implicit Attribute Length
        sizeof(uint32_t);     // Value
}

namespace dicom::net::detail {

    CommandSetDecoder::CommandSetDecoder() = default;

    //--------------------------------------------------------------------------------------------------------

    CommandSetDecoder::~CommandSetDecoder() = default;

    //--------------------------------------------------------------------------------------------------------

    CommandSetDecoder::CommandSetDecoder(CommandSetDecoder&&) = default;
    CommandSetDecoder& CommandSetDecoder::operator = (CommandSetDecoder&&) = default;

    //--------------------------------------------------------------------------------------------------------

    void CommandSetDecoder::SupplyData(const dicom::net::input_buffer& data) {
        m_buffer.insert(
            m_buffer.end(),
            reinterpret_cast<const uint8_t*>(data.data()),
            reinterpret_cast<const uint8_t*>(data.data()) + data.size()
        );

        if (m_decode_failed || m_cs) {
            // Either the decode failed or it has already completed.
            return;
        }

        if (!m_cs_length) {
            // Try to decode the CommandSetLength

            if (m_buffer.size() < CommandSetLengthLength) {
                // Not enough data
                return;
            }

            AttemptDecodeLength();
            if (m_decode_failed) {
                // Failed to decode the data
                return;
            }
        }

        // [m_cs_length] must be valid here.

        if (m_buffer.size() < *m_cs_length + CommandSetLengthLength) {
            // Not enough data
            return;
        }

        AttemptDecodeCommandSet();
    }

    //--------------------------------------------------------------------------------------------------------

    void CommandSetDecoder::AttemptDecodeLength() {
        auto stream = std::make_shared<io::part10::MemoryInputStream>(
            std::make_shared<io::part10::MemoryInputView>(m_buffer.data(), m_buffer.size())
        );
        io::part10::detail::InputContext ctx{
            stream,
            get_data_dictionary(),
            io::EndianType::Little,
            io::TagEncodingType::Implicit,
            data::StringEncodingType::ISO_IEC_646
        };

        tag_number tag;
        std::unique_ptr<data::VR> attrib;
        bool result = read_data_element(ctx, &tag, &attrib);
        if (!result || tag != tags::CommandGroupLength || attrib->Type() != data::VRType::UL) {
            m_decode_failed = true;
            return;
        }

        auto typed_attrib = static_cast<data::UL*>(attrib.get());
        if (typed_attrib->Length() != 1) {
            m_decode_failed = true;
            return;
        }

        m_cs_length = typed_attrib->First();
    }

    //--------------------------------------------------------------------------------------------------------

    void CommandSetDecoder::AttemptDecodeCommandSet() {
        auto stream = std::make_shared<io::part10::MemoryInputStream>(
            std::make_shared<io::part10::MemoryInputView>(
                m_buffer.data() + CommandSetLengthLength,
                *m_cs_length
            )
        );
        io::part10::detail::InputContext ctx{
            stream,
            get_data_dictionary(),
            io::EndianType::Little,
            io::TagEncodingType::Implicit,
            data::StringEncodingType::ISO_IEC_646
        };

        auto command_set = std::make_unique<data::AttributeSet>();

        std::streampos end_pos = ctx.Stream()->Tell() + *m_cs_length;
        while (ctx.Stream()->Tell() < end_pos) {
            tag_number tag;
            std::unique_ptr<data::VR> attrib;
            auto result = read_data_element(ctx, &tag, &attrib);

            if (!result || get_tag_group(tag) != 0x0000) {
                m_decode_failed = true;
                return;
            }

            command_set->Add(tag, std::move(attrib));
        }

        m_cs = std::move(command_set);
    }

}