#pragma once

class py_int64 : public py_lsobject
{
public:
	py_int64() = default;
	~py_int64() = default;
	py_int64(const py_int64& other) = default;
	py_int64(py_int64&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_int64(const LSOBJECT& other);
	py_int64& operator=(const py_int64& other);
	py_int64& operator=(py_int64&& other) noexcept;
	int64_t get_value();
	float get_float();
	std::string get_hex();
	std::string leading_zeros(const unsigned int& num_zeros);
	void inc(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(inc_overloads, inc, 0, 1)
	void dec(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(dec_overloads, dec, 0, 1)
	void set(const std::string& formula);
};