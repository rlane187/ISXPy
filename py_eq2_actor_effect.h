#pragma once

class py_eq2_actor_effect : public py_lsobject
{
public:
	py_eq2_actor_effect();
	~py_eq2_actor_effect();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_actor_effect(const LSOBJECT& other);
	py_eq2_actor_effect(const py_eq2_actor_effect& other);
	py_eq2_actor_effect(py_eq2_actor_effect&& other) noexcept;
	py_eq2_actor_effect& operator=(const py_eq2_actor_effect& other);
	py_eq2_actor_effect& operator=(py_eq2_actor_effect&& other) noexcept;
	int get_back_drop_icon_id();
	int get_current_increments();
	int get_id();
	bool get_is_effect_info_available();
	int get_main_icon_id();
	py_eq2_effect_info get_effect_info();
};