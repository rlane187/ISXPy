#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

eq2_character::eq2_character()
{
	pISInterface->IsTopLevelObject("Me")(0, nullptr, this->lsobject_);
}

eq2_character::~eq2_character() = default;

eq2_character::eq2_character(const eq2_character& other) = default;

eq2_character::eq2_character(eq2_character&& other) noexcept
{
	this->lsobject_ = other.lsobject_;
}

eq2_character::eq2_character(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_character& eq2_character::operator=(const eq2_character& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_character& eq2_character::operator=(eq2_character&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_bool eq2_character::check_collision(const float& to_x, const float& to_y, const float& to_z)
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
	return this->get_member(member, argc, argv);
}

ls_bool eq2_character::check_collision_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z)
{
	const int argc = 3;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(ls_float(to_x).get_value()).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(ls_float(to_y).get_value()).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(ls_float(to_z).get_value()).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	char* const member = static_cast<char *>("CheckCollision");
	return this->get_member(member, argc, argv);
}

ls_int eq2_character::get_agility()
{
	return this->get_member("Agility");
}

ls_int eq2_character::get_arcane_resist()
{
	return this->get_member("ArcaneResist");
}

ls_float eq2_character::get_arcane_resist_percent()
{
	return this->get_member("ArcaneResistPct");
}

ls_bool eq2_character::get_at_char_select()
{
	return this->get_member("AtCharSelect");
}

ls_string eq2_character::get_archetype()
{
	return this->get_member("Archetype");
}

ls_float eq2_character::get_ascension_exp_bubble()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceBubble");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_ascension_exp_current()
{
	char* const member = static_cast<char *>("GetGameData");
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperience");
	std::string result = eq2_dynamic_data(this->get_member(member, argc, argv).get_lso()).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

int eq2_character::get_ascension_exp_next_level()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceNextLevel");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_ascension_exp_percent()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionExperienceCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_ascension_level()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.AscensionLevel");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_int eq2_character::get_base_agility()
{
	return this->get_member("BaseAgility");
}

ls_int eq2_character::get_base_intelligence()
{
	return this->get_member("BaseIntelligence");
}

ls_int eq2_character::get_base_stamina()
{
	return this->get_member("BaseStamina");
}

ls_int eq2_character::get_base_strength()
{
	return this->get_member("BaseStrength");
}

ls_int eq2_character::get_base_wisdom()
{
	return this->get_member("BaseWisdom");
}

ls_float eq2_character::get_breath()
{
	return this->get_member("Breath");
}

ls_int eq2_character::get_copper()
{
	return this->get_member("Copper");
}

ls_int eq2_character::get_count_maintained()
{
	return this->get_member("CountMaintained");
}

ls_int eq2_character::get_current_health()
{
	return this->get_member("CurrentHealth");
}

ls_int eq2_character::get_current_power()
{
	return this->get_member("CurrentPower");
}

ls_int eq2_character::get_dissipation()
{
	return this->get_member("Dissipation");
}

ls_int eq2_character::get_dissonance()
{
	return this->get_member("Dissonance");
}

ls_int eq2_character::get_dissonance_remaining()
{
	return this->get_member("DissonanceRemaining");
}

ls_int eq2_character::get_elemental_resist()
{
	return this->get_member("ElementalResist");
}

ls_float eq2_character::get_elemental_resist_percent()
{
	return this->get_member("ElementalResistPct");
}

ls_float eq2_character::get_exp_bubble()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceBubble");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_exp_current()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.Experience");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_exp_debt_current()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceDebtCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_exp_next_level()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceNextLevel");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_exp_percent()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.ExperienceCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

eq2_dynamic_data eq2_character::get_game_data(const std::string& data)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	argv[0] = buffer;
	strcpy_s(buffer, _countof(buffer), data.c_str());
	return this->get_member("GetGameData", argc, argv);
}

ls_int eq2_character::get_gold()
{
	return this->get_member("Gold");
}

int eq2_character::get_group(boost::python::list& group_member_list)
{
	const int group_count = this->get_group_count().get_value();
	for (int i = 1; i < group_count; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = const_cast<char*>(buffer);
		group_member_list.append(eq2_group_member(this->get_member("Group", argc, argv)));
	}
	return len(group_member_list);
}

ls_int eq2_character::get_group_count()
{
	return this->get_member("GroupCount");
}

ls_bool eq2_character::get_grouped()
{
	return this->get_member("Grouped");
}

ls_int eq2_character::get_health_regen()
{
	return this->get_member("HealthRegen");
}

ls_bool eq2_character::get_in_game_world()
{
	return this->get_member("InGameWorld");
}

ls_int eq2_character::get_is_in_raid()
{
	return this->get_member("InRaid");
}

