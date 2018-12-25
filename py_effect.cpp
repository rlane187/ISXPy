#include "ISXPyPCH.h"
#include "ISXPy.h"

py_effect::py_effect(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

int py_effect::get_back_drop_icon_id()
{
	char* const member = static_cast<char *>("BackDropIconID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_effect::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_effect::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int py_effect::get_id()
{
	char* const member = static_cast<char *>("ID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

bool py_effect::get_is_effect_info_available()
{
	char* const member = static_cast<char *>("IsEffectInfoAvailable");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

int py_effect::get_main_icon_id()
{
	char* const member = static_cast<char *>("MainIconID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_effect::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

py_effect_info py_effect::get_effect_info()
{
	py_effect_info effect_info;
	char* const member = static_cast<char *>("ToEffectInfo");
	try
	{
		effect_info = py_effect_info(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception &) {}
	return effect_info;
}


std::string py_effect::get_type()
{
	char* const member = static_cast<char *>("Type");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}