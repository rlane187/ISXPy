#pragma once

class ls_point3_f : public ls_object
{
public:
	ls_point3_f();
	~ls_point3_f();
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_point3_f(const ls_object& other);
	ls_point3_f(const ls_point3_f& other);
	ls_point3_f(ls_point3_f&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_point3_f(const LSOBJECT& other);
	ls_point3_f& operator=(const ls_point3_f& other);
	ls_point3_f& operator=(ls_point3_f&& other) noexcept;
	ls_float get_x();
	ls_float get_y();
	ls_float get_z();
	ls_string get_xyz(const std::string& separator = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_xyz_overloads, get_xyz, 0, 1)
};