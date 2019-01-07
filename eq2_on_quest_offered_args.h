#pragma once

struct eq2_on_quest_offered_args
{
	std::string get_name() const;
	void set_name(const std::string& name);
	std::string get_description() const;
	void set_description(const std::string& description);
	unsigned int get_level() const;
	void set_level(const unsigned int& level);
	unsigned int get_status_reward() const;
	void set_status_reward(const unsigned int& level);
private:
	std::string name_{};
	std::string description_{};
	unsigned int level_ = 0;
	unsigned int status_reward_ = 0;
};