ls_bool eq2_character::get_is_in_water()
{
	return this->get_member("InWater");
}

ls_int eq2_character::get_intelligence()
{
	return this->get_member("Intelligence");
}

ls_bool eq2_character::get_is_anonymous()
{
	return this->get_member("IsAnonymous");
}

ls_bool eq2_character::get_is_auto_attack_on()
{
	return this->get_member("AutoAttackOn");
}

ls_bool eq2_character::get_is_casting_spell()
{
	return this->get_member("CastingSpell");
}

ls_bool eq2_character::get_is_declining_duel_invites()
{
	return this->get_member("IsDecliningDuelInvites");
}

ls_bool eq2_character::get_is_declining_group_invites()
{
	return this->get_member("IsDecliningGroupInvites");
}

ls_bool eq2_character::get_is_declining_guild_invites()
{
	return this->get_member("IsDecliningGuildInvites");
}

ls_bool eq2_character::get_is_declining_raid_invites()
{
	return this->get_member("IsDecliningRaidInvites");
}

ls_bool eq2_character::get_is_declining_trade_invites()
{
	return this->get_member("IsDecliningTradeInvites");
}

ls_bool eq2_character::get_is_group_leader()
{
	return this->get_member("IsGroupLeader");
}

ls_bool eq2_character::get_is_guild_privacy_on()
{
	return this->get_member("GuildPrivacyOn");
}

ls_bool eq2_character::get_is_hated()
{
	return this->get_member("IsHated");
}

ls_bool eq2_character::get_is_ignoring_all()
{
	return this->get_member("IgnoringAll");
}

ls_bool eq2_character::get_is_in_combat()
{
	return this->get_member("InCombat");
}

ls_bool eq2_character::get_is_in_first_person_view()
{
	return this->get_member("In1stPersonView");
}

ls_bool eq2_character::get_is_in_pvp()
{
	return this->get_member("IsInPVP");
}

ls_bool eq2_character::get_is_in_third_person_view()
{
	return this->get_member("In3rdPersonView");
}

ls_bool eq2_character::get_is_moving()
{
	return this->get_member("IsMoving");
}

ls_bool eq2_character::get_is_ranged_auto_attack_on()
{
	return this->get_member("RangedAutoAttackOn");
}

ls_bool eq2_character::get_is_roleplaying()
{
	return this->get_member("IsRolePlaying");
}

ls_bool eq2_character::get_is_target_in_los()
{
	return this->get_member("TargetLOS");
}

int eq2_character::get_maintained(boost::python::list& maintained_list)
{
	const int count_maintained = this->get_count_maintained().get_value();
	for (int i = 1; i <= count_maintained; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = buffer;
		maintained_list.append(eq2_maintained(this->get_member("Maintained", argc, argv)));
	}
	return len(maintained_list);
}

ls_int eq2_character::get_max_conc()
{
	return this->get_member("MaxConc");
}

ls_int eq2_character::get_max_dissonance()
{
	return this->get_member("MaxDissonance");
}

ls_int eq2_character::get_max_health()
{
	return this->get_member("MaxHealth");
}

ls_int eq2_character::get_max_power()
{
	return this->get_member("MaxPower");
}

ls_int eq2_character::get_noxious_resist()
{
	return this->get_member("NoxiousResist");
}

ls_float eq2_character::get_noxious_resist_percent()
{
	return this->get_member("NoxiousResistPct");
}

ls_int eq2_character::get_platinum()
{
	return this->get_member("Platinum");
}

ls_int eq2_character::get_power_regen()
{
	return this->get_member("PowerRegen");
}

int eq2_character::get_raid(boost::python::list& raid_member_list)
{
	const int max_raid_size = 24;
	const int current_raid_size = get_raid_count().get_value();
	int raid_members_found = 0;
	for (int i = 1; i <= max_raid_size; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING] = { 0 };
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = buffer;
		LSOBJECT ls_object = this->get_member("Raid", argc, argv).get_lso();
		if (ls_object.GetObjectData().Ptr != nullptr)
		{
			raid_members_found++;
			raid_member_list.append(eq2_group_member(ls_object));
		}
		if (raid_members_found == current_raid_size)
			break;
	}
	return len(raid_member_list);
}

ls_int eq2_character::get_raid_count()
{
	return this->get_member("RaidCount");
}

ls_int eq2_character::get_raid_group_num()
{
	return this->get_member("RaidGroupNum");
}

ls_int eq2_character::get_silver()
{
	return this->get_member("Silver");
}

ls_int eq2_character::get_stamina()
{
	return this->get_member("Stamina");
}

ls_int eq2_character::get_strength()
{
	return this->get_member("Strength");
}

