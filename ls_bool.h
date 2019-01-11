#pragma once

class ls_int;
class ls_int64;
class ls_float;
class ls_double;

class ls_bool : public ls_object
{
public:
	ls_bool() = default;
	~ls_bool() = default;
	ls_bool(const ls_bool& other) = default;
	ls_bool(ls_bool&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_bool(const LSOBJECT& other);
	ls_bool& operator=(const ls_bool& other);
	ls_bool& operator=(ls_bool&& other) noexcept;
	bool get_value();
	bool get_is_valid() const;
	bool operator!();
	int operator-();

	int64_t operator+(const bool& other);
	int64_t operator+(const ls_bool& other);
	int64_t operator+(const int& other);
	int64_t operator+(const int64_t& other);
	int64_t operator+(const ls_int& other);	
	double operator+(const double& other);
	double operator+(const ls_float& other);

	int64_t operator-(const bool& other);
	int64_t operator-(const ls_bool& other);
	int64_t operator-(const int& other);
	int64_t operator-(const int64_t& other);
	int64_t operator-(const ls_int& other);
	double operator-(const double& other);
	double operator-(const ls_float& other);

	int64_t operator*(const bool& other);
	int64_t operator*(const ls_bool& other);
	int64_t operator*(const int& other);
	int64_t operator*(const int64_t& other);
	int64_t operator*(const ls_int& other);
	double operator*(const double& other);
	double operator*(const ls_float& other);

	int64_t operator/(const bool& other);
	int64_t operator/(const ls_bool& other);
	int64_t operator/(const int& other);
	int64_t operator/(const int64_t& other);
	int64_t operator/(const ls_int& other);
	double operator/(const double& other);
	double operator/(const ls_float& other);

	int64_t operator%(const bool& other);
	int64_t operator%(const ls_bool& other);
	int64_t operator%(const int& other);
	int64_t operator%(const int64_t& other);
	int64_t operator%(const ls_int& other);

	int64_t operator>>(const bool& other);
	int64_t operator>>(const ls_bool& other);
	int64_t operator>>(const int& other);
	int64_t operator>>(const int64_t& other);
	int64_t operator>>(const ls_int& other);

	int64_t operator<<(const bool& other);
	int64_t operator<<(const ls_bool& other);
	int64_t operator<<(const int& other);
	int64_t operator<<(const int64_t& other);
	int64_t operator<<(const ls_int& other);

	int64_t operator&(const bool& other);
	int64_t operator&(const ls_bool& other);
	int64_t operator&(const int& other);
	int64_t operator&(const int64_t& other);
	int64_t operator&(const ls_int& other);

	int64_t operator^(const bool& other);
	int64_t operator^(const ls_bool& other);
	int64_t operator^(const int& other);
	int64_t operator^(const int64_t& other);
	int64_t operator^(const ls_int& other);

	int64_t operator|(const bool& other);
	int64_t operator|(const ls_bool& other);
	int64_t operator|(const int& other);
	int64_t operator|(const int64_t& other);
	int64_t operator|(const ls_int& other);

	bool operator==(const bool& other);
	bool operator==(const ls_bool& other);
	bool operator==(const int& other);	
	bool operator==(const int64_t& other);
	bool operator==(const ls_int& other);
	bool operator==(const double& other);
	bool operator==(const ls_float& other);

	bool operator!=(const bool& other);
	bool operator!=(const ls_bool& other);
	bool operator!=(const int& other);
	bool operator!=(const int64_t& other);
	bool operator!=(const ls_int& other);
	bool operator!=(const double& other);
	bool operator!=(const ls_float& other);

	bool operator&&(const bool& other);
	bool operator&&(const ls_bool& other);

	bool operator||(const bool& other);
	bool operator||(const ls_bool& other);

	bool operator<(const bool& other);
	bool operator<(const ls_bool& other);
	bool operator<(const int& other);
	bool operator<(const int64_t& other);
	bool operator<(const ls_int& other);
	bool operator<(const double& other);
	bool operator<(const ls_float& other);

	bool operator>(const bool& other);
	bool operator>(const ls_bool& other);
	bool operator>(const int& other);
	bool operator>(const int64_t& other);
	bool operator>(const ls_int& other);
	bool operator>(const double& other);
	bool operator>(const ls_float& other);

	bool operator<=(const bool& other);
	bool operator<=(const ls_bool& other);
	bool operator<=(const int& other);
	bool operator<=(const int64_t& other);
	bool operator<=(const ls_int& other);
	bool operator<=(const double& other);
	bool operator<=(const ls_float& other);

	bool operator>=(const bool& other);
	bool operator>=(const ls_bool& other);
	bool operator>=(const int& other);
	bool operator>=(const int64_t& other);
	bool operator>=(const ls_int& other);
	bool operator>=(const double& other);
	bool operator>=(const ls_float& other);

	// ReSharper disable once CppNonExplicitConversionOperator
	operator bool() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }

