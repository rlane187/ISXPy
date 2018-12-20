#include "ISXPyPCH.h"
#include "ISXPy.h"

PyEQ2DynamicData::PyEQ2DynamicData(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

std::string PyEQ2DynamicData::get_label()
{
	char* const member = static_cast<char *>("Label");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float PyEQ2DynamicData::get_percent()
{
	char* const member = static_cast<char *>("Percent");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}