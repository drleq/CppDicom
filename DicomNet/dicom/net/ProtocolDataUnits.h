#pragma once

namespace dicom::net {

    using output_buffer = asio::dynamic_vector_buffer<uint8_t, std::allocator<uint8_t>>;

    //--------------------------------------------------------------------------------------------------------

    enum class PDUType : uint8_t {
        AAssociateRQ = 0x01,
        AAssociateAC = 0x02,
        AAssociateRJ = 0x03,
        PDataTF = 0x04,
        AReleaseRQ = 0x05,
        AReleaseRP = 0x06,
        AAbortRQ = 0x07
    };

    struct DICOMNET_EXPORT PDU {
        virtual void Write(output_buffer& dest) const = 0;

    protected:
        void WriteImpl(output_buffer& dest, PDUType type) const;
        virtual void WriteContent(output_buffer& dest) const = 0;
    };

    template <PDUType Type>
    struct PDUT : PDU {
        void Write(output_buffer& dest) const override {
            WriteImpl(dest, Type);
        }        
    };

    //--------------------------------------------------------------------------------------------------------

    enum class PDUItemType : uint8_t {
        ApplicationContextItem = 0x10,
        PresentationContextItemRQ = 0x20,
        PresentationContextItemAC = 0x21,
        AbstractSyntaxItem = 0x30,
        TransferSyntaxItem = 0x40,
        UserInformationItem = 0x50,
        MaximumLengthItem = 0x51,
        ImplementationClassUIDItem = 0x52,
        AsynchronousOperationsWindowItem = 0x53,
        SCP_SCU_RoleSelectionItem = 0x54,
        ImplementationVersionNameItem = 0x55,
        SOPClassExtendedNegotiationItem = 0x56,
        SOPClassCommonExtendedNegotiationItem = 0x57,
        UserIdentitySubItemRQ = 0x58,
        UserIdentitySubItemAC = 0x59
    };

    struct DICOMNET_EXPORT PDUItem {
    protected:
        void WriteImpl(output_buffer& dest, PDUItemType type) const;
        virtual void WriteContent(output_buffer& dest) const = 0;
    };

    template <PDUItemType ItemType>
    struct PDUItemT : PDUItem {
        void Write(output_buffer& dest) const {
            WriteImpl(dest, ItemType);
        }
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT ApplicationContextItem :
        PDUItemT<PDUItemType::ApplicationContextItem>
    {
        ApplicationContextItem(std::string&& application_context_name);
        std::string ApplicationContextName;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AbstractSyntaxItem :
        PDUItemT<PDUItemType::AbstractSyntaxItem>
    {
        AbstractSyntaxItem(std::string&& abstract_syntax);
        std::string AbstractSyntax;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT TransferSyntaxItem :
        PDUItemT<PDUItemType::TransferSyntaxItem>
    {
        TransferSyntaxItem(std::string&& transfer_syntax_name);
        std::string TransferSyntax;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT PresentationContextItemRQ :
        PDUItemT<PDUItemType::PresentationContextItemRQ>
    {
        PresentationContextItemRQ(
            uint8_t presentation_context_id,
            std::string&& abstract_syntax,
            std::vector<std::string>&& transfer_syntaxes
        );
        uint8_t PresentationContextID;
        AbstractSyntaxItem AbstractSyntax;
        std::vector<TransferSyntaxItem> TransferSyntaxes;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT MaximumLengthItem :
        PDUItemT<PDUItemType::MaximumLengthItem>
    {
        MaximumLengthItem(uint32_t maximum_length);
        uint32_t MaximumLength;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT UserInformationItem :
        PDUItemT<PDUItemType::UserInformationItem>
    {
        UserInformationItem(uint32_t maximum_length);
        MaximumLengthItem MaximumLength;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AAssociateRQ :
        PDUT<PDUType::AAssociateRQ>
    {
        AAssociateRQ(
            std::string called_ae_title,
            std::string calling_ae_title,
            std::string application_context,
            uint8_t presentation_context_id,
            std::string abstract_syntax,
            std::vector<std::string> transfer_syntaxes,
            uint32_t maximum_length
        );

        std::string CalledAETitle;
        std::string CallingAETitle;
        ApplicationContextItem ApplicationContext;
        PresentationContextItemRQ PresentationContext;
        UserInformationItem UserInformation;

    protected:
        void WriteContent(output_buffer& dest) const override;
    };

}