#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2::py_eq2()
{
	pISInterface->IsTopLevelObject("EQ2")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

std::string py_eq2::get_server_name()
{
	char* const member = static_cast<char *>("ServerName");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}
