#pragma once

namespace dicom::net {

    using input_buffer = asio::const_buffer;

    using data_buffer = std::vector<uint8_t>;
    using output_buffer = asio::dynamic_vector_buffer<uint8_t, std::allocator<uint8_t>>;

    //--------------------------------------------------------------------------------------------------------

    class DICOMNET_EXPORT IDataStorage
    {
    public:
        virtual ~IDataStorage() = default;
        virtual asio::const_buffer AsBuffer() const = 0;
    };
    using DataStoragePtr = std::shared_ptr<IDataStorage>;

    //--------------------------------------------------------------------------------------------------------
    
    struct DataSequence {
        DataSequence();

        std::vector<DataStoragePtr> Sequence;

        void Insert(DataStoragePtr storage);
        output_buffer& OutputBuffer() const;
        size_t Size() const;
    };

    //--------------------------------------------------------------------------------------------------------

    enum class PDUType : uint8_t {
        AAssociateRQ = 0x01,
        AAssociateAC = 0x02,
        AAssociateRJ = 0x03,
        PDataTF = 0x04,
        AReleaseRQ = 0x05,
        AReleaseRP = 0x06,
        AAbort = 0x07
    };

    #pragma pack (push, 1)
    struct PDUHeader {
        PDUType Type;
        uint8_t Reserved;
        uint32_t Length;
    };
    #pragma pack (pop)

    struct DICOMNET_EXPORT PDU {
        virtual ~PDU();

        virtual PDUType Type() const = 0;
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

    #pragma pack (push, 1)
    struct PDUItemHeader {
        PDUItemType Type;
        uint8_t Reserved;
        uint16_t Length;
    };
    #pragma pack (pop)

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT ApplicationContextItem
    {
        ApplicationContextItem() = default;
        ApplicationContextItem(std::string&& application_context_name);
        std::string ApplicationContextName;
    };

