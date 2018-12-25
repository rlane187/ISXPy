#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

py_character::py_character()
{
	pISInterface->IsTopLevelObject("Me")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

bool py_character::check_collision(const float& to_x, const float& to_y, const float& to_z)
{
	const int argc = 3;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(to_x).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(to_y).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(to_z).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	char* const member = static_cast<char *>("CheckCollision");
	try
	{
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool py_character::get_at_char_select()
{
	char* const member = static_cast<char *>("AtCharSelect");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

std::string py_character::get_archetype()
{
	char* const member = static_cast<char *>("Archetype");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_base_strength()
{
	char* const member = static_cast<char *>("BaseStrength");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_character::get_breath()
{
	char* const member = static_cast<char *>("Breath");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string py_character::get_class()
{
	char* const member = static_cast<char *>("Class");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_copper()
{
	char* const member = static_cast<char *>("Copper");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int64_t py_character::get_current_health()
{
	char* const member = static_cast<char *>("CurrentHealth");
	try
	{
		return this->get_member(member, 0, nullptr).get_int64_from_lso();
	}
	catch (exception &) {}
	return INT64_MAX;
}

int py_character::get_current_power()
{
	char* const member = static_cast<char *>("CurrentPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_character::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_character::get_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceBubble");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int py_character::get_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.Experience");
		std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
		boost::erase_all(result, ",");
		return boost::lexical_cast<int>(result);
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_character::get_exp_debt_current()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceDebtCurrent");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}


int py_character::get_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceNextLevel");
		std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
		boost::erase_all(result, ",");
		return boost::lexical_cast<int>(result);
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_character::get_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceCurrent");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string py_character::get_gender()
{
	char* const member = static_cast<char *>("Gender");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_gold()
{
	char* const member = static_cast<char *>("Gold");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}


float py_character::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int py_character::get_health_regen()
{
	char* const member = static_cast<char *>("HealthRegen");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

bool py_character::get_in_game_world()
{
	char* const member = static_cast<char *>("InGameWorld");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool py_character::get_is_moving()
{
	char* const member = static_cast<char *>("IsMoving");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

int py_character::get_level()
{
	char* const member = static_cast<char *>("Level");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_character::get_maintained(boost::python::list& maintained_list)
{
	char* const count_maintained_string = static_cast<char *>("CountMaintained");
	char* const maintained_string = static_cast<char *>("Maintained");
	const int count_maintained = this->get_member(count_maintained_string, 0, nullptr).get_int_from_lso();
	for(int i = 1; i <= count_maintained; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = const_cast<char*>(buffer);
		maintained_list.append(py_maintained(this->get_member(maintained_string, argc, argv).get_lso()));
	}
	return len(maintained_list);
}

int py_character::get_max_conc()
{
	char* const member = static_cast<char *>("MaxConc");
	try
	{
		return this->get_member(member, 0, nullptr).get_byte_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int64_t py_character::get_max_health()
{
	char* const member = static_cast<char *>("MaxHealth");
	try
	{
		return this->get_member(member, 0, nullptr).get_int64_from_lso();
	}
	catch (exception &) {}
	return INT64_MAX;
}

int py_character::get_max_power()
{
	char* const member = static_cast<char *>("MaxPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string py_character::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_platinum()
{
	char* const member = static_cast<char *>("Platinum");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_character::get_power_regen()
{
	char* const member = static_cast<char *>("PowerRegen");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string py_character::get_race()
{
	char* const member = static_cast<char *>("Race");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_silver()
{
	char* const member = static_cast<char *>("Silver");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int py_character::get_strength()
{
	char* const member = static_cast<char *>("Strength");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string py_character::get_subclass()
{
	LSOBJECT dest;
	char* const member = static_cast<char *>("SubClass");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string py_character::get_ts_archetype()
{
	char* const member = static_cast<char *>("TSArchetype");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string py_character::get_ts_class()
{
	char* const member = static_cast<char *>("TSClass");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_character::get_ts_level()
{
	char* const member = static_cast<char *>("TSLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string py_character::get_ts_subclass()
{
	char* const member = static_cast<char *>("TSSubClass");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float py_character::get_ts_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitality");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_ts_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityLowerMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_ts_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityOverflowMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_ts_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityUpperMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int py_character::get_used_conc()
{
	char* const member = static_cast<char *>("UsedConc");
	try
	{
		return this->get_member(member, 0, nullptr).get_byte_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float py_character::get_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.Vitality");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityLowerMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityOverflowMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityUpperMarker");
		return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_water_depth()
{
	char* const member = static_cast<char *>("WaterDepth");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_x()
{

	char* const member = static_cast<char *>("X");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_y()
{
	char* const member = static_cast<char *>("Y");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::get_z()
{
	char* const member = static_cast<char *>("Z");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float py_character::heading_to(const float& to_x, const float& to_y, const float& to_z)
{
	const int argc = 3;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(to_x).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(to_y).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(to_z).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}


std::string py_character::heading_to_as_compass_bearing(const float& to_x, const float& to_y, const float& to_z)
{
	const int argc = 4;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(to_x).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(to_y).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(to_z).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	argv[3] = static_cast<char *>("AsString");
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}
