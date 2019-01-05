#pragma once

class py_eq2_dynamic_data : public py_lsobject
{
public:
	py_eq2_dynamic_data();
	~py_eq2_dynamic_data();
	py_eq2_dynamic_data(const py_eq2_dynamic_data& other);
	py_eq2_dynamic_data(py_eq2_dynamic_data&& other) noexcept;
	py_eq2_dynamic_data& operator=(const py_eq2_dynamic_data& other);
	py_eq2_dynamic_data& operator=(py_eq2_dynamic_data&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_dynamic_data(const LSOBJECT& ls_object);
	std::string get_label();
	float get_percent();
};