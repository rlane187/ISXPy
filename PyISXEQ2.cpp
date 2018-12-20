#include "ISXPyPCH.h"
#include "ISXPy.h"

PyISXEQ2::PyISXEQ2()
{
	this->tlo_name_ = std::string("ISXEQ2");
	this->ls_type_name_ = std::string("ISXEQ2");
	this->p_type_def_ = pISXEQ2Type;
}


std::string PyISXEQ2::get_version() const
{
	LSOBJECT dest;
	char* const member = static_cast<char *>("Version");
	try
	{		
		if(this->get_ls_object_from_tlo_member(0, nullptr, member, 0, nullptr, dest))
			return this->get_string_from_ls_object(dest);
	} 
	catch(exception &e) {}
	return std::string("");
}

std::string PyISXEQ2::get_api_version() const
{
	LSOBJECT dest;
	char* const member = static_cast<char *>("APIVersion");
	try
	{
		if (this->get_ls_object_from_tlo_member(0, nullptr, member, 0, nullptr, dest))
			return this->get_string_from_ls_object(dest);
	}
	catch (exception &e) {}
	return std::string("");
}

bool PyISXEQ2::get_is_ready() const
{
	LSOBJECT dest;
	char* const member = static_cast<char *>("IsReady");
	try
	{
		if (this->get_ls_object_from_tlo_member(0, nullptr, member, 0, nullptr, dest))
			return this->get_bool_from_ls_object(dest);
	}
	catch (exception &e) {}
	return false;
}

void PyISXEQ2::popup(std::string message, std::string title, std::string status) const
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(message.c_str());
	argv[1] = const_cast<char*>(title.c_str());
	argv[2] = const_cast<char*>(status.c_str());
	LSOBJECT dest;
	char* const method = static_cast<char *>("Popup");
	try
	{
		this->execute_tlo_method(0, nullptr, method, argc, argv);
	}
	catch(exception& e)	{}
}

