#pragma once

class PyMaintained : public PyLSObject
{
public:
	PyMaintained() = default;
	PyMaintained(const LSOBJECT& ls_object);
	int get_concentration_cost();
	int get_current_increments();
	int get_damage_remaining();
	float get_duration();
	bool get_is_beneficial();
	float get_max_duration();
	std::string get_name();
	PyActor get_target();
	std::string get_target_type();
	int get_uses_remaining();

};
