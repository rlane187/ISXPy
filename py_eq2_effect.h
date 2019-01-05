#pragma once

class py_eq2_effect : public py_lsobject
{
public:
	py_eq2_effect();
	~py_eq2_effect();
	py_eq2_effect(const py_eq2_effect& other);
	py_eq2_effect(py_eq2_effect&& other) noexcept;
	py_eq2_effect& operator=(const py_eq2_effect& other);
	py_eq2_effect& operator=(py_eq2_effect&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_effect(const LSOBJECT& ls_object);	
	int get_back_drop_icon_id();
	int get_current_increments();
	float get_duration();
	py_eq2_effect_info get_effect_info();
	int get_id();
	bool get_is_effect_info_available();
	int get_main_icon_id();
	float get_max_duration();	
	std::string get_type();
};