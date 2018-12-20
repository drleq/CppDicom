#pragma once

#include "dicom/data/AttributeSet.h"
#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"
#include "dicom/data/VRType.h"
#include "dicom/data/ValidityType.h"

#include "dicom/data/date.h"
#include "dicom/data/date_time.h"
#include "dicom/data/time.h"
#include "dicom/data/time_offset.h"

#include "dicom/data/AE.h"
#include "dicom/data/AS.h"
#include "dicom/data/AT.h"
#include "dicom/data/CS.h"
#include "dicom/data/DA.h"
#include "dicom/data/DS.h"
#include "dicom/data/DT.h"
#include "dicom/data/FD.h"
#include "dicom/data/FL.h"
#include "dicom/data/IS.h"
#include "dicom/data/LO.h"
#include "dicom/data/LT.h"
#include "dicom/data/OB.h"
#include "dicom/data/OD.h"
#include "dicom/data/OF.h"
#include "dicom/data/OL.h"
#include "dicom/data/OW.h"
#include "dicom/data/PN.h"
#include "dicom/data/SH.h"
#include "dicom/data/SL.h"
#include "dicom/data/SQ.h"
#include "dicom/data/SS.h"
#include "dicom/data/ST.h"
#include "dicom/data/TM.h"
#include "dicom/data/UC.h"
#include "dicom/data/UI.h"
#include "dicom/data/UL.h"
#include "dicom/data/UN.h"
#include "dicom/data/US.h"
#include "dicom/data/UR.h"
#include "dicom/data/UT.h"

#include "dicom/detail/element_defs.h"

namespace dicom {
    
    // Pull the entire dicom::data namespace up as it is frequently used.
    using data::AttributeSet;
    using data::AttributeSetPtr;
    using data::buffer;
    using data::ComponentGroup;
    using data::encoded_string;
    using data::PatientNameGroup;
    using data::StringEncodingType;
    using data::VR;
    using data::VRType;
    using data::ValidityType;

    using data::value_empty_error;
    using data::value_invalid_error;

    using data::date;
    using data::date_time;
    using data::time;
    using data::time_offset;

    using data::AE;
    using data::AS;
    using data::AT;
    using data::CS;
    using data::DA;
    using data::DS;
    using data::DT;
    using data::FD;
    using data::FL;
    using data::IS;
    using data::LO;
    using data::LT;
    using data::OB;
    using data::OD;
    using data::OF;
    using data::OL;
    using data::OW;
    using data::PN;
    using data::SH;
    using data::SL;
    using data::SQ;
    using data::SS;
    using data::ST;
    using data::TM;
    using data::UC;
    using data::UI;
    using data::UL;
    using data::UN;
    using data::UR;
    using data::US;
    using data::UT;
    using data::VRType;

}
