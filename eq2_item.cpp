#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_item::eq2_item() = default;

eq2_item::~eq2_item() = default;

eq2_item::eq2_item(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_item::eq2_item(const eq2_item& other) = default;

eq2_item::eq2_item(eq2_item&& other) noexcept = default;

eq2_item::eq2_item(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_item& eq2_item::operator=(const eq2_item& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_item& eq2_item::operator=(eq2_item&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_string eq2_item::get_name()
{
	return this->get_member("Name");
}
