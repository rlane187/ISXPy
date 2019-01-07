#pragma once

struct eq2_actor_spawned_args : eq2_actor_despawned_args
{
	unsigned int get_level() const;
	void set_level(const unsigned int& level);
	std::string get_type() const;
	void set_type(const std::string& type);
private:
	unsigned int level_ = 0;
	std::string type_{};
};