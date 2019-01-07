#pragma once

class py_string : public py_lsobject
{
public:
	py_string() = default;
	~py_string() = default;
	py_string(const py_string& other) = default;
	py_string(py_string&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_string(const LSOBJECT& other);
	py_string& operator=(const py_string& other);
	py_string& operator=(py_string&& other) noexcept;
	std::string get_value();
};