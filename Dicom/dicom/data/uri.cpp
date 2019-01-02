#include "dicom_pch.h"
#include "dicom/data/uri.h"

#include <cctype>
#include <sstream>

using namespace std;

namespace {
    using namespace dicom::data;

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] uint8_t ascii_to_lower(uint8_t c) {
        char tmp = c | 0x20;
        if (tmp >= 'a' && tmp <= 'z') { return tmp; }
        return c;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool needs_escaped(uint8_t c) {
        // List taken from RFC 2396 section 2.4.3 Excluded US-ASCII Characters.

        // Control characters should have been escaped.
        if (c <= 0x1F) { return true; }

        // UTF-8 code points should be escaped.
        if (c >= 0x80) { return true; }

        switch (c) {
        case 0x20: // Space
        case 0x7F: // Delete

        // Reserved characters
        case ';':
        case '/':
        case '?':
        case ':':
        case '@':
        case '&':
        case '=':
        case '+':
        case '$':
        case ',':

        // Delimiters
        case '<':
        case '>':
        case '#':
        case '%':
        case '"':

        // Unwise
        case '{':
        case '}':
        case '|':
        case '\\':
        case '^':
        case '[':
        case ']':
        case '`':
            return true;

        default:
            return false;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_hex_character(uint8_t c) {
        c = ascii_to_lower(c);
        if (c >= '0' && c <= '9') { return true; }
        if (c >= 'a' && c <= 'f') { return true; }
        return false;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_sub_delimiter(uint8_t c) {
        switch (c) {
        case '!':
        case '$':
        case '&':
        case '\'':
        case '(':
        case ')':
        case '*':
        case '+':
        case ',':
        case ';':
        case '=':
            return true;

        default:
            return false;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_unreserved(uint8_t c) {
        return std::isalnum(c) || (c == '-') || (c == '.') || (c == '_') || (c == '~');
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] std::string escape_string(const std::string_view& source) {
        std::string escaped;
        escaped.reserve(source.size());

        for (uint8_t c : source) {
            if (!needs_escaped(c)) {
                escaped.append(1, c);
                continue;
            }

            uint8_t tmp[3];
            tmp[0] = '%';
            uint8_t low = c & 0xF;
            uint8_t high = c >> 4;

            if (high <= 9) {
                tmp[1] = '0' + high;
            } else {
                tmp[1] = 'A' + (high - 10);
            }
            if (low <= 9) {
                tmp[2] = '0' + low;
            } else {
                tmp[2] = 'A' + (low - 10);
            }

            escaped.append(reinterpret_cast<char*>(tmp), 3);
        }

        return escaped;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] string unescape_string(const string_view& source) {
        string unescaped;
        unescaped.reserve(source.size());

        auto ptr = begin(source);
        auto end_ptr = end(source);

        while (ptr < end_ptr) {
            if (*ptr != '%') {
                unescaped.append(1, *ptr++);
                continue;
            }

            // ASCII to-lower for alpha characters
            uint8_t hex_high = ascii_to_lower(ptr[1]);
            uint8_t hex_low = ascii_to_lower(ptr[2]);

            uint8_t c;
            if (hex_low >= 'a') {
                c = hex_low - 'a';
            } else {
                c = hex_low - '0';
            }
            if (hex_high >= 'a') {
                c |= (hex_high - 'a') << 4;
            } else {
                c |= (hex_high - '0') << 4;
            }
            
            unescaped.append(1, c);
        }

        return unescaped;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename Iter>
    [[nodiscard]] bool validate_escaped_char(Iter& ptr, Iter end) {
        if (distance(ptr, end) < 3) { return false; }
        if (ptr[0] != '%') { return false; }
        if (!is_hex_character(ptr[1]) || !is_hex_character(ptr[2])) { return false; }

        advance(ptr, 3);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename Iter>
    [[nodiscard]] bool validate_pchar(Iter& ptr, Iter end) {
        bool ok =
            is_unreserved(*ptr) ||
            is_sub_delimiter(*ptr) ||
            (*ptr == ':') ||
            (*ptr == '@');

        if (ok) {
            ++ptr;
            return true;
        }

        return validate_escaped_char(ptr, end);
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_scheme(const uri_section& scheme) {
        // Scheme starts with a letter, followed by any combination of letters, digits, +, - or .
        // Canonically they are lower-case but upper-case is tolerated.

        if (!scheme || scheme.Escaped().empty()) { return false; }

        auto unescaped = scheme.Unescaped();
        auto start_ptr = unescaped.begin();
        auto end_ptr = unescaped.end();

        bool ok = isalpha(*start_ptr++);
        if (!ok) { return false; }

        if (start_ptr != end_ptr) {
            ok = all_of(
                start_ptr,
                end_ptr,
                [](char c) { return isalnum(c) || (c == '+') || (c == '.') || (c == '-'); }
            );
        }

        return ok;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_authentication(const uri_section& authentication) {
        if (!authentication) { return true; }

        auto unescaped = authentication.Unescaped();
        auto start_ptr = unescaped.begin();
        auto end_ptr = unescaped.end();

        while (start_ptr < end_ptr) {
            char c = *start_ptr;
            if (c == '%') {
                if (!validate_escaped_char(start_ptr, end_ptr)) { return false; }
                continue;
            }

            bool ok = is_unreserved(c) || is_sub_delimiter(c) || (c == ':');
            if (!ok) { return false; }

            ++start_ptr;
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_host(const uri_section& host) {
        if (!host) { return true; }
        if (host.Unescaped().empty()) { return false; }

        // The full specification for the host section includes distinctions for IPv4 and IPv6. However it's
        // quite a lot of work to validate them correctly. We perform a "close enough" validation by checking
        // the overall set of acceptable characters.

        auto start_ptr = host.Unescaped().begin();
        auto end_ptr = host.Unescaped().end();

        while (start_ptr < end_ptr) {
            bool ok =
                is_unreserved(*start_ptr) ||
                is_sub_delimiter(*start_ptr) ||
                (*start_ptr == ':');
            if (ok) {
                ++start_ptr;
                continue;
            }

            if (!validate_escaped_char(start_ptr, end_ptr)) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_port(const uri_section& port) {
        if (!port) { return true; }

        return all_of(
            port.Unescaped().begin(),
            port.Unescaped().end(),
            [](char c) { return isdigit(c); }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_path(const uri_section& path) {
        if (!path) { return false; }
        if (path.Unescaped().empty()) { return true; }

        auto start_ptr = path.Unescaped().begin();
        auto end_ptr = path.Unescaped().end();

        // Prevent the path from starting with "//"
        if (*start_ptr == '/' && distance(start_ptr, end_ptr) >= 2) {
            if (start_ptr[1] == '/') { return false; }
        }

        while (start_ptr < end_ptr) {
            auto segment_end = find(start_ptr, end_ptr, '/');

            while (start_ptr < segment_end) {
                if (!validate_pchar(start_ptr, segment_end)) { return false; }
            }

            start_ptr = segment_end;
            if (start_ptr != end_ptr) { ++start_ptr; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_query(const uri_section& query) {
        if (!query) { return true; }

        auto start_ptr = query.Unescaped().begin();
        auto end_ptr = query.Unescaped().end();

        while (start_ptr < end_ptr) {
            if (*start_ptr == '/' || *start_ptr == '?') {
                ++start_ptr;
                continue;
            }
            if (!validate_pchar(start_ptr, end_ptr)) { return false; }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool validate_fragment(const uri_section& fragment) {
        // Fragment follows the same rules as query
        return validate_query(fragment);
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] int compare_sections(const uri_section& lhs, const uri_section& rhs, bool ignore_case) {
        if (static_cast<bool>(lhs) != static_cast<bool>(rhs)) {
            return lhs ? 1 : -1;
        }
        if (!lhs) { return 0; }

        auto& value_lhs = lhs.Unescaped();
        auto& value_rhs = rhs.Unescaped();

        auto compare_size = min(value_lhs.size(), value_rhs.size());

        if (ignore_case) {
            auto lhs_it = begin(value_lhs);
            auto rhs_it = begin(value_rhs);

            while (compare_size-- > 0) {
                char lhs_c = ascii_to_lower(*lhs_it++);
                char rhs_c = ascii_to_lower(*rhs_it++);
                if (lhs_c != rhs_c) {
                    return (lhs_c < rhs_c) ? -1 : 1;
                }
            }
        } else {
            int result = value_lhs.compare(0, compare_size, value_rhs);
            if (result != 0) {
                return result;
            }
        }
        
        if (value_lhs.size() != value_rhs.size()) {
            return (value_lhs.size() < value_rhs.size()) ? -1 : 1;
        }
        return 0;
    }
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::data {

    uri::uri()
      : m_validity(ValidityType::Uninitialized)
    {}

    //--------------------------------------------------------------------------------------------------------

    uri::uri(const char* value, bool is_escaped /*= false*/)
      : uri(string(value), is_escaped)
    {}

    //--------------------------------------------------------------------------------------------------------

    uri::uri(const string_view& value, bool is_escaped /*= false*/)
      : uri(string(value), is_escaped)
    {}

    //--------------------------------------------------------------------------------------------------------

    uri::uri(string&& value, bool is_escaped /*= false*/) {
        if (is_escaped) {
            Initialize(unescape_string(value));
        } else {
            Initialize(forward<string>(value));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    uri::uri(
        const string_view& scheme,
        const string_view& path,
        const optional_section& host /*= optional_section()*/,
        const optional_section& port /*= optional_section()*/,
        const optional_section& authentication /*= optional_section()*/,
        const optional_section& query /*= optional_section()*/,
        const optional_section& fragment /*= optional_section()*/
    ) : m_validity(ValidityType::Uninitialized)
    {
        stringstream ss;
        ss << unescape_string(scheme) << ":";
        if (host) {
            ss << "//";
            if (authentication) {
                ss << unescape_string(*authentication) << '@';
            }
            ss << unescape_string(*host);
            if (port) {
                ss << ':' << unescape_string(*port);
            }

            if (path.empty() || path[0] != '/') {
                ss << '/';
            }
        }

        ss << unescape_string(path);

        if (query) {
            ss << '?' << unescape_string(*query);
        }
        if (fragment) {
            ss << '#' << unescape_string(*fragment);
        }

        Initialize(ss.str());
    }

    //--------------------------------------------------------------------------------------------------------

    uri::uri(const uri& other) {
        *this = other;
    }

    //--------------------------------------------------------------------------------------------------------

    uri::uri(uri&& other) {
        *this = forward<uri>(other);
    }

    //--------------------------------------------------------------------------------------------------------

    uri::~uri() = default;

    //--------------------------------------------------------------------------------------------------------

    uri& uri::operator = (const uri& other) {
        Initialize(std::string(other.m_value));
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    uri& uri::operator = (uri&& other) {
        Initialize(move(other.m_value));
        other.m_validity = ValidityType::Deinitialized;
        other.m_scheme = uri_section();
        other.m_authentication = uri_section();
        other.m_host = uri_section();
        other.m_port = uri_section();
        other.m_path = uri_section();
        other.m_query = uri_section();
        other.m_fragment = uri_section();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    const uri_section& uri::Scheme()   const { return m_scheme; }
    const uri_section& uri::Authentication() const { return m_authentication; }
    const uri_section& uri::Host()     const { return m_host; }
    const uri_section& uri::Port()     const { return m_port; }
    const uri_section& uri::Path()     const { return m_path; }
    const uri_section& uri::Query()    const { return m_query; }
    const uri_section& uri::Fragment() const { return m_fragment; }

    //--------------------------------------------------------------------------------------------------------

    void uri::Initialize(string&& unescaped_value) {
        m_value = forward<string>(unescaped_value);
        m_validity = ValidityType::Invalid;

        uri_section scheme;
        uri_section authentication;
        uri_section host;
        uri_section port;
        uri_section path;
        uri_section query;
        uri_section fragment;

        auto ptr = m_value.c_str();
        auto end = ptr + m_value.size();
        
        // URI = scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]

        // scheme
        auto scheme_end = find(ptr, end, ':');
        scheme = string_view(ptr, distance(ptr, scheme_end));
        if (scheme_end == end) { return; }
        
        ptr = scheme_end + 1;
        if (ptr == end) { return; }
        

        // [//[authentication@]host[:port]]
        if (distance(ptr, end) >= 2 && ptr[0] == '/' && ptr[1] == '/') {
            // authority section is present.
            ptr += 2;

            auto authority_end = find_if(
                ptr,
                end,
                [](char c) { return (c == '/') || (c == '?') || (c == '#'); }
            );

            // authentication
            auto authentication_end = find(ptr, authority_end, '@');
            if (authentication_end != authority_end) {
                authentication = string_view(ptr, distance(ptr, authentication_end));
                ptr = authentication_end + 1;
            }

            // host
            auto host_end = find(ptr, authority_end, ':');
            if (ptr == host_end) { return; }

            host = string_view(ptr, distance(ptr, host_end));
            ptr = host_end;

            // port
            if (ptr != authority_end && *ptr == ':') {
                ptr++;

                if (ptr == authority_end) { return; }
                port = string_view(ptr, distance(ptr, authority_end));
            }

            ptr = authority_end;
        }


        // path (including preceding '/')
        auto path_end = find_if(
            ptr,
            end,
            [](char c) { return c == '?' || c == '#'; }
        );
        path = string_view(ptr, distance(ptr, path_end));
        ptr = path_end;


        if (ptr != end) {
            // [?query]
            if (*ptr == '?') {
                ptr++;

                auto query_end = find(ptr, end, '#');
                query = string_view(ptr, distance(ptr, query_end));
                ptr = query_end;
            }
        }


        if (ptr != end) {
            // [#fragment]
            if (*ptr == '#') {
                ptr++;

                fragment = string_view(ptr, distance(ptr, end));
                ptr = end;
            }
        }

        // scheme is mandatory.
        if (!scheme || scheme.Unescaped().empty()) { return; }

        // authntication and port cannot exist with host.
        if (authentication || port) {
            if (!host) { return; }
        }

        if (!validate_scheme(scheme)) { return; }
        if (!validate_authentication(authentication)) { return; }
        if (!validate_host(host)) { return; }
        if (!validate_port(port)) { return; }
        if (!validate_path(path)) { return; }
        if (!validate_query(query)) { return; }
        if (!validate_fragment(fragment)) { return; }


        // All validation is complete.
        m_scheme   = move(scheme);
        m_authentication = move(authentication);
        m_host     = move(host);
        m_port     = move(port);
        m_path     = move(path);
        m_query    = move(query);
        m_fragment = move(fragment);
        m_validity = ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int uri::Compare(const uri& other) const {
        if (Validity() != other.Validity()) {
            return (Validity() < other.Validity()) ? -1 : 1;
        }

        int result = compare_sections(m_scheme, other.m_scheme, true);
        if (result != 0) { return result; }

        result = compare_sections(m_authentication, other.m_authentication, false);
        if (result != 0) { return result; }

        result = compare_sections(m_host, other.m_host, true);
        if (result != 0) { return result; }

        result = compare_sections(m_port, other.m_port, false);
        if (result != 0) { return result; }

        result = compare_sections(m_path, other.m_path, false);
        if (result != 0) { return result; }

        result = compare_sections(m_query, other.m_query, false);
        if (result != 0) { return result; }

        return compare_sections(m_fragment, other.m_fragment, false);
    }

    //--------------------------------------------------------------------------------------------------------

    bool uri::operator == (const uri& other) const {
        return Compare(other) == 0;
    }

    //--------------------------------------------------------------------------------------------------------

    bool uri::operator != (const uri& other) const {
        return Compare(other) != 0;
    }

    //--------------------------------------------------------------------------------------------------------

    uri_section::uri_section() = default;
    uri_section::~uri_section() = default;

    //--------------------------------------------------------------------------------------------------------

    uri_section::uri_section(std::string_view&& value)
      : m_value(std::forward<std::string_view>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    string uri_section::Escaped() const {
        if (!m_value) { return string(); }
        return escape_string(*m_value);
    }

}