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

ls_int eq2_maintained::get_concentration_cost()
{
	return this->get_member("ConcentrationCost");
}

ls_int eq2_maintained::get_current_increments()
{
	return this->get_member("CurrentIncrements");
}

ls_int eq2_maintained::get_damage_remaining()
{
	return this->get_member("DamageRemaining");
}

ls_float eq2_maintained::get_duration()
{
	return this->get_member("Duration");
}

ls_bool eq2_maintained::get_is_beneficial()
{
	return this->get_member("IsBeneficial");
}

ls_float eq2_maintained::get_max_duration()
{
	return this->get_member("MaxDuration");
}

ls_string eq2_maintained::get_name()
{
	return this->get_member("Name");
}

eq2_actor eq2_maintained::get_target()
{
	return this->get_member("Target");
}

ls_string eq2_maintained::get_target_type()
{
	return this->get_member("TargetType");
}

ls_int eq2_maintained::get_uses_remaining()
{
	return this->get_member("UsesRemaining");
}