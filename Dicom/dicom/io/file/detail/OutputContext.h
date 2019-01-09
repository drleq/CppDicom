#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/encoded_string.h"
#include "dicom/data/StringEncodingType.h"
#include "dicom/data/VRType.h"
#include "dicom/detail/intrinsic.h"
#include "dicom/io/file/detail/apply_endian.h"
#include "dicom/io/file/OutputStream.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/tag_number.h"

namespace dicom::io::file::detail {

    class OutputContext
    {
    public:
        OutputContext(
            const OutputStreamPtr& stream,
            const TransferSyntax* transfer_syntax,
            data::StringEncodingType string_encoding
        );

        OutputContext(const OutputContext&) = delete;
        OutputContext& operator = (const OutputContext&) = delete;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Failed() const { return m_serialization_failure; }
        void SetFailed() { m_serialization_failure = true; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] EndianType Endian() const { return m_endian; }
        [[nodiscard]] TagEncodingType Encoding() const { return m_encoding; }

        [[nodiscard]] data::StringEncodingType GetStringEncoding() const { return m_string_encoding; }
        void SetStringEncoding(data::StringEncodingType encoding) { m_string_encoding = encoding; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const OutputStreamPtr& Stream() const { return m_stream; }

        //----------------------------------------------------------------------------------------------------

        void WriteTagNumber(tag_number tag) {
            tag_number val;
            if (m_endian == EndianType::Little) {
                // [b,a,d,c] -> [d,c,b,a]
                val = dicom::detail::rotate_left32(tag, 16);
            } else {
                // [b,a,d,c] -> [c,d,a,b]
                val = dicom::detail::byte_swap32(tag);
            }
            m_stream->WriteValue(val);
        }

        //----------------------------------------------------------------------------------------------------

        void WriteImplicitTagLength(std::streamsize length) {
            if (length > 0xFFFFFFFF) {
                SetFailed();
                return;
            }

            uint32_t val = static_cast<uint32_t>(length);
            if (m_endian == EndianType::Big) {
                val = dicom::detail::byte_swap32(val);
            }
            m_stream->WriteValue(val);
        }
        void WriteExplicitTagLength(data::VRType vr_type, std::streamsize length);

        void WriteSQLength(std::streamsize length) {
            // This is the same as Implicit tag length handling
            WriteImplicitTagLength(length);
        }

        //----------------------------------------------------------------------------------------------------

        void WriteString(const std::string& src);
        void WriteUIString(const std::string& src);
        void WriteUnicode(const data::encoded_string& src);

        //----------------------------------------------------------------------------------------------------

        template <typename TVR>
        void WriteBinary(const TVR* attribute) {
            auto& binary = attribute->Value();

            if (m_endian == EndianType::Little) {
                // If endian conversion is not required then simply write the data.
                m_stream->Write(binary, binary.ByteLength());
            } else {
                // If endian conversion is required then convert it in chunks.
                const size_t TmpCapacity = 4096;
                auto tmp = std::make_unique<typename TVR::value_type[]>(TmpCapacity);

                auto binary_ptr = binary.Get();

                size_t remaining = binary.Length();
                while (remaining != 0) {
                    // Copy the next chunk
                    size_t len = std::min(remaining, TmpCapacity);
                    memcpy(tmp.get(), binary_ptr, len * sizeof(typename TVR::value_type));

                    // Convert to big endian
                    apply_endian<sizeof(typename TVR::value_type)>::Apply(tmp.get(), len);

                    // Write the data
                    m_stream->Write(tmp.get(), len * sizeof(typename TVR::value_type));
                    remaining -= len;
                    binary_ptr += len;
                }
            }
        }

    private:
        const EndianType m_endian;
        const TagEncodingType m_encoding;
        data::StringEncodingType m_string_encoding;

        OutputStreamPtr m_stream;
        bool m_serialization_failure;
    };

}