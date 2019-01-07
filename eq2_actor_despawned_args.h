#pragma once

struct eq2_actor_despawned_args
{
	unsigned int get_id() const;
	void set_id(const unsigned int& id);
	std::string get_name() const;
	void set_name(const std::string& name);
private:
	unsigned int id_ = 0;
	std::string name_{};
};