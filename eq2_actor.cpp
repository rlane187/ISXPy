#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_actor::eq2_actor() = default;

eq2_actor::~eq2_actor() = default;

eq2_actor::eq2_actor(const eq2_actor& other) = default;

eq2_actor::eq2_actor(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

eq2_actor::eq2_actor(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_actor::eq2_actor(const unsigned int& actor_id)
{
	LSOBJECT result;
	const int argc_id = 1;
	char* argv_id[argc_id];
	char buffer_id[MAX_VARSTRING];
	sprintf_s(buffer_id, _countof(buffer_id), "%u", actor_id);
	argv_id[0] = buffer_id;
	pISInterface->IsTopLevelObject("Actor")(argc_id, argv_id, result);
	this->lsobject_ = result;
}

eq2_actor::eq2_actor(const ls_int& actor_id)
{
	LSOBJECT result;
	const int argc_id = 1;
	char* argv_id[argc_id];
	char buffer_id[MAX_VARSTRING];
	sprintf_s(buffer_id, _countof(buffer_id), "%lld", ls_int(actor_id).get_value());
	argv_id[0] = buffer_id;
	pISInterface->IsTopLevelObject("Actor")(argc_id, argv_id, result);
	this->lsobject_ = result;
}

eq2_actor::eq2_actor(const std::string& query)
{
	LSOBJECT result;
	const int argc_query = 2;
	char* argv_query[argc_query];
	char buffer_query[MAX_VARSTRING];
	strcpy_s(buffer_query, _countof(buffer_query), query.c_str());
	argv_query[0] = const_cast<char *>("Query");
	argv_query[1] = buffer_query;
	pISInterface->IsTopLevelObject("Actor")(argc_query, argv_query, result);
	this->lsobject_ = result;
}

eq2_actor::eq2_actor(eq2_actor&& other) noexcept = default;

eq2_actor& eq2_actor::operator=(const eq2_actor& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_actor& eq2_actor::operator=(eq2_actor&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_actor eq2_actor::from_id(const unsigned int& actor_id)
{
	LSOBJECT ls_object;
	const int argc_id = 1;
	char* argv_id[argc_id];
	char buffer_id[MAX_VARSTRING];
	sprintf_s(buffer_id, _countof(buffer_id), "%u", actor_id);
	argv_id[0] = buffer_id;
	pISInterface->IsTopLevelObject("Actor")(argc_id, argv_id, ls_object);
	return ls_object;
}

eq2_actor eq2_actor::from_query(const std::string& query)
{
	LSOBJECT ls_object;
	const int argc_query = 2;
	char* argv_query[argc_query];
	char buffer_query[MAX_VARSTRING];
	strcpy_s(buffer_query, _countof(buffer_query), query.c_str());
	argv_query[0] = const_cast<char *>("Query");
	argv_query[1] = buffer_query;
	pISInterface->IsTopLevelObject("Actor")(argc_query, argv_query, ls_object);
	return ls_object;
}

ls_string eq2_actor::get_aura()
{
	return this->get_member("Aura");
}

ls_bool eq2_actor::check_collision(const float& to_x, const float& to_y, const float& to_z)
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
	const char* member = "CheckCollision";
	if (to_x == NULL || to_y == NULL || to_z == NULL)
		return this->get_member(member);
	return this->get_member(member, argc, argv);
}

ls_bool eq2_actor::get_can_turn()
{
	return this->get_member("CanTurn");
}

ls_string eq2_actor::get_class()
{
	return this->get_member("Class");
}

ls_float eq2_actor::get_collision_radius()
{
	return this->get_member("CollisionRadius");
}

ls_float eq2_actor::get_collision_scale()
{
	return this->get_member("CollisionScale");
}

ls_string eq2_actor::get_con_color(const bool& as_rgb)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("raw");
	const char* member = "ConColor";
	if (as_rgb)
		return this->get_member(member, argc, argv);
	return this->get_member(member);
}

ls_string eq2_actor::get_current_animation()
{
	return this->get_member("CurrentAnimation");
}

ls_int eq2_actor::get_difficulty()
{
	return this->get_member("Difficulty");
}

ls_float eq2_actor::get_distance()
{
	return this->get_member("Distance");
}

ls_float eq2_actor::get_distance2d()
{
	return this->get_member("Distance2D");
}

int eq2_actor::get_effects(boost::python::list& effect_list)
{
	char* const effect_string = static_cast<char *>("Effect");
	const int count_effects = this->get_num_effects();
	for (int i = 1; i <= count_effects; i++)
	{
		const int argc = 1;
		char* argv[argc];
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), "%d", i);
		argv[0] = const_cast<char*>(buffer);
		effect_list.append(py_eq2_actor_effect(this->get_member(effect_string, argc, argv).get_lso()));
	}
	return len(effect_list);
}

