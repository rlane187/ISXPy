#pragma once

class PyEffectInfo : public LSObject
{
public:
	PyEffectInfo() = default;
	PyEffectInfo(LSOBJECT& ls_object);
	std::string get_description();
	std::string get_name();
	std::string get_type();
};