#include "ISXPyPCH.h"
#include "ISXPy.h"

py_group_member::py_group_member(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

int py_group_member::get_arcane()
{
	char* const member = static_cast<char *>("Arcane");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

std::string py_group_member::get_class()
{
	char* const member = static_cast<char *>("Class");
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

int py_group_member::get_current_hit_points()
{
	char* const member = static_cast<char *>("CurrentHitPoints");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_current_power()
{
	char* const member = static_cast<char *>("CurrentPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_cursed()
{
	char* const member = static_cast<char *>("Cursed");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_elemental()
{
	char* const member = static_cast<char *>("Elemental");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

unsigned int py_group_member::get_id()
{
	char* const member = static_cast<char *>("ID");
	try
	{
		return this->get_member(member, 0, nullptr).get_uint_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return UINT_MAX;
}

int py_group_member::get_level()
{
	char* const member = static_cast<char *>("Level");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_max_hit_points()
{
	char* const member = static_cast<char *>("MaxHitPoints");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_max_power()
{
	char* const member = static_cast<char *>("MaxPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

std::string py_group_member::get_name()
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

int py_group_member::get_noxious()
{
	char* const member = static_cast<char *>("Noxious");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

bool py_group_member::get_in_zone()
{
	char* const member = static_cast<char *>("InZone");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return false;
}

bool py_group_member::get_is_afflicted()
{
	char* const member = static_cast<char *>("InZone");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return false;
}

unsigned int py_group_member::get_pet_id()
{
	char* const member = static_cast<char *>("PetID");
	try
	{
		return this->get_member(member, 0, nullptr).get_uint_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return UINT_MAX;
}

std::string py_group_member::get_race()
{
	char* const member = static_cast<char *>("Race");
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

int py_group_member::get_raid_group_num()
{
	char* const member = static_cast<char *>("RaidGroupNum");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_raid_role()
{
	char* const member = static_cast<char *>("RaidRole");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

int py_group_member::get_trauma()
{
	char* const member = static_cast<char *>("Trauma");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return INT_MAX;
}

std::string py_group_member::get_zone_name()
{
	char* const member = static_cast<char *>("ZoneName");
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