#pragma once

namespace dicom::data { class AttributeSet; }
#include "dicom/net/DataStorage.h"

namespace dicom::net::detail {

    class CommandSetDecoder
    {
    public:
        CommandSetDecoder();
        ~CommandSetDecoder();

        CommandSetDecoder(CommandSetDecoder&&);
        CommandSetDecoder& operator = (CommandSetDecoder&&);

        void SupplyData(const dicom::net::input_buffer& data);

        bool HasDecodeFailed() const { return m_decode_failed; }
        bool IsComplete() const { return m_cs != nullptr; }

        std::unique_ptr<dicom::data::AttributeSet> DetachCommandSet() { return std::move(m_cs); }

    private:
        dicom::net::data_buffer m_buffer;

        bool m_decode_failed = false;
        std::optional<std::streamsize> m_cs_length;
        std::unique_ptr<dicom::data::AttributeSet> m_cs;

        void AttemptDecodeLength();
        void AttemptDecodeCommandSet();
    };

}