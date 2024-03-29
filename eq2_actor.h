#pragma once

class eq2_actor : public ls_object
{
public:
	eq2_actor();
	~eq2_actor();
	explicit eq2_actor(const unsigned int& actor_id);
	explicit eq2_actor(const ls_int& actor_id);
	explicit eq2_actor(const std::string& query);
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_actor(const ls_object& other);
	eq2_actor(const eq2_actor& other);
	eq2_actor(eq2_actor&& other) noexcept;	
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_actor(const LSOBJECT& other);
	eq2_actor& operator=(const eq2_actor& other);
	eq2_actor& operator=(eq2_actor&& other) noexcept;

	virtual ls_bool check_collision(const float& to_x = NULL, const float& to_y = NULL, const float& to_z = NULL);
	virtual ls_bool check_collision_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(check_collision_overloads, check_collision, 0, 3)
	ls_string get_aura();	
	ls_bool get_can_turn();
	ls_string get_class();
	ls_float get_collision_radius();
	ls_float get_collision_scale();
	ls_string get_con_color(const bool& as_rgb = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_con_color_overloads, get_con_color, 0, 1);
	ls_string get_current_animation();
	ls_int get_difficulty();
	ls_float get_distance();
	ls_float get_distance2d();
	int get_effects(boost::python::list& effect_list);
	ls_int get_effective_level();
	ls_int get_encounter_size();
	ls_int get_faction();
	ls_string get_faction_standing();
	ls_bool get_flying_using_mount();
	ls_string get_gender();
	ls_string get_guild();
	ls_float get_heading();
	ls_float get_heading_to();
	ls_string get_heading_to_as_compass_bearing();
	ls_int get_health();
	ls_int get_id();
	ls_bool get_in_combat_mode();
	ls_bool get_in_my_group();
	ls_bool get_interactable();
	ls_bool get_is_aggro();
	ls_bool get_is_afk();
	ls_bool get_is_a_pet();
	ls_bool get_is_backing_up();
	ls_bool get_is_banker();
	ls_bool get_is_camping();
	ls_bool get_is_chest();
	ls_bool get_is_climbing();
	ls_bool get_is_crouching();
	ls_bool get_is_dead();
	ls_bool get_is_epic();
	ls_bool get_is_encounter_broken();
	ls_bool get_is_falling();
	ls_bool get_is_fd();
	ls_bool get_is_heroic();
	ls_bool get_is_idle();
	ls_bool get_is_in_same_encounter(const unsigned int& actor_id);
	ls_bool get_is_in_same_encounter_ls(const ls_int& actor_id);
	ls_bool get_is_invis();
	ls_bool get_is_jumping();
	ls_bool get_is_lfg();
	ls_bool get_is_lfw();
	ls_bool get_is_linkdead();
	ls_bool get_is_locked();
	ls_bool get_is_merchant();
	ls_bool get_is_my_pet();
	ls_bool get_is_named();
	ls_bool get_is_on_carpet();
	ls_bool get_is_on_griffin();
	ls_bool get_is_on_horse();
	ls_bool get_is_rooted();
	ls_bool get_is_running();
	ls_bool get_is_sitting();
	ls_bool get_is_solo();
	ls_bool get_is_sprinting();
	ls_bool get_is_strafing_left();
	ls_bool get_is_strafing_right();
	ls_bool get_is_swimming();
	ls_bool get_is_walking();
	ls_string get_last_name();
	ls_int get_level();
	ls_point3_f get_loc();
	ls_string get_mood();
	ls_string get_name();
	ls_int get_num_effects();
	ls_bool get_on_flying_mount();
	ls_string get_overlay();
	eq2_actor get_pet();
	ls_int get_power();
	ls_string get_race();
	ls_int get_raid_size();
	ls_float get_speed();
	ls_string get_suffix_title();
	ls_float get_swimming_speed_mod();
	ls_string get_tag_target_icon();
	ls_string get_tag_target_number();
	eq2_actor get_target();
	ls_float get_target_ring_radius();
	ls_int get_threat_to_me();
	ls_int get_threat_to_pet();
	ls_int get_threat_to_next();
	ls_int get_tint_flags();
	ls_string get_type();
	ls_point3_f get_velocity();
	ls_string get_visual_variant();
	ls_string get_who_following();
	ls_int get_who_following_id();
	ls_float get_x();
	ls_float get_y();
	ls_float get_z();
	
	void double_click();
	void waypoint_to();
	void do_face();
	void do_target();
	void location(const bool& add_location = true, const std::string& notes = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(location_overloads, location, 0, 2)
	void request_effects_info();
};