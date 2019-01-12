#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_dynamic_data::eq2_dynamic_data() = default;

eq2_dynamic_data::eq2_dynamic_data(const eq2_dynamic_data& other) = default;

eq2_dynamic_data::eq2_dynamic_data(eq2_dynamic_data&& other) noexcept = default;

eq2_dynamic_data::~eq2_dynamic_data() = default;

eq2_dynamic_data::eq2_dynamic_data(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_dynamic_data& eq2_dynamic_data::operator=(const eq2_dynamic_data& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_dynamic_data& eq2_dynamic_data::operator=(eq2_dynamic_data&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_dynamic_data::eq2_dynamic_data(const LSOBJECT& ls_object)
{
	this->lsobject_ = ls_object;
}

std::string eq2_dynamic_data::get_label()
{
	char* const member = static_cast<char *>("Label");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float eq2_dynamic_data::get_percent()
{
	char* const member = static_cast<char *>("Percent");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}