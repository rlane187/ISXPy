#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_item::py_eq2_item() = default;

py_eq2_item::~py_eq2_item() = default;

py_eq2_item::py_eq2_item(const py_eq2_item& other) = default;

py_eq2_item::py_eq2_item(py_eq2_item&& other) noexcept = default;

py_eq2_item::py_eq2_item(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_eq2_item& py_eq2_item::operator=(const py_eq2_item& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2_item& py_eq2_item::operator=(py_eq2_item&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

std::string py_eq2_item::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}
