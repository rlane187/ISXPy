#pragma once

class py_float : public py_lsobject
{
public:
	py_float() = default;
	~py_float() = default;
	py_float(const py_float& other) = default;;
	py_float(py_float&& other) noexcept = default;;
	py_float(const LSOBJECT& other);
	py_float& operator=(const py_float& other);
	py_float& operator=(py_float&& other) noexcept;
	float get_value();
};