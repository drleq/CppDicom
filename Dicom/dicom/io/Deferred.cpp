#include "dicom_pch.h"
#include "dicom/io/Deferred.h"

namespace dicom::io {

    Deferred::Deferred(LoadDeferredVRCallback load_vr_callback)
      : data::VR(data::VRType::Deferred),
        m_load_vr_callback(load_vr_callback)
    {}

    //--------------------------------------------------------------------------------------------------------

    Deferred::Deferred(const Deferred& other)
      : data::VR(other),
        m_load_vr_callback(other.m_load_vr_callback)
    {
        if (other.m_loaded_vr) {
            m_loaded_vr = other.m_loaded_vr->Copy();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    Deferred::Deferred(Deferred&& other)
      : data::VR(std::forward<Deferred>(other)),
        m_load_vr_callback(std::move(other.m_load_vr_callback)),
        m_loaded_vr(std::move(other.m_loaded_vr))
    {}

    //--------------------------------------------------------------------------------------------------------

    Deferred::~Deferred() = default;

    //--------------------------------------------------------------------------------------------------------

    bool Deferred::Load() {
        if (IsLoaded()) { return true; }
        if (!m_load_vr_callback) { return false; }

        // Load the VR
        m_loaded_vr = m_load_vr_callback();

        // Return the VR
        return (bool)m_loaded_vr;
    }

    //--------------------------------------------------------------------------------------------------------

    void Deferred::Unload() {
        m_loaded_vr.reset();
    }

    //--------------------------------------------------------------------------------------------------------

    data::ValidityType Deferred::Validate() const {
        return ValidityDeferred;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t Deferred::Compare(const data::VR* other) const {
        auto result = data::VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const Deferred*>(other);
        
        // Check if the VRs are loaded
        bool is_loaded = IsLoaded();
        if (is_loaded != typed->IsLoaded()) { return is_loaded ? -1 : 1; }

        // Compare null-ness of values
        bool is_null = !m_loaded_vr;
        bool typed_is_null = !typed->m_loaded_vr;
        if (is_null != typed_is_null) { return is_null ? -1 : 1; }
        if (is_null) { return 0; }

        // Compare the loaded VRs
        return m_loaded_vr->Compare(typed->m_loaded_vr.get());
    }

}