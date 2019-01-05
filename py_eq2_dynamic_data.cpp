#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_dynamic_data::py_eq2_dynamic_data(const LSOBJECT& ls_object)
{
	this->lsobject_ = ls_object;
}

std::string py_eq2_dynamic_data::get_label()
{
	char* const member = static_cast<char *>("Label");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_eq2_dynamic_data::get_percent()
{
	char* const member = static_cast<char *>("Percent");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}