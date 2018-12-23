#pragma once

class PyEffectInfo : public PyLSObject
{
public:
	PyEffectInfo() = default;
	PyEffectInfo(const LSOBJECT& ls_object);
	std::string get_description();
	std::string get_name();
	std::string get_type();
};