#pragma once

class py_isxeq2 : public ls_object
{
public:
	py_isxeq2();
	~py_isxeq2();
	py_isxeq2(const py_isxeq2& other);
	py_isxeq2(py_isxeq2&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_isxeq2(const LSOBJECT& other);
	py_isxeq2& operator=(const py_isxeq2& other);
	py_isxeq2& operator=(py_isxeq2&& other) noexcept;
	void add_loc(const std::string& label, const std::string& notes = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(add_loc_overloads, add_loc, 1, 2)
	void clear_abilities_cache();
	void disable_affliction_events();
	void disable_custom_zoning_text();
	void enable_affliction_events();
	void enable_custom_zoning_text();
	bool get_affliction_events_on();
	std::string get_api_version();
	int get_eq2locs_count(const bool& all_zones = false);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_eq2locs_count_overloads, get_eq2locs_count, 0, 1)
	std::string get_version();
	bool get_is_ready();
	bool get_is_valid_eq2press_key(const std::string& key_name);
	void popup(const std::string& message, const ::string& title = std::string(), const std::string& status = std::string());
	void reset_internal_vending_system();
	void set_actor_events_range(const float& range);
	void set_actor_events_time_interval(const int& time);
	void set_affliction_events_time_interval(const int& interval);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(popup_overloads, popup, 1, 3)	
};
