#pragma once

class py_eq2_dynamic_data : public py_lsobject
{
public:
	py_eq2_dynamic_data() = default;
	py_eq2_dynamic_data(const LSOBJECT& ls_object);
	std::string get_label();
	float get_percent();
};