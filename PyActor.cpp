#include "ISXPyPCH.h"
#include "ISXPy.h"

PyActor::PyActor(LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

std::string PyActor::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}
