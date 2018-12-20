#include "ISXPyPCH.h"
#include "ISXPy.h"

PyEQ2::PyEQ2()
{
	this->tlo_name_ = "EQ2";
	this->ls_type_name_ = "eq2";
	this->p_type_def_ = pEQ2Type;
}

std::string PyEQ2::get_server_name() const
{
	LSOBJECT dest;
	char* const member = static_cast<char *>("ServerName");
	try
	{
		if (this->get_ls_object_from_tlo_member(0, nullptr, member, 0, nullptr, dest))
			return PyEQ2::get_string_from_ls_object(dest);
	}
	catch (exception &e) {}
	return std::string("Error");
}
