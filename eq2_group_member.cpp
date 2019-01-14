#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_group_member::eq2_group_member() = default;

eq2_group_member::eq2_group_member(const eq2_group_member& other) = default;

eq2_group_member::eq2_group_member(eq2_group_member&& other) noexcept = default;

eq2_group_member::~eq2_group_member() = default;

eq2_group_member::eq2_group_member(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_group_member& eq2_group_member::operator=(const eq2_group_member& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_group_member& eq2_group_member::operator=(eq2_group_member&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_group_member::eq2_group_member(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

int eq2_group_member::get_arcane()
{
	char* const member = static_cast<char *>("Arcane");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int64_t eq2_group_member::get_current_health()
{
	char* const member = static_cast<char *>("HitPoints");
	return this->get_member(member, 0, nullptr).get_int64_from_lso();
}

int eq2_group_member::get_current_power()
{
	char* const member = static_cast<char *>("CurrentPower");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_cursed()
{
	char* const member = static_cast<char *>("Cursed");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_elemental()
{
	char* const member = static_cast<char *>("Elemental");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int64_t eq2_group_member::get_max_health()
{
	char* const member = static_cast<char *>("MaxHitPoints");
	return this->get_member(member, 0, nullptr).get_int64_from_lso();
}

int eq2_group_member::get_max_power()
{
	char* const member = static_cast<char *>("MaxPower");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_noxious()
{
	char* const member = static_cast<char *>("Noxious");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool eq2_group_member::get_in_zone()
{
	char* const member = static_cast<char *>("InZone");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool eq2_group_member::get_is_afflicted()
{
	char* const member = static_cast<char *>("InZone");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int eq2_group_member::get_pet_id()
{
	char* const member = static_cast<char *>("PetID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_raid_group_num()
{
	char* const member = static_cast<char *>("RaidGroupNum");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_raid_role()
{
	char* const member = static_cast<char *>("RaidRole");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int eq2_group_member::get_trauma()
{
	char* const member = static_cast<char *>("Trauma");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string eq2_group_member::get_zone_name()
{
	char* const member = static_cast<char *>("ZoneName");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}