#pragma once

class eq2_maintained : public ls_object
{
public:
	eq2_maintained();
	~eq2_maintained();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_maintained(const ls_object& other);
	eq2_maintained(const eq2_maintained& other);
	eq2_maintained(eq2_maintained&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_maintained(const LSOBJECT& other);
	eq2_maintained& operator=(const eq2_maintained& other);
	eq2_maintained& operator=(eq2_maintained&& other) noexcept;
	ls_int get_concentration_cost();
	ls_int get_current_increments();
	ls_int get_damage_remaining();
	ls_float get_duration();
	ls_bool get_is_beneficial();
	ls_float get_max_duration();
	ls_string get_name();
	eq2_actor get_target();
	ls_string get_target_type();
	ls_int get_uses_remaining();

};
