#pragma once

class py_uint : public ls_object
{
public:
	py_uint() = default;
	~py_uint() = default;
	py_uint(const py_uint& other) = default;
	py_uint(py_uint&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_uint(const LSOBJECT& other);
	py_uint& operator=(const py_uint& other);
	py_uint& operator=(py_uint&& other) noexcept;
	unsigned int get_value();
	float get_float();
	std::string get_hex();
	unsigned int get_reverse();
	std::string leading_zeros(const unsigned int& num_zeros);
	int get_signed();
	void inc(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(inc_overloads, inc, 0, 1)
		void dec(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(dec_overloads, dec, 0, 1)
		void set(const std::string& formula);
};