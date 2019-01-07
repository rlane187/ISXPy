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
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}