#pragma once

#include "dicom/io/ILoadResult.h"
#include "dicom/multiframe/frame_index.h"

#include "dicom/io/codec/ICodecFactory.h"

namespace dicom::data { class AttributeSet; }

namespace dicom::multiframe {

    using FrameList = std::vector<data::AttributeSetConstPtr>;

    class DICOM_EXPORT FrameCache
    {
    public:
        FrameCache();
        ~FrameCache();

        FrameCache(const FrameCache&) = delete;
        FrameCache& operator = (const FrameCache&) = delete;

        FrameIndexList Add(const io::LoadResultPtr& load_result);

        [[nodiscard]] FrameIndexList GetIndexList() const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] data::AttributeSetConstPtr GetFrame00(const frame_index& index) const;
        [[nodiscard]] FrameList GetFrameList(const FrameIndexList& indices) const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool LoadPixelData(const frame_index& index, const dicom::io::codec::ICodecFactory* codec_factory00);

    private:
        struct LoadResultInfo
        {
            io::LoadResultPtr m_load_result;
            FrameIndexList m_frame_indicies;
            std::vector<data::AttributeSetPtr> m_additional_attributes;
        };

        struct load_result_key
        {
            std::string_view SOPInstanceUID;
            uint32_t FrameNumberStart;

            load_result_key(const data::AttributeSetPtr& load_result);
            bool operator < (const load_result_key& other) const;
        };

        std::map<load_result_key, LoadResultInfo> m_load_results;
        std::map<frame_index, data::AttributeSetPtr> m_index_to_frame;

        FrameIndexList DeriveFromFunctionalGroupsModule(load_result_key&& key, const io::LoadResultPtr& load_result);
        FrameIndexList DeriveFromMultiFrameModule(load_result_key&& key, const io::LoadResultPtr& load_result);
    };

}