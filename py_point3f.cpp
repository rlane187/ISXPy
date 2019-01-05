#include "ISXPyPCH.h"
#include "ISXPy.h"

py_point3f::py_point3f(const LSOBJECT& ls_object)
{
	this->lsobject_ = ls_object;
}

float py_point3f::get_x()
{

	char* const member = static_cast<char *>("X");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_point3f::get_y()
{
	char* const member = static_cast<char *>("Y");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_point3f::get_z()
{
	char* const member = static_cast<char *>("Z");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string py_point3f::get_xyz(const std::string& separator)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(separator.c_str());
	char* const member = static_cast<char *>("XYZ");
	try
	{
		if(separator.empty())
			return this->get_member(member, 0, nullptr).get_string_from_lso();
		return this->get_member(member, argc, argv).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}