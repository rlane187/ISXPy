#include "ISXPyPCH.h"
#include "ISXPy.h"

std::string py_item::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return std::string("Error");
}
