#pragma once

class py_effect_info : public py_lsobject
{
public:
	py_effect_info() = default;
	py_effect_info(const LSOBJECT& ls_object);
	std::string get_description();
	std::string get_name();
	std::string get_type();
};