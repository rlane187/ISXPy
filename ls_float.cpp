#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_float::ls_float(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_float& ls_float::operator=(const ls_float& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_float& ls_float::operator=(ls_float&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

double ls_float::get_value()
{
	this->is_valid_ = false;
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatType)
	{
		this->is_valid_ = true;
		return double(this->lsobject_.GetObjectData().Float);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatPtrType)
	{
		this->is_valid_ = true;
		return double(*reinterpret_cast<float*>(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloat64Type)
	{
		this->is_valid_ = true;
		return double(this->lsobject_.GetObjectData().Float64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloat64PtrType)
	{
		this->is_valid_ = true;
		return double(*reinterpret_cast<double*>(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type float or float pointer type expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1.0f;
}

bool ls_float::get_is_valid() const
{
	return this->is_valid_;
}

double ls_float::operator-()
{
	return -1.0 * double(*this);
}

#pragma region operator +

double ls_float::operator+(const bool& other)
{
	return double(*this) + other;
}

double operator+(const bool& lhs, const ls_float& rhs)
{
	return lhs + ls_float(rhs).get_value();
}

double ls_float::operator+(const ls_bool& other)
{
	return double(*this) + ls_bool(other).get_value();
}

double ls_float::operator+(const int& other)
{
	return double(*this) + other;
}

double operator+(const int& lhs, const ls_float& rhs)
{
	return lhs + ls_float(rhs).get_value();
}

double ls_float::operator+(const int64_t& other)
{
	return double(*this) + other;
}

double operator+(const int64_t& lhs, const ls_float& rhs)
{
	return lhs + ls_float(rhs).get_value();
}

double ls_float::operator+(const ls_int& other)
{
	return double(*this) + ls_int(other).get_value();
}

double ls_float::operator+(const double& other)
{
	return double(*this) + other;
}

double operator+(const double& lhs, const ls_float& rhs)
{
	return lhs + ls_float(rhs).get_value();
}

double ls_float::operator+(const ls_float& other)
{
	return double(*this) + ls_float(other).get_value();
}

#pragma endregion

#pragma region operator -

double ls_float::operator-(const bool& other)
{
	return double(*this) - other;
}

double operator-(const bool& lhs, const ls_float& rhs)
{
	return lhs - ls_float(rhs).get_value();
}

double ls_float::operator-(const ls_bool& other)
{
	return double(*this) - ls_bool(other).get_value();
}

double ls_float::operator-(const int& other)
{
	return double(*this) - other;
}

double operator-(const int& lhs, const ls_float& rhs)
{
	return lhs - ls_float(rhs).get_value();
}

double ls_float::operator-(const int64_t& other)
{
	return double(*this) - other;
}

double operator-(const int64_t& lhs, const ls_float& rhs)
{
	return lhs - ls_float(rhs).get_value();
}

double ls_float::operator-(const ls_int& other)
{
	return double(*this) - ls_int(other).get_value();
}

double ls_float::operator-(const double& other)
{
	return double(*this) - other;
}

double operator-(const double& lhs, const ls_float& rhs)
{
	return lhs - ls_float(rhs).get_value();
}

double ls_float::operator-(const ls_float& other)
{
	return double(*this) - ls_float(other).get_value();
}

#pragma endregion

#pragma region operator *

double ls_float::operator*(const bool& other)
{
	return double(*this) * other;
}

double operator*(const bool& lhs, const ls_float& rhs)
{
	return lhs * ls_float(rhs).get_value();
}

double ls_float::operator*(const ls_bool& other)
{
	return double(*this) * ls_bool(other).get_value();
}

double ls_float::operator*(const int& other)
{
	return double(*this) * other;
}

double operator*(const int& lhs, const ls_float& rhs)
{
	return lhs * ls_float(rhs).get_value();
}

double ls_float::operator*(const int64_t& other)
{
	return double(*this) * other;
}

double operator*(const int64_t& lhs, const ls_float& rhs)
{
	return lhs * ls_float(rhs).get_value();
}

double ls_float::operator*(const ls_int& other)
{
	return double(*this) * ls_int(other).get_value();
}

double ls_float::operator*(const double& other)
{
	return double(*this) * other;
}

double operator*(const double& lhs, const ls_float& rhs)
{
	return lhs * ls_float(rhs).get_value();
}

double ls_float::operator*(const ls_float& other)
{
	return double(*this) * ls_float(other).get_value();
}

#pragma endregion

#pragma region operator /

double ls_float::operator/(const bool& other)
{
	return double(*this)/other;
}

double operator/(const bool& lhs, const ls_float& rhs)
{
	return lhs/ls_float(rhs).get_value();
}

double ls_float::operator/(const ls_bool& other)
{
	return double(*this)/ls_bool(other).get_value();
}

double ls_float::operator/(const int& other)
{
	return double(*this)/other;
}

double operator/(const int& lhs, const ls_float& rhs)
{
	return lhs/ls_float(rhs).get_value();
}

double ls_float::operator/(const int64_t& other)
{
	return double(*this)/other;
}

double operator/(const int64_t& lhs, const ls_float& rhs)
{
	return lhs/ls_float(rhs).get_value();
}

double ls_float::operator/(const ls_int& other)
{
	return double(*this)/ls_int(other).get_value();
}

double ls_float::operator/(const double& other)
{
	return double(*this)/other;
}

double operator/(const double& lhs, const ls_float& rhs)
{
	return lhs/ls_float(rhs).get_value();
}

double ls_float::operator/(const ls_float& other)
{
	return double(*this)/ls_float(other).get_value();
}

#pragma endregion

#pragma region operator ==

bool ls_float::operator==(const bool& other)
{
	return double(*this) == other;
}

bool operator==(const bool& lhs, const ls_float& rhs)
{
	return lhs == ls_float(rhs).get_value();
}

bool ls_float::operator==(const ls_bool& other)
{
	return double(*this) == ls_bool(other).get_value();
}

bool ls_float::operator==(const int& other)
{
	return double(*this) == other;
}

bool operator==(const int& lhs, const ls_float& rhs)
{
	return lhs == ls_float(rhs).get_value();
}

bool ls_float::operator==(const int64_t& other)
{
	return double(*this) == other;
}

bool operator==(const int64_t& lhs, const ls_float& rhs)
{
	return lhs == ls_float(rhs).get_value();
}

bool ls_float::operator==(const ls_int& other)
{
	return double(*this) == ls_int(other).get_value();
}

bool ls_float::operator==(const double& other)
{
	return double(*this) == other;
}

bool operator==(const double& lhs, const ls_float& rhs)
{
	return lhs == ls_float(rhs).get_value();
}

bool ls_float::operator==(const ls_float& other)
{
	return double(*this) == ls_float(other).get_value();
}

#pragma endregion

#pragma region operator !=

bool ls_float::operator!=(const bool& other)
{
	return double(*this) != other;
}

bool operator!=(const bool& lhs, const ls_float& rhs)
{
	return lhs != ls_float(rhs).get_value();
}

bool ls_float::operator!=(const ls_bool& other)
{
	return double(*this) != ls_bool(other).get_value();
}

bool ls_float::operator!=(const int& other)
{
	return double(*this) != other;
}

bool operator!=(const int& lhs, const ls_float& rhs)
{
	return lhs != ls_float(rhs).get_value();
}

bool ls_float::operator!=(const int64_t& other)
{
	return double(*this) != other;
}

bool operator!=(const int64_t& lhs, const ls_float& rhs)
{
	return lhs != ls_float(rhs).get_value();
}

bool ls_float::operator!=(const ls_int& other)
{
	return double(*this) != ls_int(other).get_value();
}

bool ls_float::operator!=(const double& other)
{
	return double(*this) != other;
}

bool operator!=(const double& lhs, const ls_float& rhs)
{
	return lhs != ls_float(rhs).get_value();
}

bool ls_float::operator!=(const ls_float& other)
{
	return double(*this) != ls_float(other).get_value();
}

#pragma endregion

#pragma region operator <

bool ls_float::operator<(const bool& other)
{
	return double(*this) < other;
}

bool operator<(const bool& lhs, const ls_float& rhs)
{
	return lhs < ls_float(rhs).get_value();
}

bool ls_float::operator<(const ls_bool& other)
{
	return double(*this) < ls_bool(other).get_value();
}

bool ls_float::operator<(const int& other)
{
	return double(*this) < other;
}

bool operator<(const int& lhs, const ls_float& rhs)
{
	return lhs < ls_float(rhs).get_value();
}

bool ls_float::operator<(const int64_t& other)
{
	return double(*this) < other;
}

bool operator<(const int64_t& lhs, const ls_float& rhs)
{
	return lhs < ls_float(rhs).get_value();
}

bool ls_float::operator<(const ls_int& other)
{
	return double(*this) < ls_int(other).get_value();
}

bool ls_float::operator<(const double& other)
{
	return double(*this) < other;
}

bool operator<(const double& lhs, const ls_float& rhs)
{
	return lhs < ls_float(rhs).get_value();
}

bool ls_float::operator<(const ls_float& other)
{
	return double(*this) < ls_float(other).get_value();
}

#pragma endregion

#pragma region operator >

bool ls_float::operator>(const bool& other)
{
	return double(*this) > other;
}

bool operator>(const bool& lhs, const ls_float& rhs)
{
	return lhs > ls_float(rhs).get_value();
}

bool ls_float::operator>(const ls_bool& other)
{
	return double(*this) > ls_bool(other).get_value();
}

bool ls_float::operator>(const int& other)
{
	return double(*this) > other;
}

bool operator>(const int& lhs, const ls_float& rhs)
{
	return lhs > ls_float(rhs).get_value();
}

bool ls_float::operator>(const int64_t& other)
{
	return double(*this) > other;
}

bool operator>(const int64_t& lhs, const ls_float& rhs)
{
	return lhs > ls_float(rhs).get_value();
}

bool ls_float::operator>(const ls_int& other)
{
	return double(*this) > ls_int(other).get_value();
}

bool ls_float::operator>(const double& other)
{
	return double(*this) > other;
}

bool operator>(const double& lhs, const ls_float& rhs)
{
	return lhs > ls_float(rhs).get_value();
}

bool ls_float::operator>(const ls_float& other)
{
	return double(*this) > ls_float(other).get_value();
}

#pragma endregion

#pragma region operator <=

bool ls_float::operator<=(const bool& other)
{
	return double(*this) <= other;
}

bool operator<=(const bool& lhs, const ls_float& rhs)
{
	return lhs <= ls_float(rhs).get_value();
}

bool ls_float::operator<=(const ls_bool& other)
{
	return double(*this) <= ls_bool(other).get_value();
}

bool ls_float::operator<=(const int& other)
{
	return double(*this) <= other;
}

bool operator<=(const int& lhs, const ls_float& rhs)
{
	return lhs <= ls_float(rhs).get_value();
}

bool ls_float::operator<=(const int64_t& other)
{
	return double(*this) <= other;
}

bool operator<=(const int64_t& lhs, const ls_float& rhs)
{
	return lhs <= ls_float(rhs).get_value();
}

bool ls_float::operator<=(const ls_int& other)
{
	return double(*this) <= ls_int(other).get_value();
}

bool ls_float::operator<=(const double& other)
{
	return double(*this) <= other;
}

bool operator<=(const double& lhs, const ls_float& rhs)
{
	return lhs <= ls_float(rhs).get_value();
}

bool ls_float::operator<=(const ls_float& other)
{
	return double(*this) <= ls_float(other).get_value();
}

#pragma endregion

#pragma region operator >=

bool ls_float::operator>=(const bool& other)
{
	return double(*this) >= other;
}

bool operator>=(const bool& lhs, const ls_float& rhs)
{
	return lhs >= ls_float(rhs).get_value();
}

bool ls_float::operator>=(const ls_bool& other)
{
	return double(*this) >= ls_bool(other).get_value();
}

bool ls_float::operator>=(const int& other)
{
	return double(*this) >= other;
}

bool operator>=(const int& lhs, const ls_float& rhs)
{
	return lhs >= ls_float(rhs).get_value();
}

bool ls_float::operator>=(const int64_t& other)
{
	return double(*this) >= other;
}

bool operator>=(const int64_t& lhs, const ls_float& rhs)
{
	return lhs >= ls_float(rhs).get_value();
}

bool ls_float::operator>=(const ls_int& other)
{
	return double(*this) >= ls_int(other).get_value();
}

bool ls_float::operator>=(const double& other)
{
	return double(*this) >= other;
}

bool operator>=(const double& lhs, const ls_float& rhs)
{
	return lhs >= ls_float(rhs).get_value();
}

bool ls_float::operator>=(const ls_float& other)
{
	return double(*this) >= ls_float(other).get_value();
}

#pragma endregion

#pragma region pow

double pow(const ls_float& lhs, const int& rhs)
{
	return pow(ls_float(lhs).get_value(), rhs);
}

double pow(const ls_float& lhs, const double& rhs)
{
	return pow(ls_float(lhs).get_value(), rhs);
}

double pow(const double& lhs, const ls_float& rhs)
{
	return pow(lhs, ls_float(rhs).get_value());
}

double pow(const ls_float& lhs, const ls_float& rhs)
{
	return pow(ls_float(lhs).get_value(), ls_float(rhs).get_value());
}

#pragma endregion