ls_int eq2_actor::get_effective_level()
{
	return this->get_member("EffectiveLevel");
}

ls_int eq2_actor::get_encounter_size()
{
	return this->get_member("EncounterSize");
}

ls_int eq2_actor::get_faction()
{
	return this->get_member("Faction");
}

ls_string eq2_actor::get_faction_standing()
{
	return this->get_member("FactionStanding");
}

ls_bool eq2_actor::get_flying_using_mount()
{
	return this->get_member("FlyingUsingMount");
}

ls_string eq2_actor::get_gender()
{
	return this->get_member("Gender");
}

ls_string eq2_actor::get_guild()
{
	return this->get_member("Guild");
}

ls_float eq2_actor::get_heading()
{
	return this->get_member("Heading");
}

ls_float eq2_actor::get_heading_to()
{
	return this->get_member("HeadingTo");
}

ls_string eq2_actor::get_heading_to_as_compass_bearing()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("AsString");
	return this->get_member("HeadingTo", argc, argv);
}

ls_int eq2_actor::get_health()
{
	return this->get_member("Health");
}

ls_int eq2_actor::get_id()
{
	return this->get_member("ID");
}

ls_bool eq2_actor::get_in_combat_mode()
{
	return this->get_member("InCombatMode");
}

ls_bool eq2_actor::get_in_my_group()
{
	return this->get_member("InMyGroup");
}

ls_bool eq2_actor::get_interactable()
{
	return this->get_member("Interactable");
}

ls_bool eq2_actor::get_is_afk()
{
	return this->get_member("IsAFK");
}

ls_bool eq2_actor::get_is_aggro()
{
	return this->get_member("IsAggro");
}

ls_bool eq2_actor::get_is_a_pet()
 {
	 return this->get_member("IsAPet");
 }

ls_bool eq2_actor::get_is_backing_up()
{
	return this->get_member("IsBackingUp");
}

ls_bool eq2_actor::get_is_banker()
 {
	 return this->get_member("IsBanker");
 }
 
ls_bool eq2_actor::get_is_camping()
{
	return this->get_member("IsCamping");
}

ls_bool eq2_actor::get_is_chest()
{
	return this->get_member("IsChest");
}

ls_bool eq2_actor::get_is_climbing()
{
	return this->get_member("IsClimbing");
}

ls_bool eq2_actor::get_is_crouching()
{
	return this->get_member("IsCrouching");
}

ls_bool eq2_actor::get_is_dead()
{
	return this->get_member("IsDead");
}

ls_bool eq2_actor::get_is_encounter_broken()
{
	return this->get_member("IsEncounterBroken");
}

ls_bool eq2_actor::get_is_epic()
{
	return this->get_member("IsEpic");
}

ls_bool eq2_actor::get_is_falling()
{
	return this->get_member("IsFalling");
}

ls_bool eq2_actor::get_is_fd()
{
	return this->get_member("IsFD");
}

ls_bool eq2_actor::get_is_heroic()
{
	return this->get_member("IsHeroic");
}

ls_bool eq2_actor::get_is_idle()
{
	return this->get_member("IsIdle");
}

ls_bool eq2_actor::get_is_invis()
{
	return this->get_member("IsInvis");
}

ls_bool eq2_actor::get_is_in_same_encounter(const unsigned int& actor_id)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", actor_id);
	argv[0] = buffer;	
	return this->get_member("IsInSameEncounter", argc, argv);
}

