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

std::string eq2_effect_info::get_description()
{
	char* const member = static_cast<char *>("Description");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string eq2_effect_info::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string eq2_effect_info::get_type()
{
	char* const member = static_cast<char *>("type");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}