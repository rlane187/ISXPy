#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_effect::eq2_effect() = default;

eq2_effect::~eq2_effect() = default;

eq2_effect::eq2_effect(const eq2_effect& other) = default;

eq2_effect::eq2_effect(eq2_effect&& other) noexcept = default;

eq2_effect& eq2_effect::operator=(const eq2_effect& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_effect& eq2_effect::operator=(eq2_effect&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_effect::eq2_effect(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_int eq2_effect::get_back_drop_icon_id()
{
	return this->get_member("BackDropIconID");
}

ls_int eq2_effect::get_current_increments()
{
	return this->get_member("CurrentIncrements");
}

ls_float eq2_effect::get_duration()
{
	return this->get_member("Duration");
}

ls_int eq2_effect::get_id()
{
	return this->get_member("ID");
}

ls_bool eq2_effect::get_is_effect_info_available()
{
	return this->get_member("IsEffectInfoAvailable");
}

ls_int eq2_effect::get_main_icon_id()
{
	return this->get_member("MainIconID");
}

ls_float eq2_effect::get_max_duration()
{
	return this->get_member("MaxDuration");
}

eq2_effect_info eq2_effect::get_effect_info()
{
	return this->get_member("ToEffectInfo");
}

ls_string eq2_effect::get_type()
{
	return this->get_member("Type");
}