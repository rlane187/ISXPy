#pragma once

class ls_integer;

class ls_boolean : public ls_object
{
public:
	ls_boolean() = default;
	~ls_boolean() = default;
	ls_boolean(const ls_boolean& other) = default;
	ls_boolean(ls_boolean&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_boolean(const LSOBJECT& other);
	ls_boolean& operator=(const ls_boolean& other);
	ls_boolean& operator=(ls_boolean&& other) noexcept;
	bool get_value();
	bool operator!();
	int operator-();

	bool operator==(const bool& other);
	bool operator==(const ls_boolean& other);
	bool operator==(const int& other);
	bool operator==(const ls_integer& other);
	bool operator==(const double& other);

	bool operator!=(const bool& other);
	bool operator!=(const ls_boolean& other);
	bool operator!=(const int& other);
	bool operator!=(const ls_integer& other);
	bool operator!=(const double& other);

	bool operator&&(const bool& other);
	bool operator&&(const ls_boolean& other);

	bool operator||(const bool& other);
	bool operator||(const ls_boolean& other);
		
	int operator+(const bool& other);
	int operator+(const ls_boolean& other);
	int operator+(const int& other);
	int operator+(const ls_integer& other);
	double operator+(const double& other);	

	int operator-(const bool& other);
	int operator-(const ls_boolean& other);
	int operator-(const int& other);
	int operator-(const ls_integer& other);
	double operator-(const double& other);

	int operator*(const bool& other);
	int operator*(const ls_boolean& other);
	int operator*(const int& other);
	int operator*(const ls_integer& other);
	double operator*(const double& other);	

	int operator/(const bool& other);
	int operator/(const ls_boolean& other);
	int operator/(const int& other);
	int operator/(const ls_integer& other);
	double operator/(const double& other);	

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

	int operator^(const bool& other);
	int operator^(const int& other);
	int operator^(const ls_integer& other);
	int operator^(const ls_boolean& other);

	int operator|(const bool& other);
	int operator|(const ls_boolean& other);
	int operator|(const int& other);
	int operator|(const ls_integer& other);

	bool operator<(const bool& other);
	bool operator<(const ls_boolean& other);
	bool operator<(const int& other);
	bool operator<(const ls_integer& other);
	bool operator<(const double& other);

	bool operator>(const bool& other);
	bool operator>(const ls_boolean& other);
	bool operator>(const int& other);
	bool operator>(const ls_integer& other);
	bool operator>(const double& other);

	bool operator<=(const bool& other);
	bool operator<=(const ls_boolean& other);
	bool operator<=(const int& other);
	bool operator<=(const ls_integer& other);
	bool operator<=(const double& other);

	bool operator>=(const bool& other);
	bool operator>=(const ls_boolean& other);
	bool operator>=(const int& other);
	bool operator>=(const ls_integer& other);
	bool operator>=(const double& other);

	// ReSharper disable once CppNonExplicitConversionOperator
	operator bool() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }

	friend	std::ostream& operator<<(std::ostream& s, const ls_boolean& b)
	{
		if (ls_boolean(b).get_value())
			return s << "True";
		return s << "False";
	}
};

bool operator==(const bool& lhs, const ls_boolean& rhs);
bool operator==(const int& lhs, const ls_boolean& rhs);
bool operator==(const double& lhs, const ls_boolean& rhs);

bool operator!=(const bool& lhs, const ls_boolean& rhs);
bool operator!=(const int& lhs, const ls_boolean& rhs);
bool operator!=(const double& lhs, const ls_boolean& rhs);

bool operator&&(const bool& lhs, const ls_boolean& rhs);

bool operator||(const bool& lhs, const ls_boolean& rhs);

int operator+(const bool& lhs, const ls_boolean& rhs);
int operator+(const int& lhs, const ls_boolean& rhs);
double operator+(const double& lhs, const ls_boolean& rhs);

int operator-(const bool& lhs, const ls_boolean& rhs);
int operator-(const int& lhs, const ls_boolean& rhs);
double operator-(const double& lhs, const ls_boolean& rhs);

int operator*(const bool& lhs, const ls_boolean& rhs);
int operator*(const int& lhs, const ls_boolean& rhs);
double operator*(const double& lhs, const ls_boolean& rhs);

int operator/(const bool& lhs, const ls_boolean& rhs);
int operator/(const int& lhs, const ls_boolean& rhs);
double operator/(const double& lhs, const ls_boolean& rhs);

int operator%(const bool& lhs, const ls_boolean& rhs);
int operator%(const int& lhs, const ls_boolean& rhs);

int operator>>(const bool& lhs, const ls_boolean& rhs);
int operator>>(const int& lhs, const ls_boolean& rhs);

int operator<<(const bool& lhs, const ls_boolean& rhs);
int operator<<(const int& lhs, const ls_boolean& rhs);

int operator&(const bool& lhs, const ls_boolean& rhs);
int operator&(const int& lhs, const ls_boolean& rhs);

int operator^(const bool& lhs, const ls_boolean& rhs);
int operator^(const int& lhs, const ls_boolean& rhs);

int operator|(const bool& lhs, const ls_boolean& rhs);
int operator|(const int& lhs, const ls_boolean& rhs);

bool operator<(const bool& lhs, const ls_boolean& rhs);
bool operator<(const int& lhs, const ls_boolean& rhs);
bool operator<(const double& lhs, const ls_boolean& rhs);

bool operator>(const bool& lhs, const ls_boolean& rhs);
bool operator>(const int& lhs, const ls_boolean& rhs);
bool operator>(const double& lhs, const ls_boolean& rhs);

bool operator<=(const bool& lhs, const ls_boolean& rhs);
bool operator<=(const int& lhs, const ls_boolean& rhs);
bool operator<=(const double& lhs, const ls_boolean& rhs);

bool operator>=(const bool& lhs, const ls_boolean& rhs);
bool operator>=(const int& lhs, const ls_boolean& rhs);
bool operator>=(const double& lhs, const ls_boolean& rhs);

double pow(const int& lhs, const ls_boolean& rhs);
double pow(const ls_boolean& lhs, const int& rhs);
double pow(const ls_boolean& lhs, const ls_boolean& rhs);
double pow(const double& lhs, const ls_boolean& rhs);
double pow(const ls_boolean& lhs, const double& rhs);