ls_bool eq2_actor::get_is_in_same_encounter_ls(const ls_int& actor_id)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%lld", ls_int(actor_id).get_value());
	argv[0] = buffer;
	return this->get_member("IsInSameEncounter", argc, argv);
}

ls_bool eq2_actor::get_is_jumping()
{
	return this->get_member("IsJumping");
}

ls_bool eq2_actor::get_is_lfg()
{
	return this->get_member("IsLFG");
}

ls_bool eq2_actor::get_is_lfw()
{
	return this->get_member("IsLFW");
}

ls_bool eq2_actor::get_is_linkdead()
{
	return this->get_member("IsLinkdead");
}

ls_bool eq2_actor::get_is_locked()
{
	return this->get_member("IsLocked");
}

ls_bool eq2_actor::get_is_merchant()
{
	return this->get_member("IsMerchant");
}

ls_bool eq2_actor::get_is_my_pet()
{
	return this->get_member("IsMyPet");
}

ls_bool eq2_actor::get_is_named()
{
	return this->get_member("IsNamed");
}

ls_bool eq2_actor::get_is_on_carpet()
{
	return this->get_member("IsOnCarpet");
}

ls_bool eq2_actor::get_is_on_horse()
{
	return this->get_member("IsOnHorse");
}

ls_bool eq2_actor::get_is_on_griffin()
{
	return this->get_member("IsOnGriffin");
}

ls_bool eq2_actor::get_is_rooted()
{
	return this->get_member("IsRooted");
}

ls_bool eq2_actor::get_is_running()
{
	return this->get_member("IsRunning");
}

ls_bool eq2_actor::get_is_sitting()
{
	return this->get_member("IsSitting");
}

ls_bool eq2_actor::get_is_solo()
{
	return this->get_member("IsSolo");
}

ls_bool eq2_actor::get_is_sprinting()
{
	return this->get_member("IsSprinting");
}

ls_bool eq2_actor::get_is_strafing_left()
{
	return this->get_member("IsStrafingLeft");
}

ls_bool eq2_actor::get_is_strafing_right()
{
	return this->get_member("IsStrafingRight");
}

ls_bool eq2_actor::get_is_swimming()
{
	return this->get_member("IsSwimming");
}

ls_bool eq2_actor::get_is_walking()
{
	return this->get_member("IsWalking");
}

ls_string eq2_actor::get_last_name()
{
	return this->get_member("LastName");
}

ls_int eq2_actor::get_level()
{
	return this->get_member("Level");
}

ls_point3_f eq2_actor::get_loc()
{
	return this->get_member("Loc");
}

eq2_actor eq2_actor::get_pet()
{
	return this->get_member("Pet");
}

ls_string eq2_actor::get_mood()
{
	return this->get_member("Mood");
}

ls_string eq2_actor::get_name()
{
	return this->get_member("Name");
}

ls_int eq2_actor::get_num_effects()
{
	return this->get_member("NumEffects");
}

ls_bool eq2_actor::get_on_flying_mount()
{
	return this->get_member("OnFlyingMount");
}

std::string eq2_actor::get_overlay()
{
	char* const member = static_cast<char *>("Overlay");
	return this->get_member(member).get_string_from_lso();
}

int eq2_actor::get_power()
{
	char* const member = static_cast<char *>("Power");
	return this->get_member(member).get_int_from_lso();
}

std::string eq2_actor::get_race()
{
	char* const member = static_cast<char *>("Race");
	return this->get_member(member).get_string_from_lso();
}

int eq2_actor::get_raid_size()
{
	char* const member = static_cast<char *>("RaidSize");
	return this->get_member(member).get_int_from_lso();
}

float eq2_actor::get_speed()
{
	char* const member = static_cast<char *>("Speed");
	return this->get_member(member).get_float_from_lso();
}

std::string eq2_actor::get_suffix_title()
{
	char* const member = static_cast<char *>("SuffixTitle");
	return this->get_member(member).get_string_from_lso();
}

float eq2_actor::get_swimming_speed_mod()
{
	char* const member = static_cast<char *>("SwimmingSpeedMod");
	return this->get_member(member).get_float_from_lso();
}

