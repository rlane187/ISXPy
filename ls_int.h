#pragma once
class ls_float;

class ls_int : public ls_object, boost::integer_arithmetic<ls_int>
{
public:
	ls_int() = default;
	~ls_int() = default;
	ls_int(const ls_int& other) = default;
	ls_int(ls_int&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_int(const LSOBJECT& other);
	ls_int& operator=(const ls_int& other);
	ls_int& operator=(ls_int&& other) noexcept;
	int get_value();

	int operator-();

	int operator+(const bool& other);
	int operator+(const ls_bool& other);
	int operator+(const int& other);
	int operator+(const ls_int& other);
	int64_t operator+(const ls_float& other);
	double operator+(const double& other);	

	int operator-(const bool& other);
	int operator-(const ls_bool& other);
	int operator-(const int& other);
	double operator-(const double& other);
	int operator-(const ls_int& other);

	int operator*(const bool& other);
	int operator*(const ls_bool& other);
	int operator*(const int& other);
	double operator*(const double& other);
	int operator*(const ls_int& other);

	int operator/(const bool& other);
	int operator/(const ls_bool& other);
	int operator/(const int& other);
	double operator/(const double& other);
	int operator/(const ls_int& other);

	int operator%(const bool& other);
	int operator%(const ls_bool& other);
	int operator%(const int& other);
	int operator%(const ls_int& other);

	int operator>>(const bool& other);
	int operator>>(const ls_bool& other);
	int operator>>(const int& other);
	int operator>>(const ls_int& other);

	int operator<<(const bool& other);
	int operator<<(const ls_bool& other);
	int operator<<(const int& other);
	int operator<<(const ls_int& other);

	int operator&(const bool& other);
	int operator&(const ls_bool& other);
	int operator&(const int& other);
	int operator&(const ls_int& other);

	int operator^(const bool& other);
	int operator^(const ls_bool& other);
	int operator^(const int& other);
	int operator^(const ls_int& other);

	int operator|(const bool& other);
	int operator|(const ls_bool& other);
	int operator|(const int& other);
	int operator|(const ls_int& other);

	bool operator==(const bool& other);
	bool operator==(const ls_bool& other);
	bool operator==(const int& other);
	bool operator==(const ls_int& other);
	bool operator==(const int64_t& other);
	bool operator==(const ls_int64& other);
	bool operator==(const double& other);
	bool operator==(const ls_float& other);	

	bool operator!=(const bool& other);
	bool operator!=(const ls_bool& other);
	bool operator!=(const int& other);
	bool operator!=(const double& other);
	bool operator!=(const ls_int& other);

	bool operator<(const bool& other);
	bool operator<(const ls_bool& other);
	bool operator<(const int& other);
	bool operator<(const double& other);
	bool operator<(const ls_int& other);

	bool operator>(const bool& other);
	bool operator>(const ls_bool& other);
	bool operator>(const int& other);
	bool operator>(const double& other);
	bool operator>(const ls_int& other);

	bool operator<=(const bool& other);
	bool operator<=(const ls_bool& other);
	bool operator<=(const int& other);
	bool operator<=(const double& other);
	bool operator<=(const ls_int& other);

	bool operator>=(const bool& other);
	bool operator>=(const ls_bool& other);
	bool operator>=(const int& other);
	bool operator>=(const double& other);
	bool operator>=(const ls_int& other);

	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return double(this->get_value()); }	
	friend
		std::ostream& operator<<(std::ostream& s, const ls_int& i) { return s << ls_int(i).get_value(); }
};

int operator+(const bool& lhs, const ls_int& rhs);
int operator+(const int& lhs, const ls_int& rhs);
double operator+(const double& lhs, const ls_int& rhs);

int operator-(const bool& lhs, const ls_int& rhs);
int operator-(const int& lhs, const ls_int& rhs);
double operator-(const double& lhs, const ls_int& rhs);

int operator*(const bool& lhs, const ls_int& rhs);
int operator*(const int& lhs, const ls_int& rhs);
double operator*(const double& lhs, const ls_int& rhs);

int operator/(const bool& lhs, const ls_int& rhs);
int operator/(const int& lhs, const ls_int& rhs);
double operator/(const double& lhs, const ls_int& rhs);

int operator%(const bool& lhs, const ls_int& rhs);
int operator%(const int& lhs, const ls_int& rhs);

int operator>>(const bool& lhs, const ls_int& rhs);
int operator>>(const int& lhs, const ls_int& rhs);

int operator<<(const bool& lhs, const ls_int& rhs);
int operator<<(const int& lhs, const ls_int& rhs);

int operator&(const bool& lhs, const ls_int& rhs);
int operator&(const int& lhs, const ls_int& rhs);

int operator^(const bool& lhs, const ls_int& rhs);
int operator^(const int& lhs, const ls_int& rhs);

int operator|(const bool& lhs, const ls_int& rhs);
int operator|(const int& lhs, const ls_int& rhs);

bool operator==(const bool& lhs, const ls_int& rhs);
bool operator==(const int& lhs, const ls_int& rhs);
bool operator==(const double& lhs, const ls_int& rhs);

bool operator!=(const bool& lhs, const ls_int& rhs);
bool operator!=(const int& lhs, const ls_int& rhs);
bool operator!=(const double& lhs, const ls_int& rhs);

bool operator<(const bool& lhs, const ls_int &rhs);
bool operator<(const int& lhs, const ls_int& rhs);
bool operator<(const double& lhs, const ls_int& rhs);

bool operator>(const bool& lhs, const ls_int& rhs);
bool operator>(const int& lhs, const ls_int& rhs);
bool operator>(const double& lhs, const ls_int& rhs);

bool operator<=(const bool& lhs, const ls_int& rhs);
bool operator<=(const int& lhs, const ls_int& rhs);
bool operator<=(const double& lhs, const ls_int& rhs);

bool operator>=(const bool& lhs, const ls_int &rhs);
bool operator>=(const int& lhs, const ls_int& rhs);
bool operator>=(const double& lhs, const ls_int& rhs);

double pow(const int& lhs, const ls_int& rhs);
double pow(const ls_int& lhs, const int& rhs);
double pow(const ls_int& lhs, const ls_int& rhs);
double pow(const double& lhs, const ls_int& rhs);
double pow(const ls_int& lhs, const double& rhs);