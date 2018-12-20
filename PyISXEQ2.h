#pragma once

class PyISXEQ2 : public TLOBase
{
public:
	std::string get_version() const;
	std::string get_api_version() const;
	bool get_is_ready() const;
	PyISXEQ2();
	void popup(std::string message, std::string title, std::string status) const;
};
