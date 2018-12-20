#include "dicomtest_pch.h"

#include "dicom_test/data/string_converter/detail/CharacterMapping.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

#include <iostream>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

using namespace std;

namespace {
    void SetUTF8(uint32_t utf32, std::string& str) {
        str.resize(6);

        auto str_begin = reinterpret_cast<uint8_t*>(str.data());
        auto str_ptr = str_begin;
        auto str_end = str_begin + 6;
        [[maybe_unused]] auto dummy = dicom::data::string_converter::detail::encode_utf8_char(utf32, str_ptr, str_end);

        str.resize(std::distance(str_begin, str_ptr));
    }

    //--------------------------------------------------------------------------------------------------------

    bool CheckUTF8(uint32_t utf32, const std::string& str) {
        auto str_begin = reinterpret_cast<const uint8_t*>(str.data());
        auto str_end = str_begin + str.size();

        char32_t decoded;
        if (!dicom::data::string_converter::detail::decode_utf8_char(str_begin, str_end, decoded)) {
            return false;
        }

        return (decoded == utf32);
    }

    //--------------------------------------------------------------------------------------------------------

    uint32_t ConvertToHex(const char* str) {
        return strtol(str, nullptr, 16);
    }

    //--------------------------------------------------------------------------------------------------------

    std::string ConvertByteSequence(const char* str) {
        std::string seq;
        auto str_ptr = str;
        while (true) {
            seq.push_back((char)strtol(str_ptr, nullptr, 16));
            if (str_ptr[2] == '\0') { break; }
            str_ptr += 3; // 2 hex chars + 1 space
        }
        return seq;
    }
}

namespace dicom_test::data::string_converter::detail {

