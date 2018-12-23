#pragma once

class PyPoint3f : public PyLSObject
{
public:
	PyPoint3f() = default;
	PyPoint3f(const LSOBJECT& ls_object);
	float get_x();
	float get_y();
	float get_z();
	std::string get_xyz(const std::string& separator = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_xyz_overloads, get_xyz, 0, 1)
};