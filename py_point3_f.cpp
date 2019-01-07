#include "ISXPyPCH.h"
#include "ISXPy.h"

py_point3_f::py_point3_f() = default;

py_point3_f::~py_point3_f() = default;

py_point3_f::py_point3_f(const py_point3_f& other) = default;

py_point3_f::py_point3_f(py_point3_f&& other) noexcept = default;

py_point3_f& py_point3_f::operator=(const py_point3_f& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_point3_f& py_point3_f::operator=(py_point3_f&& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_point3_f::py_point3_f(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

float py_point3_f::get_x()
{
	char* const member = static_cast<char *>("X");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_point3_f::get_y()
{
	char* const member = static_cast<char *>("Y");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_point3_f::get_z()
{
	char* const member = static_cast<char *>("Z");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_point3_f::get_xyz(const std::string& separator)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(separator.c_str());
	char* const member = static_cast<char *>("XYZ");
	if (separator.empty())
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	return this->get_member(member, argc, argv).get_string_from_lso();
}