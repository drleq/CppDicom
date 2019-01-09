#include "dicom_pch.h"
#include "dicom/io/part10/detail/write_file_meta_information.h"

#include "dicom/data/AE.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/OB.h"
#include "dicom/data/SH.h"
#include "dicom/data/UI.h"
#include "dicom/data/UL.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/detail/write_data_element.h"
#include "dicom/Tags.h"

#define __STRINGIFY1(a) #a
#define __STRINGIFY(a) __STRINGIFY1(a)
#define __LIBRARY_VERSION __STRINGIFY(DICOM_DLL_VERSION_MAJOR) "." __STRINGIFY(DICOM_DLL_VERSION_MINOR)

using namespace dicom::data;

namespace {
    const dicom::data::UL ZeroGroupLength(0);
    const dicom::data::UI LibraryImplementationClassUID("1.2.3.4.5.6"); // This is nonsense. Get the real number.
    const dicom::data::SH LibraryImplementationVersionName("DICOM v" __LIBRARY_VERSION); // Arbitrary

    template <typename TVR>
    [[nodiscard]] const TVR* get_one_of(const dicom::data::AttributeSet* src, dicom::tag_number tag1, dicom::tag_number tag2) {
        dicom::detail::elem_reader<TVR> vr1(src, tag1);
        if (vr1) { return vr1; }

        dicom::detail::elem_reader<TVR> vr2(src, tag2);
        if (vr2) { return vr2; }

        return nullptr;
    }
}

namespace dicom::io::part10::detail {

    using dicom::detail::elem_reader;

    bool write_file_meta_information(
        const OutputStreamPtr& stream,
        const TransferSyntax* transfer_syntax,
        const data::AttributeSet* src
    ) {
        OutputContext ctx(stream, &transfer_syntax::ExplicitLittle, StringEncodingType::ISO_IEC_646);

        // Reserve space for FileMetaInformationGroupLength
        auto group_length_position = stream->Tell();
        write_data_element(&ctx, tags::FileMetaInformationGroupLength, &ZeroGroupLength);
        auto group_start_position = stream->Tell();


        // FileMetaInformationVersion
        buffer<int8_t> information_version_buf(2);
        information_version_buf[0] = 0;
        information_version_buf[1] = 1;
        OB information_version(std::move(information_version_buf));
        write_data_element(&ctx, tags::FileMetaInformationVersion, &information_version);

        // MediaStorageSOPClassUID (fallback to SOPClassUID)
        auto sop_class_uid = get_one_of<UI>(src, tags::MediaStorageSOPClassUID, tags::SOPClassUID);
        if (sop_class_uid == nullptr) {
            // The SOP class could not be determined. Fail.
            return false;
        }
        write_data_element(&ctx, tags::MediaStorageSOPClassUID, sop_class_uid);

        // MediaStorageSOPInstanceUID (fallback to SOPInstanceUID)
        auto sop_instance_uid = get_one_of<UI>(src, tags::MediaStorageSOPInstanceUID, tags::SOPInstanceUID);
        if (sop_instance_uid == nullptr) {
            // The SOP instance could not be determined. Fail.
            return false;
        }
        write_data_element(&ctx, tags::MediaStorageSOPInstanceUID, sop_instance_uid);

        // TransferSyntaxUID
        UI transfer_syntax_vr(transfer_syntax->Uid);
        write_data_element(&ctx, tags::TransferSyntaxUID, &transfer_syntax_vr);

        // ImplementationClassUID
        write_data_element(&ctx, tags::ImplementationClassUID, &LibraryImplementationClassUID);

        // ImplementationVersionName
        write_data_element(&ctx, tags::ImplementationVersionName, &LibraryImplementationVersionName);

        // SourceApplicationEntityTitle
        elem_reader<AE> source_ae_title(src, tags::SourceApplicationEntityTitle);
        if (source_ae_title) {
            write_data_element(&ctx, tags::SourceApplicationEntityTitle, source_ae_title);
        }

        // PrivateInformationCreatorUID, PrivateInformation
        elem_reader<UI> private_info_creator_uid(src, tags::PrivateInformationCreatorUID);
        elem_reader<OB> private_info(src, tags::PrivateInformation);
        if (private_info_creator_uid && private_info) {
            write_data_element(&ctx, tags::PrivateInformationCreatorUID, private_info_creator_uid);
            write_data_element(&ctx, tags::PrivateInformation, private_info);
        }

        // Update FileMetaInformationGroupLength with the correct value
        auto group_end_position = stream->Tell();
        stream->Seek(group_length_position, std::ios::beg);

        data::UL group_length(uint32_t(group_end_position - group_start_position));
        write_data_element(&ctx, tags::FileMetaInformationGroupLength, &group_length);
        stream->Seek(0, std::ios::end);

        return *stream && !ctx.Failed();
    }

}