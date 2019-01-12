#pragma once

class py_eq2_maintained : public ls_object
{
public:
	py_eq2_maintained();
	~py_eq2_maintained();
	py_eq2_maintained(const py_eq2_maintained& other);
	py_eq2_maintained(py_eq2_maintained&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_maintained(const LSOBJECT& other);
	py_eq2_maintained& operator=(const py_eq2_maintained& other);
	py_eq2_maintained& operator=(py_eq2_maintained&& other) noexcept;
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
