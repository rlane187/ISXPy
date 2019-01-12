#pragma once

class py_eq2_group_member : public eq2_actor
{
public:
	py_eq2_group_member();
	py_eq2_group_member(const py_eq2_group_member& other);
	py_eq2_group_member(py_eq2_group_member&& other) noexcept;
	py_eq2_group_member& operator=(const py_eq2_group_member& other);
	py_eq2_group_member& operator=(py_eq2_group_member&& other) noexcept;
	~py_eq2_group_member();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_group_member(const LSOBJECT& other);
	int get_arcane();
	int64_t get_current_health();
	int get_current_power();
	int get_cursed();
	int get_elemental();
	int64_t get_max_health();
	int get_max_power();
	int get_noxious();
	bool get_in_zone();
	bool get_is_afflicted();
	int get_pet_id();
	int get_raid_group_num();
	int get_raid_role();
	int get_trauma();
	std::string get_zone_name();
};