std::string eq2_actor::get_tag_target_icon()
{
	char* const member = static_cast<char *>("TagTargetIcon");
	return this->get_member(member).get_string_from_lso();
}

std::string eq2_actor::get_tag_target_number()
{
	char* const member = static_cast<char *>("TagTargetNumber");
	return this->get_member(member).get_string_from_lso();
}

eq2_actor eq2_actor::get_target()
{
	char* const member = static_cast<char *>("Target");
	const LSOBJECT target_object = this->get_member(member).get_lso();
	return target_object;
}

float eq2_actor::get_target_ring_radius()
{
	char* const member = static_cast<char *>("TargetRingRadius");
	return this->get_member(member).get_float_from_lso();
}

int eq2_actor::get_threat_to_me()
{
	char* const member = static_cast<char *>("ThreatToMe");
	return this->get_member(member).get_int_from_lso();
}

int eq2_actor::get_threat_to_next()
{
	char* const member = static_cast<char *>("ThreatToNext");
	return this->get_member(member).get_int_from_lso();
}

int eq2_actor::get_threat_to_pet()
{
	char* const member = static_cast<char *>("ThreatToPet");
	return this->get_member(member).get_int_from_lso();
}

unsigned int eq2_actor::get_tint_flags()
{
	char* const member = static_cast<char *>("TintFlags");
	return this->get_member(member).get_uint_from_lso();
}

std::string eq2_actor::get_type()
{
	char* const member = static_cast<char *>("Type");
	return this->get_member(member).get_string_from_lso();
}



// TODO: Find out why this member always returns 0.0, 0.0, 0.0
ls_point3_f eq2_actor::get_velocity()
{
	char* const member = static_cast<char *>("Velocity");
	const LSOBJECT velocity_object = this->get_member(member).get_lso();
	return velocity_object;
}

std::string eq2_actor::get_visual_variant()
{
	char* const member = static_cast<char *>("VisualVariant");
	return this->get_member(member).get_string_from_lso();
}

std::string eq2_actor::get_who_following()
{
	char* const member = static_cast<char *>("WhoFollowing");
	return this->get_member(member).get_string_from_lso();
}

int eq2_actor::get_who_following_id()
{
	char* const member = static_cast<char *>("WhoFollowingID");
	return this->get_member(member).get_int_from_lso();
}

float eq2_actor::get_x()
{
	char* const member = static_cast<char *>("X");
	return this->get_member(member).get_float_from_lso();
}

float eq2_actor::get_y()
{
	char* const member = static_cast<char *>("Y");
	return this->get_member(member).get_float_from_lso();
}

float eq2_actor::get_z()
{
	char* const member = static_cast<char *>("Z");
	return this->get_member(member).get_float_from_lso();
}

void eq2_actor::double_click()
{
	char* const method = static_cast<char *>("DoubleClick");
	return this->execute_method(method);
}

void eq2_actor::waypoint_to()
{
	char* const method = static_cast<char *>("WaypointTo");
	return this->execute_method(method);
}

void eq2_actor::do_face()
{
	char* const method = static_cast<char *>("DoFace");
	return this->execute_method(method);
}

void eq2_actor::do_target()
{
	char* const method = static_cast<char *>("DoTarget");
	return this->execute_method(method);
}

void eq2_actor::location(const bool& add_location, const std::string& notes)
{
	const int argc = 1;
	const int argc_notes = 2;
	char* argv[argc];
	char* argv_notes[argc_notes];
	char add_or_delete[MAX_VARSTRING];
	if (add_location)
		strcpy_s(add_or_delete, _countof(add_or_delete), "Add");
	else
		strcpy_s(add_or_delete, _countof(add_or_delete), "Delete");
	argv[0] = add_or_delete;
	argv_notes[0] = add_or_delete;
	if (!notes.empty())
		argv_notes[1] = const_cast<char *>(notes.c_str());
	char* const method = static_cast<char *>("Location");
	if (add_location && !notes.empty())
		this->execute_method(method, argc_notes, argv_notes);
	else
		this->execute_method(method, argc, argv);
}

void eq2_actor::request_effects_info()
{
	char* const method = static_cast<char *>("RequestEffectsInfo");
	return this->execute_method(method);
}

