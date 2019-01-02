#pragma once

#include "dicom/data/ValidityType.h"

namespace dicom::data {

    class DICOM_EXPORT uri_section
    {
    public:
        uri_section();
        uri_section(std::string_view&& value);
        ~uri_section();

        [[nodiscard]] explicit operator bool() const { return m_value.has_value(); }
        [[nodiscard]] const std::string_view& operator*() const { return *m_value; }
        [[nodiscard]] const std::string_view& Unescaped() const { return *m_value; }
        [[nodiscard]] std::string Escaped() const;

    private:
        std::optional<std::string_view> m_value;
    };

    //--------------------------------------------------------------------------------------------------------

    class DICOM_EXPORT uri
    {
    public:
        using optional_section = std::optional<std::string>;

    public:
        uri();
        uri(const char* value, bool is_escaped = false);
        uri(const std::string_view& value, bool is_escaped = false);
        uri(std::string&& value, bool is_escaped = false);
        uri(
            const std::string_view& scheme,
            const std::string_view& path,
            const optional_section& host = optional_section(),
            const optional_section& port = optional_section(),
            const optional_section& authentication = optional_section(),
            const optional_section& query = optional_section(),
            const optional_section& fragment = optional_section()
        );
        uri(const uri& other);
        uri(uri&& other);
        ~uri();

        uri& operator = (const uri& other);
        uri& operator = (uri&& other);

    public:
        [[nodiscard]] const std::string& Value() const { return m_value; }
        [[nodiscard]] ValidityType Validity() const { return m_validity; }

        [[nodiscard]] const uri_section& Scheme() const;
        [[nodiscard]] const uri_section& Authentication() const;
        [[nodiscard]] const uri_section& Host() const;
        [[nodiscard]] const uri_section& Port() const;
        [[nodiscard]] const uri_section& Path() const;
        [[nodiscard]] const uri_section& Query() const;
        [[nodiscard]] const uri_section& Fragment() const;

        [[nodiscard]] int Compare(const uri& other) const;
        [[nodiscard]] bool operator == (const uri& other) const;
        [[nodiscard]] bool operator != (const uri& other) const;

    private:
        std::string m_value;
        ValidityType m_validity;

        uri_section m_scheme;
        uri_section m_authentication;
        uri_section m_host;
        uri_section m_port;
        uri_section m_path;
        uri_section m_query;
        uri_section m_fragment;

        void Initialize(std::string&& unescaped_value);
    };

}