    CharacterMapping::CharacterMapping(const std::filesystem::path& xml_file) {
        rapidxml::file<> in(xml_file.string().c_str());
        rapidxml::xml_document<> xml_tree;
        xml_tree.parse<rapidxml::parse_default>(in.data());

        auto root = xml_tree.first_node("characterMapping");

        // Get the valid byte sequence ranges
        auto validity = root->first_node("validity");
        set<string> unique_types;
        vector<ByteRangeGroupPtr> valid_ranges;

        // First pass. Extract named ranges.
        for (auto node = validity->first_node(); node; node = node->next_sibling()) {
            if (strcmp(node->name(), "state") == 0) {
                unique_types.emplace(node->first_attribute("type")->value());
                valid_ranges.emplace_back(new ByteRangeGroup);
            }
        }

        // Second pass. Construct the linked ranges.
        m_root_valid_range = valid_ranges[0];
        for (auto node = validity->first_node(); node; node = node->next_sibling()) {
            if (strcmp(node->name(), "state") == 0) {
                auto start = node->first_attribute("s")->value();
                auto end   = node->first_attribute("e")->value();
                auto type  = node->first_attribute("type")->value();
                auto next  = node->first_attribute("next")->value();
                auto index = distance(unique_types.begin(), unique_types.find(type));

                ByteRangeGroupPtr next_ptr;
                if (strcmp(next, "VALID") != 0) {
                    auto next_index = distance(unique_types.begin(), unique_types.find(next));
                    next_ptr = valid_ranges[next_index];
                }
                valid_ranges[index]->Add(
                    (uint8_t)strtol(start, nullptr, 16),
                    (uint8_t)strtol(end, nullptr, 16),
                    next_ptr
                );
            }
        }


        // Get the direct assignments
        auto assignments = root->first_node("assignments");
        for (auto node = assignments->first_node(); node; node = node->next_sibling()) {
            if (strcmp(node->name(), "a") == 0) {
                auto seq = ConvertByteSequence(node->first_attribute("b")->value());
                m_valid_unicode_values.emplace(
                    make_pair(
                        ConvertToHex(node->first_attribute("u")->value()),
                        std::move(seq)
                    )
                );
            } else if (strcmp(node->name(), "range") == 0) {
                m_valid_unicode_ranges.emplace_back(
                    RangeAssignment(
                        ConvertByteSequence(node->first_attribute("bFirst")->value()),
                        ConvertByteSequence(node->first_attribute("bLast")->value()),
                        ConvertToHex(node->first_attribute("uFirst")->value()),
                        ConvertToHex(node->first_attribute("uLast")->value())
                    )
                );
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    CharacterMapping::CharacterMapping(
        const std::filesystem::path& text_file,
        const ByteRangeGroupPtr& root_valid_range,
        std::function<bool (std::string&)> filter00
    ) {
        ifstream in(text_file.string());

        char line[1024];
        string byte_sequence;

        while (in.good()) {
            in.getline(line, sizeof(line));
            if (in.gcount() == 0) { break; }

            // Ignore comments and blank lines.
            if (line[0] == '#') { continue; }
            if (line[0] == '\0' || line[0] == '\n') { continue; }

            auto line_ptr = &line[2];
            auto byte_sequence_int = strtol(line_ptr, &line_ptr, 16);
            byte_sequence.assign((char*)&byte_sequence_int, (((line_ptr - line) - 2) + 1) / 2);
            std::reverse(byte_sequence.begin(), byte_sequence.end());

            auto unicode = strtol(line_ptr, &line_ptr, 16);

            if (filter00 && !filter00(byte_sequence)) { continue; }

            m_valid_unicode_values.emplace(make_pair(unicode, byte_sequence));
        }

        m_root_valid_range = root_valid_range;
    }

    //--------------------------------------------------------------------------------------------------------

    bool CharacterMapping::CheckValidByteSequences(StringConverterToUTF8 converter) const {
        std::string tmp;

        for (auto& kvp : m_valid_unicode_values) {
            tmp.clear();
            if (!converter(kvp.second, tmp)) {
                return false;
            }
            if (!CheckUTF8(kvp.first, tmp)) {
                return false;
            }
        }

        std::string seq_tmp;
        for (auto& range : m_valid_unicode_ranges) {
            std::string seq;
            uint32_t offset = 0;
            bool ok = m_root_valid_range->EnumerateValidByteSequences(
                range,
                true,
                true,
                seq,
                offset,
                [&](const std::string& byte_sequence, uint32_t unicode) -> bool {
                    tmp.clear();

                    if (!converter(byte_sequence, tmp)) {
                        return false;
                    }
                    if (!CheckUTF8(unicode, tmp)) {
                        return false;
                    }
                    return true;
                }
            );
            if (!ok) {
                return false;
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool CharacterMapping::CheckValidUnicodeValues(StringConverterFromUTF8 converter) const {
        std::string tmp;
        std::string dest;

        for (auto& kvp : m_valid_unicode_values) {
            SetUTF8(kvp.first, tmp);

            if (!converter(tmp, dest)) {
                return false;
            }
            if (dest != kvp.second) {
                return false;
            }
        }

        for (auto& range : m_valid_unicode_ranges) {
            std::string seq;
            uint32_t offset = 0;
            auto ok = m_root_valid_range->EnumerateValidByteSequences(
                range,
                true,
                true,
                seq,
                offset,
                [&](const std::string& byte_sequence, uint32_t unicode) -> bool {
                    SetUTF8(unicode, tmp);

                    if (!converter(tmp, dest)) {
                        return false;
                    }
                    if (dest != byte_sequence) {
                        return false;
                    }

                    return true;
                }
            );
            if (!ok) {
                return false;
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool CharacterMapping::CheckInvalidByteSequences(StringConverterToUTF8 converter) const {
        std::string seq;
        return m_root_valid_range->CheckInvalidByteSequences(m_root_valid_range, seq, converter);
    }

    //--------------------------------------------------------------------------------------------------------

    bool CharacterMapping::CheckInvalidUnicodeValues(StringConverterFromUTF8 converter) const {
        std::vector<uint32_t> valid_codes;

        // Build a vector of all valid UTF-32 values.
        valid_codes.reserve(m_valid_unicode_values.size());
        for (auto& kvp : m_valid_unicode_values) {
            valid_codes.push_back(kvp.first);
        }

        for (auto& range : m_valid_unicode_ranges) {
            auto start = range.StartUnicode();
            auto end = range.EndUnicode();
            valid_codes.reserve(valid_codes.size() + (end - start));
            for (uint32_t u = start; u <= end; u++) {
                valid_codes.push_back(u);
            }
        }

        std::sort(valid_codes.begin(), valid_codes.end());


        // Check the invalid codes between the values.
        std::string tmp;
        std::string dest;

        auto it = valid_codes.begin();
        auto end_it = valid_codes.end() - 1;
        do {
            uint32_t first_invalid = (*it) + 1;
            it++;
            uint32_t last_invalid = (*it) - 1;
            it++;

            for (uint32_t utf32 = first_invalid; utf32 <= last_invalid; utf32++) {
                SetUTF8(utf32, tmp);

                if (converter(tmp, dest)) {
                    std::cout << "F1: 0x" << utf32 << std::endl;
                    return false;
                }
            }
        } while (it < end_it);

        if (valid_codes.back() < 0x10FFFF) {
            uint32_t first_invalid = valid_codes.back() + 1;
            uint32_t last_invalid = 0x10FFFF;
            for (uint32_t utf32 = first_invalid; utf32 <= last_invalid; utf32++) {
                SetUTF8(utf32, tmp);

                if (converter(tmp, dest)) {
                    std::cout << "F2: 0x" << utf32 << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

}