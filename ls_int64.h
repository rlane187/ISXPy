#pragma once

class ls_int64 : public ls_object
{
public:
	ls_int64() = default;
	~ls_int64() = default;
	ls_int64(const ls_int64& other) = default;
	ls_int64(ls_int64&& other) noexcept = default;
	// ReSharper disable once CppNonExplicitConvertingConstructor
	ls_int64(const LSOBJECT& other);
	ls_int64& operator=(const ls_int64& other);
	ls_int64& operator=(ls_int64&& other) noexcept;
	int64_t get_value();

	int operator-();

	int64_t operator+(const bool& other);
	int64_t operator+(const ls_bool& other);
	int64_t operator+(const int& other);	
	int64_t operator+(const ls_int& other);
	int64_t operator+(const int64_t& other);
	int64_t operator+(const ls_int64& other);
	double operator+(const double& other);
	


	// ReSharper disable once CppNonExplicitConversionOperator
	operator int64_t() { return this->get_value(); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator int() { return int(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator long() { return long(this->get_value()); }
	// ReSharper disable once CppNonExplicitConversionOperator
	operator double() { return double(this->get_value()); }
	friend
		std::ostream& operator<<(std::ostream& s, const ls_int64& i) { return s << ls_int64(i).get_value(); }
};

int64_t operator+(const bool& lhs, const ls_int64& rhs);
int64_t operator+(const int& lhs, const ls_int64& rhs);
int64_t operator+(const int64_t& lhs, const ls_int64& rhs);
double operator+(const double& lhs, const ls_int64& rhs);