    void encode_pdu_item(output_buffer& dest, const ApplicationContextItem& item);
    bool decode_pdu_item(input_buffer& data, ApplicationContextItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AbstractSyntaxItem
    {
        AbstractSyntaxItem() = default;
        AbstractSyntaxItem(std::string&& abstract_syntax);
        std::string AbstractSyntax;
    };

    void encode_pdu_item(output_buffer& dest, const AbstractSyntaxItem& item);
    bool decode_pdu_item(input_buffer& data, AbstractSyntaxItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT TransferSyntaxItem
    {
        TransferSyntaxItem() = default;
        TransferSyntaxItem(std::string&& transfer_syntax_name);
        std::string TransferSyntax;
    };

    void encode_pdu_item(output_buffer& dest, const TransferSyntaxItem& item);
    bool decode_pdu_item(input_buffer& data, TransferSyntaxItem& item);

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
    bool decode_pdu_item(input_buffer& data, PresentationContextItemRQ& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT PresentationContextItemAC
    {
        enum class ReasonType : uint8_t {
            Acceptance = 0,
            UserRejection = 1,
            NoReason = 2,
            AbstractSyntaxNotSupported = 3,
            TransferSyntaxesNotSupported = 4
        };

        PresentationContextItemAC() = default;
        PresentationContextItemAC(
            uint8_t presentation_context_id,
            ReasonType reason,
            std::string&& transfer_syntax
        );
        uint8_t PresentationContextID;
        ReasonType Reason;
        TransferSyntaxItem TransferSyntax;
    };

    void encode_pdu_item(output_buffer& dest, const PresentationContextItemAC& item);
    bool decode_pdu_item(input_buffer& data, PresentationContextItemAC& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT MaximumLengthItem
    {
        MaximumLengthItem() = default;
        MaximumLengthItem(uint32_t maximum_length);
        uint32_t MaximumLength;
    };

    void encode_pdu_item(output_buffer& dest, const MaximumLengthItem& item);
    bool decode_pdu_item(input_buffer& data, MaximumLengthItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT ImplementationClassUIDItem
    {
        ImplementationClassUIDItem() = default;
        ImplementationClassUIDItem(std::string uid);
        std::string ImplementationClassUID;
    };

    void encode_pdu_item(output_buffer& dest, const ImplementationClassUIDItem& item);
    bool decode_pdu_item(input_buffer& data, ImplementationClassUIDItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT ImplementationVersionNameItem
    {
        ImplementationVersionNameItem() = default;
        ImplementationVersionNameItem(std::string name);
        std::string ImplementationVersionName;
    };

    void encode_pdu_item(output_buffer& dest, const ImplementationVersionNameItem& item);
    bool decode_pdu_item(input_buffer& data, ImplementationVersionNameItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT UserInformationItem
    {
        UserInformationItem() = default;
        UserInformationItem(
            uint32_t maximum_length,
            std::string implementation_class_uid,
            std::string implementation_version_name
        );
        MaximumLengthItem MaximumLength;
        ImplementationClassUIDItem ImplementationClassUID;
        ImplementationVersionNameItem ImplementationVersionName;
    };

    void encode_pdu_item(output_buffer& dest, const UserInformationItem& item);
    bool decode_pdu_item(input_buffer& data, UserInformationItem& item);

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
            uint32_t maximum_length,
            std::string implementation_class_uid,
            std::string implementation_version_name
        );

        PDUType Type() const override { return PDUType::AAssociateRQ; }

        std::string CalledAETitle;
        std::string CallingAETitle;
        ApplicationContextItem ApplicationContext;
        PresentationContextItemRQ PresentationContext;
        UserInformationItem UserInformation;
    };

    void encode_pdu(DataSequence& dest, const AAssociateRQ& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateRQ>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AAssociateAC : PDU
    {
        AAssociateAC() = default;
        AAssociateAC(
            std::string application_context,
            uint8_t presentation_context_id,
            PresentationContextItemAC::ReasonType reason,
            std::string transfer_syntax,
            uint32_t maximum_length,
            std::string implementation_class_uid,
            std::string implementation_version_name
        );

        PDUType Type() const override { return PDUType::AAssociateAC; }

        ApplicationContextItem ApplicationContext;
        PresentationContextItemAC PresentationContext;
        UserInformationItem UserInformation;
    };

    void encode_pdu(DataSequence& dest, const AAssociateAC& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateAC>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AAssociateRJ : PDU
    {
        enum class ResultType : uint8_t {
            RejectedPermanent = 1,
            RejectedTransient = 2
        };

        enum class SourceType : uint8_t {
            ServiceUser = 0,
            ServiceProviderACSE = 1,
            ServiceProviderPresentation = 2
        };

        enum class ReasonType : uint8_t {
            User_NotGiven = 1,
            User_ApplicationContextNotSupported = 2,
            User_CallingAENotRecognised = 3,
            User_CalledAENotRecognised = 7,
            ACSE_NotSpecified = 1,
            ACSE_ProtocolNotSupported = 2,
            Presentation_TemporaryCongestion = 1,
            Presentation_LocalLimitExceeded = 2
        };

        AAssociateRJ() = default;
        AAssociateRJ(ResultType result, SourceType source, ReasonType reason);

        PDUType Type() const override { return PDUType::AAssociateRJ; }

        ResultType Result;
        SourceType Source;
        ReasonType Reason;
    };

    void encode_pdu(DataSequence& dest, const AAssociateRJ& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateRJ>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT PDataTF : PDU
    {
        struct ValueItem {
            uint8_t PresentationContextID;
            DataStoragePtr EncodedData;
        };

        PDataTF() = default;
        PDataTF(std::vector<ValueItem>&& values);

        PDUType Type() const override { return PDUType::PDataTF; }

        std::vector<ValueItem> Values;
    };

    void encode_pdu(DataSequence& dest, PDataTF&& pdu);
    bool decode_pdu_data(data_buffer&& storage, std::unique_ptr<PDataTF>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AReleaseRQ : PDU
    {
        AReleaseRQ() = default;

        PDUType Type() const override { return PDUType::AReleaseRQ; }
    };

    void encode_pdu(DataSequence& dest, const AReleaseRQ& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AReleaseRQ>& pdu);
    
    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AReleaseRP : PDU
    {
        AReleaseRP() = default;

        PDUType Type() const override { return PDUType::AReleaseRP; }
    };

    void encode_pdu(DataSequence& dest, const AReleaseRP& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AReleaseRP>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AAbort : PDU
    {
        enum class SourceType : uint8_t {
            ServiceUser = 0,
            ServiceProvider = 2
        };

        enum class ReasonType : uint8_t {
            NotSpecified = 0,
            UnrecognisedPDU = 1,
            UnexpectedPDU = 2,
            UnrecognisedPDUParameter = 4,
            UnexpectedPDUParameter = 5,
            InvalidPDUParameter = 6
        };

        AAbort() = default;
        AAbort(SourceType source, ReasonType reason);

        PDUType Type() const override { return PDUType::AAbort; }

        SourceType Source;
        ReasonType Reason;
    };

    void encode_pdu(DataSequence& dest, const AAbort& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAbort>& pdu);

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<PDU> decode_pdu(data_buffer&& data);

}