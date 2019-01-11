#include "ISXPyPCH.h"
#include "ISXPy.h"

py_mutable_string::py_mutable_string() = default;

py_mutable_string::py_mutable_string(const py_mutable_string& other) = default;

py_mutable_string::py_mutable_string(py_mutable_string&& other) noexcept = default;

py_mutable_string::py_mutable_string(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_mutable_string::~py_mutable_string() = default;

py_mutable_string& py_mutable_string::operator=(const py_mutable_string& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_mutable_string& py_mutable_string::operator=(py_mutable_string&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

std::string py_mutable_string::get_string()
{
	char* const member = static_cast<char *>("String");
	return ls_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

void py_mutable_string::set(const std::string& text)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), text.c_str());
	argv[0] = buffer;
	char* const member = static_cast<char *>("Set");
	this->execute_method(member, argc, argv);
}

void py_mutable_string::concat(const std::string& text)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), text.c_str());
	argv[0] = buffer;
	char* const member = static_cast<char *>("Concat");
	this->execute_method(member, argc, argv);
}

void py_mutable_string::to_upper()
{
	char* const member = static_cast<char *>("ToUpper");
	this->execute_method(member, 0, nullptr);
}

void py_mutable_string::to_lower()
{
	char* const member = static_cast<char *>("ToLower");
	this->execute_method(member, 0, nullptr);
}