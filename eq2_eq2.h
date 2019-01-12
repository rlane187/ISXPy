#pragma once

class eq2_eq2 : public ls_object
{
public:
	eq2_eq2();
	~eq2_eq2();
	eq2_eq2(const eq2_eq2& other);
	eq2_eq2(eq2_eq2&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_eq2(const LSOBJECT& other);
	eq2_eq2& operator=(const eq2_eq2& other);
	eq2_eq2& operator=(eq2_eq2&& other) noexcept;
	void accept_pending_quest();
	ls_bool check_collision(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z);
	ls_bool check_collision_ls(const ls_float& from_x, const ls_float& from_y, const ls_float& from_z, const ls_float& to_x, const ls_float& to_y, const ls_float& to_z);
	void confirm_zone_teleporter_destination();
	void decline_pending_quest();
	ls_float heading_to(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z);
	ls_float heading_to_ls(const ls_float& from_x, const ls_float& from_y, const ls_float& from_z, const ls_float& to_x, const ls_float& to_y, const ls_float& to_z);
	ls_int get_ho_current_wheel_slot();
	ls_string get_ho_description();
	ls_int get_ho_icon_id_1();
	ls_int get_ho_icon_id_2();
	ls_int get_ho_icon_id_3();
	ls_int get_ho_icon_id_4();
	ls_int get_ho_icon_id_5();
	ls_int get_ho_icon_id_6();
	eq2_actor get_ho_last_manipulator();
	ls_string get_ho_name();
	ls_float get_ho_time_elapsed();
	ls_float get_ho_time_limit();
	ls_float get_ho_time_remaining();
	ls_int get_ho_wheel_id();
	ls_int get_ho_wheel_state();
	ls_int get_ho_wheel_type();
	ls_bool get_ho_window_active();	
	ls_int get_ho_window_state();
	ls_int get_inbox_mail_count();
	ls_float get_master_volume();
	ls_int get_num_radars();
	ls_bool get_on_battleground();
	ls_string get_pending_quest_description();
	ls_string get_pending_quest_name();
	int get_persistent_zones(boost::python::list& zone_list);
	ls_bool get_ready_to_refine_transmute_or_salvage();
	ls_string get_server_name();
	ls_int get_zoning();
	ls_int persistent_zone_id(const std::string& zone_name);
	ls_int persistent_zone_id_ls(const ls_string& zone_name);
	void set_master_volume(const float& percent);
	void toggle_show_all_on_screen_announcements();
	int query_actors(boost::python::list& actor_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_actors_overloads, query_actors, 1, 2)
	
};