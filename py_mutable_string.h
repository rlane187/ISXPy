#pragma once

class py_mutable_string : public py_lsobject
{
public:
	py_mutable_string();
	~py_mutable_string();
	py_mutable_string(const py_mutable_string& other);
	py_mutable_string(py_mutable_string&& other) noexcept;
	py_mutable_string(const LSOBJECT& other);
	py_mutable_string& operator=(const py_mutable_string& other);
	py_mutable_string& operator=(py_mutable_string&& other) noexcept;
	std::string get_string();
};