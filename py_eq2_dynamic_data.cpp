#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_dynamic_data::py_eq2_dynamic_data(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

std::string py_eq2_dynamic_data::get_label()
{
	char* const member = static_cast<char *>("Label");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float py_eq2_dynamic_data::get_percent()
{
	char* const member = static_cast<char *>("Percent");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}