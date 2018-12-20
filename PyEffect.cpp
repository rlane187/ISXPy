#include "ISXPyPCH.h"
#include "ISXPy.h"

PyEffect::PyEffect(LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

int PyEffect::get_back_drop_icon_id()
{
	char* const member = static_cast<char *>("BackDropIconID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyEffect::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyEffect::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int PyEffect::get_id()
{
	char* const member = static_cast<char *>("ID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

bool PyEffect::get_is_effect_info_available()
{
	char* const member = static_cast<char *>("IsEffectInfoAvailable");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

int PyEffect::get_main_icon_id()
{
	char* const member = static_cast<char *>("MainIconID");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyEffect::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

PyEffectInfo PyEffect::get_effect_info()
{
	PyEffectInfo effect_info;
	char* const member = static_cast<char *>("ToEffectInfo");
	try
	{
		effect_info = PyEffectInfo(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception &) {}
	return effect_info;
}


std::string PyEffect::get_type()
{
	char* const member = static_cast<char *>("Type");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}