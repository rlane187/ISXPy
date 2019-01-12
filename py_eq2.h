#pragma once

class py_eq2 : public ls_object
{
public:
	py_eq2();
	~py_eq2();
	py_eq2(const py_eq2& other);
	py_eq2(py_eq2&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2(const LSOBJECT& other);
	py_eq2& operator=(const py_eq2& other);
	py_eq2& operator=(py_eq2&& other) noexcept;
	void accept_pending_quest();
	bool check_collision(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z);
	void confirm_zone_teleporter_destination();
	void decline_pending_quest();
	float heading_to(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z);
	int get_ho_current_wheel_slot();
	std::string get_ho_description();
	int get_ho_icon_id_1();
	int get_ho_icon_id_2();
	int get_ho_icon_id_3();
	int get_ho_icon_id_4();
	int get_ho_icon_id_5();
	int get_ho_icon_id_6();
	eq2_actor get_ho_last_manipulator();
	std::string get_ho_name();
	float get_ho_time_elapsed();
	float get_ho_time_limit();
	float get_ho_time_remaining();
	int get_ho_wheel_id();
	int get_ho_wheel_state();
	int get_ho_wheel_type();
	bool get_ho_window_active();	
	int get_ho_window_state();
	int get_inbox_mail_count();
	float get_master_volume();
	int get_num_radars();
	bool get_on_battleground();
	std::string get_pending_quest_description();
	std::string get_pending_quest_name();
	int get_persistent_zones(boost::python::list& zone_list);
	bool get_ready_to_refine_transmute_or_salvage();
	std::string get_server_name();
	int get_zoning();
	unsigned int persistent_zone_id(const std::string& zone_name);
	void set_master_volume(const float& percent);
	void toggle_show_all_on_screen_announcements();
	int query_actors(boost::python::list& actor_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_actors_overloads, query_actors, 1, 2)
	
};