ls_float eq2_character::get_time_to_campout()
{
	return this->get_member("TimeToCampOut");
}

ls_float eq2_character::get_tithe_exp_bubble()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceBubble");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_tithe_exp_current()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperience");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

int eq2_character::get_tithe_exp_next_level()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceNextLevel");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_tithe_exp_percent()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheExperienceCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_tithe_vitality_overflow_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TitheVitalityOverflowMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_string eq2_character::get_subclass()
{
	return this->get_member("SubClass");
}

ls_string eq2_character::get_ts_archetype()
{
	return this->get_member("TSArchetype");
}

ls_string eq2_character::get_ts_class()
{
	return this->get_member("TSClass");
}

ls_float eq2_character::get_ts_exp_bubble()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceBubble");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_ts_exp_current()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperience");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_ts_exp_debt_current()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSExperienceDebtCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

int eq2_character::get_ts_exp_next_level()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceNextLevel");
	std::string result = eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_label();
	boost::erase_all(result, ",");
	return boost::lexical_cast<int>(result);
}

ls_float eq2_character::get_ts_exp_percent()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TradeskillExperienceCurrent");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_int eq2_character::get_ts_level()
{
	return this->get_member("TSLevel");
}

ls_string eq2_character::get_ts_subclass()
{
	return this->get_member("TSSubClass");
}

ls_float eq2_character::get_ts_vitality()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitality");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_ts_vitality_lower_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityLowerMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_ts_vitality_overflow_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityOverflowMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_ts_vitality_upper_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.TSVitalityUpperMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_int eq2_character::get_used_conc()
{
	return this->get_member("UsedConc");
}

ls_float eq2_character::get_vitality()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.Vitality");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_vitality_lower_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityLowerMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_vitality_overflow_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityOverflowMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_vitality_upper_marker()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("Self.VitalityUpperMarker");
	return eq2_dynamic_data(this->get_member("GetGameData", argc, argv)).get_percent();
}

ls_float eq2_character::get_water_depth()
{
	return this->get_member("WaterDepth");
}

ls_int eq2_character::get_wisdom()
{
	return this->get_member("Wisdom");
}

ls_float eq2_character::get_heading_to(const float& to_x, const float& to_y, const float& to_z)
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
	return this->get_member("HeadingTo", argc, argv);
}

ls_float eq2_character::get_heading_to_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z)
{
	const int argc = 3;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(ls_float(to_x).get_value()).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(ls_float(to_y).get_value()).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(ls_float(to_z).get_value()).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	return this->get_member("HeadingTo", argc, argv);
}

ls_string eq2_character::get_heading_to_as_compass_bearing(const float& to_x, const float& to_y, const float& to_z)
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
	return this->get_member("HeadingTo", argc, argv);
}

ls_string eq2_character::get_heading_to_as_compass_bearing_ls(const ls_float& to_x, const ls_float& to_y, const ls_float& to_z)
{
	const int argc = 4;
	char* argv[argc];
	char buffer_x[MAX_VARSTRING];
	char buffer_y[MAX_VARSTRING];
	char buffer_z[MAX_VARSTRING];
	strcpy_s(buffer_x, _countof(buffer_x), boost::lexical_cast<std::string>(ls_float(to_x).get_value()).c_str());
	strcpy_s(buffer_y, _countof(buffer_y), boost::lexical_cast<std::string>(ls_float(to_y).get_value()).c_str());
	strcpy_s(buffer_z, _countof(buffer_z), boost::lexical_cast<std::string>(ls_float(to_z).get_value()).c_str());
	argv[0] = buffer_x;
	argv[1] = buffer_y;
	argv[2] = buffer_z;
	argv[3] = static_cast<char *>("AsString");
	return this->get_member("HeadingTo", argc, argv);
}

eq2_group_member eq2_character::get_group_member(const int& member_or_id, const std::string& name)
{
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
	if (member_or_id <= 5)
		return this->get_member("Group", argc, argv);
	else
		return this->get_member("Group", argc_by_id, argv_by_id);
}

eq2_group_member eq2_character::get_raid_member(const int& member_or_id, const int& group_num, const std::string& name)
{
	eq2_group_member group_member;
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
	// Search by id.
	if (member_or_id > 24)
		return this->get_member("Raid", argc_by_id, argv_by_id);
	// Search by group and member number.
	if (member_or_id > 0 && member_or_id <= 6 && group_num > 0)
		return this->get_member("Raid", argc_by_group, argv_by_group);
	// Search by name or member number
	return this->get_member("Raid", argc, argv);
}

eq2_maintained eq2_character::maintained(const int& number, const std::string& name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	if (name.empty())
		sprintf_s(buffer, _countof(buffer), "%d", number);
	else
		strcpy_s(buffer, _countof(buffer), name.c_str());
	argv[0] = buffer;
	return this->get_member("Maintained", argc, argv);
}

