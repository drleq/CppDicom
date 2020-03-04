#pragma once

#include "dicom/data/VR.h"
#include "dicom/tag.h"

namespace dicom { struct private_tag; }

namespace dicom::data {

    class DICOM_EXPORT AttributeSet
    {
    public:
        using attribute_map = std::map<tag_number, VR*>;
        using const_iterator = attribute_map::const_iterator;

        //----------------------------------------------------------------------------------------------------

        AttributeSet();
        AttributeSet(bool own_attributes);
        AttributeSet(AttributeSet&& other);
        ~AttributeSet();

        AttributeSet& operator = (AttributeSet&& other);

        // Disable copy semantics
        AttributeSet(const AttributeSet&) = delete;
        AttributeSet& operator = (const AttributeSet&) = delete;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool OwnsAttributes() const { return m_owns_attributes; }

        //----------------------------------------------------------------------------------------------------

        std::unique_ptr<VR> Add(tag_number tag, std::unique_ptr<VR>&& attribute);
		std::unique_ptr<VR> Remove(tag_number tag);

        std::unique_ptr<VR> Add(const private_tag& tag, std::unique_ptr<VR>&& attribute);
        std::unique_ptr<VR> Remove(const private_tag& tag);

        void AddAll(AttributeSet&& other);
        void CopyAll(const AttributeSet& other);
        void CopyRange(const_iterator first, const_iterator last);

        template <typename First, typename... Rest>
        void CopyExact(const AttributeSet& other, const First& first, const Rest&... rest) {
            Add(first, other.Get(first)->Copy());

            if constexpr (sizeof...(Rest) > 0) {
                CopyExact(other, rest...);
            }
        }

        template <typename TSource, typename TDest>
        void CopyTo(const AttributeSet& other, const TSource& source, const TDest& dest) {
            Add(dest, other.Get(source)->Copy());
        }

        //----------------------------------------------------------------------------------------------------

        std::unique_ptr<VR> AddValue(const tag& tag, uint16_t value);

        template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
        std::unique_ptr<VR> AddValue(const tag& tag, T value) {
            return AddValue(tag, static_cast<std::underlying_type_t<T>>(value));
        }

        //----------------------------------------------------------------------------------------------------

        template <typename T>
        T GetValue(const tag& tag) const {
            static_assert("Unknown value type");
        }

        template <> uint16_t GetValue<uint16_t>(const tag& tag) const;

        //----------------------------------------------------------------------------------------------------

        void AddUnowned(tag_number tag, VR* unowned_attribute);
        void AddUnowned(const private_tag& tag, VR* unowned_attribute);
        void AddAllUnowned(const AttributeSet& other);
        void AddRangeUnowned(const_iterator first, const_iterator last);

        void RemoveUnowned(tag_number tag);
        void RemoveUnowned(const private_tag& tag);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Contains(tag_number tag) const {
            return m_attributes.find(tag) != m_attributes.end();
        }

        [[nodiscard]] const VR* Get(tag_number tag) const {
            auto it = m_attributes.find(tag);
            return (it != m_attributes.end()) ? it->second : nullptr;
        }

		template <typename T>
        [[nodiscard]] const T* Get(tag_number tag) const {
			auto vr = AttributeSet::Get(tag);
			return dynamic_cast<const T*>(vr);
		}

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Contains(const private_tag& tag) const;
        [[nodiscard]] const VR* Get(const private_tag& tag) const;

        template <typename T>
        [[nodiscard]] const T* Get(const private_tag& tag) const {
            auto vr = AttributeSet::Get(tag);
            return dynamic_cast<const T*>(vr);
        }

        [[nodiscard]] bool TryGetPrivateCreator(tag_number tag, const std::string_view** private_creator) const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const_iterator Begin() const { return m_attributes.cbegin(); }
        [[nodiscard]] const_iterator End() const { return m_attributes.cend(); }

        [[nodiscard]] const_iterator BeginGroup(tag_group group) const {
            return m_attributes.lower_bound(make_tag_number(group, 0x0000));
        }
        [[nodiscard]] const_iterator EndGroup(tag_group group) const {
            return m_attributes.upper_bound(make_tag_number(group, 0xFFFF));
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] AttributeSet Copy() const;

        void MoveGroupRange(AttributeSet&& other, tag_group start, tag_group end);

    private:
        bool m_owns_attributes;
        attribute_map m_attributes;
        std::map<tag_group, std::map<std::string_view, tag_number>> m_creator_group_masks;
        std::vector<data::VR*> m_owned_creator_attributes;

        std::unique_ptr<VR> AddRaw(tag_number tag, VR* attribute);
        std::unique_ptr<VR> RemoveRaw(tag_number tag);
        
        tag_number UpdateCreator(const private_tag& tag);
        void UpdateCreatorFromRaw(tag_number tag, VR* attribute);
        void RemoveCreatorFromRaw(tag_number tag);

        void AssertOwned() const;
        void AssertUnowned() const;
    };

    // STL ADL functions
    inline auto begin(const AttributeSet& as) { return as.Begin(); }
    inline auto end(const AttributeSet& as) { return as.End(); }

    using AttributeSetPtr = std::shared_ptr<AttributeSet>;
    using AttributeSetConstPtr = std::shared_ptr<const AttributeSet>;

}