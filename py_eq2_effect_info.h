#pragma once

class py_eq2_effect_info : public ls_object
{
public:
	py_eq2_effect_info();
	~py_eq2_effect_info();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_effect_info(const LSOBJECT& other);
	py_eq2_effect_info(const py_eq2_effect_info& other);
	py_eq2_effect_info(py_eq2_effect_info&& other) noexcept;
	py_eq2_effect_info& operator=(const py_eq2_effect_info& other);
	py_eq2_effect_info& operator=(py_eq2_effect_info&& other) noexcept;
	std::string get_description();
	std::string get_name();
	std::string get_type();
};