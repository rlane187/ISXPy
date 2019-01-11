#pragma once

class ls_float : public ls_object
{
public:
	ls_float() = default;
	~ls_float() = default;
	ls_float(const ls_float& other) = default;;
	ls_float(ls_float&& other) noexcept = default;;
	explicit ls_float(const LSOBJECT& other);
	ls_float& operator=(const ls_float& other);
	ls_float& operator=(ls_float&& other) noexcept;
	double get_value();
	bool get_is_valid() const;

	double operator-();

	double operator+(const bool& other);
	double operator+(const ls_bool& other);
	double operator+(const int& other);
	double operator+(const int64_t& other);
	double operator+(const ls_int& other);
	double operator+(const double& other);
	double operator+(const ls_float& other);

	double operator-(const bool& other);
	double operator-(const ls_bool& other);
	double operator-(const int& other);
	double operator-(const int64_t& other);
	double operator-(const ls_int& other);
	double operator-(const double& other);
	double operator-(const ls_float& other);

	double operator*(const bool& other);
	double operator*(const ls_bool& other);
	double operator*(const int& other);
	double operator*(const int64_t& other);
	double operator*(const ls_int& other);
	double operator*(const double& other);
	double operator*(const ls_float& other);

	double operator/(const bool& other);
	double operator/(const ls_bool& other);
	double operator/(const int& other);
	double operator/(const int64_t& other);
	double operator/(const ls_int& other);
	double operator/(const double& other);
	double operator/(const ls_float& other);

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
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int64_t() { return int64_t(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return this->get_value(); }
	friend
		std::ostream& operator<<(std::ostream& s, const ls_float& f)
	{
		const std::string display = boost::lexical_cast<std::string, double>(ls_float(f).get_value());
		return s << display;
	}
};

double operator+(const bool& lhs, const ls_float& rhs);
double operator+(const int& lhs, const ls_float& rhs);
double operator+(const int64_t& lhs, const ls_float& rhs);
double operator+(const double& lhs, const ls_float& rhs);

double operator-(const bool& lhs, const ls_float& rhs);
double operator-(const int& lhs, const ls_float& rhs);
double operator-(const int64_t& lhs, const ls_float& rhs);
double operator-(const double& lhs, const ls_float& rhs);

double operator*(const bool& lhs, const ls_float& rhs);
double operator*(const int& lhs, const ls_float& rhs);
double operator*(const int64_t& lhs, const ls_float& rhs);
double operator*(const double& lhs, const ls_float& rhs);

double operator/(const bool& lhs, const ls_float& rhs);
double operator/(const int& lhs, const ls_float& rhs);
double operator/(const int64_t& lhs, const ls_float& rhs);
double operator/(const double& lhs, const ls_float& rhs);

bool operator==(const bool& lhs, const ls_float& rhs);
bool operator==(const int& lhs, const ls_float& rhs);
bool operator==(const int64_t& lhs, const ls_float& rhs);
bool operator==(const double& lhs, const ls_float& rhs);

bool operator!=(const bool& lhs, const ls_float& rhs);
bool operator!=(const int& lhs, const ls_float& rhs);
bool operator!=(const int64_t& lhs, const ls_float& rhs);
bool operator!=(const double& lhs, const ls_float& rhs);

bool operator<(const bool& lhs, const ls_float& rhs);
bool operator<(const int& lhs, const ls_float& rhs);
bool operator<(const int64_t& lhs, const ls_float& rhs);
bool operator<(const double& lhs, const ls_float& rhs);

bool operator>(const bool& lhs, const ls_float& rhs);
bool operator>(const int& lhs, const ls_float& rhs);
bool operator>(const int64_t& lhs, const ls_float& rhs);
bool operator>(const double& lhs, const ls_float& rhs);

bool operator<=(const bool& lhs, const ls_float& rhs);
bool operator<=(const int& lhs, const ls_float& rhs);
bool operator<=(const int64_t& lhs, const ls_float& rhs);
bool operator<=(const double& lhs, const ls_float& rhs);

bool operator>=(const bool& lhs, const ls_float& rhs);
bool operator>=(const int& lhs, const ls_float& rhs);
bool operator>=(const int64_t& lhs, const ls_float& rhs);
bool operator>=(const double& lhs, const ls_float& rhs);

double pow(const ls_float& lhs, const int& rhs);
double pow(const ls_float& lhs, const double& rhs);
double pow(const double& lhs, const ls_float& rhs);
double pow(const ls_float& lhs, const ls_float& rhs);