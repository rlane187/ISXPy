#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_maintained::eq2_maintained() = default;

eq2_maintained::~eq2_maintained() = default;

eq2_maintained::eq2_maintained(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_maintained::eq2_maintained(const eq2_maintained& other) = default;

eq2_maintained::eq2_maintained(eq2_maintained&& other) noexcept = default;

eq2_maintained::eq2_maintained(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_maintained& eq2_maintained::operator=(const eq2_maintained& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_maintained& eq2_maintained::operator=(eq2_maintained&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int eq2_maintained::get_concentration_cost()
{
	char* const member = static_cast<char *>("ConcentrationCost");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_maintained::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_maintained::get_damage_remaining()
{
	char* const member = static_cast<char *>("DamageRemaining");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float eq2_maintained::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

bool eq2_maintained::get_is_beneficial()
{
	char* const member = static_cast<char *>("IsBeneficial");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

float eq2_maintained::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string eq2_maintained::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

eq2_actor eq2_maintained::get_target()
{
	char* const member = static_cast<char *>("Target");
	const LSOBJECT target_object = this->get_member(member, 0, nullptr).get_lso();
	return target_object;
}

std::string eq2_maintained::get_target_type()
{
	char* const member = static_cast<char *>("TargetType");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int eq2_maintained::get_uses_remaining()
{
	char* const member = static_cast<char *>("UsesRemaining");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}