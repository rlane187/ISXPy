#include "ISXPyPCH.h"
#include "ISXPy.h"

std::string eq2_on_quest_offered_args::get_name() const
{
	return this->name_;
}

void eq2_on_quest_offered_args::set_name(const std::string& name)
{
	this->name_ = name;
}

std::string eq2_on_quest_offered_args::get_description() const
{
	return this->description_;
}

void eq2_on_quest_offered_args::set_description(const std::string& description)
{
	this->description_ = description;
}

unsigned int eq2_on_quest_offered_args::get_level() const
{
	return this->level_;
}

void eq2_on_quest_offered_args::set_level(const unsigned int& level)
{
	this->level_ = level;
}

unsigned int eq2_on_quest_offered_args::get_status_reward() const
{
	return this->status_reward_;
}

void eq2_on_quest_offered_args::set_status_reward(const unsigned int& status_reward)
{
	this->status_reward_ = status_reward;
}