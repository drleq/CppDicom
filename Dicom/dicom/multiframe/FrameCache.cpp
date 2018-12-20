#include "dicom_pch.h"
#include "dicom/multiframe/FrameCache.h"

#include "dicom/data/IS.h"
#include "dicom/data/OB.h"
#include "dicom/data/SQ.h"
#include "dicom/data/UI.h"
#include "dicom/data/UL.h"
#include "dicom/Tags.h"
#include "dicom/UIDs.h"

#include "dicom/detail/elem_reader.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/multiframe/PrivateTags.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;
using namespace dicom::io;

namespace {
    [[nodiscard]] bool is_multi_frame(const AttributeSetPtr& metadata) {
        // The NumberOfFrames attribute is present in both the MultiFrameModule and the
        // MultiFrameFunctionalGroupsModule.
        return metadata->Contains(tags::NumberOfFrames);
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool is_functional_groups_module(const AttributeSetPtr& metadata) {
        // PerFrameFunctionalGroupsSequence is Type 1 even if empty.
        return metadata->Contains(tags::PerFrameFunctionalGroupsSequence);
    }

    //--------------------------------------------------------------------------------------------------------

    // Combines a single macro and combines it with an attribute set. Ownership is not transferred.
    void combine_attributes(AttributeSet* as, const AttributeSet* macro) {
        for (auto& kvp : *macro) {
            auto sq = dynamic_cast<const SQ*>(kvp.second);
            if (!sq) { continue; }
            
			for (auto& item : sq->Items()) {
				as->AddAllUnowned(*item);
			}
        }
    }
}

namespace dicom::multiframe {

    FrameCache::FrameCache() = default;

    //--------------------------------------------------------------------------------------------------------

    FrameCache::~FrameCache() = default;

    //--------------------------------------------------------------------------------------------------------

