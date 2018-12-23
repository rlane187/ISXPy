#pragma once

class PyActor : public PyLSObject
{
public:
	PyActor() = default;
	PyActor(const LSOBJECT& ls_object);
	std::string get_aura();
	bool check_collision(const float& to_x = NULL, const float& to_y = NULL, const float& to_z = NULL);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(check_collision_overloads, check_collision, 0, 3)
	std::string get_class();
	float get_collision_radius();
	float get_collision_scale();
	std::string get_con_color(const bool& as_rgb = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_con_color_overloads, get_con_color, 0, 1);
	std::string get_current_animation();
	float get_distance();
	float get_distance2d();
	int get_effective_level();
	int get_faction();
	std::string get_faction_standing();
	bool get_flying_using_mount();
	std::string get_gender();
	std::string get_guild();
	float get_heading();
	float get_heading_to();
	std::string get_heading_to_as_compass_bearing();
	int get_health();
	unsigned int get_id();
	bool get_in_my_group();
	bool get_interactable();
	std::string get_last_name();
	int get_level();
	PyPoint3f get_loc();
	std::string get_mood();
	std::string get_name();
	bool get_on_flying_mount();
	std::string get_overlay();
	PyActor get_pet();
	int get_power();
	std::string get_race();
	float get_speed();
	std::string get_suffix_title();
	float get_swimming_speed_mod();
	PyActor get_target();
	float get_target_ring_radius();
	int get_threat_to_me();
	int get_threat_to_pet();
	int get_threat_to_next();
	unsigned int get_tint_flags();
	std::string get_type();
	PyPoint3f get_velocity();
	std::string get_visual_variant();
	std::string get_who_following();
	int get_who_following_id();
	float get_x();
	float get_y();
	float get_z();
};