#pragma once

class py_character : public py_lsobject
{
public:
	py_character();
	bool check_collision(const float& to_x, const float& to_y, const float& to_z);
	int get_agility();
	int get_arcane_resist();
	float get_arcane_resist_percent();
	std::string get_archetype();
	float get_ascension_exp_bubble();
	int get_ascension_exp_current();
	int get_ascension_exp_next_level();
	float get_ascension_exp_percent();
	int get_ascension_level();
	bool get_at_char_select();
	bool get_is_auto_attack_on();
	int get_base_agility();
	int get_base_intelligence();
	int get_base_stamina();
	int get_base_strength();
	int get_base_wisdom();
	float get_breath();
	std::string get_class();
	int get_copper();
	int get_count_maintained();
	int64_t get_current_health();
	int get_current_power();
	int get_dissipation();
	int get_dissonance();
	int get_dissonance_remaining();
	int get_effective_level();
	int get_elemental_resist();
	float get_elemental_resist_percent();
	float get_exp_bubble();
	int get_exp_current();
	float get_exp_debt_current();
	int get_exp_next_level();
	float get_exp_percent();
	std::string get_gender();
	int get_gold();
	int get_group(boost::python::list& group_member_list);
	int get_group_count();
	bool get_grouped();
	float get_heading();
	int get_health_regen();
	bool get_in_game_world();
	bool get_is_in_raid();
	bool get_is_in_water();
	int get_intelligence();
	bool get_is_casting_spell();
	bool get_is_group_leader();
	bool get_is_hated();
	bool get_is_in_combat();
	bool get_is_in_first_person_view();
	bool get_is_in_pvp();
	bool get_is_in_third_person_view();
	bool get_is_moving();
	bool get_is_ranged_auto_attack_on();
	int get_level();
	int get_max_conc();
	int get_max_dissonance();
	int64_t get_max_health();	
	int get_max_power();
	int get_maintained(boost::python::list& maintained_list);
	std::string get_name();
	int get_noxious_resist();
	float get_noxious_resist_percent();
	int get_power_regen();
	int get_platinum();
	std::string get_race();
	int get_raid(boost::python::list& raid_member_list);
	int get_raid_count();
	int get_raid_group_num();	
	int get_silver();
	std::string get_subclass();
	int get_stamina();
	int get_strength();
	float get_tithe_exp_bubble();
	int get_tithe_exp_current();
	int get_tithe_exp_next_level();
	float get_tithe_exp_percent();
	float get_tithe_vitality_overflow_marker();
	std::string get_ts_archetype();
	std::string get_ts_class();
	float get_ts_exp_bubble();
	int get_ts_exp_current();
	float get_ts_exp_debt_current();
	int get_ts_exp_next_level();
	float get_ts_exp_percent();
	int get_ts_level();
	std::string get_ts_subclass();
	float get_ts_vitality();
	float get_ts_vitality_lower_marker();
	float get_ts_vitality_upper_marker();
	float get_ts_vitality_overflow_marker();
	int get_used_conc();
	float get_vitality();
	float get_vitality_lower_marker();
	float get_vitality_overflow_marker();
	float get_vitality_upper_marker();
	float get_water_depth();
	int get_wisdom();
	float get_x();
	float get_y();
	float get_z();
	float heading_to(const float& to_x, const float& to_y, const float& to_z);
	std::string heading_to_as_compass_bearing(const float& to_x, const float& to_y, const float& to_z);
	py_maintained maintained(const int& number = 0, const std::string& name = std::string());
	py_maintained maintained_1(const int& number) { return maintained(number); }
	py_maintained maintained_2(const std::string& name) { return maintained(0, name); }
	int query_effects(boost::python::list& effect_list, const std::string& query = std::string());
	int query_inventory(boost::python::list& item_list, const std::string& query = std::string());
	int query_recipes(boost::python::list& recipe_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_effects_overloads, query_effects, 1, 2)
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_inventory_overloads, query_inventory, 1, 2)
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_recipes_overloads, query_recipes, 1, 2)
	
	py_group_member get_group_member(const int& member_or_id = -1, const std::string& name = std::string());
	py_group_member get_group_member_1(const int& member_or_id) { return get_group_member(member_or_id); };
	py_group_member get_group_member_2(const std::string& name) { return get_group_member(-1, name); };
	py_group_member get_raid_member(const int& member_or_id = -1, const int& group_num = -1, const std::string& name = std::string());
	py_group_member get_raid_member_1(const int& member_or_id) { return get_raid_member(member_or_id); }
	py_group_member get_raid_member_2(const int& member_or_id, const int& group_number) { return get_raid_member(member_or_id, group_number); }
	py_group_member get_raid_member_3(const std::string& name) { return get_raid_member(-1, -1, name); }
};
