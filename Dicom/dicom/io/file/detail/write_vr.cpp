#include "dicom_pch.h"
#include "dicom/io/file/detail/write_vr.h"

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
#include "dicom/data/UR.h"
#include "dicom/data/US.h"
#include "dicom/data/UT.h"
#include "dicom/io/Deferred.h"
#include "dicom/io/file/detail/OutputContext.h"
#include "dicom/io/file/detail/write_sq.h"

using namespace dicom::data;

namespace {
    // Helper to cast from VR* to T*. Acts as shorthand.
    template <typename T>
    [[nodiscard]] const T* as(const VR* attribute) {
        // Static cast should be OK as switch statement handles the type check.
        return static_cast<const T*>(attribute);
    }
}

namespace dicom::io::file::detail {

    void write_vr(OutputContext* ctx, const data::VR* attribute) {
        if (!*ctx->Stream() || ctx->Failed()) { return; }

        auto vr_type = attribute->Type();
        switch (vr_type) {
        // Handle tags that are represented by the Default Character Repertoire.
        case VRType::AE: ctx->WriteString(as<AE>(attribute)->Value()); break;
        case VRType::AS: ctx->WriteString(as<AS>(attribute)->Value()); break;
        case VRType::CS: ctx->WriteString(as<CS>(attribute)->Value()); break;
        case VRType::DA: ctx->WriteString(as<DA>(attribute)->Value()); break;
        case VRType::DS: ctx->WriteString(as<DS>(attribute)->Value()); break;
        case VRType::DT: ctx->WriteString(as<DT>(attribute)->Value()); break;
        case VRType::IS: ctx->WriteString(as<IS>(attribute)->Value()); break;
        case VRType::TM: ctx->WriteString(as<TM>(attribute)->Value()); break;
        case VRType::UI: ctx->WriteUIString(as<UI>(attribute)->Value()); break;
        case VRType::UR: ctx->WriteString(as<UR>(attribute)->Value().Value()); break;

        // Handle tags that are represented by Unicode.
        case VRType::LO: ctx->WriteUnicode(as<LO>(attribute)->Value()); break;
        case VRType::LT: ctx->WriteUnicode(as<LT>(attribute)->Value()); break;
        case VRType::PN: ctx->WriteUnicode(as<PN>(attribute)->Value()); break;
        case VRType::SH: ctx->WriteUnicode(as<SH>(attribute)->Value()); break;
        case VRType::ST: ctx->WriteUnicode(as<ST>(attribute)->Value()); break;
        case VRType::UC: ctx->WriteUnicode(as<UC>(attribute)->Value()); break;
        case VRType::UT: ctx->WriteUnicode(as<UT>(attribute)->Value()); break;

        // Handle tags that are represented as binary.
        case VRType::FD: ctx->WriteBinary(as<FD>(attribute)); break;
        case VRType::FL: ctx->WriteBinary(as<FL>(attribute)); break;
        case VRType::OB: ctx->WriteBinary(as<OB>(attribute)); break;
        case VRType::OD: ctx->WriteBinary(as<OD>(attribute)); break;
        case VRType::OF: ctx->WriteBinary(as<OF>(attribute)); break;
        case VRType::OL: ctx->WriteBinary(as<OL>(attribute)); break;
        case VRType::OW: ctx->WriteBinary(as<OW>(attribute)); break;
        case VRType::SL: ctx->WriteBinary(as<SL>(attribute)); break;
        case VRType::SS: ctx->WriteBinary(as<SS>(attribute)); break;
        case VRType::UL: ctx->WriteBinary(as<UL>(attribute)); break;
        case VRType::UN: ctx->WriteBinary(as<UN>(attribute)); break;
        case VRType::US: ctx->WriteBinary(as<US>(attribute)); break;

        // Handle AT specifically
        case VRType::AT: {
            auto vr = as<AT>(attribute);
            for (auto& tag_number : vr->Value()) {
                ctx->WriteTagNumber(tag_number);
            }
            break;
        }

        // Handle SQ specifically
        case VRType::SQ: write_sq(ctx, as<SQ>(attribute), false); break;

        case VRType::Deferred: // We should not see Deferred items here.
        default:
            // Unknown VRType. Something very bad has happened.
            ctx->SetFailed();
            break;
        }
    }

}