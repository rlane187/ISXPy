#pragma once

class PyActor : public LSObject
{
public:
	PyActor() = default;
	PyActor(LSOBJECT& ls_object);
	std::string get_name();
};