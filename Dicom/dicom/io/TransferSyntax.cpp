#include "dicom_pch.h"
#include "dicom/io/TransferSyntax.h"

namespace dicom::io::transfer_syntax {
    const TransferSyntax ImplicitLittle = { "Implicit VR Little Endian", "1.2.840.10008.1.2", EndianType::Little, TagEncodingType::Implicit, PixelDataEncodingType::Native, PixelDataCompressionType::None };
    const TransferSyntax ExplicitLittle = { "Explicit VR Little Endian", "1.2.840.10008.1.2.1", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Native, PixelDataCompressionType::None };
    const TransferSyntax ExplicitBig = { "Explicit VR Big Endian", "1.2.840.10008.1.2.2", EndianType::Big, TagEncodingType::Explicit, PixelDataEncodingType::Native, PixelDataCompressionType::None };
    const TransferSyntax RLECompression = { "Run Length Encoded Compression", "1.2.840.10008.1.2.5", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::RLE };
    const TransferSyntax JpegBaseline = { "JPEG Baseline Compression", "1.2.840.10008.1.2.4.50", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Jpeg };
    const TransferSyntax JpegExtended = { "JPEG Extended Compression", "1.2.840.10008.1.2.4.51", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Jpeg };
    const TransferSyntax JpegLossless = { "JPEG Lossless, Non-Hierarchical", "1.2.840.10008.1.2.4.57", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::JpegLossless };
    const TransferSyntax JpegLosslessFOP = { "JPEG Lossless, Non-Hierarchical, First-Order Precision", "1.2.840.10008.1.2.4.70", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::JpegLossless };
    const TransferSyntax JpegLSLossless = { "JPEG-LS Lossless", "1.2.840.10008.1.2.4.80", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::JpegLSLossless };
    const TransferSyntax JpegLSNearLossless = { "JPEG-LS Near-Lossless, Non-Hierarchical", "1.2.840.10008.1.2.4.81", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::JpegLS };
    const TransferSyntax Jpeg2000Lossless = { "JPEG 2000 Lossless", "1.2.840.10008.1.2.4.90", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Jpeg2000Lossless };
    const TransferSyntax Jpeg2000 = { "JPEG 2000", "1.2.840.10008.1.2.4.91", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Jpeg2000 };
    const TransferSyntax Mpeg2MainLevel = { "MPEG-2 Main Profile, Main Level", "1.2.840.10008.1.2.4.100", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Mpeg2 };
    const TransferSyntax Mpeg2HighLevel = { "MPEG-2 Main Profile, High Level", "1.2.840.10008.1.2.4.101", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Mpeg2 };
    const TransferSyntax Mpeg4 = { "MPEG-4 High Level", "1.2.840.10008.1.2.4.102", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Mpeg4 };
    const TransferSyntax Mpeg4BDCompatible = { "MPEG-4 BD-Compatible High Level", "1.2.840.10008.1.2.4.103", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Encapsulated, PixelDataCompressionType::Mpeg4 };
    const TransferSyntax Deflate = { "Deflate", "1.2.840.10008.1.2.1.99", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Native, PixelDataCompressionType::Deflate };
    const TransferSyntax JpipReferenced = { "JPIP Referenced", "1.2.840.10008.1.2.4.94", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Native, PixelDataCompressionType::Jpip };
    const TransferSyntax JpipDeflateReferenced = { "JPIP Deflate Referenced", "1.2.840.10008.1.2.4.95", EndianType::Little, TagEncodingType::Explicit, PixelDataEncodingType::Native, PixelDataCompressionType::JpipDeflate };
} 

namespace {
    using namespace dicom::io;

    //--------------------------------------------------------------------------------------------------------

    #define MAKE_TRANSFER_SYNTAX_ENTRY(ts) {ts.Uid, &ts}
    const std::map<std::string_view, const TransferSyntax*> s_transfer_syntax_by_uid = {
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::ImplicitLittle),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::ExplicitLittle),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::ExplicitBig),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::RLECompression),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegBaseline),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegExtended),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegLossless),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegLosslessFOP),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegLSLossless),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpegLSNearLossless),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Jpeg2000Lossless),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Jpeg2000),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Mpeg2MainLevel),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Mpeg2HighLevel),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Mpeg4),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Mpeg4BDCompatible),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::Deflate),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpipReferenced),
        MAKE_TRANSFER_SYNTAX_ENTRY(transfer_syntax::JpipDeflateReferenced)
    };
    #undef MAKE_TRANSFER_SYNTAX_ENTRY

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_basic_transfer_syntax(const TransferSyntax* syntax) {
        return (syntax == &transfer_syntax::ImplicitLittle) ||
               (syntax == &transfer_syntax::ExplicitLittle) ||
               (syntax == &transfer_syntax::ExplicitBig);
    }
}

namespace dicom::io {

	const TransferSyntax* get_transfer_syntax(const std::string_view& uid)  {
		auto it = s_transfer_syntax_by_uid.find(uid);
		return (it != s_transfer_syntax_by_uid.end()) ? it->second : nullptr;
	}

    //--------------------------------------------------------------------------------------------------------

    bool can_directly_convert_transfer_syntax(const TransferSyntax* syntax_1, const TransferSyntax* syntax_2) {
        // No-op conversion will always be possible.
        if (syntax_1 == syntax_2) { return true; }

        if (is_basic_transfer_syntax(syntax_1) && is_basic_transfer_syntax(syntax_2)) {
            // If both are basic syntaxes then conversion is trivial and lossless.
            return true;
        }

        // Some form of compression is being applied. Direct conversion is impossible without codec support.
        return false;
    }

}