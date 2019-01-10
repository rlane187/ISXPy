#pragma once

class py_mutable_string : public ls_object
{
public:
	py_mutable_string();
	~py_mutable_string();
	py_mutable_string(const py_mutable_string& other);
	py_mutable_string(py_mutable_string&& other) noexcept;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_mutable_string(const LSOBJECT& other);
	py_mutable_string& operator=(const py_mutable_string& other);
	py_mutable_string& operator=(py_mutable_string&& other) noexcept;
	std::string get_string();
	void set(const std::string& text);
	void concat(const std::string& text);
	void to_upper();
	void to_lower();
};