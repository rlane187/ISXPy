#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_effect_info::py_eq2_effect_info() = default;

py_eq2_effect_info::~py_eq2_effect_info() = default;

py_eq2_effect_info::py_eq2_effect_info(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_eq2_effect_info::py_eq2_effect_info(const py_eq2_effect_info& other) = default;

py_eq2_effect_info::py_eq2_effect_info(py_eq2_effect_info&& other) noexcept = default;

py_eq2_effect_info& py_eq2_effect_info::operator=(const py_eq2_effect_info& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2_effect_info& py_eq2_effect_info::operator=(py_eq2_effect_info&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

std::string py_eq2_effect_info::get_description()
{
	char* const member = static_cast<char *>("Description");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_effect_info::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_effect_info::get_type()
{
	char* const member = static_cast<char *>("type");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}