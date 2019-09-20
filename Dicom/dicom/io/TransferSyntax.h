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
        extern DICOM_EXPORT const TransferSyntax ImplicitLittle;
        extern DICOM_EXPORT const TransferSyntax ExplicitLittle;
        extern DICOM_EXPORT const TransferSyntax ExplicitBig;
        extern DICOM_EXPORT const TransferSyntax RLECompression;
        extern DICOM_EXPORT const TransferSyntax JpegBaseline;
        extern DICOM_EXPORT const TransferSyntax JpegExtended;
        extern DICOM_EXPORT const TransferSyntax JpegLossless;
        extern DICOM_EXPORT const TransferSyntax JpegLosslessFOP;
        extern DICOM_EXPORT const TransferSyntax JpegLSLossless;
        extern DICOM_EXPORT const TransferSyntax JpegLSNearLossless;
        extern DICOM_EXPORT const TransferSyntax Jpeg2000Lossless;
        extern DICOM_EXPORT const TransferSyntax Jpeg2000;
        extern DICOM_EXPORT const TransferSyntax Mpeg2MainLevel;
        extern DICOM_EXPORT const TransferSyntax Mpeg2HighLevel;
        extern DICOM_EXPORT const TransferSyntax Mpeg4;
        extern DICOM_EXPORT const TransferSyntax Mpeg4BDCompatible;
        extern DICOM_EXPORT const TransferSyntax Deflate;
        extern DICOM_EXPORT const TransferSyntax JpipReferenced;
        extern DICOM_EXPORT const TransferSyntax JpipDeflateReferenced;
    } // namespace transfer_syntax

}