	friend	std::ostream& operator<<(std::ostream& s, const ls_bool& b)
	{
		if (ls_bool(b).get_value())
			return s << "True";
		return s << "False";
	}
};

int64_t operator+(const bool& lhs, const ls_bool& rhs);
int64_t operator+(const int& lhs, const ls_bool& rhs);
int64_t operator+(const int64_t& lhs, const ls_bool& rhs);
double operator+(const double& lhs, const ls_bool& rhs);

int64_t operator-(const bool& lhs, const ls_bool& rhs);
int64_t operator-(const int& lhs, const ls_bool& rhs);
int64_t operator-(const int64_t& lhs, const ls_bool& rhs);
double operator-(const double& lhs, const ls_bool& rhs);

int64_t operator*(const bool& lhs, const ls_bool& rhs);
int64_t operator*(const int& lhs, const ls_bool& rhs);
int64_t operator*(const int64_t& lhs, const ls_bool& rhs);
double operator*(const double& lhs, const ls_bool& rhs);

int64_t operator/(const bool& lhs, const ls_bool& rhs);
int64_t operator/(const int& lhs, const ls_bool& rhs);
int64_t operator/(const int64_t& lhs, const ls_bool& rhs);
double operator/(const double& lhs, const ls_bool& rhs);

int64_t operator%(const bool& lhs, const ls_bool& rhs);
int64_t operator%(const int& lhs, const ls_bool& rhs);
int64_t operator%(const int64_t& lhs, const ls_bool& rhs);

int64_t operator>>(const bool& lhs, const ls_bool& rhs);
int64_t operator>>(const int& lhs, const ls_bool& rhs);
int64_t operator>>(const int64_t& lhs, const ls_bool& rhs);

int64_t operator<<(const bool& lhs, const ls_bool& rhs);
int64_t operator<<(const int& lhs, const ls_bool& rhs);
int64_t operator<<(const int64_t& lhs, const ls_bool& rhs);

int64_t operator&(const bool& lhs, const ls_bool& rhs);
int64_t operator&(const int& lhs, const ls_bool& rhs);
int64_t operator&(const int64_t& lhs, const ls_bool& rhs);

int64_t operator^(const bool& lhs, const ls_bool& rhs);
int64_t operator^(const int& lhs, const ls_bool& rhs);
int64_t operator^(const int64_t& lhs, const ls_bool& rhs);

int64_t operator|(const bool& lhs, const ls_bool& rhs);
int64_t operator|(const int& lhs, const ls_bool& rhs);
int64_t operator|(const int64_t& lhs, const ls_bool& rhs);

bool operator==(const bool& lhs, const ls_bool& rhs);
bool operator==(const int& lhs, const ls_bool& rhs);
bool operator==(const int64_t& lhs, const ls_bool& rhs);
bool operator==(const double& lhs, const ls_bool& rhs);

bool operator!=(const bool& lhs, const ls_bool& rhs);
bool operator!=(const int& lhs, const ls_bool& rhs);
bool operator!=(const int64_t& lhs, const ls_bool& rhs);
bool operator!=(const double& lhs, const ls_bool& rhs);

bool operator&&(const bool& lhs, const ls_bool& rhs);

bool operator||(const bool& lhs, const ls_bool& rhs);

bool operator<(const bool& lhs, const ls_bool& rhs);
bool operator<(const int& lhs, const ls_bool& rhs);
bool operator<(const int64_t& lhs, const ls_bool& rhs);
bool operator<(const double& lhs, const ls_bool& rhs);

bool operator>(const bool& lhs, const ls_bool& rhs);
bool operator>(const int& lhs, const ls_bool& rhs);
bool operator>(const int64_t& lhs, const ls_bool& rhs);
bool operator>(const double& lhs, const ls_bool& rhs);

bool operator<=(const bool& lhs, const ls_bool& rhs);
bool operator<=(const int& lhs, const ls_bool& rhs);
bool operator<=(const int64_t& lhs, const ls_bool& rhs);
bool operator<=(const double& lhs, const ls_bool& rhs);

bool operator>=(const bool& lhs, const ls_bool& rhs);
bool operator>=(const int& lhs, const ls_bool& rhs);
bool operator>=(const int64_t& lhs, const ls_bool& rhs);
bool operator>=(const double& lhs, const ls_bool& rhs);

double pow(const int& lhs, const ls_bool& rhs);
double pow(const ls_bool& lhs, const int& rhs);
double pow(const ls_bool& lhs, const ls_bool& rhs);
double pow(const double& lhs, const ls_bool& rhs);
double pow(const ls_bool& lhs, const double& rhs);