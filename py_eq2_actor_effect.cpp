#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_actor_effect::py_eq2_actor_effect() = default;

py_eq2_actor_effect::~py_eq2_actor_effect() = default;

py_eq2_actor_effect::py_eq2_actor_effect(const py_eq2_actor_effect& other) = default;

py_eq2_actor_effect::py_eq2_actor_effect(py_eq2_actor_effect&& other) noexcept = default;

py_eq2_actor_effect::py_eq2_actor_effect(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_eq2_actor_effect& py_eq2_actor_effect::operator=(const py_eq2_actor_effect& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2_actor_effect& py_eq2_actor_effect::operator=(py_eq2_actor_effect&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int py_eq2_actor_effect::get_back_drop_icon_id()
{
	char* const member = static_cast<char *>("BackDropIconID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor_effect::get_current_increments()
{
	char* const member = static_cast<char *>("CurrentIncrements");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor_effect::get_id()
{
	char* const member = static_cast<char *>("ID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_eq2_actor_effect::get_is_effect_info_available()
{
	char* const member = static_cast<char *>("IsEffectInfoAvailable");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int py_eq2_actor_effect::get_main_icon_id()
{
	char* const member = static_cast<char *>("MainIconID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

py_eq2_effect_info py_eq2_actor_effect::get_effect_info()
{
	char* const member = static_cast<char *>("ToEffectInfo");
	py_eq2_effect_info effect_info = this->get_member(member, 0, nullptr).get_lso();
	return effect_info;
}