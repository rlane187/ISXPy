#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_recipe::eq2_recipe(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_recipe& eq2_recipe::operator=(const ls_object& other)
{
	if (this != &other)
		this->lsobject_ = other.get_lso();
	return *this;
}

eq2_recipe& eq2_recipe::operator=(ls_object&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.get_lso();
	return *this;
}

ls_string eq2_recipe::get_name()
{
	return this->get_member("Name");
}