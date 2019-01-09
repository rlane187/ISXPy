#pragma once
class py_float;

class py_int : public py_lsobject, boost::integer_arithmetic<py_int>
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
	int operator-();
	int operator+(const int& other);
	double operator+(const double& other);
	int operator+(const py_int& other);
	int operator-(const int& other);
	double operator-(const double& other);
	int operator-(const py_int& other);
	int operator*(const int& other);
	double operator*(const double& other);
	int operator*(const py_int& other);
	int operator/(const int& other);
	double operator/(const double& other);
	int operator/(const py_int& other);
	int operator%(const int& other);
	int operator%(const py_int& other);	
	int operator>>(const int& other);
	int operator>>(const py_int& other);
	int operator<<(const int& other);
	int operator<<(const py_int& other);
	int operator&(const int& other);
	int operator&(const py_int& other);
	int operator^(const int& other);
	int operator^(const py_int& other);
	int operator|(const int& other);
	int operator|(const py_int& other);
	bool operator==(const int& other);
	bool operator==(const double& other);
	bool operator==(const py_int& other);
	bool operator!=(const int& other);
	bool operator!=(const double& other);
	bool operator!=(const py_int& other);
	bool operator<(const int& other);
	bool operator<(const double& other);
	bool operator<(const py_int& other);
	bool operator>(const int& other);
	bool operator>(const double& other);
	bool operator>(const py_int& other);
	bool operator<=(const int& other);
	bool operator<=(const double& other);
	bool operator<=(const py_int& other);
	bool operator>=(const int& other);
	bool operator>=(const double& other);
	bool operator>=(const py_int& other);

	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return double(this->get_value()); }	
	friend
		std::ostream& operator<<(std::ostream& s, const py_int& i) { return s << py_int(i).get_value(); }
};

int operator+(const int& lhs, const py_int& rhs);
double operator+(const double& lhs, const py_int& rhs);
int operator-(const int& lhs, const py_int& rhs);
double operator-(const double& lhs, const py_int& rhs);
int operator*(const int& lhs, const py_int& rhs);
double operator*(const double& lhs, const py_int& rhs);
int operator/(const int& lhs, const py_int& rhs);
double operator/(const double& lhs, const py_int& rhs);
int operator%(const int& lhs, const py_int& rhs);
int operator>>(const int& lhs, const py_int& rhs);
int operator<<(const int& lhs, const py_int& rhs);
int operator&(const int& lhs, const py_int& rhs);
int operator^(const int& lhs, const py_int& rhs);
int operator|(const int& lhs, const py_int& rhs);

bool operator==(const int& lhs, const py_int& rhs);
bool operator==(const double& lhs, const py_int& rhs);
bool operator!=(const int& lhs, const py_int& rhs);
bool operator!=(const double& lhs, const py_int& rhs);
bool operator<(const int& lhs, const py_int& rhs);
bool operator<(const double& lhs, const py_int& rhs);
bool operator>(const int& lhs, const py_int& rhs);
bool operator>(const double& lhs, const py_int& rhs);
bool operator<=(const int& lhs, const py_int& rhs);
bool operator<=(const double& lhs, const py_int& rhs);
bool operator>=(const int& lhs, const py_int& rhs);
bool operator>=(const double& lhs, const py_int& rhs);

double pow(const int& lhs, const py_int& rhs);
double pow(const py_int& lhs, const int& rhs);
double pow(const py_int& lhs, const py_int& rhs);
double pow(const double& lhs, const py_int& rhs);
double pow(const py_int& lhs, const double& rhs);