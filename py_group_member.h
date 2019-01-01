#pragma once

class py_group_member : public py_lsobject
{
public:
	py_group_member() = default;
	py_group_member(const LSOBJECT& ls_object);
	int get_arcane();
	std::string get_class();
	int64_t get_current_health();
	int get_current_power();
	int get_cursed();
	int get_effective_level();
	int get_elemental();
	int get_id();
	int get_level();
	int64_t get_max_health();
	int get_max_power();
	std::string get_name();
	int get_noxious();
	bool get_in_zone();
	bool get_is_afflicted();
	int get_pet_id();
	std::string get_race();
	int get_raid_group_num();
	int get_raid_role();
	int get_trauma();
	std::string get_zone_name();
};