    FrameIndexList FrameCache::Add(const io::LoadResultPtr& load_result) {
        auto& metadata = load_result->Metadata();
        load_result_key result_key(metadata);

        auto result_it = m_load_results.find(result_key);
        if (result_it != m_load_results.end()) {
            throw runtime_error("Collision in load result key");
        }

        if (!is_multi_frame(metadata)) {
            // Not a multi-frame image. We can store the FrameIndexTag in the metadata directly as it will
            // take ownership.
            metadata->Add(private_tags::FrameIndexTag, make_unique<IS>(0));
            frame_index index(metadata.get());

            LoadResultInfo info;
            info.m_load_result = load_result;
            info.m_frame_indicies.push_back(index);

            m_index_to_frame.emplace(index, load_result->Metadata());
            m_load_results.emplace(move(result_key), move(info));

            return FrameIndexList(1, index);
        }

        if (is_functional_groups_module(metadata)) {
            return DeriveFromFunctionalGroupsModule(move(result_key), load_result);
        } else {
            return DeriveFromMultiFrameModule(move(result_key), load_result);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    AttributeSetConstPtr FrameCache::GetFrame00(const frame_index& index) const {
        auto it = m_index_to_frame.find(index);
        return (it != m_index_to_frame.end()) ? it->second : nullptr;
    }

    //--------------------------------------------------------------------------------------------------------

    FrameList FrameCache::GetFrameList(const FrameIndexList& indices) const {
        FrameList frames;
        frames.reserve(indices.size());
        for (auto& index : indices) {
			frames.push_back(GetFrame00(index));
		}
        return frames;
    }

    //--------------------------------------------------------------------------------------------------------

    FrameIndexList FrameCache::GetIndexList() const {
        FrameIndexList index_list;
        index_list.reserve(m_index_to_frame.size());
        for (auto& kvp : m_index_to_frame) {
			index_list.push_back(kvp.first);
		}
        return index_list;
    }

    //--------------------------------------------------------------------------------------------------------

    bool FrameCache::LoadPixelData(
        const frame_index& index,
        const dicom::io::codec::ICodecFactory* codec_factory00
    ) {
        // Look up the frame and its metadata
        auto frame_it = m_index_to_frame.find(index);
        if (frame_it == m_index_to_frame.end()) { return false; }

        // If the pixel data is already loaded then there is nothing to do
        auto metadata = frame_it->second;
        if (metadata->Contains(tags::PixelData)) { return true; }

        // Construct the key and find the load result
        load_result_key key(metadata);

        auto it = m_load_results.find(key);
        if (it == m_load_results.end()) { return false; }
        auto& load_result_info = it->second;

        // Verify that [index] is in the range of frames for this load result
        auto frame_count = load_result_info.m_load_result->FrameCount();
        if (frame_count == 0) { return false; }

        auto frame_number_end = key.FrameNumberStart + frame_count;
        if (index.FrameNumber() < key.FrameNumberStart || index.FrameNumber() >= frame_number_end) {
            throw runtime_error("Frame number not found within loaded data");
        }

        auto frame_index = index.FrameNumber() - key.FrameNumberStart;
        if (!metadata->OwnsAttributes() &&
            frame_index >= load_result_info.m_additional_attributes.size()
        ) {
            return false;
        }

        // Load the raw pixel data for the frame
        buffer<int8_t> pixel_data = load_result_info.m_load_result->GetPixelData(frame_index);

        auto& transfer_syntax_uid = metadata->Get<UI>(tags::TransferSyntaxUID)->Value();
        auto transfer_syntax = get_transfer_syntax(transfer_syntax_uid);
        if (transfer_syntax->PixelDataCompression != PixelDataCompressionType::None) {
            // The pixel data is compressed. Create a codec to decompress it
			if (codec_factory00 == nullptr) { return false; }
            auto codec = codec_factory00->Create00(
                transfer_syntax->PixelDataCompression,
                dicom::io::codec::PixelDataFormatType::RGB24
            );
            if (!codec) { return false; }

            // Decompress the data
            auto decoded_image = codec->Decode00(pixel_data, pixel_data.ByteLength());
            if (!decoded_image) { return false; }

            // TODO: Sanity check [decoded_image] against tags
            pixel_data = decoded_image->DetachBuffer();
        }

        auto pixel_data_vr = make_unique<OB>(move(pixel_data));

        if (metadata->OwnsAttributes()) {
            metadata->Add(tags::PixelData, move(pixel_data_vr));
        } else {
            metadata->AddUnowned(tags::PixelData, pixel_data_vr.get());
            auto& additional_attributes = load_result_info.m_additional_attributes[frame_index];            
            additional_attributes->Add(tags::PixelData, move(pixel_data_vr));
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    FrameIndexList FrameCache::DeriveFromFunctionalGroupsModule(
        load_result_key&& key,
        const io::LoadResultPtr& load_result
    ) {
        auto& metadata = load_result->Metadata();

        auto per_frame_groups = metadata->Get<SQ>(tags::PerFrameFunctionalGroupsSequence);
        auto shared_groups00 = metadata->Get<SQ>(tags::SharedFunctionalGroupsSequence);

        // Check for the ConcatenationFrameOffsetNumber, which acts as an offset to the implicit
        // frame number.
        uint32_t frame_number = 0;
        auto frame_offset = metadata->Get<UL>(tags::ConcatenationFrameOffsetNumber);
        if (frame_offset && !frame_offset->Empty()) {
            frame_number = frame_offset->First();
        }

        LoadResultInfo info;
        info.m_load_result = load_result;
        info.m_frame_indicies.reserve(per_frame_groups->Size());
        info.m_additional_attributes.reserve(per_frame_groups->Size());

        FrameIndexList index_list;
        index_list.reserve(per_frame_groups->Size());

        for (size_t i = 0; i < per_frame_groups->Size(); i++) {
            // Build the new frame, adding per-frame attributes after the common ones to ensure the most
            // specific survive. (There should be no conflicts, but just in case).
            auto frame = make_shared<AttributeSet>(false);

            // Add all items from the source _except_ the per-frame and shared functional groups.
            for (auto it = metadata->Begin(); it != metadata->End(); ++it) {
                tag_number tag = it->first;
                if (tag == tags::PerFrameFunctionalGroupsSequence) { continue; }
                if (tag == tags::SharedFunctionalGroupsSequence) { continue; }

                frame->AddUnowned(it->first, it->second);
            }

            if (shared_groups00) {
                for (auto& macro_item : shared_groups00->Items()) {
                    combine_attributes(frame.get(), macro_item.get());
                }
            }
            combine_attributes(frame.get(), per_frame_groups->Items()[i].get());

            // Derive the frame_index and cache the frame. Take ownership of the FrameIndexTag separately.
            auto frame_index_vr = make_unique<IS>(frame_number++);
            frame->AddUnowned(private_tags::FrameIndexTag, frame_index_vr.get());

            auto additional_attributes = make_shared<AttributeSet>();
            additional_attributes->Add(private_tags::FrameIndexTag, move(frame_index_vr));
            
            frame_index index(frame.get());
            info.m_frame_indicies.push_back(index);
            info.m_additional_attributes.emplace_back(move(additional_attributes));
            index_list.push_back(index);

            m_index_to_frame.emplace(index, move(frame));
        }

        m_load_results.emplace(forward<load_result_key>(key), move(info));
        return index_list;
    }

    //--------------------------------------------------------------------------------------------------------

    FrameIndexList FrameCache::DeriveFromMultiFrameModule(
        load_result_key&& key,
        const io::LoadResultPtr& load_result
    ) {
        auto& metadata = load_result->Metadata();

        // Get the number of frames in the sequence.
        auto number_of_frames = metadata->Get<IS>(tags::NumberOfFrames)->First();

        LoadResultInfo info;
        info.m_load_result = load_result;
        info.m_frame_indicies.reserve(number_of_frames);
        info.m_additional_attributes.reserve(number_of_frames);

        FrameIndexList index_list;
        index_list.reserve(number_of_frames);

        uint32_t frame_number = 0;

        for (int32_t i = 0; i < number_of_frames; i++) {
            // Build the new frame.
            auto frame = make_shared<AttributeSet>(false);

            // Add all attributes from the source.
            frame->AddRangeUnowned(metadata->BeginGroup(0x0002), metadata->EndGroup(0x7000));

            // Derive the frame_index and cache the frame. Take ownership of the FrameIndexTag separately.
            auto frame_index_vr = make_unique<IS>(frame_number++);
            frame->AddUnowned(private_tags::FrameIndexTag, frame_index_vr.get());

            auto additional_attributes = make_shared<AttributeSet>();
            additional_attributes->Add(private_tags::FrameIndexTag, move(frame_index_vr));

            frame_index index(frame.get());
            info.m_frame_indicies.push_back(index);
            info.m_additional_attributes.emplace_back(move(additional_attributes));
            index_list.push_back(index);

            m_index_to_frame.emplace(index, move(frame));
        }

        m_load_results.emplace(forward<load_result_key>(key), move(info));
        return index_list;
    }

    //--------------------------------------------------------------------------------------------------------

    bool FrameCache::load_result_key::operator < (const load_result_key& other) const {
        int result = SOPInstanceUID.compare(other.SOPInstanceUID);
        if (result == -1) { return true; }

        return FrameNumberStart < other.FrameNumberStart;
    }

    //--------------------------------------------------------------------------------------------------------

    FrameCache::load_result_key::load_result_key(const AttributeSetPtr& metadata) {
        detail::elem_reader<UI> sop_instance_uid(metadata.get(), tags::SOPInstanceUID);
        detail::elem_reader<UL> frame_offset_number(metadata.get(), tags::ConcatenationFrameOffsetNumber);

        // Check the SOPInstanceUID is available.
        if (!sop_instance_uid) {
            throw logic_error("SOPInstanceUID is missing");
        }

        uint32_t first_frame_index = frame_offset_number ? frame_offset_number->First() : 0;

        SOPInstanceUID = sop_instance_uid->Value();
        FrameNumberStart = first_frame_index;
    }

}