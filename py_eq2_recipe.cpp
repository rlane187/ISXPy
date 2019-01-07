#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_recipe::py_eq2_recipe() = default;

std::string py_eq2_recipe::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}