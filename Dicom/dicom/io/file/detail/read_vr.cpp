#include "dicom_pch.h"
#include "dicom/io/file/detail/read_vr.h"

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
#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_sq.h"

using namespace std;
using namespace dicom::data;

namespace dicom::io::file::detail {

    unique_ptr<data::VR> read_vr(InputContext& ctx, streamsize length, VRType vr_type) {
        if (!*ctx.Stream() || ctx.Failed()) { return nullptr; }

        unique_ptr<VR> vr;
        switch (vr_type) {
        // Handle tags that are represented by the Default Character Repertoire.
        case VRType::AE: vr = ctx.ReadString<AE>(length); break;
        case VRType::AS: vr = ctx.ReadString<AS>(length); break;
        case VRType::CS: vr = ctx.ReadString<CS>(length); break;
        case VRType::DA: vr = ctx.ReadString<DA>(length); break;
        case VRType::DS: vr = ctx.ReadString<DS>(length); break;
        case VRType::DT: vr = ctx.ReadString<DT>(length); break;
        case VRType::IS: vr = ctx.ReadString<IS>(length); break;
        case VRType::TM: vr = ctx.ReadString<TM>(length); break;
        case VRType::UI: vr = ctx.ReadString<UI>(length); break;
        case VRType::UR: vr = ctx.ReadString<UR>(length); break;

        // Handle tags that are represented by Unicode.
        case VRType::LO: vr = ctx.ReadUnicode<LO>(length); break;
        case VRType::LT: vr = ctx.ReadUnicode<LT>(length); break;
        case VRType::PN: vr = ctx.ReadUnicode<PN>(length); break;
        case VRType::SH: vr = ctx.ReadUnicode<SH>(length); break;
        case VRType::ST: vr = ctx.ReadUnicode<ST>(length); break;
        case VRType::UC: vr = ctx.ReadUnicode<UC>(length); break;
        case VRType::UT: vr = ctx.ReadUnicode<UT>(length); break;

        // Handle tags that are represented as binary.
        case VRType::FD: vr = ctx.ReadBinary<FD>(length); break;
        case VRType::FL: vr = ctx.ReadBinary<FL>(length); break;
        case VRType::OB: vr = ctx.ReadBinary<OB>(length); break;
        case VRType::OD: vr = ctx.ReadBinary<OD>(length); break;
        case VRType::OF: vr = ctx.ReadBinary<OF>(length); break;
        case VRType::OL: vr = ctx.ReadBinary<OL>(length); break;
        case VRType::OW: vr = ctx.ReadBinary<OW>(length); break;
        case VRType::SL: vr = ctx.ReadBinary<SL>(length); break;
        case VRType::SS: vr = ctx.ReadBinary<SS>(length); break;
        case VRType::UL: vr = ctx.ReadBinary<UL>(length); break;
        case VRType::UN: vr = ctx.ReadBinary<UN>(length); break;
        case VRType::US: vr = ctx.ReadBinary<US>(length); break;

        // Handle AT specifically
        case VRType::AT: {
            size_t count = static_cast<size_t>(length / sizeof(int32_t));
            if (count == 1) {
                vr = make_unique<AT>(ctx.ReadTagNumber());
            } else {
                AT::container_type tag_numbers(count);
                for (size_t i = 0; i < count; i++) { tag_numbers[i] = ctx.ReadTagNumber(); }
                vr = make_unique<AT>(move(tag_numbers));
            }
            break;
        }

        // Handle SQ specifically
        case VRType::SQ: vr = read_sq(ctx, length); break;

        default:
            // Unknown VR type. General de-serialization failure.
            ctx.SetFailed();
            break;
        }

        return vr;
    }

}