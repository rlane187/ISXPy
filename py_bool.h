#pragma once

class py_int;

class py_bool : public py_lsobject
{
public:
	py_bool() = default;
	~py_bool() = default;
	py_bool(const py_bool& other) = default;
	py_bool(py_bool&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	py_bool(const LSOBJECT& other);
	py_bool& operator=(const py_bool& other);
	py_bool& operator=(py_bool&& other) noexcept;
	bool get_value();
	void toggle();
	void set(const std::string& formula);
	bool operator!();
	bool operator==(const bool& other);
	bool operator==(const py_bool& other);
	bool operator!=(const bool& other);
	bool operator!=(const py_bool& other);
	bool operator&&(const bool& other);
	bool operator&&(const py_bool& other);
	bool operator||(const bool& other);
	bool operator||(const py_bool& other);
	int operator-();
	int operator+(const int& other);
	int operator+(const py_int& other);
	double operator+(const double& other);
	int operator+(const py_bool& other);
	int operator-(const int& other);
	int operator-(const py_int& other);
	double operator-(const double& other);
	int operator-(const py_bool& other);
	int operator*(const int& other);
	int operator*(const py_int& other);
	double operator*(const double& other);
	int operator*(const py_bool& other);
	int operator/(const int& other);
	int operator/(const py_int& other);
	double operator/(const double& other);
	int operator/(const py_bool& other);
	int operator%(const int& other);
	int operator%(const py_int& other);
	int operator%(const py_bool& other);
	int operator>>(const int& other);
	int operator>>(const py_int& other);
	int operator>>(const py_bool& other);
	int operator<<(const int& other);
	int operator<<(const py_int& other);
	int operator<<(const py_bool& other);
	int operator&(const int& other);
	int operator&(const py_int& other);
	int operator&(const py_bool& other);
	int operator^(const int& other);
	int operator^(const py_int& other);
	int operator^(const py_bool& other);
	int operator|(const int& other);
	int operator|(const py_int& other);
	int operator|(const py_bool& other);
	bool operator==(const int& other);
	bool operator==(const py_int& other);
	bool operator==(const double& other);
	bool operator!=(const int& other);
	bool operator!=(const py_int& other);
	bool operator!=(const double& other);
	bool operator<(const int& other);
	bool operator<(const py_int& other);
	bool operator<(const double& other);
	bool operator<(const py_bool& other);
	bool operator>(const int& other);
	bool operator>(const py_int& other);
	bool operator>(const double& other);
	bool operator>(const py_bool& other);
	bool operator<=(const int& other);
	bool operator<=(const py_int& other);
	bool operator<=(const double& other);
	bool operator<=(const py_bool& other);
	bool operator>=(const int& other);
	bool operator>=(const py_int& other);
	bool operator>=(const double& other);
	bool operator>=(const py_bool& other);


	// ReSharper disable once CppNonExplicitConversionOperator
	operator bool() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }

	friend	std::ostream& operator<<(std::ostream& s, const py_bool& b)
	{
		if (py_bool(b).get_value())
			return s << "True";
		return s << "False";
	}
};

int operator+(const int& lhs, const py_bool& rhs);
double operator+(const double& lhs, const py_bool& rhs);
int operator-(const int& lhs, const py_bool& rhs);
double operator-(const double& lhs, const py_bool& rhs);
int operator*(const int& lhs, const py_bool& rhs);
double operator*(const double& lhs, const py_bool& rhs);
int operator/(const int& lhs, const py_bool& rhs);
double operator/(const double& lhs, const py_bool& rhs);
int operator%(const int& lhs, const py_bool& rhs);
int operator>>(const int& lhs, const py_bool& rhs);
int operator<<(const int& lhs, const py_bool& rhs);
int operator&(const int& lhs, const py_bool& rhs);
int operator^(const int& lhs, const py_bool& rhs);
int operator|(const int& lhs, const py_bool& rhs);

bool operator==(const bool& lhs, const py_bool& rhs);
bool operator==(const int& lhs, const py_bool& rhs);
bool operator==(const double& lhs, const py_bool& rhs);
bool operator!=(const bool& lhs, const py_bool& rhs);
bool operator!=(const int& lhs, const py_bool& rhs);
bool operator!=(const double& lhs, const py_bool& rhs);
bool operator&&(const bool& lhs, const py_bool& rhs);
bool operator||(const bool& lhs, const py_bool& rhs);
bool operator<(const int& lhs, const py_bool& rhs);
bool operator<(const double& lhs, const py_bool& rhs);
bool operator>(const int& lhs, const py_bool& rhs);
bool operator>(const double& lhs, const py_bool& rhs);
bool operator<=(const int& lhs, const py_bool& rhs);
bool operator<=(const double& lhs, const py_bool& rhs);
bool operator>=(const int& lhs, const py_bool& rhs);
bool operator>=(const double& lhs, const py_bool& rhs);

double pow(const int& lhs, const py_bool& rhs);
double pow(const py_bool& lhs, const int& rhs);
double pow(const py_bool& lhs, const py_bool& rhs);
double pow(const double& lhs, const py_bool& rhs);
double pow(const py_bool& lhs, const double& rhs);