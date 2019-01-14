#pragma once

class eq2_character : public eq2_actor
{
public:
	eq2_character();
	~eq2_character();
	eq2_character(const eq2_character& other);
	eq2_character(eq2_character&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_character(const LSOBJECT& other);
	eq2_character& operator=(const eq2_character& other);
	eq2_character& operator=(eq2_character&& other) noexcept;
	ls_bool check_collision(const float& to_x, const float& to_y, const float& to_z) override;
	ls_bool check_collision_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z) override;
	ls_int get_agility();
	ls_int get_arcane_resist();
	ls_float get_arcane_resist_percent();
	ls_string get_archetype();
	ls_float get_ascension_exp_bubble();
	int get_ascension_exp_current();
	int get_ascension_exp_next_level();
	ls_float get_ascension_exp_percent();
	int get_ascension_level();
	ls_bool get_at_char_select();	
	ls_int get_base_agility();
	ls_int get_base_intelligence();
	ls_int get_base_stamina();
	ls_int get_base_strength();
	ls_int get_base_wisdom();
	ls_float get_breath();
	ls_int get_copper();
	ls_int get_count_maintained();
	ls_int get_current_health();
	ls_int get_current_power();
	ls_int get_dissipation();
	ls_int get_dissonance();
	ls_int get_dissonance_remaining();
	ls_int get_elemental_resist();
	ls_float get_elemental_resist_percent();
	ls_float get_exp_bubble();
	int get_exp_current();
	ls_float get_exp_debt_current();
	int get_exp_next_level();
	ls_float get_exp_percent();
	eq2_dynamic_data get_game_data(const std::string& data);
	ls_int get_gold();
	int get_group(boost::python::list& group_member_list);
	ls_int get_group_count();
	eq2_group_member get_group_member(const int& member_or_id = -1, const std::string& name = std::string());
	eq2_group_member get_group_member_1(const int& member_or_id) { return get_group_member(member_or_id); };
	eq2_group_member get_group_member_2(const std::string& name) { return get_group_member(-1, name); };
	ls_bool get_grouped();
	ls_int get_health_regen();
	ls_bool get_in_game_world();	
	ls_int get_intelligence();
	ls_bool get_is_anonymous();
	ls_bool get_is_auto_attack_on();
	ls_bool get_is_casting_spell();
	ls_bool get_is_declining_duel_invites();
	ls_bool get_is_declining_group_invites();
	ls_bool get_is_declining_guild_invites();
	ls_bool get_is_declining_raid_invites();
	ls_bool get_is_declining_trade_invites();
	ls_bool get_is_group_leader();
	ls_bool get_is_guild_privacy_on();
	ls_bool get_is_hated();
	ls_bool get_is_ignoring_all();
	ls_bool get_is_in_combat();
	ls_bool get_is_in_first_person_view();
	ls_bool get_is_in_pvp();
	ls_int get_is_in_raid();
	ls_bool get_is_in_third_person_view();
	ls_bool get_is_in_water();
	ls_bool get_is_moving();
	ls_bool get_is_ranged_auto_attack_on();
	ls_bool get_is_roleplaying();
	ls_bool get_is_target_in_los();
	ls_int get_max_conc();
	ls_int get_max_dissonance();
	ls_int get_max_health();	
	ls_int get_max_power();
	int get_maintained(boost::python::list& maintained_list);
	ls_int get_noxious_resist();
	ls_float get_noxious_resist_percent();
	ls_int get_power_regen();
	ls_int get_platinum();
	int get_raid(boost::python::list& raid_member_list);
	ls_int get_raid_count();
	ls_int get_raid_group_num();
	eq2_group_member get_raid_member(const int& member_or_id = -1, const int& group_num = -1, const std::string& name = std::string());
	eq2_group_member get_raid_member_1(const int& member_or_id) { return get_raid_member(member_or_id); }
	eq2_group_member get_raid_member_2(const int& member_or_id, const int& group_number) { return get_raid_member(member_or_id, group_number); }
	eq2_group_member get_raid_member_3(const std::string& name) { return get_raid_member(-1, -1, name); }
	ls_int get_silver();
	ls_string get_subclass();
	ls_int get_stamina();
	ls_int get_strength();
	ls_float get_time_to_campout();
	ls_float get_tithe_exp_bubble();
	int get_tithe_exp_current();
	int get_tithe_exp_next_level();
	ls_float get_tithe_exp_percent();
	ls_float get_tithe_vitality_overflow_marker();
	ls_string get_ts_archetype();
	ls_string get_ts_class();
	ls_float get_ts_exp_bubble();
	int get_ts_exp_current();
	ls_float get_ts_exp_debt_current();
	int get_ts_exp_next_level();
	ls_float get_ts_exp_percent();
	ls_int get_ts_level();
	ls_string get_ts_subclass();
	ls_float get_ts_vitality();
	ls_float get_ts_vitality_lower_marker();
	ls_float get_ts_vitality_upper_marker();
	ls_float get_ts_vitality_overflow_marker();
	ls_int get_used_conc();
	ls_float get_vitality();
	ls_float get_vitality_lower_marker();
	ls_float get_vitality_overflow_marker();
	ls_float get_vitality_upper_marker();
	ls_float get_water_depth();
	ls_int get_wisdom();
	ls_float get_heading_to(const float& to_x, const float& to_y, const float& to_z);
	ls_float get_heading_to_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z);
	ls_string get_heading_to_as_compass_bearing(const float& to_x, const float& to_y, const float& to_z);
	ls_string get_heading_to_as_compass_bearing_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z);
	eq2_maintained maintained(const int& number = 0, const std::string& name = std::string());
	eq2_maintained maintained_1(const int& number) { return maintained(number); }
	eq2_maintained maintained_2(const std::string& name) { return maintained(0, name); }
	int query_effects(boost::python::list& effect_list, const std::string& query = std::string());
	int query_inventory(boost::python::list& item_list, const std::string& query = std::string());
	int query_recipes(boost::python::list& recipe_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_effects_overloads, query_effects, 1, 2)
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_inventory_overloads, query_inventory, 1, 2)
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_recipes_overloads, query_recipes, 1, 2)
	void face(const float& heading);
	void face_ls(const ls_float& heading);
	void take_all_vending_coin();
	void reset_zone_timer(const std::string& zone_name);
	void reset_zone_timer_ls(const ls_string& zone_name);
	void bank_deposit(const std::string& type, const int& amount, const bool& from_shared = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(bank_deposit_overloads, bank_deposit, 2, 3)
	void shared_bank_deposit(const std::string& type, const int& amount, const bool& from_bank = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(shared_bank_deposit_overloads, shared_bank_deposit, 2, 3)
	void bank_withdraw(const std::string& type, const int& amount);
	void shared_bank_withdraw(const std::string& type, const int& amount);
	void guild_bank_deposit(const int& bank_number, const int& amount);
	void guild_bank_withdraw(const int& bank_number, const int& amount);
	void deposit_into_house_escrow(const int& coin_amount, const int& status_amount);
};
