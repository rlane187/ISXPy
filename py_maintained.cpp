#include "ISXPyPCH.h"
#include "ISXPy.h"

py_maintained::py_maintained(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

int py_maintained::get_concentration_cost()
{
	char* const member = static_cast<char *>("ConcentrationCost");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_maintained::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_maintained::get_damage_remaining()
{
	char* const member = static_cast<char *>("DamageRemaining");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_maintained::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}


bool py_maintained::get_is_beneficial()
{
	char* const member = static_cast<char *>("IsBeneficial");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

float py_maintained::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string py_maintained::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

py_actor py_maintained::get_target()
{
	py_actor actor;
	char* const member = static_cast<char *>("Target");
	try
	{
		actor = this->get_member(member, 0, nullptr).get_lso();
	}
	catch (exception &) {}
	return actor;
}

std::string py_maintained::get_target_type()
{
	char* const member = static_cast<char *>("TargetType");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_maintained::get_uses_remaining()
{
	char* const member = static_cast<char *>("UsesRemaining");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}