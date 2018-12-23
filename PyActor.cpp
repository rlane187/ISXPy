#include "ISXPyPCH.h"
#include "ISXPy.h"

PyActor::PyActor(const LSOBJECT& ls_object)
{
	this->ls_object_ = ls_object;
}

std::string PyActor::get_aura()
{
	char* const member = static_cast<char *>("Aura");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

bool PyActor::check_collision(const float& to_x, const float& to_y, const float& to_z)
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
	catch (exception &) {}
	return false;
}

std::string PyActor::get_class()
{
	char* const member = static_cast<char *>("Class");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_con_color(const bool& as_rgb)
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
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_current_animation()
{
	char* const member = static_cast<char *>("CurrentAnimation");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float PyActor::get_distance()
{
	char* const member = static_cast<char *>("Distance");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyActor::get_distance2d()
{
	char* const member = static_cast<char *>("Distance2D");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

int PyActor::get_effective_level()
{
	char* const member = static_cast<char *>("EffectiveLevel");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyActor::get_faction()
{
	char* const member = static_cast<char *>("Faction");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyActor::get_faction_standing()
{
	char* const member = static_cast<char *>("FactionStanding");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_gender()
{
	char* const member = static_cast<char *>("Gender");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_guild()
{
	char* const member = static_cast<char *>("Guild");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float PyActor::get_heading()
{
	char* const member = static_cast<char *>("Heading");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyActor::get_heading_to()
{
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

std::string PyActor::get_heading_to_as_compass_bearing()
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>("AsString");
	char* const member = static_cast<char *>("HeadingTo");
	try
	{
		return this->get_member(member, argc, argv).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyActor::get_health()
{
	char* const member = static_cast<char *>("Health");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

unsigned int PyActor::get_id()
{
	char* const member = static_cast<char *>("ID");
	try
	{
		return this->get_member(member, 0, nullptr).get_uint_from_lso();
	}
	catch (exception &) {}
	return UINT_MAX;
}

std::string PyActor::get_last_name()
{
	char* const member = static_cast<char *>("LastName");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyActor::get_level()
{
	char* const member = static_cast<char *>("Level");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

PyPoint3f PyActor::get_loc()
{
	PyPoint3f loc;
	char* const member = static_cast<char *>("Loc");
	try
	{
		loc = PyPoint3f(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception&) {}
	return loc;
}

PyActor PyActor::get_pet()
{
	PyActor pet;
	char* const member = static_cast<char *>("Pet");
	try
	{
		pet = PyActor(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception&) { }
	return pet;
}

std::string PyActor::get_mood()
{
	char* const member = static_cast<char *>("Mood");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}


std::string PyActor::get_name()
{
	char* const member = static_cast<char *>("Name");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_overlay()
{
	char* const member = static_cast<char *>("Overlay");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int PyActor::get_power()
{
	char* const member = static_cast<char *>("Power");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

std::string PyActor::get_race()
{
	char* const member = static_cast<char *>("Race");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

std::string PyActor::get_suffix_title()
{
	char* const member = static_cast<char *>("SuffixTitle");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

PyActor PyActor::get_target()
{
	PyActor pet;
	char* const member = static_cast<char *>("Target");
	try
	{
		pet = PyActor(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception&) {}
	return pet;
}

int PyActor::get_threat_to_me()
{
	char* const member = static_cast<char *>("ThreatToMe");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyActor::get_threat_to_next()
{
	char* const member = static_cast<char *>("ThreatToNext");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

int PyActor::get_threat_to_pet()
{
	char* const member = static_cast<char *>("ThreatToPet");
	try
	{
		return this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception &) {}
	return INT_MAX;
}

unsigned PyActor::get_tint_flags()
{
	char* const member = static_cast<char *>("TintFlags");
	try
	{
		return this->get_member(member, 0, nullptr).get_uint_from_lso();
	}
	catch (exception &) {}
	return UINT_MAX;
}

std::string PyActor::get_type()
{
	char* const member = static_cast<char *>("Type");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

// TODO: Find out why this member always returns 0.0, 0.0, 0.0
PyPoint3f PyActor::get_velocity()
{
	PyPoint3f velocity;
	char* const member = static_cast<char *>("Velocity");
	try
	{
		velocity = PyPoint3f(this->get_member(member, 0, nullptr).get_lso());
	}
	catch (exception&) {}
	return velocity;
}

std::string PyActor::get_visual_variant()
{
	char* const member = static_cast<char *>("VisualVariant");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

float PyActor::get_x()
{

	char* const member = static_cast<char *>("X");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyActor::get_y()
{
	char* const member = static_cast<char *>("Y");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}

float PyActor::get_z()
{
	char* const member = static_cast<char *>("Z");
	try
	{
		return this->get_member(member, 0, nullptr).get_float_from_lso();
	}
	catch (exception &) {}
	return FLT_MAX;
}