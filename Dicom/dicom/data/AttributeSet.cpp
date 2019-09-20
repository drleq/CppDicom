#include "dicom_pch.h"
#include "dicom/data/AttributeSet.h"

#include "dicom/data/LO.h"
#include "dicom/data/US.h"
#include "dicom/private_tag.h"

using namespace std;

namespace dicom::data {

	AttributeSet::AttributeSet()
      : m_owns_attributes(true)
    {}

    //--------------------------------------------------------------------------------------------------------

    AttributeSet::AttributeSet(bool own_attributes)
      : m_owns_attributes(own_attributes)
    {}

    //--------------------------------------------------------------------------------------------------------

    AttributeSet::AttributeSet(AttributeSet&& other) = default;
    AttributeSet& AttributeSet::operator = (AttributeSet&& other) = default;

	//--------------------------------------------------------------------------------------------------------

	AttributeSet::~AttributeSet() {
        if (m_owns_attributes) {
            for (auto& attribute : m_attributes) { delete attribute.second; }
        }

        for (auto creator_attribute : m_owned_creator_attributes) { delete creator_attribute; }
	}

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

	unique_ptr<VR> AttributeSet::Add(tag_number tag, unique_ptr<VR>&& attribute) {
        AssertOwned();

        // Private Creator tags must pass validation.
        if (is_creator_tag(tag)) { UpdateCreatorFromRaw(tag, attribute.get()); }
        return AddRaw(tag, attribute.release());
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::Remove(tag_number tag) {
        AssertOwned();

        // Private Creator tags cannot be manually removed.
        if (is_creator_tag(tag)) { return nullptr; }
        return RemoveRaw(tag);
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::Add(const private_tag& tag, unique_ptr<VR>&& attribute) {
        AssertOwned();

        // Update the Private Creator information if required, getting the remapped tag number.
        auto _tag = UpdateCreator(tag);

        // Update the attribute map, returning the old VR if one was already assigned.
        return AddRaw(_tag, attribute.release());
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::Remove(const private_tag& tag) {
        AssertOwned();

        // Find private tag information for the group.
        auto creator_mask_it = m_creator_group_masks.find(tag.Group());
        if (creator_mask_it == m_creator_group_masks.end()) { return nullptr; }

        // Find private tag information for the creator, within the group.
        auto& creator_masks = creator_mask_it->second;
        auto mask_it = creator_masks.find(tag.CreatorName());
        if (mask_it == creator_masks.end()) { return nullptr; }

        auto mask = mask_it->second;
        auto _tag = tag_number(mask | tag.Element);

        // Clean up the Private Creator tag.
        RemoveCreatorFromRaw(_tag);

        // Update the attribute map, returning the removed VR.
        return RemoveRaw(_tag);
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::AddValue(const tag& tag, uint16_t value) {
        switch (tag.Type) {
        case VRType::US: return Add(tag, std::make_unique<US>(value));

        default:
            throw std::invalid_argument("Tag does not match value type");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    template <>
    uint16_t AttributeSet::GetValue<uint16_t>(const tag& tag) const {
        auto vr = Get(tag);
        switch (vr->Type()) {
        case VRType::US: return static_cast<const data::US*>(vr)->First();
        
        default:
            throw std::invalid_argument("Tag does not match value type");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AddAll(AttributeSet&& other) {
        AssertOwned();

        // This will iterate [other.m_attributes] in ascending order of the tag value. This will ensure that
        // creator tags are encountered first.
        for (auto& kvp : other.m_attributes) {
            Add(kvp.first, unique_ptr<VR>(kvp.second));
        }

        other.m_attributes.clear();
        other.m_creator_group_masks.clear();
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::CopyAll(const AttributeSet& other) {
        AssertOwned();

        // This will iterate [other.m_attributes] in ascending order of the tag value. This will ensure that
        // creator tags are encountered first.
        for (auto& kvp : other.m_attributes) {
            Add(kvp.first, kvp.second->Copy());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::CopyRange(const_iterator first, const_iterator last) {
        AssertOwned();

        // This will iterate [other.m_attributes] in ascending order of the tag value. This will ensure that
        // creator tags are encountered first.
        for (; first != last; ++first) {
            Add(first->first, first->second->Copy());
        }
    }

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AddUnowned(tag_number tag, VR* unowned_attribute) {
        AssertUnowned();

        // Private Creator tags must pass validation.
        if (is_creator_tag(tag)) { UpdateCreatorFromRaw(tag, unowned_attribute); }
        AddRaw(tag, unowned_attribute);
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AddUnowned(const private_tag& tag, VR* unowned_attribute) {
        AssertUnowned();

        // Update the Private Creator information if required, getting the remapped tag number.
        auto _tag = UpdateCreator(tag);

        // Update the attribute map, returning the old VR if one was already assigned.
        AddRaw(_tag, unowned_attribute);
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AddAllUnowned(const AttributeSet& other) {
        AssertUnowned();

        // This will iterate [other.m_attributes] in ascending order of the tag value. This will ensure that
        // creator tags are encountered first.
        for (auto& kvp : other.m_attributes) {
            AddUnowned(kvp.first, kvp.second);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AddRangeUnowned(const_iterator first, const_iterator last) {
        AssertUnowned();

        // This will iterate [other.m_attributes] in ascending order of the tag value. This will ensure that
        // creator tags are encountered first.
        for (; first != last; ++first) {
            AddUnowned(first->first, first->second);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::RemoveUnowned(tag_number tag) {
        AssertUnowned();

        // Private Creator tags cannot be manually removed.
        if (is_creator_tag(tag)) { return; }
        RemoveRaw(tag);
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::RemoveUnowned(const private_tag& tag) {
        AssertUnowned();

        // Find private tag information for the group.
        auto creator_mask_it = m_creator_group_masks.find(tag.Group());
        if (creator_mask_it == m_creator_group_masks.end()) { return; }

        // Find private tag information for the creator, within the group.
        auto& creator_masks = creator_mask_it->second;
        auto mask_it = creator_masks.find(tag.CreatorName());
        if (mask_it == creator_masks.end()) { return; }

        auto mask = mask_it->second;
        auto _tag = tag_number(mask | tag.Element);

        // Clean up the Private Creator tag.
        RemoveCreatorFromRaw(_tag);

        // Update the attribute map, returning the removed VR.
        RemoveRaw(_tag);
    }

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    bool AttributeSet::Contains(const private_tag& tag) const {
        // Find private tag information for the group.
        auto creator_mask_it = m_creator_group_masks.find(tag.Group());
        if (creator_mask_it == m_creator_group_masks.end()) { return false; }

        // Find private tag information for the creator, within the group.
        auto& creator_masks = creator_mask_it->second;
        auto it = creator_masks.find(tag.CreatorName());
        if (it == creator_masks.end()) { return false; }

        // Defer to non-private tag method.
        auto _tag = tag_number(it->second | tag.Element);
        return Contains(_tag);
    }

    //--------------------------------------------------------------------------------------------------------

    const VR* AttributeSet::Get(const private_tag& tag) const {
        // Find private tag information for the group.
        auto creator_mask_it = m_creator_group_masks.find(tag.Group());
        if (creator_mask_it == m_creator_group_masks.end()) { return nullptr; }

        // Find private tag information for the creator, within the group.
        auto& creator_masks = creator_mask_it->second;
        auto it = creator_masks.find(tag.CreatorName());
        if (it == creator_masks.end()) { return nullptr; }

        // Defer to non-private tag method.
        auto _tag = tag_number(it->second | tag.Element);
        return Get(_tag);
    }

    //--------------------------------------------------------------------------------------------------------

    bool AttributeSet::TryGetPrivateCreator(tag_number tag, const std::string_view** private_creator) const {
        // Non-private tags cannot have a private creator.
        if (!is_private_tag(tag)) { return false; }

        // Search for private creators for the group.
        tag_group group = get_tag_group(tag);
        auto group_it = m_creator_group_masks.find(group);
        if (group_it == m_creator_group_masks.end()) { return false; }

        // Search for the specific private creator mask.
        uint8_t element = uint8_t(tag >> 8);
        auto expected_mask = make_creator_mask(group, element);
        auto& creator_masks = group_it->second;
        for (auto& kvp : creator_masks) {
            if (kvp.second == expected_mask) {
                // Found a match.
                *private_creator = &kvp.first;
                return true;
            }
        }

        // No match.
        return false;
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::AddRaw(tag_number tag, VR* attribute) {
        auto it = m_attributes.find(tag);
        if (it == m_attributes.end()) {
            // No previous attribute. Add new one.
            m_attributes.emplace(tag, attribute);
            return nullptr;
        }

        // Old attribute exists. Update it.
        if (m_owns_attributes) {
            auto old_attribute = it->second;
            it->second = attribute;
            return unique_ptr<VR>(old_attribute);
        } else {
            it->second = attribute;
            return nullptr;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    unique_ptr<VR> AttributeSet::RemoveRaw(tag_number tag) {
        auto it = m_attributes.find(tag);
        if (it == m_attributes.end()) { return nullptr; }

        // Attribute exists. Remove it.
        if (m_owns_attributes) {
            auto old_attribute = it->second;
            m_attributes.erase(it);
            return unique_ptr<VR>(old_attribute);
        } else {
            m_attributes.erase(it);
            return nullptr;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    uint32_t AttributeSet::UpdateCreator(const private_tag& tag) {
        auto& creator_masks = m_creator_group_masks[tag.Group()];

        auto mask_it = creator_masks.find(tag.CreatorName());
        if (mask_it != creator_masks.end()) {
            // Mapping already exists.
            return mask_it->second | tag.Element;
        }

        // Find the lowest mask number not already occupied in this group.
        int i = 0x10;
        for (; i <= 0xFF; i++) {
            auto it = find_if(
                creator_masks.begin(),
                creator_masks.end(),
                [=](const auto& kvp) { return uint8_t(kvp.second >> 8) == i; }
            );
            if (it == creator_masks.end()) { break; }
        }

        // There is finite space for unique private creators. Nothing we can do about that.
        if (i == 0x100) { throw runtime_error("Too many private creators for group"); }

        // Save the mask.
        auto mask = make_creator_mask(tag.Group(), uint8_t(i));
        creator_masks.emplace(tag.CreatorName(), mask);

        // Add a Private Creator attribute.
		auto new_creator_tag = make_unique<LO>(
            encoded_string(tag.CreatorName(), StringEncodingType::UTF8)
        );
        if (!m_owns_attributes) {
            // We still need to own these attributes.
            m_owned_creator_attributes.push_back(new_creator_tag.get());
        }
        AddRaw(make_creator_tag(tag.Group(), uint8_t(i)), new_creator_tag.release());

        // Return the remapped tag number.
        return mask | tag.Element;
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::UpdateCreatorFromRaw(tag_number creator_tag, VR* attribute) {
        // [attribute] must be a validated LO.
        auto creator00 = dynamic_cast<LO*>(attribute);
        if (creator00 == nullptr || (creator00->Validity() == ValidityType::Invalid)) { return; }

        // Derive the Private Creator information.
        tag_group group = get_tag_group(creator_tag);
        auto& creator_name = creator00->ParsedValue();
        auto expected_mask = creator_tag_to_mask(creator_tag);

        auto creator_masks_it = m_creator_group_masks.find(group);
        if (creator_masks_it == m_creator_group_masks.end()) {
            // No mappings in the group yet. Easy to populate directly with the [expected_mask].
            map<string_view, tag_number> masks;
            masks.emplace(creator_name, expected_mask);
            m_creator_group_masks.emplace(group, move(masks));
            return;
        }

        auto& creator_masks = creator_masks_it->second;
        auto mask_it = creator_masks.find(creator_name);
        if (mask_it == creator_masks.end()) {
            // Creator isn't registered for this group yet. Check that the [expected_mask] is available.
            auto it = find_if(
                creator_masks.begin(),
                creator_masks.end(),
                [=](const auto& kvp) { return (kvp.second == expected_mask); }
            );
            if (it != creator_masks.end()) { throw runtime_error("Private tag creator collision"); }

            // No collisions. Add the mapping.
            creator_masks.emplace(creator_name, expected_mask);
        } else {
            // Creator is already registered for this group. Check consistency of the mask.
            //if (mask_it->second != expected_mask) { throw runtime_error("Private tag creator is inconsistent"); }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::RemoveCreatorFromRaw(tag_number tag) {
        // Extract the private creator mask from the tag.
        auto mask = tag & 0xFFFFFF00;

        // Only remove the creator if there are no mapped attributes.
        auto start_it = m_attributes.lower_bound(mask);
        auto end_it = m_attributes.upper_bound(mask | 0xFF);
        if (distance(start_it, end_it) != 0) { return; }

        // Search for the Private Creator entry.
        tag_group group = get_tag_group(tag);
        auto creator_mask_it = m_creator_group_masks.find(group);
        if (creator_mask_it == m_creator_group_masks.end()) { return; }

        auto& creator_masks = creator_mask_it->second;
        auto mask_it = find_if(
            creator_masks.begin(),
            creator_masks.end(),
            [=](const auto& kvp) { return kvp.second == mask; }
        );
        if (mask_it == creator_masks.end()) { return; }

        // Remove the Private Creator for this group and remove the attribute created for it.
        creator_masks.erase(mask_it);
        unique_ptr<VR> old_vr = RemoveRaw(creator_mask_to_tag(mask));
        auto owned_it = find(
            m_owned_creator_attributes.begin(),
            m_owned_creator_attributes.end(),
            old_vr.get()
        );
        if (owned_it != m_owned_creator_attributes.end()) {
            m_owned_creator_attributes.erase(owned_it);
        }

        // Remove the group if no more private mappings exist for it.
        if (creator_masks.empty()) { m_creator_group_masks.erase(creator_mask_it); }
    }

    //--------------------------------------------------------------------------------------------------------

    AttributeSet AttributeSet::Copy() const {
        AttributeSet copy;
        copy.CopyAll(*this);
        return copy;
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AssertOwned() const {
        if (!m_owns_attributes) {
            throw logic_error("AttributeSet only accepts unowned attributes");
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void AttributeSet::AssertUnowned() const {
        if (m_owns_attributes) {
            throw logic_error("AttributeSet only accepts owned attributes");
        }
    }

}