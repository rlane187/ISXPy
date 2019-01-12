#pragma once

class eq2_effect : public ls_object
{
public:
	eq2_effect();
	~eq2_effect();
	eq2_effect(const eq2_effect& other);
	eq2_effect(eq2_effect&& other) noexcept;
	eq2_effect& operator=(const eq2_effect& other);
	eq2_effect& operator=(eq2_effect&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_effect(const LSOBJECT& ls_object);

	int get_back_drop_icon_id();
	int get_current_increments();
	float get_duration();
	eq2_effect_info get_effect_info();
	int get_id();
	bool get_is_effect_info_available();
	int get_main_icon_id();
	float get_max_duration();	
	std::string get_type();
};