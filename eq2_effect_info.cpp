#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_effect_info::eq2_effect_info() = default;

eq2_effect_info::~eq2_effect_info() = default;

eq2_effect_info::eq2_effect_info(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_effect_info::eq2_effect_info(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_effect_info::eq2_effect_info(const eq2_effect_info& other) = default;

eq2_effect_info::eq2_effect_info(eq2_effect_info&& other) noexcept = default;

eq2_effect_info& eq2_effect_info::operator=(const eq2_effect_info& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_effect_info& eq2_effect_info::operator=(eq2_effect_info&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_string eq2_effect_info::get_description()
{
	return this->get_member("Description");
}

ls_string eq2_effect_info::get_name()
{
	return this->get_member("Name");
}

ls_string eq2_effect_info::get_type()
{
	return this->get_member("Type");
}