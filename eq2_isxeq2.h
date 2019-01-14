#pragma once

class eq2_isxeq2 : public ls_object
{
public:
	eq2_isxeq2();
	~eq2_isxeq2();
	eq2_isxeq2(const eq2_isxeq2& other);
	eq2_isxeq2(eq2_isxeq2&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_isxeq2(const LSOBJECT& other);
	eq2_isxeq2& operator=(const eq2_isxeq2& other);
	eq2_isxeq2& operator=(eq2_isxeq2&& other) noexcept;
	void add_loc(const std::string& label, const std::string& notes = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(add_loc_overloads, add_loc, 1, 2)
	void clear_abilities_cache();
	void disable_affliction_events();
	void disable_custom_zoning_text();
	void enable_affliction_events();
	void enable_custom_zoning_text();
	ls_bool get_affliction_events_on();
	ls_string get_api_version();
	ls_int get_eq2locs_count(const bool& all_zones = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_eq2locs_count_overloads, get_eq2locs_count, 0, 1)
	ls_string get_version();
	ls_bool get_is_ready();
	ls_bool get_is_valid_eq2press_key(const std::string& key_name);
	void popup(const std::string& message, const ::string& title = std::string(), const std::string& status = std::string());
	void reset_internal_vending_system();
	void set_actor_events_range(const float& range);
	void set_actor_events_time_interval(const int& time);
	void set_affliction_events_time_interval(const int& interval);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(popup_overloads, popup, 1, 3)	
};
