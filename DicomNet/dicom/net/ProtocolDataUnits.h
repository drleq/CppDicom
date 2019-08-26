#pragma once

namespace dicom::net {

    using data_buffer = std::vector<uint8_t>;
    using input_buffer = asio::const_buffer;
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

    struct PDUHeader {
        PDUType Type;
        uint8_t Reserved;
        uint32_t Length;
    };

    struct DICOMNET_EXPORT PDU {
        virtual ~PDU();
    };

    using PDUPtr = std::unique_ptr<PDU>;

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

    struct PDUItemHeader {
        PDUItemType Type;
        uint8_t Reserved;
        uint16_t Length;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT ApplicationContextItem
    {
        ApplicationContextItem() = default;
        ApplicationContextItem(std::string&& application_context_name);
        std::string ApplicationContextName;
    };

    void encode_pdu_item(output_buffer& dest, const ApplicationContextItem& item);
    bool decode_pdu_item(input_buffer& dest, ApplicationContextItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AbstractSyntaxItem
    {
        AbstractSyntaxItem() = default;
        AbstractSyntaxItem(std::string&& abstract_syntax);
        std::string AbstractSyntax;
    };

    void encode_pdu_item(output_buffer& dest, const AbstractSyntaxItem& item);
    bool decode_pdu_item(input_buffer& dest, AbstractSyntaxItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT TransferSyntaxItem
    {
        TransferSyntaxItem() = default;
        TransferSyntaxItem(std::string&& transfer_syntax_name);
        std::string TransferSyntax;
    };

    void encode_pdu_item(output_buffer& dest, const TransferSyntaxItem& item);
    bool decode_pdu_item(input_buffer& dest, TransferSyntaxItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT PresentationContextItemRQ
    {
        PresentationContextItemRQ() = default;
        PresentationContextItemRQ(
            uint8_t presentation_context_id,
            std::string&& abstract_syntax,
            std::vector<std::string>&& transfer_syntaxes
        );
        uint8_t PresentationContextID;
        AbstractSyntaxItem AbstractSyntax;
        std::vector<TransferSyntaxItem> TransferSyntaxes;
    };

    void encode_pdu_item(output_buffer& dest, const PresentationContextItemRQ& item);
    bool decode_pdu_item(input_buffer& dest, PresentationContextItemRQ& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT MaximumLengthItem
    {
        MaximumLengthItem() = default;
        MaximumLengthItem(uint32_t maximum_length);
        uint32_t MaximumLength;
    };

    void encode_pdu_item(output_buffer& dest, const MaximumLengthItem& item);
    bool decode_pdu_item(input_buffer& dest, MaximumLengthItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT UserInformationItem
    {
        UserInformationItem() = default;
        UserInformationItem(uint32_t maximum_length);
        MaximumLengthItem MaximumLength;
    };

    void encode_pdu_item(output_buffer& dest, const UserInformationItem& item);
    bool decode_pdu_item(input_buffer& dest, UserInformationItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AAssociateRQ : PDU
    {
        AAssociateRQ() = default;
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
    };

    void encode_pdu(output_buffer& dest, const AAssociateRQ& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateRQ>& pdu);

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<PDU> decode_pdu(const data_buffer& data);

}