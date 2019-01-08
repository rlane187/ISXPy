#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2_actor::py_eq2_actor() = default;

py_eq2_actor::~py_eq2_actor() = default;

py_eq2_actor::py_eq2_actor(const py_eq2_actor& other) = default;

py_eq2_actor::py_eq2_actor(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_eq2_actor::py_eq2_actor(const unsigned int& actor_id)
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

py_eq2_actor::py_eq2_actor(const std::string& query)
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

py_eq2_actor::py_eq2_actor(py_eq2_actor&& other) noexcept = default;

py_eq2_actor& py_eq2_actor::operator=(const py_eq2_actor& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2_actor& py_eq2_actor::operator=(py_eq2_actor&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2_actor py_eq2_actor::from_id(const unsigned int& actor_id)
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

py_eq2_actor py_eq2_actor::from_query(const std::string& query)
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

std::string py_eq2_actor::get_aura()
{
	char* const member = static_cast<char *>("Aura");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

bool py_eq2_actor::check_collision(const float& to_x, const float& to_y, const float& to_z)
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
	if (to_x == NULL || to_y == NULL || to_z == NULL)
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	return this->get_member(member, argc, argv).get_bool_from_lso();
}

bool py_eq2_actor::get_can_turn()
{
	char* const member = static_cast<char *>("CanTurn");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2_actor::get_class()
{
	char* const member = static_cast<char *>("Class");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_eq2_actor::get_collision_radius()
{
	char* const member = static_cast<char *>("CollisionRadius");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2_actor::get_collision_scale()
{
	char* const member = static_cast<char *>("CollisionScale");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_eq2_actor::get_con_color(const bool& as_rgb)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("raw");
	char* const member = static_cast<char *>("ConColor");
	if (as_rgb)
		return this->get_member(member, argc, argv).get_string_from_lso();
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_actor::get_current_animation()
{
	char* const member = static_cast<char *>("CurrentAnimation");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2_actor::get_difficulty()
{
	char* const member = static_cast<char *>("Difficulty");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_eq2_actor::get_distance()
{
	char* const member = static_cast<char *>("Distance");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2_actor::get_distance2d()
{
	char* const member = static_cast<char *>("Distance2D");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_eq2_actor::get_effects(boost::python::list& effect_list)
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

int py_eq2_actor::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor::get_encounter_size()
{
	char* const member = static_cast<char *>("EncounterSize");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor::get_faction()
{
	char* const member = static_cast<char *>("Faction");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_eq2_actor::get_faction_standing()
{
	char* const member = static_cast<char *>("FactionStanding");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

bool py_eq2_actor::get_flying_using_mount()
{
	char* const member = static_cast<char *>("FlyingUsingMount");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2_actor::get_gender()
{
	char* const member = static_cast<char *>("Gender");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_actor::get_guild()
{
	char* const member = static_cast<char *>("Guild");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_eq2_actor::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2_actor::get_heading_to()
{
	char* const member = static_cast<char *>("HeadingTo");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_eq2_actor::get_heading_to_as_compass_bearing()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("AsString");
	char* const member = static_cast<char *>("HeadingTo");
	return this->get_member(member, argc, argv).get_string_from_lso();
}

int py_eq2_actor::get_health()
{
	char* const member = static_cast<char *>("Health");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

unsigned int py_eq2_actor::get_id()
{
	char* const member = static_cast<char *>("ID");
	return this->get_member(member, 0, nullptr).get_uint_from_lso();
}

bool py_eq2_actor::get_in_combat_mode()
{
	char* const member = static_cast<char *>("InCombatMode");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_in_my_group()
{
	char* const member = static_cast<char *>("InMyGroup");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_interactable()
{
	char* const member = static_cast<char *>("Interactable");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_afk()
{
	char* const member = static_cast<char *>("IsAFK");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_aggro()
{
	char* const member = static_cast<char *>("IsAggro");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_a_pet()
 {
	 char* const member = static_cast<char *>("IsAPet");
	 return this->get_member(member, 0, nullptr).get_bool_from_lso();
 }

bool py_eq2_actor::get_is_backing_up()
{
	char* const member = static_cast<char *>("IsBackingUp");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_banker()
 {
	 char* const member = static_cast<char *>("IsBanker");
	 return this->get_member(member, 0, nullptr).get_bool_from_lso();
 }
 
bool py_eq2_actor::get_is_camping()
{
	char* const member = static_cast<char *>("IsCamping");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_chest()
{
	char* const member = static_cast<char *>("IsChest");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_climbing()
{
	char* const member = static_cast<char *>("IsClimbing");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_crouching()
{
	char* const member = static_cast<char *>("IsCrouching");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_dead()
{
	char* const member = static_cast<char *>("IsDead");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_encounter_broken()
{
	char* const member = static_cast<char *>("IsEncounterBroken");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_epic()
{
	char* const member = static_cast<char *>("IsEpic");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_falling()
{
	char* const member = static_cast<char *>("IsFalling");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_fd()
{
	char* const member = static_cast<char *>("IsFD");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_heroic()
{
	char* const member = static_cast<char *>("IsHeroic");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_idle()
{
	char* const member = static_cast<char *>("IsIdle");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_invis()
{
	char* const member = static_cast<char *>("IsInvis");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_in_same_encounter(const unsigned int& actor_id)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", actor_id);
	argv[0] = buffer;	
	char* const member = static_cast<char *>("IsInSameEncounter");
	return this->get_member(member, argc, argv).get_bool_from_lso();
}

bool py_eq2_actor::get_is_jumping()
{
	char* const member = static_cast<char *>("IsJumping");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_lfg()
{
	char* const member = static_cast<char *>("IsLFG");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_lfw()
{
	char* const member = static_cast<char *>("IsLFW");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_linkdead()
{
	char* const member = static_cast<char *>("IsLinkdead");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_locked()
{
	char* const member = static_cast<char *>("IsLocked");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_merchant()
{
	char* const member = static_cast<char *>("IsMerchant");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_my_pet()
{
	char* const member = static_cast<char *>("IsMyPet");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_named()
{
	char* const member = static_cast<char *>("IsNamed");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_on_carpet()
{
	char* const member = static_cast<char *>("IsOnCarpet");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_on_horse()
{
	char* const member = static_cast<char *>("IsOnHorse");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_on_griffin()
{
	char* const member = static_cast<char *>("IsOnGriffin");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_rooted()
{
	char* const member = static_cast<char *>("IsRooted");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_running()
{
	char* const member = static_cast<char *>("IsRunning");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_sitting()
{
	char* const member = static_cast<char *>("IsSitting");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_solo()
{
	char* const member = static_cast<char *>("IsSolo");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_sprinting()
{
	char* const member = static_cast<char *>("IsSprinting");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_strafing_left()
{
	char* const member = static_cast<char *>("IsStrafingLeft");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_strafing_right()
{
	char* const member = static_cast<char *>("IsStrafingRight");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_swimming()
{
	char* const member = static_cast<char *>("IsSwimming");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

bool py_eq2_actor::get_is_walking()
{
	char* const member = static_cast<char *>("IsWalking");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2_actor::get_last_name()
{
	char* const member = static_cast<char *>("LastName");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2_actor::get_level()
{
	char* const member = static_cast<char *>("Level");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

py_point3_f py_eq2_actor::get_loc()
{
	char* const member = static_cast<char *>("Loc");
	const LSOBJECT loc_object = this->get_member(member, 0, nullptr).get_lso();
	return loc_object;
}

py_eq2_actor py_eq2_actor::get_pet()
{
	char* const member = static_cast<char *>("Pet");
	const LSOBJECT pet_object = this->get_member(member, 0, nullptr).get_lso();
	return pet_object;
}

std::string py_eq2_actor::get_mood()
{
	char* const member = static_cast<char *>("Mood");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_actor::get_name()
{
	std::string result("NULL");
	if(this->lsobject_.ObjectType)
	{
		char* const member = static_cast<char *>("Name");
		result = this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	return result;
}

int py_eq2_actor::get_num_effects()
{
	char* const member = static_cast<char *>("NumEffects");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_eq2_actor::get_on_flying_mount()
{
	char* const member = static_cast<char *>("OnFlyingMount");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2_actor::get_overlay()
{
	char* const member = static_cast<char *>("Overlay");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2_actor::get_power()
{
	char* const member = static_cast<char *>("Power");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_eq2_actor::get_race()
{
	char* const member = static_cast<char *>("Race");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2_actor::get_raid_size()
{
	char* const member = static_cast<char *>("RaidSize");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_eq2_actor::get_speed()
{
	char* const member = static_cast<char *>("Speed");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_eq2_actor::get_suffix_title()
{
	char* const member = static_cast<char *>("SuffixTitle");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_eq2_actor::get_swimming_speed_mod()
{
	char* const member = static_cast<char *>("SwimmingSpeedMod");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

std::string py_eq2_actor::get_tag_target_icon()
{
	char* const member = static_cast<char *>("TagTargetIcon");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_actor::get_tag_target_number()
{
	char* const member = static_cast<char *>("TagTargetNumber");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

py_eq2_actor py_eq2_actor::get_target()
{
	char* const member = static_cast<char *>("Target");
	const LSOBJECT target_object = this->get_member(member, 0, nullptr).get_lso();
	return target_object;
}

float py_eq2_actor::get_target_ring_radius()
{
	char* const member = static_cast<char *>("TargetRingRadius");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_eq2_actor::get_threat_to_me()
{
	char* const member = static_cast<char *>("ThreatToMe");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor::get_threat_to_next()
{
	char* const member = static_cast<char *>("ThreatToNext");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2_actor::get_threat_to_pet()
{
	char* const member = static_cast<char *>("ThreatToPet");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

unsigned int py_eq2_actor::get_tint_flags()
{
	char* const member = static_cast<char *>("TintFlags");
	return this->get_member(member, 0, nullptr).get_uint_from_lso();
}

std::string py_eq2_actor::get_type()
{
	char* const member = static_cast<char *>("Type");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}



// TODO: Find out why this member always returns 0.0, 0.0, 0.0
py_point3_f py_eq2_actor::get_velocity()
{
	char* const member = static_cast<char *>("Velocity");
	const LSOBJECT velocity_object = this->get_member(member, 0, nullptr).get_lso();
	return velocity_object;
}

std::string py_eq2_actor::get_visual_variant()
{
	char* const member = static_cast<char *>("VisualVariant");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2_actor::get_who_following()
{
	char* const member = static_cast<char *>("WhoFollowing");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2_actor::get_who_following_id()
{
	char* const member = static_cast<char *>("WhoFollowingID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_eq2_actor::get_x()
{
	char* const member = static_cast<char *>("X");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2_actor::get_y()
{
	char* const member = static_cast<char *>("Y");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2_actor::get_z()
{
	char* const member = static_cast<char *>("Z");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

void py_eq2_actor::double_click()
{
	char* const method = static_cast<char *>("DoubleClick");
	return this->execute_method(method, 0, nullptr);
}

void py_eq2_actor::waypoint_to()
{
	char* const method = static_cast<char *>("WaypointTo");
	return this->execute_method(method, 0, nullptr);
}

void py_eq2_actor::do_face()
{
	char* const method = static_cast<char *>("DoFace");
	return this->execute_method(method, 0, nullptr);
}

void py_eq2_actor::do_target()
{
	char* const method = static_cast<char *>("DoTarget");
	return this->execute_method(method, 0, nullptr);
}

void py_eq2_actor::location(const bool& add_location, const std::string& notes)
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

void py_eq2_actor::request_effects_info()
{
	char* const method = static_cast<char *>("RequestEffectsInfo");
	return this->execute_method(method, 0, nullptr);
}

py_string py_eq2_actor::get_name_lso()
{
	char* const member = static_cast<char *>("Name");
	return py_string(this->get_member(member, 0, nullptr).get_lso());
}
