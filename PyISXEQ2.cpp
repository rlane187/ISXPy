#include "ISXPyPCH.h"
#include "ISXPy.h"

PyISXEQ2::PyISXEQ2()
{
	pISInterface->IsTopLevelObject("ISXEQ2")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

void PyISXEQ2::disable_affliction_events()
{
	char* const method = static_cast<char *>("DisableAfflictionEvents");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void PyISXEQ2::disable_custom_zoning_text()
{
	char* const method = static_cast<char *>("DisableCustomZoningText");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void PyISXEQ2::enable_affliction_events()
{
	char* const method = static_cast<char *>("EnableAfflictionEvents");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void PyISXEQ2::enable_custom_zoning_text()
{
	char* const method = static_cast<char *>("EnableCustomZoningText");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

bool PyISXEQ2::get_affliction_events_on()
{
	char* const member = static_cast<char *>("AfflictionEventsOn");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

std::string PyISXEQ2::get_api_version()
{
	char* const member = static_cast<char *>("APIVersion");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyISXEQ2::get_version()
{
	char* const member = static_cast<char *>("Version");
	try
	{		
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	} 
	catch(exception &) {}
	return std::string("Error");
}

bool PyISXEQ2::get_is_ready()
{
	char* const member = static_cast<char *>("IsReady");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool PyISXEQ2::get_is_valid_eq2press_key(std::string key_name)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(key_name.c_str());
	char* const member = static_cast<char *>("IsValidEQ2PressKey");
	try
	{
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}


void PyISXEQ2::popup(std::string& message, std::string& title, std::string& status)
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(message.c_str());
	argv[1] = const_cast<char*>(title.c_str());
	argv[2] = const_cast<char*>(status.c_str());
	char* const method = static_cast<char *>("Popup");
	try
	{
		this->execute_method(method, argc, argv);
	}
	catch(exception&)	{}
}

