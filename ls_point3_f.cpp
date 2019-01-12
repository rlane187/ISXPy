#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_point3_f::ls_point3_f() = default;

ls_point3_f::~ls_point3_f() = default;

ls_point3_f::ls_point3_f(const ls_point3_f& other) = default;

ls_point3_f::ls_point3_f(ls_point3_f&& other) noexcept = default;

ls_point3_f::ls_point3_f(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

ls_point3_f& ls_point3_f::operator=(const ls_point3_f& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_point3_f& ls_point3_f::operator=(ls_point3_f&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_point3_f::ls_point3_f(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_float ls_point3_f::get_x()
{
	return this->get_member("X");
}

ls_float ls_point3_f::get_y()
{
	return this->get_member("Y");
}

ls_float ls_point3_f::get_z()
{
	return this->get_member("Z");
}

ls_string ls_point3_f::get_xyz(const std::string& separator)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(separator.c_str());
	const char* member = "XYZ";
	if (separator.empty())
		return this->get_member(member);
	return this->get_member(member, argc, argv);
}