#include "ISXPyPCH.h"
#include "ISXPy.h"

py_actor::py_actor(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

py_actor py_actor::from_id(const unsigned int& actor_id)
{
	LSOBJECT ls_object;
	const int argc_id = 1;
	char* argv_id[argc_id];
	char buffer_id[MAX_VARSTRING];
	sprintf_s(buffer_id, _countof(buffer_id), "%u", actor_id);
	argv_id[0] = buffer_id;
	try
	{
		pISInterface->IsTopLevelObject("Actor")(argc_id, argv_id, ls_object);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return ls_object;
}

py_actor py_actor::from_query(const std::string& query)
{
	LSOBJECT ls_object;
	const int argc_query = 2;
	char* argv_query[argc_query];
	char buffer_query[MAX_VARSTRING];
	strcpy_s(buffer_query, _countof(buffer_query), query.c_str());
	argv_query[0] = const_cast<char *>("Query");
	argv_query[1] = buffer_query;
	try
	{
		pISInterface->IsTopLevelObject("Actor")(argc_query, argv_query, ls_object);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return ls_object;
}

std::string py_actor::get_aura()
{
	char* const member = static_cast<char *>("Aura");
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

bool py_actor::check_collision(const float& to_x, const float& to_y, const float& to_z)
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
		if (to_x == NULL || to_y == NULL || to_z == NULL)
			return this->get_member(member, 0, nullptr).get_bool_from_lso();
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return false;
}

bool py_actor::get_can_turn()
{
	char* const member = static_cast<char *>("CanTurn");
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

std::string py_actor::get_class()
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

float py_actor::get_collision_radius()
{
	char* const member = static_cast<char *>("CollisionRadius");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

float py_actor::get_collision_scale()
{
	char* const member = static_cast<char *>("CollisionScale");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

std::string py_actor::get_con_color(const bool& as_rgb)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("raw");
	char* const member = static_cast<char *>("ConColor");
	try
	{
		if(as_rgb)
			return this->get_member(member, argc, argv).get_string_from_lso();
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return std::string("Error");
}

std::string py_actor::get_current_animation()
{
	char* const member = static_cast<char *>("CurrentAnimation");
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

int py_actor::get_difficulty()
{
	char* const member = static_cast<char *>("Difficulty");
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

float py_actor::get_distance()
{
	char* const member = static_cast<char *>("Distance");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

float py_actor::get_distance2d()
{
	char* const member = static_cast<char *>("Distance2D");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

int py_actor::get_effects(boost::python::list& effect_list)
{
	char* const count_effect_string = static_cast<char *>("NumEffects");
	char* const effect_string = static_cast<char *>("Effect");
	try
	{
		const int count_effects = this->get_member(count_effect_string, 0, nullptr).get_int_from_lso();
		for (int i = 1; i <= count_effects; i++)
		{
			const int argc = 1;
			char* argv[argc];
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, _countof(buffer), "%d", i);
			argv[0] = const_cast<char*>(buffer);
			effect_list.append(py_actor_effect(this->get_member(effect_string, argc, argv).get_lso()));
		}
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return len(effect_list);
}

int py_actor::get_effective_level()
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

int py_actor::get_encounter_size()
{
	char* const member = static_cast<char *>("EncounterSize");
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

int py_actor::get_faction()
{
	char* const member = static_cast<char *>("Faction");
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

std::string py_actor::get_faction_standing()
{
	char* const member = static_cast<char *>("FactionStanding");
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

bool py_actor::get_flying_using_mount()
{
	char* const member = static_cast<char *>("FlyingUsingMount");
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

std::string py_actor::get_gender()
{
	char* const member = static_cast<char *>("Gender");
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

std::string py_actor::get_guild()
{
	char* const member = static_cast<char *>("Guild");
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

float py_actor::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

float py_actor::get_heading_to()
{
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

std::string py_actor::get_heading_to_as_compass_bearing()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("AsString");
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_string_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return std::string("Error");
}

int py_actor::get_health()
{
	char* const member = static_cast<char *>("Health");
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

unsigned int py_actor::get_id()
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

bool py_actor::get_in_combat_mode()
{
	char* const member = static_cast<char *>("InCombatMode");
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

bool py_actor::get_in_my_group()
{
	char* const member = static_cast<char *>("InMyGroup");
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

bool py_actor::get_interactable()
{
	char* const member = static_cast<char *>("Interactable");
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

bool py_actor::get_is_afk()
{
	char* const member = static_cast<char *>("IsAFK");
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

bool py_actor::get_is_aggro()
{
	char* const member = static_cast<char *>("IsAggro");
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

bool py_actor::get_is_a_pet()
 {
	 char* const member = static_cast<char *>("IsAPet");
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

bool py_actor::get_is_backing_up()
{
	char* const member = static_cast<char *>("IsBackingUp");
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

bool py_actor::get_is_banker()
 {
	 char* const member = static_cast<char *>("IsBanker");
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
 
bool py_actor::get_is_camping()
{
	char* const member = static_cast<char *>("IsCamping");
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

bool py_actor::get_is_chest()
{
	char* const member = static_cast<char *>("IsChest");
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

bool py_actor::get_is_climbing()
{
	char* const member = static_cast<char *>("IsClimbing");
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

bool py_actor::get_is_crouching()
{
	char* const member = static_cast<char *>("IsCrouching");
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

bool py_actor::get_is_dead()
{
	char* const member = static_cast<char *>("IsDead");
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

bool py_actor::get_is_encounter_broken()
{
	char* const member = static_cast<char *>("IsEncounterBroken");
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

bool py_actor::get_is_epic()
{
	char* const member = static_cast<char *>("IsEpic");
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

bool py_actor::get_is_falling()
{
	char* const member = static_cast<char *>("IsFalling");
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

bool py_actor::get_is_fd()
{
	char* const member = static_cast<char *>("IsFD");
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

bool py_actor::get_is_heroic()
{
	char* const member = static_cast<char *>("IsHeroic");
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

bool py_actor::get_is_idle()
{
	char* const member = static_cast<char *>("IsIdle");
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

bool py_actor::get_is_invis()
{
	char* const member = static_cast<char *>("IsInvis");
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

bool py_actor::get_is_in_same_encounter(const unsigned int& actor_id)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", actor_id);
	argv[0] = buffer;	
	char* const member = static_cast<char *>("IsInSameEncounter");
	try
	{
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return false;
}

bool py_actor::get_is_jumping()
{
	char* const member = static_cast<char *>("IsJumping");
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

bool py_actor::get_is_lfg()
{
	char* const member = static_cast<char *>("IsLFG");
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

bool py_actor::get_is_lfw()
{
	char* const member = static_cast<char *>("IsLFW");
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

bool py_actor::get_is_linkdead()
{
	char* const member = static_cast<char *>("IsLinkdead");
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

bool py_actor::get_is_locked()
{
	char* const member = static_cast<char *>("IsLocked");
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

bool py_actor::get_is_merchant()
{
	char* const member = static_cast<char *>("IsMerchant");
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

bool py_actor::get_is_my_pet()
{
	char* const member = static_cast<char *>("IsMyPet");
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

bool py_actor::get_is_named()
{
	char* const member = static_cast<char *>("IsNamed");
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

bool py_actor::get_is_on_carpet()
{
	char* const member = static_cast<char *>("IsOnCarpet");
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

bool py_actor::get_is_on_horse()
{
	char* const member = static_cast<char *>("IsOnHorse");
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

bool py_actor::get_is_on_griffin()
{
	char* const member = static_cast<char *>("IsOnGriffin");
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

bool py_actor::get_is_rooted()
{
	char* const member = static_cast<char *>("IsRooted");
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

bool py_actor::get_is_running()
{
	char* const member = static_cast<char *>("IsRunning");
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

bool py_actor::get_is_sitting()
{
	char* const member = static_cast<char *>("IsSitting");
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

bool py_actor::get_is_solo()
{
	char* const member = static_cast<char *>("IsSolo");
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

bool py_actor::get_is_sprinting()
{
	char* const member = static_cast<char *>("IsSprinting");
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

bool py_actor::get_is_strafing_left()
{
	char* const member = static_cast<char *>("IsStrafingLeft");
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

bool py_actor::get_is_strafing_right()
{
	char* const member = static_cast<char *>("IsStrafingRight");
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

bool py_actor::get_is_swimming()
{
	char* const member = static_cast<char *>("IsSwimming");
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

bool py_actor::get_is_walking()
{
	char* const member = static_cast<char *>("IsWalking");
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

std::string py_actor::get_last_name()
{
	char* const member = static_cast<char *>("LastName");
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

int py_actor::get_level()
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

py_point3f py_actor::get_loc()
{
	py_point3f loc;
	char* const member = static_cast<char *>("Loc");
	try
	{
		loc = py_point3f(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return loc;
}

py_actor py_actor::get_pet()
{
	py_actor pet;
	char* const member = static_cast<char *>("Pet");
	try
	{
		pet = py_actor(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return pet;
}

std::string py_actor::get_mood()
{
	char* const member = static_cast<char *>("Mood");
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

std::string py_actor::get_name()
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

int py_actor::get_num_effects()
{
	char* const member = static_cast<char *>("NumEffects");
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

bool py_actor::get_on_flying_mount()
{
	char* const member = static_cast<char *>("OnFlyingMount");
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

std::string py_actor::get_overlay()
{
	char* const member = static_cast<char *>("Overlay");
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

int py_actor::get_power()
{
	char* const member = static_cast<char *>("Power");
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

std::string py_actor::get_race()
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

int py_actor::get_raid_size()
{
	char* const member = static_cast<char *>("RaidSize");
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

float py_actor::get_speed()
{
	char* const member = static_cast<char *>("Speed");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

std::string py_actor::get_suffix_title()
{
	char* const member = static_cast<char *>("SuffixTitle");
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

float py_actor::get_swimming_speed_mod()
{
	char* const member = static_cast<char *>("SwimmingSpeedMod");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

std::string py_actor::get_tag_target_icon()
{
	char* const member = static_cast<char *>("TagTargetIcon");
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

std::string py_actor::get_tag_target_number()
{
	char* const member = static_cast<char *>("TagTargetNumber");
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

py_actor py_actor::get_target()
{
	py_actor pet;
	char* const member = static_cast<char *>("Target");
	try
	{
		pet = py_actor(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return pet;
}

float py_actor::get_target_ring_radius()
{
	char* const member = static_cast<char *>("TargetRingRadius");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

int py_actor::get_threat_to_me()
{
	char* const member = static_cast<char *>("ThreatToMe");
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

int py_actor::get_threat_to_next()
{
	char* const member = static_cast<char *>("ThreatToNext");
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

int py_actor::get_threat_to_pet()
{
	char* const member = static_cast<char *>("ThreatToPet");
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

unsigned int py_actor::get_tint_flags()
{
	char* const member = static_cast<char *>("TintFlags");
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

std::string py_actor::get_type()
{
	char* const member = static_cast<char *>("Type");
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



// TODO: Find out why this member always returns 0.0, 0.0, 0.0
py_point3f py_actor::get_velocity()
{
	py_point3f velocity;
	char* const member = static_cast<char *>("Velocity");
	try
	{
		velocity = py_point3f(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return velocity;
}

std::string py_actor::get_visual_variant()
{
	char* const member = static_cast<char *>("VisualVariant");
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

std::string py_actor::get_who_following()
{
	char* const member = static_cast<char *>("WhoFollowing");
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

int py_actor::get_who_following_id()
{
	char* const member = static_cast<char *>("WhoFollowingID");
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

float py_actor::get_x()
{
	char* const member = static_cast<char *>("X");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

float py_actor::get_y()
{
	char* const member = static_cast<char *>("Y");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

float py_actor::get_z()
{
	char* const member = static_cast<char *>("Z");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
	return FLT_MAX;
}

void py_actor::double_click()
{
	char* const method = static_cast<char *>("DoubleClick");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
}

void py_actor::waypoint_to()
{
	char* const method = static_cast<char *>("WaypointTo");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
}

void py_actor::do_face()
{
	char* const method = static_cast<char *>("DoFace");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
}

void py_actor::do_target()
{
	char* const method = static_cast<char *>("DoTarget");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
}

void py_actor::location(const bool& add_location, const std::string& notes)
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
	try
	{
		if(add_location && !notes.empty())
			this->execute_method(method, argc_notes, argv_notes);
		else
			this->execute_method(method, argc, argv);
	}
	catch (boost::python::error_already_set&)
	{
		PyErr_Print();
	}	
}

void py_actor::request_effects_info()
{
	char* const method = static_cast<char *>("RequestEffectsInfo");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (boost::python::error_already_set &)
	{
		PyErr_Print();
	}
}