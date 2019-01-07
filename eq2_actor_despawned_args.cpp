#include "ISXPyPCH.h"
#include "ISXPy.h"

unsigned int eq2_actor_despawned_args::get_id() const
{
	return this->id_;
}

void eq2_actor_despawned_args::set_id(const unsigned& id)
{
	this->id_ = id;
}

std::string eq2_actor_despawned_args::get_name() const
{
	return this->name_;
}

void eq2_actor_despawned_args::set_name(const std::string& name)
{
	this->name_ = name;
}