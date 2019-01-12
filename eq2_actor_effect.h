#pragma once

class eq2_actor_effect : public ls_object
{
public:
	eq2_actor_effect();
	~eq2_actor_effect();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_actor_effect(const LSOBJECT& other);
	eq2_actor_effect(const eq2_actor_effect& other);
	eq2_actor_effect(eq2_actor_effect&& other) noexcept;
	eq2_actor_effect& operator=(const eq2_actor_effect& other);
	eq2_actor_effect& operator=(eq2_actor_effect&& other) noexcept;

	ls_int get_back_drop_icon_id();
	ls_int get_current_increments();
	ls_int get_id();
	ls_bool get_is_effect_info_available();
	ls_int get_main_icon_id();
	eq2_effect_info get_effect_info();
};