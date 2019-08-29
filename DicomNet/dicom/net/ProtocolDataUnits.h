#pragma once

namespace dicom::net {

    using input_buffer = asio::const_buffer;

    using data_buffer = std::vector<uint8_t>;
    using output_buffer = asio::dynamic_vector_buffer<uint8_t, std::allocator<uint8_t>>;

    //--------------------------------------------------------------------------------------------------------

    class IDataStorage
    {
    public:
        virtual ~IDataStorage() = default;
        virtual asio::const_buffer AsBuffer() const = 0;
    };
    using DataStoragePtr = std::shared_ptr<IDataStorage>;

    class OutputDataStorage : public IDataStorage
    {
    public:
        OutputDataStorage()
          : Storage(),
            OutputBuffer(asio::dynamic_buffer(Storage))
        {}
        virtual ~OutputDataStorage() = default;

        data_buffer Storage;
        output_buffer OutputBuffer;

        asio::const_buffer AsBuffer() const override {
            return asio::buffer(Storage);
        }
    };
    
    struct DataSequence {
        std::vector<DataStoragePtr> Sequence;

        void Insert(DataStoragePtr storage) {
            if (Sequence.back()->AsBuffer().size() == 0) {
                // Remove the current buffer from the sequence if it's empty.
                Sequence.pop_back();
            }

            // Insert a custom DataStorage at the current location.
            Sequence.push_back(std::move(storage));

            // Create a new output_buffer after the custom storage to maintain the sequence.
            Sequence.push_back(std::make_shared<OutputDataStorage>());
        }

        output_buffer& OutputBuffer() const {
            return dynamic_cast<OutputDataStorage&>(*Sequence.back()).OutputBuffer;
        }

        size_t Size() const {
            size_t total = 0;
            for (auto& ds : Sequence) {
                total += ds->AsBuffer().size();
            }
            return total;
        }
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

    struct DICOMNET_EXPORT MaximumLengthItem
    {
        MaximumLengthItem() = default;
        MaximumLengthItem(uint32_t maximum_length);
        uint32_t MaximumLength;
    };

    void encode_pdu_item(output_buffer& dest, const MaximumLengthItem& item);
    bool decode_pdu_item(input_buffer& data, MaximumLengthItem& item);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT UserInformationItem
    {
        UserInformationItem() = default;
        UserInformationItem(uint32_t maximum_length);
        MaximumLengthItem MaximumLength;
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
            uint32_t maximum_length
        );

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
            std::string abstract_syntax,
            std::vector<std::string> transfer_syntaxes,
            uint32_t maximum_length
        );

        ApplicationContextItem ApplicationContext;
        PresentationContextItemRQ PresentationContext;
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

        std::vector<ValueItem> Values;
    };

    void encode_pdu(DataSequence& dest, const PDataTF& pdu);
    bool decode_pdu_data(data_buffer&& storage, std::unique_ptr<PDataTF>& pdu);

    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AReleaseRQ : PDU
    {
        AReleaseRQ() = default;
    };

    void encode_pdu(DataSequence& dest, const AReleaseRQ& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AReleaseRQ>& pdu);
    
    //--------------------------------------------------------------------------------------------------------

    struct DICOMNET_EXPORT AReleaseRP : PDU
    {
        AReleaseRP() = default;
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

        SourceType Source;
        ReasonType Reason;
    };

    void encode_pdu(DataSequence& dest, const AAbort& pdu);
    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAbort>& pdu);

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<PDU> decode_pdu(data_buffer&& data);

}