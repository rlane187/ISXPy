#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_int::ls_int(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_int& ls_int::operator=(const ls_int& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_int& ls_int::operator=(ls_int&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int64_t ls_int::get_value()
{	
	this->is_valid_ = false;
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pByteType)
	{
		this->is_valid_ = true;
		return int64_t(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBytePtrType)
	{
		this->is_valid_ = true;
		return int64_t(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntType)
	{
		this->is_valid_ = true;
		return int64_t(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntPtrType)
	{
		this->is_valid_ = true;
		return int64_t(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintType)
	{
		this->is_valid_ = true;
		return int64_t(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintPtrType)
	{
		this->is_valid_ = true;
		return int64_t(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64Type)
	{
		this->is_valid_ = true;
		return int64_t(this->lsobject_.GetObjectData().Int64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64PtrType)
	{
		this->is_valid_ = true;
		return int64_t(*(this->lsobject_.GetObjectData().Int64Ptr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS integer or integer pointer type expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

bool ls_int::get_is_valid() const
{
	return this->is_valid_;
}

int64_t ls_int::operator-()
{
	return -1 * int64_t(*this);
}

#pragma region operator +

int64_t ls_int::operator+(const bool& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const bool& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

int64_t ls_int::operator+(const ls_bool& other)
{
	return int64_t(*this) + ls_bool(other).get_value();
}

int64_t ls_int::operator+(const int& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const int& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

int64_t ls_int::operator+(const int64_t& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const int64_t& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

int64_t ls_int::operator+(const ls_int& other)
{
	return int64_t(*this) + ls_int(other).get_value();
}

double ls_int::operator+(const double& other)
{
	return int64_t(*this) + other;
}

double operator+(const double& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

double ls_int::operator+(const ls_float& other)
{
	return int64_t(*this) + ls_float(other).get_value();
}

#pragma endregion

#pragma region operator -

int64_t ls_int::operator-(const bool& other)
{
	return int64_t(*this) - other;
}

int64_t operator-(const bool& lhs, const ls_int& rhs)
{
	return lhs - ls_int(rhs).get_value();
}

int64_t ls_int::operator-(const ls_bool& other)
{
	return int64_t(*this) - ls_bool(other).get_value();
}

int64_t ls_int::operator-(const int& other)
{
	return int64_t(*this) - other;
}

int64_t operator-(const int& lhs, const ls_int& rhs)
{
	return lhs - ls_int(rhs).get_value();
}

int64_t ls_int::operator-(const int64_t& other)
{
	return int64_t(*this) - other;
}

int64_t operator-(const int64_t& lhs, const ls_int& rhs)
{
	return lhs - ls_int(rhs).get_value();
}

int64_t ls_int::operator-(const ls_int& other)
{
	return  int64_t(*this) - ls_int(other).get_value();
}

double operator-(const double& lhs, const ls_int& rhs)
{
	return lhs - ls_int(rhs).get_value();
}

double ls_int::operator-(const double& other)
{
	return int64_t(*this) - other;
}

double ls_int::operator-(const ls_float& other)
{
	return int64_t(*this) + ls_float(other).get_value();
}

#pragma endregion

#pragma region operator *

int64_t ls_int::operator*(const bool& other)
{
	return int64_t(*this) * other;
}

int64_t operator*(const bool& lhs, const ls_int& rhs)
{
	return lhs * ls_int(rhs).get_value();
}

int64_t ls_int::operator*(const ls_bool& other)
{
	return int64_t(*this) * ls_bool(other).get_value();
}

int64_t ls_int::operator*(const int& other)
{
	return int64_t(*this) * other;
}

int64_t operator*(const int& lhs, const ls_int& rhs)
{
	return lhs * ls_int(rhs).get_value();
}

int64_t ls_int::operator*(const ls_int& other)
{
	return int64_t(*this) * ls_int(other).get_value();
}

int64_t ls_int::operator*(const int64_t& other)
{
	return int64_t(*this) * other;
}

int64_t operator*(const int64_t& lhs, const ls_int& rhs)
{
	return lhs * ls_int(rhs).get_value();
}

double ls_int::operator*(const double& other)
{
	return int64_t(*this) * other;
}

double operator*(const double& lhs, const ls_int& rhs)
{
	return lhs * ls_int(rhs).get_value();
}

double ls_int::operator*(const ls_float& other)
{
	return int64_t(*this) * ls_float(other).get_value();
}

#pragma endregion

#pragma region operator /

int64_t ls_int::operator/(const bool& other)
{
	return int64_t(*this)/other;
}

int64_t operator/(const bool& lhs, const ls_int& rhs)
{
	return lhs/ls_int(rhs).get_value();
}

int64_t ls_int::operator/(const ls_bool& other)
{
	return int64_t(*this)/ls_bool(other).get_value();
}

int64_t ls_int::operator/(const int& other)
{
	return int64_t(*this)/other;
}

int64_t operator/(const int& lhs, const ls_int& rhs)
{
	return lhs/ls_int(rhs).get_value();
}

int64_t ls_int::operator/(const ls_int& other)
{
	return int64_t(*this)/ls_int(other).get_value();
}

int64_t ls_int::operator/(const int64_t& other)
{
	return int64_t(*this)/other;
}

int64_t operator/(const int64_t& lhs, const ls_int& rhs)
{
	return lhs/ls_int(rhs).get_value();
}

double ls_int::operator/(const double& other)
{
	return int64_t(*this)/other;
}

double operator/(const double& lhs, const ls_int& rhs)
{
	return lhs/ls_int(rhs).get_value();
}

double ls_int::operator/(const ls_float& other)
{
	return int64_t(*this)/ls_float(other).get_value();
}

#pragma endregion

#pragma region operator %

int64_t ls_int::operator%(const bool& other)
{
	return int64_t(*this) % other;
}

int64_t operator%(const bool& lhs, const ls_int& rhs)
{
	return lhs % ls_int(rhs).get_value();
}

int64_t ls_int::operator%(const ls_bool& other)
{
	return int64_t(*this) % ls_bool(other).get_value();
}

int64_t ls_int::operator%(const int& other)
{
	return int64_t(*this) % other;
}

int64_t operator%(const int& lhs, const ls_int& rhs)
{
	return lhs % ls_int(rhs).get_value();
}

int64_t ls_int::operator%(const ls_int& other)
{
	return int64_t(*this) % ls_int(other).get_value();
}

int64_t ls_int::operator%(const int64_t& other)
{
	return int64_t(*this) % other;
}

int64_t operator%(const int64_t& lhs, const ls_int& rhs)
{
	return lhs % ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator >>

int64_t ls_int::operator>>(const bool& other)
{
	return int64_t(*this) >> other;
}

int64_t operator>>(const bool& lhs, const ls_int& rhs)
{
	return lhs >> ls_int(rhs).get_value();
}

int64_t ls_int::operator>>(const ls_bool& other)
{
	return int64_t(*this) >> ls_bool(other).get_value();
}

int64_t ls_int::operator>>(const int& other)
{
	return int64_t(*this) >> other;
}

int64_t operator>>(const int& lhs, const ls_int& rhs)
{
	return lhs >> ls_int(rhs).get_value();
}

int64_t ls_int::operator>>(const ls_int& other)
{
	return int64_t(*this) >> ls_int(other).get_value();
}

int64_t ls_int::operator>>(const int64_t& other)
{
	return int64_t(*this) >> other;
}

int64_t operator>>(const int64_t& lhs, const ls_int& rhs)
{
	return lhs >> ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator <<

int64_t ls_int::operator<<(const bool& other)
{
	return int64_t(*this) << other;
}

int64_t operator<<(const bool& lhs, const ls_int& rhs)
{
	return lhs << ls_int(rhs).get_value();
}

int64_t ls_int::operator<<(const ls_bool& other)
{
	return int64_t(*this) << ls_bool(other).get_value();
}

int64_t ls_int::operator<<(const int& other)
{
	return int64_t(*this) << other;
}

int64_t operator<<(const int& lhs, const ls_int& rhs)
{
	return lhs << ls_int(rhs).get_value();
}

int64_t ls_int::operator<<(const ls_int& other)
{
	return int64_t(*this) << ls_int(other).get_value();
}

int64_t ls_int::operator<<(const int64_t& other)
{
	return int64_t(*this) << other;
}

int64_t operator<<(const int64_t& lhs, const ls_int& rhs)
{
	return lhs << ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator &

int64_t ls_int::operator&(const bool& other)
{
	return int64_t(*this) & other;
}

int64_t operator&(const bool& lhs, const ls_int& rhs)
{
	return lhs & ls_int(rhs).get_value();
}

int64_t ls_int::operator&(const ls_bool& other)
{
	return int64_t(*this) & ls_bool(other).get_value();
}

int64_t ls_int::operator&(const int& other)
{
	return int64_t(*this) & other;
}

int64_t operator&(const int& lhs, const ls_int& rhs)
{
	return lhs & ls_int(rhs).get_value();
}

int64_t ls_int::operator&(const ls_int& other)
{
	return int64_t(*this) & ls_int(other).get_value();
}

int64_t ls_int::operator&(const int64_t& other)
{
	return int64_t(*this) & other;
}

int64_t operator&(const int64_t& lhs, const ls_int& rhs)
{
	return lhs & ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator ^

int64_t ls_int::operator^(const bool& other)
{
	return int64_t(*this) ^ other;
}

int64_t operator^(const bool& lhs, const ls_int& rhs)
{
	return lhs ^ ls_int(rhs).get_value();
}

int64_t ls_int::operator^(const ls_bool& other)
{
	return int64_t(*this) ^ ls_bool(other).get_value();
}

int64_t ls_int::operator^(const int& other)
{
	return int64_t(*this) ^ other;
}

int64_t operator^(const int& lhs, const ls_int& rhs)
{
	return lhs ^ ls_int(rhs).get_value();
}

int64_t ls_int::operator^(const ls_int& other)
{
	return int64_t(*this) ^ ls_int(other).get_value();
}

int64_t ls_int::operator^(const int64_t& other)
{
	return int64_t(*this) ^ other;
}

int64_t operator^(const int64_t& lhs, const ls_int& rhs)
{
	return lhs ^ ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator |

int64_t ls_int::operator|(const bool& other)
{
	return int64_t(*this) | other;
}

int64_t operator|(const bool& lhs, const ls_int& rhs)
{
	return lhs | ls_int(rhs).get_value();
}

int64_t ls_int::operator|(const ls_bool& other)
{
	return int64_t(*this) | ls_bool(other).get_value();
}

int64_t ls_int::operator|(const int& other)
{
	return int64_t(*this) | other;
}

int64_t operator|(const int& lhs, const ls_int& rhs)
{
	return lhs | ls_int(rhs).get_value();
}

int64_t ls_int::operator|(const ls_int& other)
{
	return int64_t(*this) | ls_int(other).get_value();
}

int64_t ls_int::operator|(const int64_t& other)
{
	return int64_t(*this) | other;
}

int64_t operator|(const int64_t& lhs, const ls_int& rhs)
{
	return lhs | ls_int(rhs).get_value();
}

#pragma endregion

#pragma region operator ==

bool ls_int::operator==(const bool& other)
{
	return int(*this) == other;
}

bool operator==(const bool& lhs, const ls_int& rhs)
{
	return lhs == ls_int(rhs).get_value();
}

bool ls_int::operator==(const ls_bool& other)
{
	return int(*this) == ls_bool(other).get_value();
}

bool ls_int::operator==(const int& other)
{
	return int(*this) == other;
}

bool operator==(const int& lhs, const ls_int& rhs)
{
	return lhs == ls_int(rhs).get_value();
}

bool ls_int::operator==(const int64_t& other)
{
	return int64_t(*this) == other;
}

bool operator==(const int64_t& lhs, const ls_int& rhs)
{
	return lhs == ls_int(rhs).get_value();
}

bool ls_int::operator==(const ls_int& other)
{
	return int(*this) == ls_int(other).get_value();
}

bool ls_int::operator==(const double& other)
{
	return int(*this) == other;
}

bool operator==(const double& lhs, const ls_int& rhs)
{
	return lhs == ls_int(rhs).get_value();
}

bool ls_int::operator==(const ls_float& other)
{
	return int64_t(*this) == ls_float(other).get_value();
}

#pragma endregion

#pragma region operator !=

bool ls_int::operator!=(const bool& other)
{
	return int(*this) != other;
}

bool operator!=(const bool& lhs, const ls_int& rhs)
{
	return lhs != ls_int(rhs).get_value();
}

bool ls_int::operator!=(const ls_bool& other)
{
	return int(*this) != ls_bool(other).get_value();
}

bool ls_int::operator!=(const int& other)
{
	return int(*this) != other;
}

bool operator!=(const int& lhs, const ls_int& rhs)
{
	return lhs != ls_int(rhs).get_value();
}

bool ls_int::operator!=(const int64_t& other)
{
	return int64_t(*this) != other;
}

bool operator!=(const int64_t& lhs, const ls_int& rhs)
{
	return lhs != ls_int(rhs).get_value();
}

bool ls_int::operator!=(const ls_int& other)
{
	return int(*this) != ls_int(other).get_value();
}

bool ls_int::operator!=(const double& other)
{
	return int(*this) != other;
}

bool operator!=(const double& lhs, const ls_int& rhs)
{
	return lhs != ls_int(rhs).get_value();
}

bool ls_int::operator!=(const ls_float& other)
{
	return int64_t(*this) != ls_float(other).get_value();
}

#pragma endregion

#pragma region operator <

bool ls_int::operator<(const bool& other)
{
	return int(*this) < other;
}

bool operator<(const bool& lhs, const ls_int& rhs)
{
	return lhs < ls_int(rhs).get_value();
}

bool ls_int::operator<(const ls_bool& other)
{
	return int(*this) < ls_bool(other).get_value();
}

bool ls_int::operator<(const int& other)
{
	return int(*this) < other;
}

bool operator<(const int& lhs, const ls_int& rhs)
{
	return lhs < ls_int(rhs).get_value();
}

bool ls_int::operator<(const int64_t& other)
{
	return int64_t(*this) < other;
}

bool operator<(const int64_t& lhs, const ls_int& rhs)
{
	return lhs < ls_int(rhs).get_value();
}

bool ls_int::operator<(const ls_int& other)
{
	return int(*this) < ls_int(other).get_value();
}

bool ls_int::operator<(const double& other)
{
	return int(*this) < other;
}

bool operator<(const double& lhs, const ls_int& rhs)
{
	return lhs < ls_int(rhs).get_value();
}

bool ls_int::operator<(const ls_float& other)
{
	return int64_t(*this) < ls_float(other).get_value();
}

#pragma endregion

#pragma region operator >

bool ls_int::operator>(const bool& other)
{
	return int(*this) > other;
}

bool operator>(const bool& lhs, const ls_int& rhs)
{
	return lhs > ls_int(rhs).get_value();
}

bool ls_int::operator>(const ls_bool& other)
{
	return int(*this) > ls_bool(other).get_value();
}

bool ls_int::operator>(const int& other)
{
	return int(*this) > other;
}

bool operator>(const int& lhs, const ls_int& rhs)
{
	return lhs > ls_int(rhs).get_value();
}

bool ls_int::operator>(const int64_t& other)
{
	return int64_t(*this) > other;
}

bool operator>(const int64_t& lhs, const ls_int& rhs)
{
	return lhs > ls_int(rhs).get_value();
}

bool ls_int::operator>(const ls_int& other)
{
	return int(*this) > ls_int(other).get_value();
}

bool ls_int::operator>(const double& other)
{
	return int(*this) > other;
}

bool operator>(const double& lhs, const ls_int& rhs)
{
	return lhs > ls_int(rhs).get_value();
}

bool ls_int::operator>(const ls_float& other)
{
	return int64_t(*this) > ls_float(other).get_value();
}

#pragma endregion

#pragma region operator <=

bool ls_int::operator<=(const bool& other)
{
	return int(*this) <= other;
}

bool operator<=(const bool& lhs, const ls_int& rhs)
{
	return lhs <= ls_int(rhs).get_value();
}

bool ls_int::operator<=(const ls_bool& other)
{
	return int(*this) <= ls_bool(other).get_value();
}

bool ls_int::operator<=(const int& other)
{
	return int(*this) <= other;
}

bool operator<=(const int& lhs, const ls_int& rhs)
{
	return lhs <= ls_int(rhs).get_value();
}

bool ls_int::operator<=(const int64_t& other)
{
	return int64_t(*this) <= other;
}

bool operator<=(const int64_t& lhs, const ls_int& rhs)
{
	return lhs <= ls_int(rhs).get_value();
}

bool ls_int::operator<=(const ls_int& other)
{
	return int(*this) <= ls_int(other).get_value();
}

bool ls_int::operator<=(const double& other)
{
	return int(*this) <= other;
}

bool operator<=(const double& lhs, const ls_int& rhs)
{
	return lhs <= ls_int(rhs).get_value();
}

bool ls_int::operator<=(const ls_float& other)
{
	return int64_t(*this) <= ls_float(other).get_value();
}

#pragma endregion

#pragma region operator >=

bool ls_int::operator>=(const bool& other)
{
	return int(*this) >= other;
}

bool operator>=(const bool& lhs, const ls_int& rhs)
{
	return lhs >= ls_int(rhs).get_value();
}

bool ls_int::operator>=(const ls_bool& other)
{
	return int(*this) >= ls_bool(other).get_value();
}

bool ls_int::operator>=(const int& other)
{
	return int(*this) >= other;
}

bool operator>=(const int& lhs, const ls_int& rhs)
{
	return lhs >= ls_int(rhs).get_value();
}

bool ls_int::operator>=(const int64_t& other)
{
	return int64_t(*this) >= other;
}

bool operator>=(const int64_t& lhs, const ls_int& rhs)
{
	return lhs >= ls_int(rhs).get_value();
}

bool ls_int::operator>=(const ls_int& other)
{
	return int(*this) >= ls_int(other).get_value();
}

bool ls_int::operator>=(const double& other)
{
	return int(*this) >= other;
}

bool operator>=(const double& lhs, const ls_int& rhs)
{
	return lhs >= ls_int(rhs).get_value();
}

bool ls_int::operator>=(const ls_float& other)
{
	return int64_t(*this) >= ls_float(other).get_value();
}

#pragma  endregion

#pragma region pow

double pow(const int& lhs, const ls_int& rhs)
{
	return pow(double(lhs), ls_int(rhs).get_value());
}

double pow(const ls_int& lhs, const ls_int& rhs)
{
	return pow(double(ls_int(lhs).get_value()), double(ls_int(lhs).get_value()));
}

double pow(const double& lhs, const ls_int& rhs)
{
	return pow(lhs, ls_int(rhs).get_value());
}

double pow(const float& lhs, const ls_int& rhs)
{
	return pow(lhs, ls_int(rhs).get_value());
}

double pow(const ls_int& lhs, const int& rhs)
{
	return pow(double(ls_int(lhs).get_value()), rhs);
}

double pow(const ls_int& lhs, const double& rhs)
{
	return pow(double(ls_int(lhs).get_value()), rhs);
}

#pragma endregion