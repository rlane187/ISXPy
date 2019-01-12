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

int eq2_effect::get_back_drop_icon_id()
{
	char* const member = static_cast<char *>("BackDropIconID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_effect::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float eq2_effect::get_duration()
{
	char* const member = static_cast<char *>("Duration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int eq2_effect::get_id()
{
	char* const member = static_cast<char *>("ID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool eq2_effect::get_is_effect_info_available()
{
	char* const member = static_cast<char *>("IsEffectInfoAvailable");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int eq2_effect::get_main_icon_id()
{
	char* const member = static_cast<char *>("MainIconID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float eq2_effect::get_max_duration()
{
	char* const member = static_cast<char *>("MaxDuration");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

eq2_effect_info eq2_effect::get_effect_info()
{
	char* const member = static_cast<char *>("ToEffectInfo");
	eq2_effect_info effect_info = eq2_effect_info(this->get_member(member, 0, nullptr).get_lso());
	return effect_info;
}

std::string eq2_effect::get_type()
{
	char* const member = static_cast<char *>("Type");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}