#include "ISXPyPCH.h"
#include "ISXPy.h"

unsigned int eq2_actor_spawned_args::get_level() const
{
	return this->level_;
}

void eq2_actor_spawned_args::set_level(const unsigned& level)
{
	this->level_ = level;
}

std::string eq2_actor_spawned_args::get_type() const
{
	return this->type_;
}

void eq2_actor_spawned_args::set_type(const std::string& type)
{
	this->type_ = type;
}
