#pragma once

#include "dicom/io/EndianType.h"
#include "dicom/io/TagEncodingType.h"
#include "dicom/io/PixelDataCompressionType.h"
#include "dicom/io/PixelDataEncodingType.h"

namespace dicom::io {

	struct DICOM_EXPORT TransferSyntax
	{
        std::string_view Name;
        std::string_view Uid;
        EndianType Endian;
        TagEncodingType TagEncoding;
        PixelDataEncodingType PixelDataEncoding;
        PixelDataCompressionType PixelDataCompression;
	};

    DICOM_EXPORT [[nodiscard]] const TransferSyntax* get_transfer_syntax(const std::string_view& uid);
    DICOM_EXPORT [[nodiscard]] bool can_directly_convert_transfer_syntax(
        const TransferSyntax* syntax_1,
        const TransferSyntax* syntax_2
    );

    namespace transfer_syntax {
        extern const TransferSyntax ImplicitLittle;
        extern const TransferSyntax ExplicitLittle;
        extern const TransferSyntax ExplicitBig;
        extern const TransferSyntax RLECompression;
        extern const TransferSyntax JpegBaseline;
        extern const TransferSyntax JpegExtended;
        extern const TransferSyntax JpegLossless;
        extern const TransferSyntax JpegLosslessFOP;
        extern const TransferSyntax JpegLSLossless;
        extern const TransferSyntax JpegLSNearLossless;
        extern const TransferSyntax Jpeg2000Lossless;
        extern const TransferSyntax Jpeg2000;
        extern const TransferSyntax Mpeg2MainLevel;
        extern const TransferSyntax Mpeg2HighLevel;
        extern const TransferSyntax Mpeg4;
        extern const TransferSyntax Mpeg4BDCompatible;
        extern const TransferSyntax Deflate;
        extern const TransferSyntax JpipReferenced;
        extern const TransferSyntax JpipDeflateReferenced;
    } // namespace transfer_syntax

}