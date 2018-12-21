#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

PyCharacter::PyCharacter()
{
	pISInterface->IsTopLevelObject("Me")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

bool PyCharacter::check_collision(float to_x, float to_y, float to_z)
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(std::to_string(to_x).c_str());
	argv[1] = const_cast<char*>(std::to_string(to_y).c_str());
	argv[2] = const_cast<char*>(std::to_string(to_z).c_str());
	LSOBJECT dest;
	char* const member = static_cast<char *>("CheckCollision");
	try
	{
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool PyCharacter::get_at_char_select()
{
	char* const member = static_cast<char *>("AtCharSelect");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

std::string PyCharacter::get_archetype()
{
	char* const member = static_cast<char *>("Archetype");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_base_strength()
{
	char* const member = static_cast<char *>("BaseStrength");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyCharacter::get_breath()
{
	char* const member = static_cast<char *>("Breath");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string PyCharacter::get_class()
{
	char* const member = static_cast<char *>("Class");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_copper()
{
	char* const member = static_cast<char *>("Copper");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int64_t PyCharacter::get_current_health()
{
	char* const member = static_cast<char *>("CurrentHealth");
	try
	{
		return this->get_member(member, 0, nullptr).get_int64_from_lso();
	}
	catch (exception &) {}
	return INT64_MAX;
}

int PyCharacter::get_current_power()
{
	char* const member = static_cast<char *>("CurrentPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyCharacter::get_effects(boost::python::list& effect_list)
{
	LSOBJECT index_object;
	size_t size = 0;	
	const int random = rand() % INT_MAX;
	const int argc = 1;
	char* argv[argc];
	char* method = const_cast<char*>("QueryEffects");
	char variable_name[MAX_VARSTRING];
	char declare_command[MAX_VARSTRING];
	char delete_command[MAX_VARSTRING];
	sprintf_s(variable_name, _countof(variable_name), "%s_%d", "PyEffects", random);
	printf(variable_name);
	sprintf_s(declare_command, _countof(declare_command), "DeclareVariable %s index:effect global", variable_name);
	printf(declare_command);
	sprintf_s(delete_command, _countof(delete_command), "DeleteVariable %s", variable_name);
	printf(delete_command);
	argv[0] = variable_name;	
	try
	{		
		pISInterface->ExecuteCommand(declare_command);
		pISInterface->DataParse(argv[0], index_object);
		this->execute_method(method, argc, argv);
		size = static_cast<LSIndex*>(index_object.Ptr)->GetContainerUsed();
		for (size_t i = 0; i < size; i++)
		{
			effect_list.append(reinterpret_cast<PyEffect*>((*static_cast<LSIndex*>(index_object.Ptr)->GetIndex())[i]));
		}
		pISInterface->ExecuteCommand(delete_command);
	}
	catch (exception &) {}
	return len(effect_list);
}

int PyCharacter::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyCharacter::get_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceBubble");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int PyCharacter::get_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.Experience");
		std::string result = PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_label();
		boost::erase_all(result, ",");
		return boost::lexical_cast<int>(result);
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyCharacter::get_exp_debt_current()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceDebtCurrent");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}


int PyCharacter::get_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceNextLevel");
		std::string result = PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_label();
		boost::erase_all(result, ",");
		return boost::lexical_cast<int>(result);
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyCharacter::get_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.ExperienceCurrent");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string PyCharacter::get_gender()
{
	char* const member = static_cast<char *>("Gender");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_gold()
{
	char* const member = static_cast<char *>("Gold");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}


float PyCharacter::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int PyCharacter::get_health_regen()
{
	char* const member = static_cast<char *>("HealthRegen");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

bool PyCharacter::get_in_game_world()
{
	char* const member = static_cast<char *>("InGameWorld");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool PyCharacter::get_is_moving()
{
	char* const member = static_cast<char *>("IsMoving");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

int PyCharacter::get_level()
{
	char* const member = static_cast<char *>("Level");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyCharacter::get_maintained(boost::python::list& maintained_list)
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
		maintained_list.append(PyMaintained(this->get_member(maintained_string, argc, argv).get_lso()));
	}
	return len(maintained_list);
}

int PyCharacter::get_max_conc()
{
	char* const member = static_cast<char *>("MaxConc");
	try
	{
		return this->get_member(member, 0, nullptr).get_byte_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int64_t PyCharacter::get_max_health()
{
	char* const member = static_cast<char *>("MaxHealth");
	try
	{
		return this->get_member(member, 0, nullptr).get_int64_from_lso();
	}
	catch (exception &) {}
	return INT64_MAX;
}

int PyCharacter::get_max_power()
{
	char* const member = static_cast<char *>("MaxPower");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyCharacter::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_platinum()
{
	char* const member = static_cast<char *>("Platinum");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyCharacter::get_power_regen()
{
	char* const member = static_cast<char *>("PowerRegen");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyCharacter::get_race()
{
	char* const member = static_cast<char *>("Race");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_silver()
{
	char* const member = static_cast<char *>("Silver");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyCharacter::get_strength()
{
	char* const member = static_cast<char *>("Strength");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyCharacter::get_subclass()
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

std::string PyCharacter::get_ts_archetype()
{
	char* const member = static_cast<char *>("TSArchetype");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyCharacter::get_ts_class()
{
	char* const member = static_cast<char *>("TSClass");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyCharacter::get_ts_level()
{
	char* const member = static_cast<char *>("TSLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyCharacter::get_ts_subclass()
{
	char* const member = static_cast<char *>("TSSubClass");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float PyCharacter::get_ts_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitality");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_ts_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityLowerMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_ts_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityOverflowMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_ts_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.TSVitalityUpperMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int PyCharacter::get_used_conc()
{
	char* const member = static_cast<char *>("UsedConc");
	try
	{
		return this->get_member(member, 0, nullptr).get_byte_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

float PyCharacter::get_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.Vitality");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityLowerMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityOverflowMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	try
	{
		const int argc = 1;
		char* argv[argc];
		argv[0] = const_cast<char*>("Self.VitalityUpperMarker");
		return PyEQ2DynamicData(this->get_member(member, argc, argv).get_lso()).get_percent();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_water_depth()
{
	char* const member = static_cast<char *>("WaterDepth");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_x()
{

	char* const member = static_cast<char *>("X");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_y()
{
	char* const member = static_cast<char *>("Y");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::get_z()
{
	char* const member = static_cast<char *>("Z");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyCharacter::heading_to(float to_x, float to_y, float to_z)
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(std::to_string(to_x).c_str());
	argv[1] = const_cast<char*>(std::to_string(to_y).c_str());
	argv[2] = const_cast<char*>(std::to_string(to_z).c_str());
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}


std::string PyCharacter::heading_to_as_compass_bearing(float to_x, float to_y, float to_z)
{
	const int argc = 4;
	char* argv[argc];
	argv[0] = const_cast<char*>(std::to_string(to_x).c_str());
	argv[1] = const_cast<char*>(std::to_string(to_y).c_str());
	argv[2] = const_cast<char*>(std::to_string(to_z).c_str());
	argv[3] = static_cast<char *>("AsString");
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}
