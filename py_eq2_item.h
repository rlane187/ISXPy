#pragma once

class py_eq2_item : public py_lsobject
{
public:
	py_eq2_item();
	~py_eq2_item();
	py_eq2_item(const py_eq2_item& other);
	py_eq2_item(py_eq2_item&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_eq2_item(const LSOBJECT& other);
	py_eq2_item& operator=(const py_eq2_item& other);
	py_eq2_item& operator=(py_eq2_item&& other) noexcept;
	std::string get_name();
};