#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/encoded_string.h"
#include "dicom/detail/intrinsic.h"
#include "dicom/io/part10/detail/apply_endian.h"
#include "dicom/io/part10/AttributeFilter.h"
#include "dicom/io/part10/InputStream.h"
#include "dicom/io/TransferSyntax.h"

namespace dicom::io::part10::detail {

    class InputContext
    {
    public:
        // Used for loading the whole dataset
        InputContext(
            const InputStreamPtr& stream,
            const DataDictionaryPtr& dict,
            const TransferSyntax* transfer_syntax,
            AttributeFilter attribute_filter = nullptr,
            PrivateAttributeFilter private_attribute_filter = nullptr
        );

        // Used for loading individual deferred items
        InputContext(
            const InputStreamPtr& stream,
            const DataDictionaryPtr& dict,
            EndianType endian,
            TagEncodingType tag_encoding,
            data::StringEncodingType string_encoding
        );

        InputContext(const InputContext&) = delete;
        InputContext& operator = (const InputContext&) = delete;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Failed() const { return m_deserialization_failure; }
        void SetFailed() { m_deserialization_failure = true; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] EndianType Endian() const { return m_endian; }
        [[nodiscard]] TagEncodingType Encoding() const { return m_encoding; }
        [[nodiscard]] const dicom::DataDictionaryPtr& DataDictionary() const { return m_data_dictionary; }
        
        [[nodiscard]] data::StringEncodingType GetStringEncoding() const { return m_string_encoding; }
        void SetStringEncoding(data::StringEncodingType encoding) { m_string_encoding = encoding; }
        
        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const InputStreamPtr& Stream() const { return m_stream; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] AttributeFilterResult Filter(const dicom::data::AttributeSet* as, tag_number tag) const {
            // Apply the filters in order of likelihood of occurrence.

            if (!is_private_tag(tag)) {
                if (!m_attribute_filter) { return AttributeFilterResult::Load; }
                return m_attribute_filter(tag);
            }

            if (is_creator_tag(tag)) {
                return AttributeFilterResult::Load;
            }

            if (!m_private_attribute_filter) {
                return AttributeFilterResult::Defer;
            }

            const std::string_view* private_creator;
            if (as->TryGetPrivateCreator(tag, &private_creator)) {
                return m_private_attribute_filter(private_creator, tag);
            }
            return AttributeFilterResult::Defer;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] data::VRType LookupVRType(const dicom::data::AttributeSet* as, tag_number tag) const {
            // Apply the lookup in order of likelihood of occurrence.

            if (!is_private_tag(tag)) {
                auto _tag = m_data_dictionary->Get(tag);
                return _tag ? _tag->Type : dicom::data::VRType::UN;
            }

            if (is_creator_tag(tag)) {
                return dicom::data::VRType::LO;
            }

            const std::string_view* private_creator;
            if (as->TryGetPrivateCreator(tag, &private_creator)) {
                auto _tag = m_data_dictionary->Get(*private_creator, tag);
                if (_tag) { return _tag->Type; }
            }
            return dicom::data::VRType::UN;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] tag_number ReadTagNumber() {
            auto tag = m_stream->ReadValue<tag_number>();
            if (m_endian == EndianType::Little) {
                // [d,c,b,a] -> [b,a,d,c]
                return dicom::detail::rotate_left32(tag, 16);
            } else {
                // [c,d,a,b] -> [b,a,d,c]
                return dicom::detail::byte_swap32(tag);
            }
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] std::streamsize ReadImplicitTagLength() {
            auto length = m_stream->ReadValue<uint32_t>();
            if (m_endian == EndianType::Little) {
                return length;
            } else {
                return dicom::detail::byte_swap32(length);
            }
        }
        [[nodiscard]] std::streamsize ReadExplicitTagLength(data::VRType vr_type, std::streamoff end_position);

        [[nodiscard]] std::streamsize ReadSQLength() {
            // This is the same as Implicit tag length handling
            return ReadImplicitTagLength();
        }

        //----------------------------------------------------------------------------------------------------

        template <typename TVR>
        [[nodiscard]] std::unique_ptr<TVR> ReadString(std::streamsize length) {
            // Simply read the string and return it.
            std::string s(static_cast<size_t>(length), '\0');
            if (!TryReadString(length, s)) { return nullptr; }
            return std::make_unique<TVR>(std::move(s));
        }

        //----------------------------------------------------------------------------------------------------

        template <typename TVR>
        [[nodiscard]] std::unique_ptr<TVR> ReadUnicode(std::streamsize length) {
            // Read the string
            auto raw_string = m_stream->ReadBinary(length);
            if (!m_stream->Good()) { return nullptr; }

            // Return it
            return std::make_unique<TVR>(
                data::encoded_string(std::move(raw_string), m_string_encoding)
            );
        }

        //----------------------------------------------------------------------------------------------------

        template <typename TVR>
        [[nodiscard]] std::unique_ptr<TVR> ReadBinary(std::streamsize length) {
            // Sanity check the length
            if (length % sizeof(typename TVR::value_type) != 0) { return nullptr; }

            auto binary = typename TVR::buffer_type(m_stream->ReadBinary(length));
            if (!m_stream->Good()) { return nullptr; }

            if (m_endian == EndianType::Big) {
                // Endian conversion is required.
                apply_endian<sizeof(typename TVR::value_type)>::Apply(binary, binary.Length());
            }

            return std::make_unique<TVR>(std::move(binary));
        }

    private:
        const EndianType m_endian;
        const TagEncodingType m_encoding;
        dicom::DataDictionaryPtr m_data_dictionary;
        data::StringEncodingType m_string_encoding;
        AttributeFilter m_attribute_filter;
        PrivateAttributeFilter m_private_attribute_filter;

        InputStreamPtr m_stream;
        bool m_deserialization_failure;

        bool TryReadString(std::streamsize length, std::string& dest);
    };

}