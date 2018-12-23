#pragma once

class PyEffect : public PyLSObject
{
public:
	PyEffect() = default;
	PyEffect(const LSOBJECT& ls_object);	
	int get_back_drop_icon_id();
	int get_current_increments();
	float get_duration();
	PyEffectInfo get_effect_info();
	int get_id();
	bool get_is_effect_info_available();
	int get_main_icon_id();
	float get_max_duration();	
	std::string get_type();
};