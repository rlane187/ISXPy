#pragma once

class PyEQ2DynamicData : public PyLSObject
{
public:
	PyEQ2DynamicData() = default;
	PyEQ2DynamicData(const LSOBJECT& ls_object);
	std::string get_label();
	float get_percent();
};