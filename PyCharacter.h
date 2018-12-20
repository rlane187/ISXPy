#pragma once

class PyCharacter : public LSObject
{
public:
	PyCharacter();
	bool check_collision(float to_x, float to_y, float to_z);
	std::string get_archetype();
	bool get_at_char_select();	
	int get_base_strength();
	float get_breath();
	std::string get_class();
	int64_t get_current_health();
	int get_current_power();
	int get_effective_level();
	int get_exp_current();
	int get_exp_next_level();
	float get_exp_percent();
	std::string get_gender();
	float get_heading();
	int get_health_regen();
	bool get_in_game_world();
	bool get_is_moving();
	int get_level();
	int get_max_conc();
	int64_t get_max_health();
	int get_max_power();
	std::string get_name();
	int get_power_regen();
	std::string get_race();
	std::string get_subclass();
	int get_strength();
	std::string get_ts_archetype();
	std::string get_ts_class();
	int get_ts_level();
	std::string get_ts_subclass();
	int get_used_conc();
	float get_water_depth();
	float get_x();
	float get_y();
	float get_z();
	float heading_to(float to_x, float to_y, float to_z);
	std::string heading_to_as_compass_bearing(float to_x, float to_y, float to_z);
};
