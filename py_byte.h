#pragma once

class py_byte : public py_lsobject
{
public:
	py_byte() = default;
	~py_byte() = default;
	py_byte(const py_byte& other) = default;
	py_byte(py_byte&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_byte(const LSOBJECT& other);
	py_byte& operator=(const py_byte& other);
	py_byte& operator=(py_byte&& other) noexcept;
	unsigned int get_value();
	void inc(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(inc_overloads, inc, 0, 1)
	void dec(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(dec_overloads, dec, 0, 1)
	void set(const std::string& formula = std::string());
};