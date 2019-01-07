#pragma once

class py_point3_f : public py_lsobject
{
public:
	py_point3_f();
	~py_point3_f();
	py_point3_f(const py_point3_f& other);
	py_point3_f(py_point3_f&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_point3_f(const LSOBJECT& other);
	py_point3_f& operator=(const py_point3_f& other);
	py_point3_f& operator=(py_point3_f&& other);
	float get_x();
	float get_y();
	float get_z();
	std::string get_xyz(const std::string& separator = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_xyz_overloads, get_xyz, 0, 1)
};