#pragma once

class py_maintained : public py_lsobject
{
public:
	py_maintained() = default;
	py_maintained(const LSOBJECT& ls_object);
	int get_concentration_cost();
	int get_current_increments();
	int get_damage_remaining();
	float get_duration();
	bool get_is_beneficial();
	float get_max_duration();
	std::string get_name();
	py_eq2_actor get_target();
	std::string get_target_type();
	int get_uses_remaining();

};
