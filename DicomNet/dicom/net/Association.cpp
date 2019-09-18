#include "dicomnet_pch.h"
#include "dicom/net/Association.h"

#include "dicom/net/StateMachine.h"
#include "dicom/net/Tags.h"

#include "dicom/DataDictionary.h"
#include "dicom/data/UL.h"
#include "dicom/data/VR.h"
#include "dicom/data/VRType.h"
#include "dicom/detail/intrinsic.h"
#include "dicom/tag.h"
#include "dicom/tag_number.h"
#include "dicom/io/part10/InputStream.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/read_vr.h"

namespace {
    using namespace dicom;
    using namespace dicom::data;
    using namespace dicom::net;

    DataDictionaryPtr get_data_dictionary() {
        DataDictionaryPtr dict = std::make_shared<DataDictionary>();
        dicom::net::tags::populate_data_dictionary(dict);
        return dict;
    }

    class MemoryInputStream : public io::part10::InputStream
    {
    public:
        MemoryInputStream(const uint8_t* data, std::streamsize length)
          : m_data(data),
            m_offset(0)
        {
            Initialize(length);
        }
        virtual ~MemoryInputStream() = default;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Good() const override final { return (m_offset >= 0) && (m_offset <= Length()); }
        [[nodiscard]] std::streampos Tell() const override final { return m_offset; }

        //----------------------------------------------------------------------------------------------------

        void Seek(std::streamoff offset, std::ios::seekdir dir) override final {
            switch (dir) {
            case std::ios::beg: m_offset = offset; break;
            case std::ios::cur: m_offset += offset; break;
            case std::ios::end: m_offset = Length() + offset; break;
            }
        }

        //----------------------------------------------------------------------------------------------------

        bool Read(void* dest, std::streamsize length) override final {
            if (Length() - m_offset < length) {
                m_offset += length;
                return false;
            }

            memcpy(dest, &m_data[m_offset], length);
            m_offset += length;
            return true;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] data::buffer<char> ReadBinary(std::streamsize length) override final {
            data::buffer<char> tmp(static_cast<size_t>(length));
            Read(tmp, length);
            return tmp;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] io::part10::ReOpenStreamFunction CreateReOpenFunction() const override final {
            return {};
        }

    private:
        const uint8_t* m_data;
        std::streampos m_offset;
    };

    [[nodiscard]] bool read_data_element(
        io::part10::detail::InputContext& ctx,
        tag_number* tag,
        std::unique_ptr<data::VR>* attribute
    ) {
        *tag = ctx.ReadTagNumber();
        auto length = ctx.ReadImplicitTagLength();

        auto vr_type = ctx.DataDictionary()->Get(*tag);
        if (!vr_type) {
            // Unknown attribute.
            return false;
        }

        *attribute = io::part10::detail::read_vr(ctx, length, vr_type->Type);
        if (!attribute) {
            return false;
        }

        return !ctx.Failed() && ctx.Stream()->Good();
    }
}

namespace dicom::net {

    Association::Association(
        asio::io_context& context,
        asio::ip::tcp::socket&& provider_socket
    ) {
        m_state_machine = std::make_unique<StateMachine>(
            context,
            static_cast<AcseHandlers*>(this),
            std::forward<asio::ip::tcp::socket>(provider_socket)
        );
    }

    //--------------------------------------------------------------------------------------------------------

    Association::Association(
        asio::io_context& context,
        const asio::ip::tcp::endpoint& remote_provider_endpoint
    ) {
        m_state_machine = std::make_unique<StateMachine>(
            context,
            static_cast<AcseHandlers*>(this),
            remote_provider_endpoint
        );
    }

    //--------------------------------------------------------------------------------------------------------

    Association::~Association() = default;

    //--------------------------------------------------------------------------------------------------------

    bool Association::IsClosed() const {
        return m_state_machine->IsClosed();
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::Abort() const {
        m_state_machine->Abort();
    }

    //--------------------------------------------------------------------------------------------------------

    Association::AcceptanceResult Association::IsAssociationAcceptable(const AAssociateRQ& pdu) {
        return AcceptanceResult{
            true,
            pdu.PresentationContext.TransferSyntaxes.front().TransferSyntax,
            128 * 1024
        };
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::OnData(PDataTF&& pdu) {
        // Establish DIMSE message stream
        // - Read Command Group Length value (UL - 12 bytes total)
        // - Read of Command Group based on length
        // - If C-STORE start stream handler
        if (!m_current00) {
            auto buf = pdu.Values.front().EncodedData->AsBuffer();

            // Skip the control byte.
            buf += 1;

            auto stream = std::make_shared<MemoryInputStream>(
                reinterpret_cast<const uint8_t*>(buf.data()),
                buf.size()
            );
            io::part10::detail::InputContext ctx{
                stream,
                get_data_dictionary(),
                dicom::io::EndianType::Little,
                dicom::io::TagEncodingType::Implicit,
                StringEncodingType::ISO_IEC_646
            };

            // Read the Command Group Length value
            tag_number tag;
            std::unique_ptr<VR> attrib;
            bool result = read_data_element(ctx, &tag, &attrib);
            if (!result || tag != tags::CommandGroupLength) {
                // Fail.
                return;
            }

            std::streampos cs_length = dynamic_cast<dicom::data::UL*>(attrib.get())->First();
            m_current00 = DimseCommandSet{
                cs_length,
                { reinterpret_cast<const uint8_t*>(buf.data()) + ctx.Stream()->Tell(), reinterpret_cast<const uint8_t*>(buf.data()) + buf.size() },
                std::make_unique<dicom::data::AttributeSet>()
            };

            if (cs_length <= ctx.Stream()->Length() - ctx.Stream()->Tell()) {
                // Can read entire commad set now.
                std::streampos end_pos = ctx.Stream()->Tell() + cs_length;
                while (ctx.Stream()->Tell() < end_pos) {
                    result = read_data_element(ctx, &tag, &attrib);
                    if (!result || get_tag_group(tag) != 0x0000) {
                        // Error.
                        return;
                    }

                    m_current00->Attributes->Add(tag, std::move(attrib));
                }
                
            } else {
                // Need to wait for more data.
            }
        }

    }

}