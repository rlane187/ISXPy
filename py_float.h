#pragma once

class py_float : public ls_object
{
public:
	py_float() = default;
	~py_float() = default;
	py_float(const py_float& other) = default;;
	py_float(py_float&& other) noexcept = default;;
	explicit py_float(const LSOBJECT& other);
	py_float& operator=(const py_float& other);
	py_float& operator=(py_float&& other) noexcept;
	float get_value();
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