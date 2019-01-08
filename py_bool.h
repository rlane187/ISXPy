#pragma once

class py_bool : public py_lsobject
{
public:
	py_bool() = default;
	~py_bool() = default;
	py_bool(const py_bool& other) = default;
	py_bool(py_bool&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_bool(const LSOBJECT& other);
	py_bool& operator=(const py_bool& other);
	py_bool& operator=(py_bool&& other) noexcept;
	bool get_value();
	void toggle();
	void set(const std::string& formula);
};