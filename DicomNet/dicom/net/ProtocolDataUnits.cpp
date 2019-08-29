#include "dicomnet_pch.h"
#include "dicom/net/ProtocolDataUnits.h"

namespace {
    using namespace dicom::net;

    template <typename WriteContent>
    void encode_pdu_impl(
        DataSequence& dest,
        PDUType type,
        WriteContent write_content
    ) {
        auto& buf = dest.OutputBuffer();

        // Reserve space for the header values
        auto header_start = buf.size();
        buf.prepare(sizeof(PDUHeader));
        buf.commit(sizeof(PDUHeader));

        // Write all additional content
        auto content_start = dest.Size();
        write_content(dest);
        auto content_end = dest.Size();

        // Re-open the header data and fill it in
        auto header_buffer = buf.data(header_start, sizeof(PDUHeader));
        auto header_ptr = reinterpret_cast<PDUHeader*>(header_buffer.data());
        header_ptr->Type = type;
        header_ptr->Reserved = 0;
        header_ptr->Length = static_cast<uint32_t>(content_end - content_start);
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename WriteContent>
    void encode_pdu_item_impl(
        output_buffer& buf,
        PDUItemType type,
        WriteContent write_content
    ) {
        // Reserve space for the header values
        auto header_start = buf.size();
        buf.prepare(sizeof(PDUItemHeader));
        buf.commit(sizeof(PDUItemHeader));

        // Write all additional content
        auto content_start = buf.size();
        write_content(buf);
        auto content_end = buf.size();

        // Re-open the header data and fill it in
        auto header_buffer = buf.data(header_start, sizeof(PDUItemHeader));
        auto header_ptr = reinterpret_cast<PDUItemHeader*>(header_buffer.data());
        header_ptr->Type = type;
        header_ptr->Reserved = 0;
        header_ptr->Length = static_cast<uint16_t>(content_end - content_start);
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename PDU_T>
    std::unique_ptr<PDU_T> decode_pdu_data_impl(input_buffer& data) {
        std::unique_ptr<PDU_T> pdu;
        if (!decode_pdu_data(data, pdu)) {
            return nullptr;
        }
        return pdu;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename HandleItem>
    bool decode_pdu_items_impl(input_buffer& data, HandleItem handle_item) {
        // While we still have data...
        while (data.size() >= sizeof(PDUItemHeader)) {
            // Read the PDU item header
            auto header_ptr = reinterpret_cast<const PDUItemHeader*>(data.data());
            data += sizeof(PDUItemHeader);
            
            // Decode the PDU item data
            auto item_buffer = asio::buffer(data, header_ptr->Length);
            bool result = handle_item(*header_ptr, item_buffer);
            if (!result) {
                return false;
            }

            // Advance [data]
            data += header_ptr->Length;
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    std::string decode_unterminated_string(const uint8_t* data, size_t length) {
        auto str = std::string_view{
            reinterpret_cast<const char*>(data),
            length
        };

        auto start = str.find_first_not_of(' ');
        if (start == std::string_view::npos) {
            return std::string(str);
        }

        auto end = str.find_last_not_of(' ');
        return std::string{ str, start, end-start };
    }
}

namespace dicom::net {

    PDU::~PDU() = default;

    //--------------------------------------------------------------------------------------------------------

    ApplicationContextItem::ApplicationContextItem(std::string&& abstract_context_name)
      : ApplicationContextName(std::forward<std::string>(abstract_context_name))
    {
        if (ApplicationContextName.size() > 64) {
            throw std::invalid_argument("Name exceeds 64 characters");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu_item(output_buffer& dest, const ApplicationContextItem& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::ApplicationContextItem,
            [&item](auto& d) {
                auto sub_buffer = d.prepare(item.ApplicationContextName.size());
                d.commit(item.ApplicationContextName.size());
                memcpy(sub_buffer.data(), item.ApplicationContextName.data(), item.ApplicationContextName.size());
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& dest, ApplicationContextItem& item) {
        item.ApplicationContextName = std::string{
            reinterpret_cast<const char*>(dest.data()),
            dest.size()
        };
        return true;
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

    void encode_pdu_item(output_buffer& dest, const AbstractSyntaxItem& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::AbstractSyntaxItem,
            [&item](auto& d) {
                auto sub_buffer = d.prepare(item.AbstractSyntax.size());
                d.commit(item.AbstractSyntax.size());
                memcpy(sub_buffer.data(), item.AbstractSyntax.data(), item.AbstractSyntax.size());
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& dest, AbstractSyntaxItem& item) {
        item.AbstractSyntax = std::string{
            reinterpret_cast<const char*>(dest.data()),
            dest.size()
        };
        return true;
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

    void encode_pdu_item(output_buffer& dest, const TransferSyntaxItem& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::TransferSyntaxItem,
            [&item](auto& d) {
                auto sub_buffer = d.prepare(item.TransferSyntax.size());
                d.commit(item.TransferSyntax.size());
                memcpy(sub_buffer.data(), item.TransferSyntax.data(), item.TransferSyntax.size());
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& dest, TransferSyntaxItem& item) {
        item.TransferSyntax = std::string{
            reinterpret_cast<const char*>(dest.data()),
            dest.size()
        };
        return true;
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

    void encode_pdu_item(output_buffer& dest, const PresentationContextItemRQ& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::PresentationContextItemRQ,
            [&item](auto& d) {
                {
                    auto sub_buffer = d.prepare(4);
                    d.commit(4);

                    auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                    memset(data_ptr, 0, 4);
                    data_ptr[0] = item.PresentationContextID;
                }

                encode_pdu_item(d, item.AbstractSyntax);
                for (auto& ts : item.TransferSyntaxes) {
                    encode_pdu_item(d, ts);
                }
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& data, PresentationContextItemRQ& item) {
        {
            if (data.size() < 4) {
                return false;
            }

            item.PresentationContextID = *reinterpret_cast<const uint8_t*>(data.data());
            data += 4;
        }

        return decode_pdu_items_impl(
            data,
            [&item](const PDUItemHeader& header, input_buffer& d) -> bool {
                switch (header.Type) {
                case PDUItemType::AbstractSyntaxItem:
                    return decode_pdu_item(d, item.AbstractSyntax);

                case PDUItemType::TransferSyntaxItem: {
                    TransferSyntaxItem ts;
                    if (!decode_pdu_item(d, ts)) {
                        return false;
                    }
                    item.TransferSyntaxes.push_back(std::move(ts));
                    return true;
                }

                default:
                    return false;
                }
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    MaximumLengthItem::MaximumLengthItem(uint32_t maximum_length)
      : MaximumLength(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu_item(output_buffer& dest, const MaximumLengthItem& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::MaximumLengthItem,
            [&item](auto& d) {
                auto sub_buffer = d.prepare(sizeof(uint32_t));
                d.commit(sizeof(uint32_t));
                *reinterpret_cast<uint32_t*>(sub_buffer.data()) = item.MaximumLength;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& data, MaximumLengthItem& item) {
        if (data.size() < sizeof(uint32_t)) {
            return false;
        }

        item.MaximumLength = *reinterpret_cast<const uint32_t*>(data.data());
        data += sizeof(uint32_t);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    UserInformationItem::UserInformationItem(uint32_t maximum_length)
      : MaximumLength(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu_item(output_buffer& dest, const UserInformationItem& item) {
        encode_pdu_item_impl(
            dest,
            PDUItemType::UserInformationItem,
            [&item](auto& d) {
                encode_pdu_item(d, item.MaximumLength);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_item(input_buffer& data, UserInformationItem& item) {
        return decode_pdu_items_impl(
            data,
            [&item](const PDUItemHeader& header, input_buffer& d) -> bool {
                if (header.Type != PDUItemType::MaximumLengthItem) {
                    return false;
                }

                return decode_pdu_item(d, item.MaximumLength);
            }
        );
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

    void encode_pdu(DataSequence& dest, const AAssociateRQ& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AAssociateRQ,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                {
                    auto sub_buffer = d.prepare(68);
                    d.commit(68);

                    auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                    memset(data_ptr, 0, 68);

                    *reinterpret_cast<uint16_t*>(&data_ptr[0]) = 1; // ProtocolVersion
                    memcpy(&data_ptr[5], pdu.CalledAETitle.data(), pdu.CalledAETitle.size());
                    memcpy(&data_ptr[21], pdu.CallingAETitle.data(), pdu.CallingAETitle.size());
                }

                encode_pdu_item(d, pdu.ApplicationContext);
                encode_pdu_item(d, pdu.PresentationContext);
                encode_pdu_item(d, pdu.UserInformation);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateRQ>& pdu) {
        auto tmp = std::make_unique<AAssociateRQ>();

        {
            if (data.size() < 68) {
                return false;
            }

            auto sub_buffer = asio::buffer(data, 68);
            data += 68;

            auto data_ptr = reinterpret_cast<const uint8_t*>(sub_buffer.data());
            if (*reinterpret_cast<const uint16_t*>(&data_ptr[0]) != 1) {
                // Validate the Protocol Version.
                return false;
            }

            tmp->CalledAETitle = decode_unterminated_string(&data_ptr[5], 16);
            tmp->CallingAETitle = decode_unterminated_string(&data_ptr[21], 16);
        }

        bool result = decode_pdu_items_impl(
            data,
            [&tmp](const PDUItemHeader& header, input_buffer& d) -> bool {
                switch (header.Type) {
                case PDUItemType::ApplicationContextItem: return decode_pdu_item(d, tmp->ApplicationContext);
                case PDUItemType::PresentationContextItemRQ: return decode_pdu_item(d, tmp->PresentationContext);
                case PDUItemType::UserInformationItem: return decode_pdu_item(d, tmp->UserInformation);
                default:
                    // Unexpected PDU item type.
                    return false;
                }
            }
        );
        if (!result) {
            return false;
        }

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    AAssociateAC::AAssociateAC(
        std::string application_context,
        uint8_t presentation_context_id,
        std::string abstract_syntax,
        std::vector<std::string> transfer_syntaxes,
        uint32_t maximum_length
    ) : ApplicationContext(std::move(application_context)),
        PresentationContext(
            presentation_context_id,
            std::move(abstract_syntax),
            std::move(transfer_syntaxes)
        ),
        UserInformation(maximum_length)
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const AAssociateAC& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AAssociateAC,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                {
                    auto sub_buffer = d.prepare(68);
                    d.commit(68);

                    auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                    memset(data_ptr, 0, 68);
                    *reinterpret_cast<uint16_t*>(&data_ptr[0]) = 1; // ProtocolVersion
                }

                encode_pdu_item(d, pdu.ApplicationContext);
                encode_pdu_item(d, pdu.PresentationContext);
                encode_pdu_item(d, pdu.UserInformation);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateAC>& pdu) {
        auto tmp = std::make_unique<AAssociateAC>();

        {
            if (data.size() < 68) {
                return false;
            }

            auto sub_buffer = asio::buffer(data, 68);
            data += 68;

            auto data_ptr = reinterpret_cast<const uint8_t*>(sub_buffer.data());
            if (*reinterpret_cast<const uint16_t*>(&data_ptr[0]) != 1) {
                // Validate the Protocol Version.
                return false;
            }
        }

        bool result = decode_pdu_items_impl(
            data,
            [&tmp](const PDUItemHeader& header, input_buffer& d) -> bool {
                switch (header.Type) {
                case PDUItemType::ApplicationContextItem: return decode_pdu_item(d, tmp->ApplicationContext);
                case PDUItemType::PresentationContextItemRQ: return decode_pdu_item(d, tmp->PresentationContext);
                case PDUItemType::UserInformationItem: return decode_pdu_item(d, tmp->UserInformation);
                default:
                    // Unexpected PDU item type.
                    return false;
                }
            }
        );
        if (!result) {
            return false;
        }

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    AAssociateRJ::AAssociateRJ(ResultType result, SourceType source, ReasonType reason)
      : Result(result),
        Source(source),
        Reason(reason)
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const AAssociateRJ& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AAssociateRJ,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                auto sub_buffer = d.prepare(4);
                d.commit(4);

                auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                data_ptr[0] = 0;
                data_ptr[1] = static_cast<uint8_t>(pdu.Result);
                data_ptr[2] = static_cast<uint8_t>(pdu.Source);
                data_ptr[3] = static_cast<uint8_t>(pdu.Reason);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAssociateRJ>& pdu) {
        auto tmp = std::make_unique<AAssociateRJ>();

        if (data.size() < 4) {
            return false;
        }

        auto sub_buffer = asio::buffer(data, 4);
        data += 4;

        auto data_ptr = reinterpret_cast<const uint8_t*>(sub_buffer.data());
        tmp->Result = static_cast<AAssociateRJ::ResultType>(data_ptr[1]);
        tmp->Source = static_cast<AAssociateRJ::SourceType>(data_ptr[2]);
        tmp->Reason = static_cast<AAssociateRJ::ReasonType>(data_ptr[3]);

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    PDataTF::PDataTF(std::vector<ValueItem>&& values)
      : Values(std::forward<std::vector<ValueItem>>(values))
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const PDataTF& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::PDataTF,
            [&pdu](DataSequence& ds) {
                for (auto& value : pdu.Values) {
                    // Re-obtain the output buffer for each item as it will be changing
                    auto& d = ds.OutputBuffer();

                    // Output the PDV header
                    size_t data_size = value.EncodedData->AsBuffer().size();
                    size_t value_size = data_size + 5;
                    auto sub_buffer = d.prepare(value_size);
                    d.commit(value_size);

                    auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                    *reinterpret_cast<uint32_t*>(&data_ptr[0]) = static_cast<uint32_t>(data_size);
                    data_ptr[4] = value.PresentationContextID;

                    // Attach the PDV data directly (no copy)
                    ds.Insert(value.EncodedData);
                }
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(data_buffer&& storage, std::unique_ptr<PDataTF>& pdu) {
        using SharedDataBuffer = std::shared_ptr<data_buffer>;
        class SharedValueDataStorage : public IDataStorage {
        public:
            SharedValueDataStorage(SharedDataBuffer storage, size_t offset, size_t length)
              : Storage(storage),
                Offset(offset),
                Length(length)
            {}

            virtual ~SharedValueDataStorage() = default;

            SharedDataBuffer Storage;
            size_t Offset;
            size_t Length;

            asio::const_buffer AsBuffer() const override {
                return asio::const_buffer(Storage->data() + Offset, Length);
            }
        };

        auto shared_storage = std::make_shared<data_buffer>(std::forward<data_buffer>(storage));
        auto tmp = std::make_unique<PDataTF>();

        size_t data_remaining = shared_storage->size();
        auto data_ptr = reinterpret_cast<uint8_t*>(shared_storage->data());

        while (data_remaining > 0) {
            if (data_remaining < 5) {
                // Not enough data for the PDV header.
                return false;
            }

            // Build a new ValueItem using the [shared_storage]
            PDataTF::ValueItem value;
            uint32_t value_length = *reinterpret_cast<const uint32_t*>(data_ptr[0]);
            value.PresentationContextID = data_ptr[4];

            if (value_length + 5 > data_remaining) {
                // Not enough data for the PDV
                return false;
            }

            value.EncodedData = std::make_shared<SharedValueDataStorage>(
                shared_storage,
                std::distance(shared_storage->data(), data_ptr + 5),
                value_length
            );

            data_ptr += value_length + 5;
            data_remaining -= value_length + 5;
        }

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const AReleaseRQ& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AReleaseRQ,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                auto sub_buffer = d.prepare(4);
                d.commit(4);

                auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                *reinterpret_cast<uint32_t*>(data_ptr) = 0; // Reserved
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AReleaseRQ>& pdu) {
        auto tmp = std::make_unique<AReleaseRQ>();

        if (data.size() < 4) {
            return false;
        }

        // Reserved value unchecked.
        data += 4;

        pdu = std::move(tmp);
        return true;
    }    

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const AReleaseRP& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AReleaseRP,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                auto sub_buffer = d.prepare(4);
                d.commit(4);

                auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                *reinterpret_cast<uint32_t*>(data_ptr) = 0; // Reserved
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AReleaseRP>& pdu) {
        auto tmp = std::make_unique<AReleaseRP>();

        if (data.size() < 4) {
            return false;
        }

        // Reserved value unchecked.
        data += 4;

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    AAbort::AAbort(SourceType source, ReasonType reason)
      : Source(source),
        Reason(reason)
    {}

    //--------------------------------------------------------------------------------------------------------

    void encode_pdu(DataSequence& dest, const AAbort& pdu) {
        encode_pdu_impl(
            dest,
            PDUType::AAbort,
            [&pdu](DataSequence& ds) {
                auto& d = ds.OutputBuffer();
                auto sub_buffer = d.prepare(4);
                d.commit(4);

                auto data_ptr = reinterpret_cast<uint8_t*>(sub_buffer.data());
                data_ptr[0] = 0;
                data_ptr[1] = 0;
                data_ptr[2] = static_cast<uint8_t>(pdu.Source);
                data_ptr[3] = static_cast<uint8_t>(pdu.Reason);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_pdu_data(input_buffer& data, std::unique_ptr<AAbort>& pdu) {
        auto tmp = std::make_unique<AAbort>();

        if (data.size() < 4) {
            return false;
        }

        auto sub_buffer = asio::buffer(data, 4);
        data += 4;

        auto data_ptr = reinterpret_cast<const uint8_t*>(sub_buffer.data());
        tmp->Source = static_cast<AAbort::SourceType>(data_ptr[2]);
        tmp->Reason = static_cast<AAbort::ReasonType>(data_ptr[3]);

        pdu = std::move(tmp);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<PDU> decode_pdu(data_buffer&& data) {
        if (data.size() < sizeof(PDUHeader)) {
            // No PDUHeader available.
            return nullptr;
        }

        auto header_ptr = reinterpret_cast<const PDUHeader*>(data.data());
        if (header_ptr->Length > data.size() - sizeof(PDUHeader)) {
            // Not enough data in the buffer.
            return nullptr;
        }

        auto pdu_data = asio::buffer(const_cast<const data_buffer&>(data)) + sizeof(PDUHeader);

        switch (header_ptr->Type) {
        case PDUType::AAssociateRQ: return decode_pdu_data_impl<AAssociateRQ>(pdu_data);
        case PDUType::AAssociateAC: return decode_pdu_data_impl<AAssociateAC>(pdu_data);
        case PDUType::AAssociateRJ: return decode_pdu_data_impl<AAssociateRJ>(pdu_data);
        case PDUType::AReleaseRQ:   return decode_pdu_data_impl<AReleaseRQ>(pdu_data);
        case PDUType::AReleaseRP:   return decode_pdu_data_impl<AReleaseRP>(pdu_data);
        case PDUType::AAbort:       return decode_pdu_data_impl<AAbort>(pdu_data);

        case PDUType::PDataTF: {
            // PDataTF is special in that we want to move the data ownership for efficiency.
            std::unique_ptr<PDataTF> pdu;
            if (!decode_pdu_data(std::forward<data_buffer>(data), pdu)) {
                return false;
            }
            return pdu;
        }
        default:
            // Unknown PDU type.
            return nullptr;
        }
    }

}