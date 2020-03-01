#pragma once

#include "dicom/net/detail/CommandSetDecoder.h"
#include "dicom/net/AcseHandlers.h"
#include "dicom/net/DimseHandlers.h"
namespace dicom::data { class AttributeSet; }
namespace dicom::net { class StateMachine; }

namespace dicom::net {

    class DICOMNET_EXPORT Association :
        private AcseHandlers
    {
    public:
        Association(
            asio::io_context& context,
            asio::ip::tcp::socket&& provider_socket,
            std::shared_ptr<DimseHandlers> dimse_handlers
        );
        Association(
            asio::io_context& context,
            const asio::ip::tcp::endpoint& remote_provider_endpoint
        );
        virtual ~Association();

        bool IsClosed() const;
        void Abort() const;

    private: // AcseHandlers
        AcceptanceResult IsAssociationAcceptable(const AAssociateRQ& pdu) override;
        void OnData(PDataTF&& pdu) override;

    private:
        std::shared_ptr<DimseHandlers> m_dimse_handlers;
        std::unique_ptr<StateMachine> m_state_machine;

        detail::CommandSetDecoder m_cs_decoder;

        void HandleCEcho(const DimseHandlerContext& context) const;
        void HandleCFind(const DimseHandlerContext& context) const;

        void HandleCFindMatch(
            const DimseHandlerContext& context,
            std::unique_ptr<data::AttributeSet>&& identifier,
            bool all_optional_keys_supported
        ) const;

        static void AddResponseFields(
            data::AttributeSet& command_set,
            const DimseHandlerContext& context,
            DimseOp operation
        );
        void EncodeAndSendResponse(std::unique_ptr<data::AttributeSet>&& response) const;
    };

}