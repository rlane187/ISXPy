#include "ISXPyPCH.h"
#include "ISXPy.h"

BOOST_PYTHON_MODULE(isxeq2)
{
	using namespace boost::python;
	import("isxpy");

#pragma region eq2_actor

	class_<eq2_actor, bases<ls_object>>("actor")
		.def(init<const int&>())
		.def(init<const ls_int&>())
		.def(init<const std::string&>())
		.def(init<const LSOBJECT&>())
		.def(init<const ls_object&>())
		.add_property("aura", &eq2_actor::get_aura)
		.add_property("can_turn", &eq2_actor::get_can_turn)
		.add_property("char_class", &eq2_actor::get_class)
		.def("check_collision", &eq2_actor::check_collision, eq2_actor::check_collision_overloads(args("to_x", "to_y", "to_z")))
		.def("check_collision", &eq2_actor::check_collision_ls)
		.add_property("collision_radius", &eq2_actor::get_collision_radius)
		.add_property("collision_scale", &eq2_actor::get_collision_scale)
		.def("con_color", &eq2_actor::get_con_color, eq2_actor::get_con_color_overloads(args("as_rgb")))
		.add_property("current_animation", &eq2_actor::get_current_animation)
		.add_property("difficulty", &eq2_actor::get_difficulty)
		.add_property("distance", &eq2_actor::get_distance)
		.add_property("distance2d", &eq2_actor::get_distance2d)
		.add_property("effective_level", &eq2_actor::get_effective_level)
		.add_property("encounter_size", &eq2_actor::get_encounter_size)
		.add_property("faction", &eq2_actor::get_faction)
		.add_property("faction_standing", &eq2_actor::get_faction_standing)
		.add_property("flying_using_mount", &eq2_actor::get_flying_using_mount)
		.add_property("gender", &eq2_actor::get_gender)
		.add_property("guild", &eq2_actor::get_guild)
		.add_property("heading", &eq2_actor::get_heading)
		.def("heading_to", &eq2_actor::get_heading_to)
		.add_property("heading_to_as_compass_bearing", &eq2_actor::get_heading_to_as_compass_bearing)
		.add_property("id", &eq2_actor::get_id)
		.add_property("in_combat_mode", &eq2_actor::get_in_combat_mode)
		.add_property("in_my_group", &eq2_actor::get_in_my_group)
		.add_property("interactable", &eq2_actor::get_interactable)
		.add_property("is_afk", &eq2_actor::get_is_afk)
		.add_property("is_aggro", &eq2_actor::get_is_aggro)
		.add_property("is_a_pet", &eq2_actor::get_is_a_pet)
		.add_property("is_backing_up", &eq2_actor::get_is_backing_up)
		.add_property("is_banker", &eq2_actor::get_is_banker)
		.add_property("is_camping", &eq2_actor::get_is_camping)
		.add_property("is_chest", &eq2_actor::get_is_chest)
		.add_property("is_climbing", &eq2_actor::get_is_climbing)
		.add_property("is_crouching", &eq2_actor::get_is_crouching)
		.add_property("is_dead", &eq2_actor::get_is_dead)
		.add_property("is_encounter_broken", &eq2_actor::get_is_encounter_broken)
		.add_property("is_epic", &eq2_actor::get_is_epic)
		.add_property("is_falling", &eq2_actor::get_is_falling)
		.add_property("is_fd", &eq2_actor::get_is_fd)
		.add_property("is_heroic", &eq2_actor::get_is_heroic)
		.add_property("is_idle", &eq2_actor::get_is_idle)
		.def("is_in_same_encounter", &eq2_actor::get_is_in_same_encounter)
		.def("is_in_same_encounter", &eq2_actor::get_is_in_same_encounter_ls)
		.add_property("is_invis", &eq2_actor::get_is_invis)
		.add_property("is_jumping", &eq2_actor::get_is_jumping)
		.add_property("is_lfg", &eq2_actor::get_is_lfg)
		.add_property("is_lfw", &eq2_actor::get_is_lfw)
		.add_property("is_linkdead", &eq2_actor::get_is_linkdead)
		.add_property("is_locked", &eq2_actor::get_is_locked)
		.add_property("is_merchant", &eq2_actor::get_is_merchant)
		.add_property("is_my_pet", &eq2_actor::get_is_my_pet)
		.add_property("is_named", &eq2_actor::get_is_named)
		.add_property("is_on_carpet", &eq2_actor::get_is_on_carpet)
		.add_property("is_on_griffin", &eq2_actor::get_is_on_griffin)
		.add_property("is_on_horse", &eq2_actor::get_is_on_horse)
		.add_property("is_rooted", &eq2_actor::get_is_rooted)
		.add_property("is_sitting", &eq2_actor::get_is_sitting)
		.add_property("is_solo", &eq2_actor::get_is_solo)
		.add_property("is_stealthed", &eq2_actor::get_is_invis)
		.add_property("is_strafing_left", &eq2_actor::get_is_strafing_left)
		.add_property("is_strafing_right", &eq2_actor::get_is_strafing_right)
		.add_property("is_swimming", &eq2_actor::get_is_swimming)
		.add_property("health", &eq2_actor::get_health)
		.add_property("last_name", &eq2_actor::get_last_name)
		.add_property("level", &eq2_actor::get_level)
		.add_property("loc", &eq2_actor::get_loc)
		.add_property("mood", &eq2_actor::get_mood)
		.add_property("name", &eq2_actor::get_name)
		.add_property("get_num_effects", &eq2_actor::get_num_effects)
		.add_property("on_flying_mount", &eq2_actor::get_on_flying_mount)
		.add_property("pet", &eq2_actor::get_pet)
		.add_property("power", &eq2_actor::get_power)
		.add_property("race", &eq2_actor::get_race)
		.add_property("raid_size", &eq2_actor::get_raid_size)
		.add_property("speed", &eq2_actor::get_speed)
		.add_property("suffix_title", &eq2_actor::get_suffix_title)
		.add_property("swimming_speed_mod", &eq2_actor::get_swimming_speed_mod)
		.add_property("tag_target_icon", &eq2_actor::get_tag_target_icon)
		.add_property("tag_target_number", &eq2_actor::get_tag_target_number)
		.add_property("target", &eq2_actor::get_target)
		.add_property("target_ring_radius", &eq2_actor::get_target_ring_radius)
		.add_property("threat_to_me", &eq2_actor::get_threat_to_me)
		.add_property("threat_to_next", &eq2_actor::get_threat_to_next)
		.add_property("threat_to_pet", &eq2_actor::get_threat_to_pet)
		.add_property("tint_flags", &eq2_actor::get_tint_flags)
		.add_property("type", &eq2_actor::get_type)
		.add_property("velocity", &eq2_actor::get_velocity)
		.add_property("visual_variant", &eq2_actor::get_visual_variant)
		.add_property("who_following", &eq2_actor::get_who_following)
		.add_property("who_following_id", &eq2_actor::get_who_following_id)
		.add_property("x", &eq2_actor::get_x)
		.add_property("y", &eq2_actor::get_y)
		.add_property("z", &eq2_actor::get_z)
		.def("get_effects", &eq2_actor::get_effects)
		.def("double_click", &eq2_actor::double_click)
		.def("waypoint_to", &eq2_actor::waypoint_to)
		.def("do_face", &eq2_actor::do_face)
		.def("do_target", &eq2_actor::do_target)
		.def("location", &eq2_actor::location, eq2_actor::location_overloads(args("add_location", "notes")));

#pragma endregion

#pragma region eq2_actor_effect

	class_<eq2_actor_effect, bases<ls_object>>("actor_effect", init<const LSOBJECT&>())
		.add_property("back_drop_icon_id", &eq2_actor_effect::get_back_drop_icon_id)
		.add_property("current_increments", &eq2_actor_effect::get_current_increments)
		.add_property("is_effect_info_available", &eq2_actor_effect::get_is_effect_info_available)
		.add_property("main_icon_id", &eq2_actor_effect::get_main_icon_id)
		.add_property("effect_info", &eq2_actor_effect::get_effect_info)
		.add_property("id", &eq2_actor_effect::get_id);

#pragma endregion

#pragma region eq2_character

	class_<eq2_character, bases<eq2_actor>>("character")
		.add_property("agility", &eq2_character::get_agility)
		.add_property("arcane_resist", &eq2_character::get_arcane_resist)
		.add_property("arcane_resist_percent", &eq2_character::get_arcane_resist_percent)
		.add_property("archetype", &eq2_character::get_archetype)
		.add_property("ascension_exp_bubble", &eq2_character::get_ascension_exp_bubble)
		.add_property("ascension_exp_current", &eq2_character::get_ascension_exp_current)
		.add_property("ascension_exp_next_level", &eq2_character::get_ascension_exp_next_level)
		.add_property("ascension_exp_percent", &eq2_character::get_ascension_exp_percent)
		.add_property("ascension_level", &eq2_character::get_ascension_level)
		.add_property("at_char_select", &eq2_character::get_at_char_select)
		.add_property("base_agility", &eq2_character::get_base_agility)
		.add_property("base_intelligence", &eq2_character::get_base_intelligence)
		.add_property("base_stamina", &eq2_character::get_base_stamina)
		.add_property("base_strength", &eq2_character::get_base_strength)
		.add_property("base_wisdom", &eq2_character::get_base_wisdom)
		.add_property("breath", &eq2_character::get_breath)
		.def("check_collision", &eq2_character::check_collision)
		.def("check_collision", &eq2_character::check_collision_ls)
		.add_property("copper", &eq2_character::get_copper)
		.add_property("count_maintained", &eq2_character::get_count_maintained)
		.add_property("current_health", &eq2_character::get_current_health)
		.add_property("current_power", &eq2_character::get_current_power)
		.add_property("dissipation", &eq2_character::get_dissipation)
		.add_property("dissonance", &eq2_character::get_dissonance)
		.add_property("dissonance_remaining", &eq2_character::get_dissonance_remaining)
		.add_property("elemental_resist", &eq2_character::get_elemental_resist)
		.add_property("elemental_resist_percent", &eq2_character::get_elemental_resist_percent)
		.add_property("exp_bubble", &eq2_character::get_exp_bubble)
		.add_property("exp_current", &eq2_character::get_exp_current)
		.add_property("exp_debt_current", &eq2_character::get_exp_debt_current)
		.add_property("exp_next_level", &eq2_character::get_exp_next_level)
		.add_property("exp_percent", &eq2_character::get_exp_percent)
		.def("get_game_data", &eq2_character::get_game_data)
		.add_property("gold", &eq2_character::get_gold)
		.add_property("grouped", &eq2_character::get_grouped)
		.add_property("group_count", &eq2_character::get_group_count)
		.add_property("health_regen", &eq2_character::get_health_regen)
		.add_property("is_anonymous", &eq2_character::get_is_anonymous)
		.add_property("is_auto_attack_on", &eq2_character::get_is_auto_attack_on)
		.add_property("is_casting_spell", &eq2_character::get_is_casting_spell)
		.add_property("is_declining_duel_invites", &eq2_character::get_is_declining_duel_invites)
		.add_property("is_declining_group_invites", &eq2_character::get_is_declining_group_invites)
		.add_property("is_declining_guild_invites", &eq2_character::get_is_declining_guild_invites)
		.add_property("is_declining_raid_invites", &eq2_character::get_is_declining_raid_invites)
		.add_property("is_declining_trade_invites", &eq2_character::get_is_declining_trade_invites)
		.add_property("in_game_world", &eq2_character::get_in_game_world)
		.add_property("is_guild_privacy_on", &eq2_character::get_is_guild_privacy_on)
		.add_property("is_ignoring_all", &eq2_character::get_is_ignoring_all)	
		.add_property("is_in_combat", &eq2_character::get_is_in_combat)
		.add_property("is_in_first_person_view", &eq2_character::get_is_in_first_person_view)
		.add_property("is_in_pvp", &eq2_character::get_is_in_pvp)
		.add_property("is_in_raid", &eq2_character::get_is_in_raid)
		.add_property("is_in_third_person_view", &eq2_character::get_is_in_third_person_view)
		.add_property("is_in_water", &eq2_character::get_is_in_water)
		.add_property("is_ranged_auto_attack_on", &eq2_character::get_is_ranged_auto_attack_on)
		.add_property("intelligence", &eq2_character::get_intelligence)
		.add_property("is_group_leader", &eq2_character::get_is_group_leader)
		.add_property("is_hated", &eq2_character::get_is_hated)
		.add_property("is_moving", &eq2_character::get_is_moving)
		.add_property("is_roleplaying", &eq2_character::get_is_roleplaying)
		.add_property("is_target_in_los", &eq2_character::get_is_target_in_los)
		.def("Maintained", &eq2_character::maintained_1)
		.def("Maintained", &eq2_character::maintained_2)
		.add_property("max_conc", &eq2_character::get_max_conc)
		.add_property("max_dissonance", &eq2_character::get_max_dissonance)
		.add_property("max_health", &eq2_character::get_max_health)
		.add_property("max_power", &eq2_character::get_max_power)
		.add_property("noxious_resist", &eq2_character::get_noxious_resist)
		.add_property("noxious_resist_percent", &eq2_character::get_noxious_resist_percent)
		.add_property("platinum", &eq2_character::get_platinum)
		.add_property("power_regen", &eq2_character::get_power_regen)
		.add_property("raid_count", &eq2_character::get_raid_count)
		.add_property("raid_group_num", &eq2_character::get_raid_group_num)
		.add_property("silver", &eq2_character::get_silver)
		.add_property("stamina", &eq2_character::get_stamina)
		.add_property("strength", &eq2_character::get_strength)
		.add_property("subclass", &eq2_character::get_subclass)
		.add_property("time_to_campout", &eq2_character::get_time_to_campout)
		.add_property("tithe_exp_bubble", &eq2_character::get_tithe_exp_bubble)
		.add_property("tithe_exp_current", &eq2_character::get_tithe_exp_current)
		.add_property("tithe_exp_next_level", &eq2_character::get_tithe_exp_next_level)
		.add_property("tithe_exp_percent", &eq2_character::get_tithe_exp_percent)
		.add_property("tithe_vitality_overflow_marker", &eq2_character::get_tithe_vitality_overflow_marker)
		.add_property("ts_archetype", &eq2_character::get_ts_archetype)
		.add_property("ts_class", &eq2_character::get_ts_class)
		.add_property("ts_exp_bubble", &eq2_character::get_ts_exp_bubble)
		.add_property("ts_exp_current", &eq2_character::get_ts_exp_current)
		.add_property("ts_exp_debt_current", &eq2_character::get_ts_exp_debt_current)
		.add_property("ts_exp_next_level", &eq2_character::get_ts_exp_next_level)
		.add_property("ts_exp_percent", &eq2_character::get_ts_exp_percent)
		.add_property("ts_level", &eq2_character::get_ts_level)
		.add_property("ts_subclass", &eq2_character::get_ts_subclass)
		.add_property("ts_vitality", &eq2_character::get_ts_vitality)
		.add_property("ts_vitality_lower_marker", &eq2_character::get_ts_vitality_lower_marker)
		.add_property("ts_vitality_overflow_marker", &eq2_character::get_ts_vitality_overflow_marker)
		.add_property("ts_vitality_upper_marker", &eq2_character::get_ts_vitality_upper_marker)
		.add_property("used_conc", &eq2_character::get_used_conc)
		.add_property("vitality", &eq2_character::get_vitality)
		.add_property("vitality_lower_marker", &eq2_character::get_vitality_lower_marker)
		.add_property("vitality_overflow_marker", &eq2_character::get_vitality_overflow_marker)
		.add_property("vitality_upper_marker", &eq2_character::get_vitality_upper_marker)
		.add_property("water_depth", &eq2_character::get_water_depth)
		.add_property("wisdom", &eq2_character::get_wisdom)
		.def("query_effects", &eq2_character::query_effects, eq2_character::query_effects_overloads(args("effect_list", "query")))
		.def("query_inventory", &eq2_character::query_inventory, eq2_character::query_inventory_overloads(args("item_list", "query")))
		.def("query_recipes", &eq2_character::query_recipes, eq2_character::query_recipes_overloads(args("recipe_list", "query")))
		.def("get_maintained", &eq2_character::get_maintained)
		.def("heading_to", &eq2_character::get_heading_to)
		.def("heading_to", &eq2_character::get_heading_to_ls)
		.def("heading_to_as_compass_bearing", &eq2_character::get_heading_to_as_compass_bearing)
		.def("heading_to_as_compass_bearing", &eq2_character::get_heading_to_as_compass_bearing_ls)
		.def("get_group", &eq2_character::get_group)
		.def("get_group_member", &eq2_character::get_group_member_1)
		.def("get_group_member", &eq2_character::get_group_member_2)
		.def("get_raid", &eq2_character::get_raid)
		.def("get_raid_member", &eq2_character::get_raid_member_1)
		.def("get_raid_member", &eq2_character::get_raid_member_2)
		.def("get_raid_member", &eq2_character::get_raid_member_3)
		.def("face", &eq2_character::face)
		.def("face", &eq2_character::face_ls)
		.def("take_all_vending_coin", &eq2_character::take_all_vending_coin)
		.def("reset_zone_timer", &eq2_character::reset_zone_timer)
		.def("reset_zone_timer", &eq2_character::reset_zone_timer_ls)
		.def("bank_deposit", &eq2_character::bank_deposit, eq2_character::bank_deposit_overloads(args("type", "amount", "from_shared_bank")))
		.def("shared_bank_deposit", &eq2_character::shared_bank_deposit, eq2_character::shared_bank_deposit_overloads(args("type", "amount", "from_bank")))
		.def("bank_withdraw", &eq2_character::bank_withdraw)
		.def("shared_bank_withdraw", &eq2_character::shared_bank_withdraw)
		.def("guild_bank_deposit", &eq2_character::guild_bank_deposit)
		.def("guild_bank_withdraw", &eq2_character::guild_bank_withdraw)
		.def("deposit_into_house_escrow", &eq2_character::deposit_into_house_escrow);

#pragma endregion

#pragma region eq2_dynamic_data

		class_<eq2_dynamic_data, bases<ls_object>>("dynamic_data", init<const LSOBJECT&>())
			.add_property("label", &eq2_dynamic_data::get_label)
			.add_property("percent", &eq2_dynamic_data::get_percent);

#pragma endregion

#pragma region eq2_eq2

	class_<eq2_eq2, bases<ls_object>>("eq2")
		.def("accept_pending_quests", &eq2_eq2::accept_pending_quest)
		.def("check_collision", &eq2_eq2::check_collision)
		.def("check_collision", &eq2_eq2::check_collision_ls)
		.def("confirm_zone_teleporter_destination", &eq2_eq2::confirm_zone_teleporter_destination)
		.def("decline_pending_quest", &eq2_eq2::decline_pending_quest)
		.def("get_persistent_zones", &eq2_eq2::get_persistent_zones)
		.def("heading_to", &eq2_eq2::heading_to)
		.def("heading_to", &eq2_eq2::heading_to_ls)
		.add_property("ho_current_wheel_slot", &eq2_eq2::get_ho_current_wheel_slot)
		.add_property("ho_description", &eq2_eq2::get_ho_description)
		.add_property("ho_icon_id_1", &eq2_eq2::get_ho_icon_id_1)
		.add_property("ho_icon_id_2", &eq2_eq2::get_ho_icon_id_2)
		.add_property("ho_icon_id_3", &eq2_eq2::get_ho_icon_id_3)
		.add_property("ho_icon_id_4", &eq2_eq2::get_ho_icon_id_4)
		.add_property("ho_icon_id_5", &eq2_eq2::get_ho_icon_id_5)
		.add_property("ho_icon_id_6", &eq2_eq2::get_ho_icon_id_6)
		.add_property("ho_last_manipulator", &eq2_eq2::get_ho_last_manipulator)
		.add_property("ho_name", &eq2_eq2::get_ho_name)
		.add_property("ho_time_elapsed", &eq2_eq2::get_ho_time_elapsed)
		.add_property("ho_time_limit", &eq2_eq2::get_ho_time_limit)
		.add_property("ho_time_remaining", &eq2_eq2::get_ho_time_remaining)
		.add_property("ho_wheel_state", &eq2_eq2::get_ho_wheel_state)
		.add_property("ho_wheel_type", &eq2_eq2::get_ho_wheel_type)
		.add_property("ho_window_active", &eq2_eq2::get_ho_window_active)
		.add_property("ho_window_state", &eq2_eq2::get_ho_window_state)
		.add_property("inbox_mail_count", &eq2_eq2::get_inbox_mail_count)
		.add_property("master_volume", &eq2_eq2::get_master_volume, &eq2_eq2::set_master_volume)
		.add_property("num_radars", &eq2_eq2::get_num_radars)
		.add_property("on_battleground", &eq2_eq2::get_on_battleground)
		.add_property("pending_quest_description", &eq2_eq2::get_pending_quest_description)
		.add_property("pending_quest_name", &eq2_eq2::get_pending_quest_name)
		.def("persistent_zone_id", &eq2_eq2::persistent_zone_id)
		.def("persistent_zone_id", &eq2_eq2::persistent_zone_id_ls)
		.add_property("ready_to_refine_transmute_or_salvage", &eq2_eq2::get_ready_to_refine_transmute_or_salvage)
		.add_property("server_name", &eq2_eq2::get_server_name)
		.def("toggle_show_all_on_screen_announcements", &eq2_eq2::toggle_show_all_on_screen_announcements)
		.def("query_actors", &eq2_eq2::query_actors, eq2_eq2::query_actors_overloads(args("actor_list", "query")))
		.add_property("zoning", &eq2_eq2::get_zoning);

#pragma endregion

#pragma region eq2_effect

	class_<eq2_effect, bases<ls_object>>("effect", init<const LSOBJECT&>())
		.add_property("back_drop_icon_id", &eq2_effect::get_back_drop_icon_id)
		.add_property("current_increments", &eq2_effect::get_current_increments)
		.add_property("duration", &eq2_effect::get_duration)
		.add_property("effect_info", &eq2_effect::get_effect_info)
		.add_property("id", &eq2_effect::get_id)
		.add_property("is_effect_info_available", &eq2_effect::get_is_effect_info_available)
		.add_property("main_icon_id", &eq2_effect::get_main_icon_id)
		.add_property("max_duration", &eq2_effect::get_max_duration);

#pragma endregion

#pragma region eq2_effect_info

	class_<eq2_effect_info, bases<ls_object>>("effect_info", init<const LSOBJECT&>())
		.add_property("description", &eq2_effect_info::get_description)
		.add_property("name", &eq2_effect_info::get_name)
		.add_property("type", &eq2_effect_info::get_type);

#pragma endregion

#pragma region eq2_group_member

	class_<eq2_group_member, bases<eq2_actor>>("group_member")
		.add_property("arcane", &eq2_group_member::get_arcane)
		.add_property("current_health", &eq2_group_member::get_current_health)
		.add_property("current_power", &eq2_group_member::get_current_power)
		.add_property("cursed", &eq2_group_member::get_cursed)
		.add_property("elemental", &eq2_group_member::get_elemental)
		.add_property("max_health", &eq2_group_member::get_max_health)
		.add_property("max_power", &eq2_group_member::get_max_power)
		.add_property("noxious", &eq2_group_member::get_noxious)
		.add_property("in_zone", &eq2_group_member::get_in_zone)
		.add_property("is_afflicted", &eq2_group_member::get_is_afflicted)
		.add_property("pet_id", &eq2_group_member::get_pet_id)
		.add_property("raid_group_num", &eq2_group_member::get_raid_group_num)
		.add_property("raid_role", &eq2_group_member::get_raid_role)
		.add_property("trauma", &eq2_group_member::get_trauma)
		.add_property("zone_name", &eq2_group_member::get_zone_name);

#pragma endregion

#pragma region eq2_isxeq2

	class_<eq2_isxeq2, bases<ls_object>>("isxeq2")
		.def("add_loc", &eq2_isxeq2::add_loc, eq2_isxeq2::add_loc_overloads(args("label", "notes")))
		.add_property("affliction_events_on", &eq2_isxeq2::get_affliction_events_on)
		.add_property("api_version", &eq2_isxeq2::get_api_version)
		.def("clear_abilities_cache", &eq2_isxeq2::clear_abilities_cache)
		.def("disable_affliction_events", &eq2_isxeq2::disable_affliction_events)
		.def("disable_custom_zoning_text", &eq2_isxeq2::disable_custom_zoning_text)
		.def("enable_affliction_events", &eq2_isxeq2::enable_affliction_events)
		.def("enable_custom_zoning_text", &eq2_isxeq2::enable_custom_zoning_text)
		.def("eq2locs_count", &eq2_isxeq2::get_eq2locs_count, eq2_isxeq2::get_eq2locs_count_overloads(args("all_zones")))
		.add_property("is_ready", &eq2_isxeq2::get_is_ready)
		.def("is_valid_eq2press_key", &eq2_isxeq2::get_is_valid_eq2press_key, args("key"))
		.def("popup", &eq2_isxeq2::popup, eq2_isxeq2::popup_overloads(args("message", "title", "status")))
		.def("reset_internal_vending_system", &eq2_isxeq2::reset_internal_vending_system)
		.def("set_actor_events_range", &eq2_isxeq2::set_actor_events_range, args("range"))
		.def("set_actor_events_time_interval", &eq2_isxeq2::set_actor_events_time_interval, args("time"))
		.def("set_affliction_events_time_interval", &eq2_isxeq2::set_affliction_events_time_interval, args("time"))
		.add_property("version", &eq2_isxeq2::get_version);

#pragma endregion

#pragma region eq2_item

	class_<eq2_item, bases<ls_object>>("item")
		.add_property("name", &eq2_item::get_name);

#pragma endregion

#pragma region eq2_maintained

	class_<eq2_maintained, bases<ls_object>>("maintained")
		.add_property("concentration_cost", &eq2_maintained::get_concentration_cost)
		.add_property("current_increments", &eq2_maintained::get_current_increments)
		.add_property("damage_remaining", &eq2_maintained::get_damage_remaining)
		.add_property("duration", &eq2_maintained::get_duration)
		.add_property("is_beneficial", &eq2_maintained::get_is_beneficial)
		.add_property("max_duration", &eq2_maintained::get_max_duration)
		.add_property("name", &eq2_maintained::get_name)
		.add_property("target", &eq2_maintained::get_target)
		.add_property("target_type", &eq2_maintained::get_target_type)
		.add_property("uses_remaining", &eq2_maintained::get_uses_remaining);

#pragma endregion

#pragma region eq2_recipe

	class_<eq2_recipe, bases<ls_object>>("recipe")
		.add_property("name", &eq2_recipe::get_name);

#pragma endregion

#pragma region event args

	class_<eq2_actor_despawned_args>("eq2_actor_despawned_args")
		.add_property("id", &eq2_actor_despawned_args::get_id, &eq2_actor_despawned_args::set_id)
		.add_property("name", &eq2_actor_despawned_args::get_name, &eq2_actor_despawned_args::set_name);

	class_<eq2_actor_spawned_args, bases<eq2_actor_despawned_args>>("eq2_actor_spawned_args")
		.add_property("level", &eq2_actor_spawned_args::get_level, &eq2_actor_spawned_args::set_level)
		.add_property("type", &eq2_actor_spawned_args::get_type, &eq2_actor_spawned_args::set_type);

	class_<eq2_on_quest_offered_args>("eq2_on_quest_offered_args")
		.add_property("name", &eq2_on_quest_offered_args::get_name, &eq2_on_quest_offered_args::set_name)
		.add_property("description", &eq2_on_quest_offered_args::get_description, &eq2_on_quest_offered_args::set_description)
		.add_property("level", &eq2_on_quest_offered_args::get_level, &eq2_on_quest_offered_args::set_level)
		.add_property("status_reward", &eq2_on_quest_offered_args::get_status_reward, &eq2_on_quest_offered_args::set_status_reward);

#pragma endregion

}

void initialize_module_isxeq2()
{
	PyImport_AppendInittab("isxeq2", PyInit_isxeq2);
}

void shutdown_module_isxeq2()
{

}