void eq2_character::face(const float& heading)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(heading).c_str());
	argv[0] = buffer;
	this->execute_method("face", argc, argv);
}

void eq2_character::face_ls(const ls_float& heading)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(ls_float(heading).get_value()).c_str());
	argv[0] = buffer;
	this->execute_method("face", argc, argv);
}

void eq2_character::take_all_vending_coin()
{
	this->execute_method("TakeAllVendingCoin");
}

void eq2_character::reset_zone_timer(const std::string& zone_name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), zone_name.c_str());
	argv[0] = buffer;
	this->execute_method("ResetZoneTimer", argc, argv);
}

void eq2_character::reset_zone_timer_ls(const ls_string& zone_name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), ls_string(zone_name).get_value().c_str());
	argv[0] = buffer;
	this->execute_method("ResetZoneTimer", argc, argv);
}

void eq2_character::bank_deposit(const std::string& type, const int& amount, const bool& from_shared)
{
	const int argc = 2;
	const int argc_from_shared = 3;
	char* argv[argc];
	char* argv_from_shared[argc_from_shared];
	char buffer_type[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	char buffer_from_shared[MAX_VARSTRING];
	strcpy_s(buffer_type, _countof(buffer_type), type.c_str());
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	strcpy_s(buffer_from_shared, _countof(buffer_from_shared), "FromShared");
	argv[0] = buffer_type;
	argv[1] = buffer_amount;
	argv_from_shared[0] = buffer_type;
	argv_from_shared[1] = buffer_amount;
	argv_from_shared[2] = buffer_from_shared;
	if (from_shared)
		this->execute_method("BankDeposit", argc_from_shared, argv_from_shared);
	else
		this->execute_method("BankDeposit", argc, argv);
}

void eq2_character::shared_bank_deposit(const std::string& type, const int& amount, const bool& from_bank)
{
	const int argc = 2;
	const int argc_from_bank = 3;
	char* argv[argc];
	char* argv_from_bank[argc_from_bank];
	char buffer_type[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	char buffer_from_bank[MAX_VARSTRING];
	strcpy_s(buffer_type, _countof(buffer_type), type.c_str());
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	strcpy_s(buffer_from_bank, _countof(buffer_from_bank), "FromBank");
	argv[0] = buffer_type;
	argv[1] = buffer_amount;
	argv_from_bank[0] = buffer_type;
	argv_from_bank[1] = buffer_amount;
	argv_from_bank[2] = buffer_from_bank;
	if (from_bank)
		this->execute_method("SharedBankDeposit", argc_from_bank, argv_from_bank);
	else
		this->execute_method("SharedBankDeposit", argc, argv);
}

void eq2_character::bank_withdraw(const std::string& type, const int& amount)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_type[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	strcpy_s(buffer_type, _countof(buffer_type), type.c_str());
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	argv[0] = buffer_type;
	argv[1] = buffer_amount;
	this->execute_method("BankWithdraw", argc, argv);
}

void eq2_character::shared_bank_withdraw(const std::string& type, const int& amount)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_type[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	strcpy_s(buffer_type, _countof(buffer_type), type.c_str());
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	argv[0] = buffer_type;
	argv[1] = buffer_amount;
	this->execute_method("SharedBankWithdraw", argc, argv);
}

void eq2_character::guild_bank_deposit(const int& bank_number, const int& amount)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_bank[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	sprintf_s(buffer_bank, _countof(buffer_bank), "%d", bank_number);
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	argv[0] = buffer_bank;
	argv[1] = buffer_amount;
	this->execute_method("GuildBankDeposit", argc, argv);
}

void eq2_character::guild_bank_withdraw(const int& bank_number, const int& amount)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_bank[MAX_VARSTRING];
	char buffer_amount[MAX_VARSTRING];
	sprintf_s(buffer_bank, _countof(buffer_bank), "%d", bank_number);
	sprintf_s(buffer_amount, _countof(buffer_amount), "%d", amount);
	argv[0] = buffer_bank;
	argv[1] = buffer_amount;
	this->execute_method("GuildBankWithdraw", argc, argv);
}

void eq2_character::deposit_into_house_escrow(const int& coin_amount, const int& status_amount)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_coin[MAX_VARSTRING];
	char buffer_status[MAX_VARSTRING];
	sprintf_s(buffer_coin, _countof(buffer_coin), "%d", coin_amount);
	sprintf_s(buffer_status, _countof(buffer_status), "%d", status_amount);
	argv[0] = buffer_coin;
	argv[1] = buffer_status;
	this->execute_method("DepositIntoHouseEscrow", argc, argv);
}
