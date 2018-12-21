#include "ISXPyPCH.h"
#include "ISXPy.h"

PyEQ2::PyEQ2()
{
	pISInterface->IsTopLevelObject("EQ2")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

std::string PyEQ2::get_server_name()
{
	char* const member = static_cast<char *>("ServerName");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}
