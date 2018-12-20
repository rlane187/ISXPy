#include "ISXPyPCH.h"
#include "ISXPy.h"

PyEffectInfo::PyEffectInfo(LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

std::string PyEffectInfo::get_description()
{
	char* const member = static_cast<char *>("Description");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyEffectInfo::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyEffectInfo::get_type()
{
	char* const member = static_cast<char *>("type");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}