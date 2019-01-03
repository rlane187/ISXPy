#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

py_character::py_character()
{
	if (!pISInterface->IsTopLevelObject("Me")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this)))
		PyErr_SetString(PyExc_NameError, "\'Me\' TLO not found. ISXEQ2 is probably not loaded.");
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
	return this->get_member(member, argc, argv).get_bool_from_lso();
}

int py_character::get_agility()
{
	char* const member = static_cast<char *>("Agility");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_arcane_resist()
{
	char* const member = static_cast<char *>("ArcaneResist");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_arcane_resist_percent()
{
	char* const member = static_cast<char *>("ArcaneResistPct");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

bool py_character::get_at_char_select()
{
	char* const member = static_cast<char *>("AtCharSelect");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_character::get_archetype()
{
	char* const member = static_cast<char *>("Archetype");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_character::get_ascension_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceBubble");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_ascension_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperience");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

int py_character::get_ascension_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceNextLevel");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_ascension_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_ascension_level()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionLevel");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

int py_character::get_base_agility()
{
	char* const member = static_cast<char *>("BaseAgility");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_base_intelligence()
{
	char* const member = static_cast<char *>("BaseIntelligence");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_base_stamina()
{
	char* const member = static_cast<char *>("BaseStamina");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_base_strength()
{
	char* const member = static_cast<char *>("BaseStrength");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_base_wisdom()
{
	char* const member = static_cast<char *>("BaseWisdom");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_breath()
{
	char* const member = static_cast<char *>("Breath");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_character::get_class()
{
	char* const member = static_cast<char *>("Class");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_character::get_copper()
{
	char* const member = static_cast<char *>("Copper");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_count_maintained()
{
	char* const member = static_cast<char *>("CountMaintained");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int64_t py_character::get_current_health()
{
	char* const member = static_cast<char *>("CurrentHealth");
	return this->get_member(member, 0, nullptr).get_int64_from_lso();
}

int py_character::get_current_power()
{
	char* const member = static_cast<char *>("CurrentPower");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_dissipation()
{
	char* const member = static_cast<char *>("Dissipation");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_dissonance()
{
	char* const member = static_cast<char *>("Dissonance");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_dissonance_remaining()
{
	char* const member = static_cast<char *>("DissonanceRemaining");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_elemental_resist()
{
	char* const member = static_cast<char *>("ElementalResist");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_elemental_resist_percent()
{
	char* const member = static_cast<char *>("ElementalResistPct");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_character::get_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceBubble");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.Experience");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_exp_debt_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceDebtCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceNextLevel");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

std::string py_character::get_gender()
{
	char* const member = static_cast<char *>("Gender");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_character::get_gold()
{
	char* const member = static_cast<char *>("Gold");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_group(boost::python::list& group_member_list)
{
	char* const group_string = static_cast<char *>("Group");
	const int group_count = this->get_group_count();
	for (int i = 1; i < group_count; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = const_cast<char*>(buffer);
		group_member_list.append(py_group_member(this->get_member(group_string, argc, argv).get_lso()));
	}
	return len(group_member_list);
}

int py_character::get_group_count()
{
	char* const member = static_cast<char *>("GroupCount");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_character::get_grouped()
{
	char* const member = static_cast<char *>("Grouped");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

float py_character::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_character::get_health_regen()
{
	char* const member = static_cast<char *>("HealthRegen");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_character::get_in_game_world()
{
	char* const member = static_cast<char *>("InGameWorld");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_raid()
{
	char* const member = static_cast<char *>("InRaid");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_water()
{
	char* const member = static_cast<char *>("InWater");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int py_character::get_intelligence()
{
	char* const member = static_cast<char *>("Intelligence");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_character::get_is_auto_attack_on()
{
	char* const member = static_cast<char *>("AutoAttackOn");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_casting_spell()
{
	char* const member = static_cast<char *>("CastingSpell");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_group_leader()
{
	char* const member = static_cast<char *>("IsGroupLeader");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_hated()
{
	char* const member = static_cast<char *>("IsHated");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_combat()
{
	char* const member = static_cast<char *>("InCombat");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_first_person_view()
{
	char* const member = static_cast<char *>("In1stPersonView");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_pvp()
{
	char* const member = static_cast<char *>("IsInPVP");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_in_third_person_view()
{
	char* const member = static_cast<char *>("In3rdPersonView");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_moving()
{
	char* const member = static_cast<char *>("IsMoving");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_character::get_is_ranged_auto_attack_on()
{
	char* const member = static_cast<char *>("RangedAutoAttackOn");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int py_character::get_level()
{
	char* const member = static_cast<char *>("Level");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_maintained(boost::python::list& maintained_list)
{
	char* const maintained_string = static_cast<char *>("Maintained");
	const int count_maintained = this->get_count_maintained();
	for (int i = 1; i <= count_maintained; i++)
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
	return this->get_member(member, 0, nullptr).get_byte_from_lso();
}

int py_character::get_max_dissonance()
{
	char* const member = static_cast<char *>("MaxDissonance");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int64_t py_character::get_max_health()
{
	char* const member = static_cast<char *>("MaxHealth");
	return this->get_member(member, 0, nullptr).get_int64_from_lso();
}

int py_character::get_max_power()
{
	char* const member = static_cast<char *>("MaxPower");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_character::get_name()
{
	char* const member = static_cast<char *>("Name");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_character::get_noxious_resist()
{
	char* const member = static_cast<char *>("NoxiousResist");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_noxious_resist_percent()
{
	char* const member = static_cast<char *>("NoxiousResistPct");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_character::get_platinum()
{
	char* const member = static_cast<char *>("Platinum");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_power_regen()
{
	char* const member = static_cast<char *>("PowerRegen");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_character::get_race()
{
	char* const member = static_cast<char *>("Race");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_character::get_raid(boost::python::list& raid_member_list)
{
	const int max_raid_size = 24;
	const int current_raid_size = get_raid_count();
	int raid_members_found = 0;
	char* const member = static_cast<char *>("Raid");
	for (int i = 1; i <= max_raid_size; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING] = { 0 };
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = buffer;
		LSOBJECT ls_object = this->get_member(member, argc, argv).get_lso();
		if (ls_object.GetObjectData().Ptr != nullptr)
		{
			raid_members_found++;
			raid_member_list.append(py_group_member(ls_object));
		}
		if (raid_members_found == current_raid_size)
			break;
	}
	return len(raid_member_list);
}

int py_character::get_raid_count()
{
	char* const member = static_cast<char *>("RaidCount");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_raid_group_num()
{
	char* const member = static_cast<char *>("RaidGroupNum");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_silver()
{
	char* const member = static_cast<char *>("Silver");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_stamina()
{
	char* const member = static_cast<char *>("Stamina");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_character::get_strength()
{
	char* const member = static_cast<char *>("Strength");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_tithe_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceBubble");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_tithe_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperience");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

int py_character::get_tithe_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceNextLevel");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_tithe_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_tithe_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheVitalityOverflowMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

std::string py_character::get_subclass()
{
	char* const member = static_cast<char *>("SubClass");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_character::get_ts_archetype()
{
	char* const member = static_cast<char *>("TSArchetype");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_character::get_ts_class()
{
	char* const member = static_cast<char *>("TSClass");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_character::get_ts_exp_bubble()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceBubble");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_ts_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperience");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_ts_exp_debt_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSExperienceDebtCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_ts_exp_next_level()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceNextLevel");
	std::string result = py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

float py_character::get_ts_exp_percent()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceCurrent");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_ts_level()
{
	char* const member = static_cast<char *>("TSLevel");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_character::get_ts_subclass()
{
	char* const member = static_cast<char *>("TSSubClass");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_character::get_ts_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitality");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_ts_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityLowerMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_ts_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityOverflowMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_ts_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityUpperMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

int py_character::get_used_conc()
{
	char* const member = static_cast<char *>("UsedConc");
	return this->get_member(member, 0, nullptr).get_byte_from_lso();
}

float py_character::get_vitality()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.Vitality");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_vitality_lower_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityLowerMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_vitality_overflow_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityOverflowMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_vitality_upper_marker()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityUpperMarker");
	return py_eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_percent();
}

float py_character::get_water_depth()
{
	char* const member = static_cast<char *>("WaterDepth");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_character::get_wisdom()
{
	char* const member = static_cast<char *>("Wisdom");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_character::get_x()
{

	char* const member = static_cast<char *>("X");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_character::get_y()
{
	char* const member = static_cast<char *>("Y");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_character::get_z()
{
	char* const member = static_cast<char *>("Z");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
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
	return this->get_member(member, argc, argv).get_float_from_lso();
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
	return this->get_member(member, argc, argv).get_string_from_lso();
}

py_group_member py_character::get_group_member(const int& member_or_id, const std::string& name)
{
	py_group_member group_member;
	const int argc = 1;
	const int argc_by_id = 2;
	char* argv[argc];
	char* argv_by_id[argc_by_id];
	char buffer[MAX_VARSTRING];
	char buffer_by_id[MAX_VARSTRING];
	strcpy_s(buffer_by_id, _countof(buffer_by_id), "id");
	if (member_or_id != -1)
		sprintf_s(buffer, _countof(buffer), "%d", member_or_id);
	else
		strcpy_s(buffer, _countof(buffer), name.c_str());
	argv[0] = buffer;
	argv_by_id[0] = buffer_by_id;
	argv_by_id[1] = buffer;
	char* const member = static_cast<char*>("Group");
	if (member_or_id <= 5)
		group_member = this->get_member(member, argc, argv).get_lso();
	else
		group_member = this->get_member(member, argc_by_id, argv_by_id).get_lso();
	return group_member;
}

py_group_member py_character::get_raid_member(const int& member_or_id, const int& group_num, const std::string& name)
{
	py_group_member group_member;
	const int argc = 1;
	const int argc_by_id = 2;
	const int argc_by_group = 2;
	char* argv[argc];
	char* argv_by_id[argc_by_id];
	char* argv_by_group[argc_by_group];
	char buffer[MAX_VARSTRING];
	char buffer_by_id[MAX_VARSTRING];
	char buffer_by_group[MAX_VARSTRING];
	strcpy_s(buffer_by_id, _countof(buffer_by_id), "id");
	sprintf_s(buffer_by_group, _countof(buffer_by_group), "%d", group_num);
	if (member_or_id != -1)
		sprintf_s(buffer, _countof(buffer), "%d", member_or_id);
	else
		strcpy_s(buffer, _countof(buffer), name.c_str());
	argv[0] = buffer;
	argv_by_id[0] = buffer_by_id;
	argv_by_id[1] = buffer;
	argv_by_group[0] = buffer_by_group;
	argv_by_group[1] = buffer;
	char* const member = static_cast<char*>("Raid");
	try
	{
		// Search by id.
		if (member_or_id > 24)
			group_member = py_group_member(this->get_member(member, argc_by_id, argv_by_id).get_lso());
		// Search by group and member number.
		else if (member_or_id > 0 && member_or_id <= 6 && group_num > 0)
			group_member = py_group_member(this->get_member(member, argc_by_group, argv_by_group).get_lso());
		// Search by name or member number
		else
			group_member = py_group_member(this->get_member(member, argc, argv).get_lso());
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}
	return group_member;
}

py_maintained py_character::maintained(const int& number, const std::string& name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	if (name.empty())
		sprintf_s(buffer, _countof(buffer), "%d", number);
	else
		strcpy_s(buffer, _countof(buffer), name.c_str());
	char* const member = static_cast<char*>("Maintained");
	argv[0] = buffer;
	return this->get_member(member, argc, argv).get_lso();
}
