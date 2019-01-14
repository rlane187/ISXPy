#pragma once

class eq2_effect_info : public ls_object
{
public:
	eq2_effect_info();
	~eq2_effect_info();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_effect_info(const ls_object& other);
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_effect_info(const LSOBJECT& other);
	eq2_effect_info(const eq2_effect_info& other);
	eq2_effect_info(eq2_effect_info&& other) noexcept;
	eq2_effect_info& operator=(const eq2_effect_info& other);
	eq2_effect_info& operator=(eq2_effect_info&& other) noexcept;
	ls_string get_description();
	ls_string get_name();
	ls_string get_type();
};