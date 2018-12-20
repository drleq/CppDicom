#include "dicom_pch.h"
#include "dicom/io/file/detail/InputContext.h"

namespace dicom::io::file::detail {

    InputContext::InputContext(
        const InputStreamPtr& stream,
        const dicom::DataDictionaryPtr& dict,
        const TransferSyntax* transfer_syntax,
        AttributeFilter attribute_filter,
        PrivateAttributeFilter private_attribute_filter
    ) : m_endian(transfer_syntax->Endian),
        m_encoding(transfer_syntax->TagEncoding),
        m_data_dictionary(dict),
        m_string_encoding(data::StringEncodingType::ISO_IEC_646),
        m_attribute_filter(attribute_filter),
        m_private_attribute_filter(private_attribute_filter),
        m_stream(stream),
        m_deserialization_failure(false)
    {}

    //--------------------------------------------------------------------------------------------------------

    InputContext::InputContext(
        const InputStreamPtr& stream,
        const dicom::DataDictionaryPtr& dict,
        EndianType endian,
        TagEncodingType tag_encoding,
        data::StringEncodingType string_encoding
    ) : m_endian(endian),
        m_encoding(tag_encoding),
        m_data_dictionary(dict),
        m_string_encoding(string_encoding),
        m_attribute_filter(nullptr),
        m_private_attribute_filter(nullptr),
        m_stream(stream),
        m_deserialization_failure(false)
    {}

    //--------------------------------------------------------------------------------------------------------

    std::streamsize InputContext::ReadExplicitTagLength(data::VRType vr_type, std::streamoff end_position) {
        uint16_t default_length = m_stream->ReadValue<uint16_t>();
        if (m_endian == EndianType::Big) {
            default_length = __builtin_bswap16(default_length);
        }

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
            // Read the large tag 32bit length
            auto length = m_stream->ReadValue<uint32_t>();
            if (m_endian == EndianType::Big) {
                length = __builtin_bswap32(length);
            }

            // Correct the special case length of 0xFFFFFFFF, meaning all remaining data
            if (length == 0xFFFFFFFF) {
                auto len = end_position - m_stream->Tell();
                length = (len < 0) ? 0 : static_cast<uint32_t>(len);
            }
            return length;
        }

        default:
            return default_length;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    bool InputContext::TryReadString(std::streamsize length, std::string& dest) {
        if (length == 0) { return true; }

        // Read the string data
        if (!m_stream->Read(dest.data(), static_cast<size_t>(length))) { return false; }

        // Strings may be padded to even length. Or odd length. Or with the wrong character.
        switch (dest.back()) {
        case ' ':
        case '\0':
            dest.resize(dest.size() - 1);
            break;
        }
        return true;
    }

}