#include "ISXPyPCH.h"
#include "ISXPy.h"

py_maintained::py_maintained(const LSOBJECT& ls_object)
{
	this->lsobject_ = ls_object;
}

int py_maintained::get_concentration_cost()
{
	char* const member = static_cast<char *>("ConcentrationCost");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_maintained::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_maintained::get_damage_remaining()
{
	char* const member = static_cast<char *>("DamageRemaining");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_maintained::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

bool py_maintained::get_is_beneficial()
{
	char* const member = static_cast<char *>("IsBeneficial");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

float py_maintained::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_maintained::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

py_eq2_actor py_maintained::get_target()
{
	char* const member = static_cast<char *>("Target");
	const LSOBJECT target_object = this->get_member(member, 0, nullptr).get_lso();
	return target_object;
}

std::string py_maintained::get_target_type()
{
	char* const member = static_cast<char *>("TargetType");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_maintained::get_uses_remaining()
{
	char* const member = static_cast<char *>("UsesRemaining");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}