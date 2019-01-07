#pragma once
class py_float;

class py_int : public py_lsobject
{
public:
	py_int() = default;
	~py_int() = default;
	py_int(const py_int& other) = default;
	py_int(py_int&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_int(const LSOBJECT& other);
	py_int& operator=(const py_int& other);
	py_int& operator=(py_int&& other) noexcept;
	int get_value();
	float get_float();
	std::string get_hex();
	int get_reverse();
	std::string leading_zeros(const unsigned int& num_zeros);
	unsigned int get_unsigned();
	void inc(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(inc_overloads, inc, 0, 1)
	void dec(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(dec_overloads, dec, 0, 1)
	void set(const std::string& formula);
};