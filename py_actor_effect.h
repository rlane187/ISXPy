#pragma once

class py_actor_effect : public py_lsobject
{
public:
	py_actor_effect() = default;
	py_actor_effect(const LSOBJECT& ls_object);
	int get_back_drop_icon_id();
	int get_current_increments();
	int get_id();
	bool get_is_effect_info_available();
	int get_main_icon_id();
	py_effect_info get_effect_info();
};