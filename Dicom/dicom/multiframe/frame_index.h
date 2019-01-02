#pragma once

namespace dicom::data { class AttributeSet; }
namespace dicom::data { class UI; }

namespace dicom::multiframe {

    class DICOM_EXPORT frame_index
    {
    public:
        frame_index(const data::AttributeSet* attribute_set);
        frame_index(const data::AttributeSet* attribute_set, uint32_t frame_number);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const data::UI* StudyInstanceUID() const { return m_study_instance_uid; }
        [[nodiscard]] const data::UI* SeriesInstanceUID() const { return m_series_instance_uid; }
        [[nodiscard]] const data::UI* SOPInstanceUID() const { return m_sop_instance_uid; }
        [[nodiscard]] uint32_t FrameNumber() const { return m_frame_number; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const frame_index& other) const;

        [[nodiscard]] bool operator == (const frame_index& other) const { return Compare(other) == 0; }
        [[nodiscard]] bool operator != (const frame_index& other) const { return Compare(other) != 0; }
        [[nodiscard]] bool operator <  (const frame_index& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const frame_index& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const frame_index& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const frame_index& other) const { return Compare(other) >= 0; }

    private:
        const data::UI* m_study_instance_uid;
        const data::UI* m_series_instance_uid;
        const data::UI* m_sop_instance_uid;
        uint32_t m_frame_number;
    };

    using FrameIndexList = std::vector<frame_index>;

}