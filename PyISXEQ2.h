#pragma once

class PyISXEQ2 : public LSObject
{
public:
	PyISXEQ2();
	void disable_affliction_events();
	void disable_custom_zoning_text();
	void enable_affliction_events();
	void enable_custom_zoning_text();
	bool get_affliction_events_on();
	std::string get_api_version();
	std::string get_version();
	bool get_is_ready();
	bool get_is_valid_eq2press_key(std::string key_name);
	void popup(std::string& message, std::string& title = std::string(), std::string& status = std::string());
	void set_actor_events_range(float range);
	void set_actor_events_time_interval(int time);
	void set_affliction_events_time_interval(int interval);
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(isxeq2_popup_overloads, popup, 1, 3)	
};
