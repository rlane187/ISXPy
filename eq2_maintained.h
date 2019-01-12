#pragma once

class eq2_maintained : public ls_object
{
public:
	eq2_maintained();
	~eq2_maintained();
	eq2_maintained(const ls_object& other);
	eq2_maintained(const eq2_maintained& other);
	eq2_maintained(eq2_maintained&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_maintained(const LSOBJECT& other);
	eq2_maintained& operator=(const eq2_maintained& other);
	eq2_maintained& operator=(eq2_maintained&& other) noexcept;
	int get_concentration_cost();
	int get_current_increments();
	int get_damage_remaining();
	float get_duration();
	bool get_is_beneficial();
	float get_max_duration();
	std::string get_name();
	eq2_actor get_target();
	std::string get_target_type();
	int get_uses_remaining();

};
