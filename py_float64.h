#pragma once

class py_float64 : public ls_object
{
public:
	py_float64() = default;
	~py_float64() = default;
	py_float64(const py_float64& other) = default;;
	py_float64(py_float64&& other) noexcept = default;;
	explicit py_float64(const LSOBJECT& other);
	py_float64& operator=(const py_float64& other);
	py_float64& operator=(py_float64&& other) noexcept;
	double get_value();
	std::string get_deci();
	std::string get_centi();
	std::string get_milli();
	int get_int();
	std::string precision(const unsigned int& decimal_places);
	int get_ceil();
	int get_round();
	void inc(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(inc_overloads, inc, 0, 1)
	void dec(const std::string& formula = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(dec_overloads, dec, 0, 1)
	void set(const std::string& formula = std::string());
};