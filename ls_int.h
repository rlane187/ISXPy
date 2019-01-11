#pragma once
class ls_float;

class ls_int : public ls_object
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
	int64_t get_value();
	bool get_is_valid() const;

	int64_t operator-();

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
	int64_t operator-(const int64_t &other);
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
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int64_t() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return double(this->get_value()); }	
	friend
		std::ostream& operator<<(std::ostream& s, const ls_int& i) { return s << ls_int(i).get_value(); }
};

int64_t operator+(const bool& lhs, const ls_int& rhs);
int64_t operator+(const int& lhs, const ls_int& rhs);
int64_t operator+(const int64_t& lhs, const ls_int& rhs);
double operator+(const double& lhs, const ls_int& rhs);

int64_t operator-(const bool& lhs, const ls_int& rhs);
int64_t operator-(const int& lhs, const ls_int& rhs);
int64_t operator-(const int64_t& lhs, const ls_int& rhs);
double operator-(const double& lhs, const ls_int& rhs);

int64_t operator*(const bool& lhs, const ls_int& rhs);
int64_t operator*(const int& lhs, const ls_int& rhs);
int64_t operator*(const int64_t& lhs, const ls_int& rhs);
double operator*(const double& lhs, const ls_int& rhs);

int64_t operator/(const bool& lhs, const ls_int& rhs);
int64_t operator/(const int& lhs, const ls_int& rhs);
int64_t operator/(const int64_t& lhs, const ls_int& rhs);
double operator/(const double& lhs, const ls_int& rhs);

int64_t operator%(const bool& lhs, const ls_int& rhs);
int64_t operator%(const int& lhs, const ls_int& rhs);
int64_t operator%(const int64_t& lhs, const ls_int& rhs);

int64_t operator>>(const bool& lhs, const ls_int& rhs);
int64_t operator>>(const int& lhs, const ls_int& rhs);
int64_t operator>>(const int64_t& lhs, const ls_int& rhs);

int64_t operator<<(const bool& lhs, const ls_int& rhs);
int64_t operator<<(const int& lhs, const ls_int& rhs);
int64_t operator<<(const int64_t& lhs, const ls_int& rhs);

int64_t operator&(const bool& lhs, const ls_int& rhs);
int64_t operator&(const int& lhs, const ls_int& rhs);
int64_t operator&(const int64_t& lhs, const ls_int& rhs);

int64_t operator^(const bool& lhs, const ls_int& rhs);
int64_t operator^(const int& lhs, const ls_int& rhs);
int64_t operator^(const int64_t& lhs, const ls_int& rhs);

int64_t operator|(const bool& lhs, const ls_int& rhs);
int64_t operator|(const int& lhs, const ls_int& rhs);
int64_t operator|(const int64_t& lhs, const ls_int& rhs);

bool operator==(const bool& lhs, const ls_int& rhs);
bool operator==(const int& lhs, const ls_int& rhs);
bool operator==(const int64_t& lhs, const ls_int& rhs);
bool operator==(const double& lhs, const ls_int& rhs);

bool operator!=(const bool& lhs, const ls_int& rhs);
bool operator!=(const int& lhs, const ls_int& rhs);
bool operator!=(const int64_t& lhs, const ls_int& rhs);
bool operator!=(const double& lhs, const ls_int& rhs);

bool operator<(const bool& lhs, const ls_int& rhs);
bool operator<(const int& lhs, const ls_int& rhs);
bool operator<(const int64_t& lhs, const ls_int& rhs);
bool operator<(const double& lhs, const ls_int& rhs);

bool operator>(const bool& lhs, const ls_int& rhs);
bool operator>(const int& lhs, const ls_int& rhs);
bool operator>(const int64_t& lhs, const ls_int& rhs);
bool operator>(const double& lhs, const ls_int& rhs);

bool operator<=(const bool& lhs, const ls_int& rhs);
bool operator<=(const int& lhs, const ls_int& rhs);
bool operator<=(const int64_t& lhs, const ls_int& rhs);
bool operator<=(const double& lhs, const ls_int& rhs);

bool operator>=(const bool& lhs, const ls_int& rhs);
bool operator>=(const int& lhs, const ls_int& rhs);
bool operator>=(const int64_t& lhs, const ls_int& rhs);
bool operator>=(const double& lhs, const ls_int& rhs);

double pow(const int& lhs, const ls_int& rhs);
double pow(const ls_int& lhs, const int& rhs);
double pow(const ls_int& lhs, const ls_int& rhs);
double pow(const double& lhs, const ls_int& rhs);
double pow(const ls_int& lhs, const double& rhs);