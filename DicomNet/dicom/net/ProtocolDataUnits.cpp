#include "dicomnet_pch.h"
#include "dicom/net/ProtocolDataUnits.h"

namespace dicom::net {

    void PDU::WriteImpl(output_buffer& dest, PDUType type) const {
        // Reserve space for the header values
        auto header_start = dest.size();
        dest.prepare(6);
        dest.commit(6);

        // Write all additional content
        auto content_start = dest.size();
        WriteContent(dest);
        auto content_end = dest.size();

        // Re-open the header data and fill it in
        auto header_buffer = dest.data(header_start, 6);
        auto header_ptr = reinterpret_cast<uint8_t*>(header_buffer.data());

        header_ptr[0] = static_cast<uint8_t>(type);
        header_ptr[1] = 0;
        *reinterpret_cast<uint32_t*>(&header_ptr[2]) = static_cast<uint32_t>(content_end - content_start);
    }

    //--------------------------------------------------------------------------------------------------------

    void PDUItem::WriteImpl(output_buffer& dest, PDUItemType type) const {
        // Reserve space for the header values
        auto header_start = dest.size();
        dest.prepare(4);
        dest.commit(4);

        // Write all additional content
        auto content_start = dest.size();
        WriteContent(dest);
        auto content_end = dest.size();

        // Re-open the header data and fill it in
        auto header_buffer = dest.data(header_start, 4);
        auto header_ptr = reinterpret_cast<uint8_t*>(header_buffer.data());
        header_ptr[0] = static_cast<uint8_t>(type);
        header_ptr[1] = 0;
        *reinterpret_cast<uint16_t*>(&header_ptr[2]) = static_cast<uint16_t>(content_end - content_start);
    }

    //--------------------------------------------------------------------------------------------------------

    ApplicationContextItem::ApplicationContextItem(std::string&& abstract_context_name)
      : ApplicationContextName(std::forward<std::string>(abstract_context_name))
    {
        if (ApplicationContextName.size() > 64) {
            throw std::invalid_argument("Name exceeds 64 characters");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void ApplicationContextItem::WriteContent(output_buffer& dest) const {
        auto sub_buffer = dest.prepare(ApplicationContextName.size());
        dest.commit(ApplicationContextName.size());

        memcpy(sub_buffer.data(), ApplicationContextName.data(), ApplicationContextName.size());
    }

    //--------------------------------------------------------------------------------------------------------

    AbstractSyntaxItem::AbstractSyntaxItem(std::string&& abstract_syntax)
      : AbstractSyntax(std::forward<std::string>(abstract_syntax))
    {
        if (AbstractSyntax.size() > 64) {
            throw std::invalid_argument("Abstract syntax exceeds 64 characters");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AbstractSyntaxItem::WriteContent(output_buffer& dest) const {
        auto sub_buffer = dest.prepare(AbstractSyntax.size());
        dest.commit(AbstractSyntax.size());

        memcpy(sub_buffer.data(), AbstractSyntax.data(), AbstractSyntax.size());
    }

    //--------------------------------------------------------------------------------------------------------

    TransferSyntaxItem::TransferSyntaxItem(std::string&& transfer_syntax)
      : TransferSyntax(std::forward<std::string>(transfer_syntax))
    {
        if (TransferSyntax.size() > 64) {
            throw std::invalid_argument("Transfer syntax exceeds 64 characters");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void TransferSyntaxItem::WriteContent(output_buffer& dest) const {
        auto sub_buffer = dest.prepare(TransferSyntax.size());
        dest.commit(TransferSyntax.size());

        memcpy(sub_buffer.data(), TransferSyntax.data(), TransferSyntax.size());
    }

    //--------------------------------------------------------------------------------------------------------

    PresentationContextItemRQ::PresentationContextItemRQ(
        uint8_t presentation_context_id,
        std::string&& abstract_syntax,
        std::vector<std::string>&& transfer_syntaxes
    ) : PresentationContextID(presentation_context_id),
        AbstractSyntax(std::forward<std::string>(abstract_syntax))
    {
        for (auto& ts : transfer_syntaxes) {
            TransferSyntaxes.emplace_back(std::move(ts));
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void PresentationContextItemRQ::WriteContent(output_buffer& dest) const {
        {
            auto sub_buffer = dest.prepare(4);
            dest.commit(4);

            auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
            memset(data_ptr, 0, 4);
            data_ptr[0] = PresentationContextID;
        }

        AbstractSyntax.Write(dest);
        for (auto& ts : TransferSyntaxes) {
            ts.Write(dest);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    MaximumLengthItem::MaximumLengthItem(uint32_t maximum_length)
      : MaximumLength(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void MaximumLengthItem::WriteContent(output_buffer& dest) const {
        auto sub_buffer = dest.prepare(4);
        dest.commit(4);

        *reinterpret_cast<uint32_t*>(sub_buffer.data()) = MaximumLength;
    }

    //--------------------------------------------------------------------------------------------------------

    UserInformationItem::UserInformationItem(uint32_t maximum_length)
      : MaximumLength(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void UserInformationItem::WriteContent(output_buffer& dest) const {
        MaximumLength.Write(dest);
    }

    //--------------------------------------------------------------------------------------------------------

    AAssociateRQ::AAssociateRQ(
        std::string called_ae_title,
        std::string calling_ae_title,
        std::string application_context,
        uint8_t presentation_context_id,
        std::string abstract_syntax,
        std::vector<std::string> transfer_syntaxes,
        uint32_t maximum_length
    ) : CalledAETitle(std::move(called_ae_title)),
        CallingAETitle(std::move(calling_ae_title)),
        ApplicationContext(std::move(application_context)),
        PresentationContext(
            presentation_context_id,
            std::move(abstract_syntax),
            std::move(transfer_syntaxes)
        ),
        UserInformation(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void AAssociateRQ::WriteContent(output_buffer& dest) const {
        {
            auto sub_buffer = dest.prepare(68);
            dest.commit(68);

            auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
            memset(data_ptr, 0, 68);

            *reinterpret_cast<uint16_t*>(data_ptr[0]) = 1; // ProtocolVersion
            memcpy(&data_ptr[5], CalledAETitle.data(), CalledAETitle.size());
            memcpy(&data_ptr[21], CallingAETitle.data(), CallingAETitle.size());
        }

        ApplicationContext.Write(dest);
        PresentationContext.Write(dest);
        UserInformation.Write(dest);
    }

}