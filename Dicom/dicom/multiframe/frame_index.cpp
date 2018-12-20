#include "dicom_pch.h"
#include "dicom/multiframe/frame_index.h"

#include "dicom/detail/private_elem_reader.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/IS.h"
#include "dicom/data/UI.h"
#include "dicom/multiframe/PrivateTags.h"
#include "dicom/Tags.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    [[nodiscard]] int32_t CompareVRs(const VR* left, const VR* right) {
        if (left == right) { return 0; }
        if (!left) {
            if (!right) { return 0; }
            return 1;
        }
        if (!right) { return -1; }

        return left->Compare(right);
    }
}

namespace dicom::multiframe {

    frame_index::frame_index(const data::AttributeSet* attribute_set)
      : m_study_instance_uid(attribute_set->Get<UI>(tags::StudyInstanceUID)),
        m_series_instance_uid(attribute_set->Get<UI>(tags::SeriesInstanceUID)),
        m_sop_instance_uid(attribute_set->Get<UI>(tags::SOPInstanceUID)),
        m_frame_number(0)
    {
        detail::private_elem_reader<IS> frame_number(attribute_set, private_tags::FrameIndexTag);
        if (frame_number && !frame_number->Empty()) { m_frame_number = frame_number->First(); }
    }

    //--------------------------------------------------------------------------------------------------------

    frame_index::frame_index(const data::AttributeSet* attribute_set, uint32_t frame_number)
      : m_study_instance_uid(attribute_set->Get<UI>(tags::StudyInstanceUID)),
        m_series_instance_uid(attribute_set->Get<UI>(tags::SeriesInstanceUID)),
        m_sop_instance_uid(attribute_set->Get<UI>(tags::SOPInstanceUID)),
        m_frame_number(frame_number)
    {}

    //--------------------------------------------------------------------------------------------------------

    int32_t frame_index::Compare(const frame_index& other) const {
        int32_t result = CompareVRs(m_study_instance_uid, other.m_study_instance_uid);
        if (result) { return result; }

        result = CompareVRs(m_series_instance_uid, other.m_series_instance_uid);
        if (result) { return result; }

        result = CompareVRs(m_sop_instance_uid, other.m_sop_instance_uid);
        if (result) { return result; }

        if (m_frame_number < other.m_frame_number) { return -1; }
        return (m_frame_number == other.m_frame_number) ? 0 : 1;
    }

}