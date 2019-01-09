#include "dicom_pch.h"
#include "dicom/io/part10/detail/OutputContext.h"

#include "dicom/data/VRType.h"
#include "dicom/data/string_converter/StringConverter.h"
#include "dicom/detail/intrinsic.h"

namespace dicom::io::part10::detail {

    OutputContext::OutputContext(
        const OutputStreamPtr& stream,
        const TransferSyntax* transfer_syntax,
        data::StringEncodingType string_encoding
    ) : m_endian(transfer_syntax->Endian),
        m_encoding(transfer_syntax->TagEncoding),
        m_string_encoding(string_encoding),
        m_stream(stream),
        m_serialization_failure(false)
    {}

    //--------------------------------------------------------------------------------------------------------

    void OutputContext::WriteExplicitTagLength(data::VRType vr_type, std::streamsize length) {
        switch (vr_type) {
        case data::VRType::OB:
        case data::VRType::OD:
        case data::VRType::OF:
        case data::VRType::OL:
        case data::VRType::OW:
        case data::VRType::SQ:
        case data::VRType::UC:
        case data::VRType::UN:
        case data::VRType::UR:
        case data::VRType::UT: {
            // Sanity check the length being written.
            if (length > 0xFFFFFFFF) {
                SetFailed();
                return;
            }

            // The default length is ignored. Set it to zero.
            m_stream->WriteValue(uint16_t(0));

            // Write the large tag length
            uint32_t len = static_cast<uint32_t>(length);
            if (m_endian == EndianType::Big) {
                len = dicom::detail::byte_swap32(len);
            }
            m_stream->WriteValue(len);
            break;
        }

        default:
            // Sanity check the length being written.
            if (length > 0xFFFF) {
                SetFailed();
                return;
            }

            // Write the default length.
            uint16_t len = static_cast<uint16_t>(length);
            if (m_endian == EndianType::Big) {
                len = dicom::detail::byte_swap16(len);
            }
            m_stream->WriteValue(len);
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void OutputContext::WriteString(const std::string& src) {
        if (src.empty()) { return; }

        // Write the string data
        if (!m_stream->Write(src.data(), src.size())) { return; }

        // Strings should be padded to even length. UI is padded with '\0' while others use space.
        if (src.size() & 1) {
            m_stream->WriteValue(uint8_t(' '));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void OutputContext::WriteUnicode(const data::encoded_string& src) {
        if (src.Value().Empty()) { return; }

        data::buffer<char> converted;
        const data::buffer<char>* encoded = &src.Value();

        if (src.Encoding() != m_string_encoding) {
            // [src] must be convertable to UTF-16.
            if (src.Validity() != data::ValidityType::Valid) {
                SetFailed();
                return;
            }

            // Convert the string via UTF-16
            if (!data::string_converter::convert_from_utf8(m_string_encoding, src.Parsed(), converted)) {
                SetFailed();
                return;
            }

            encoded = &converted;
        }

        // Write the encoded data
        if (!m_stream->Write(*encoded, encoded->ByteLength())) { return; }

        // Strings should be padded to even length. UI is padded with '\0' while others use space.
        if (encoded->ByteLength() & 1) {
            m_stream->WriteValue(uint8_t(' '));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void OutputContext::WriteUIString(const std::string& src) {
        if (src.empty()) { return; }

        // Write the string data
        if (!m_stream->Write(src.data(), src.size())) { return; }

        // Strings should be padded to even length. UI is padded with '\0' while others use space.
        if (src.size() & 1) {
            m_stream->WriteValue(uint8_t('\0'));
        }
    }

}