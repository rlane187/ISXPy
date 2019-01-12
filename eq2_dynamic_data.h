#pragma once

class eq2_dynamic_data : public ls_object
{
public:
	eq2_dynamic_data();
	~eq2_dynamic_data();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_dynamic_data(const ls_object& other);
	eq2_dynamic_data(const eq2_dynamic_data& other);
	eq2_dynamic_data(eq2_dynamic_data&& other) noexcept;
	eq2_dynamic_data& operator=(const eq2_dynamic_data& other);
	eq2_dynamic_data& operator=(eq2_dynamic_data&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	eq2_dynamic_data(const LSOBJECT& ls_object);
	std::string get_label();
	float get_percent();
};