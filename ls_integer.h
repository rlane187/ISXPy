#pragma once
class py_float;

class ls_integer : public ls_object, boost::integer_arithmetic<ls_integer>
{
public:
	ls_integer() = default;
	~ls_integer() = default;
	ls_integer(const ls_integer& other) = default;
	ls_integer(ls_integer&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_integer(const LSOBJECT& other);
	ls_integer& operator=(const ls_integer& other);
	ls_integer& operator=(ls_integer&& other) noexcept;
	int get_value();

	int operator-();

	int operator+(const bool& other);
	int operator+(const ls_boolean& other);
	int operator+(const int& other);
	double operator+(const double& other);
	int operator+(const ls_integer& other);

	int operator-(const bool& other);
	int operator-(const ls_boolean& other);
	int operator-(const int& other);
	double operator-(const double& other);
	int operator-(const ls_integer& other);

	int operator*(const bool& other);
	int operator*(const ls_boolean& other);
	int operator*(const int& other);
	double operator*(const double& other);
	int operator*(const ls_integer& other);

	int operator/(const bool& other);
	int operator/(const ls_boolean& other);
	int operator/(const int& other);
	double operator/(const double& other);
	int operator/(const ls_integer& other);

	int operator%(const bool& other);
	int operator%(const ls_boolean& other);
	int operator%(const int& other);
	int operator%(const ls_integer& other);

	int operator>>(const bool& other);
	int operator>>(const ls_boolean& other);
	int operator>>(const int& other);
	int operator>>(const ls_integer& other);

	int operator<<(const bool& other);
	int operator<<(const ls_boolean& other);
	int operator<<(const int& other);
	int operator<<(const ls_integer& other);

	int operator&(const bool& other);
	int operator&(const ls_boolean& other);
	int operator&(const int& other);
	int operator&(const ls_integer& other);
		
	int operator^(const int& other);
	int operator^(const ls_integer& other);

	int operator|(const int& other);
	int operator|(const ls_integer& other);

	bool operator==(const int& other);
	bool operator==(const double& other);
	bool operator==(const ls_integer& other);

	bool operator!=(const int& other);
	bool operator!=(const double& other);
	bool operator!=(const ls_integer& other);

	bool operator<(const int& other);
	bool operator<(const double& other);
	bool operator<(const ls_integer& other);

	bool operator>(const int& other);
	bool operator>(const double& other);
	bool operator>(const ls_integer& other);

	bool operator<=(const int& other);
	bool operator<=(const double& other);
	bool operator<=(const ls_integer& other);

	bool operator>=(const int& other);
	bool operator>=(const double& other);
	bool operator>=(const ls_integer& other);

	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return double(this->get_value()); }	
	friend
		std::ostream& operator<<(std::ostream& s, const ls_integer& i) { return s << ls_integer(i).get_value(); }
};

int operator+(const bool& lhs, const ls_integer& rhs);
int operator+(const int& lhs, const ls_integer& rhs);
double operator+(const double& lhs, const ls_integer& rhs);

int operator-(const bool& lhs, const ls_integer& rhs);
int operator-(const int& lhs, const ls_integer& rhs);
double operator-(const double& lhs, const ls_integer& rhs);

int operator*(const bool& lhs, const ls_integer& rhs);
int operator*(const int& lhs, const ls_integer& rhs);
double operator*(const double& lhs, const ls_integer& rhs);

int operator/(const bool& lhs, const ls_integer& rhs);
int operator/(const int& lhs, const ls_integer& rhs);
double operator/(const double& lhs, const ls_integer& rhs);

int operator%(const bool& lhs, const ls_integer& rhs);
int operator%(const int& lhs, const ls_integer& rhs);

int operator>>(const bool& lhs, const ls_integer& rhs);
int operator>>(const int& lhs, const ls_integer& rhs);

int operator<<(const bool& lhs, const ls_integer& rhs);
int operator<<(const int& lhs, const ls_integer& rhs);

int operator&(const bool& lhs, const ls_integer& rhs);
int operator&(const int& lhs, const ls_integer& rhs);

int operator^(const int& lhs, const ls_integer& rhs);

int operator|(const int& lhs, const ls_integer& rhs);

bool operator==(const int& lhs, const ls_integer& rhs);
bool operator==(const double& lhs, const ls_integer& rhs);

bool operator!=(const int& lhs, const ls_integer& rhs);
bool operator!=(const double& lhs, const ls_integer& rhs);

bool operator<(const int& lhs, const ls_integer& rhs);
bool operator<(const double& lhs, const ls_integer& rhs);

bool operator>(const int& lhs, const ls_integer& rhs);
bool operator>(const double& lhs, const ls_integer& rhs);

bool operator<=(const int& lhs, const ls_integer& rhs);
bool operator<=(const double& lhs, const ls_integer& rhs);

bool operator>=(const int& lhs, const ls_integer& rhs);
bool operator>=(const double& lhs, const ls_integer& rhs);

double pow(const int& lhs, const ls_integer& rhs);
double pow(const ls_integer& lhs, const int& rhs);
double pow(const ls_integer& lhs, const ls_integer& rhs);
double pow(const double& lhs, const ls_integer& rhs);
double pow(const ls_integer& lhs, const double& rhs);