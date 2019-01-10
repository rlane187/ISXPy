#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_integer::ls_integer(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_integer& ls_integer::operator=(const ls_integer& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_integer& ls_integer::operator=(ls_integer&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int ls_integer::get_value()
{	
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pByteType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBytePtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntPtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintPtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64Type)
	{
		return int(this->lsobject_.GetObjectData().Int64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64PtrType)
	{
		return int(*(this->lsobject_.GetObjectData().Int64Ptr));
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

int ls_integer::operator-()
{
	return -1 * int(*this);
}

#pragma region operator +

int ls_integer::operator+(const bool& other)
{
	return int(*this) + other;
}

int operator+(const bool& lhs, const ls_integer& rhs)
{
	return lhs + ls_integer(rhs).get_value();
}

int ls_integer::operator+(const ls_boolean& other)
{
	return int(*this) + ls_boolean(other).get_value();
}

int ls_integer::operator+(const int& other)
{
	return int(*this) + other;
}

int operator+(const int& lhs, const ls_integer& rhs)
{
	return lhs + ls_integer(rhs).get_value();
}

int ls_integer::operator+(const ls_integer& other)
{
	return int(*this) + ls_integer(other).get_value();
}

double ls_integer::operator+(const double& other)
{
	return int(*this) + other;
}

double operator+(const double& lhs, const ls_integer& rhs)
{
	return lhs + ls_integer(rhs).get_value();
}

#pragma endregion

#pragma region operator -

int ls_integer::operator-(const bool& other)
{
	return int(*this) - other;
}

int operator-(const bool& lhs, const ls_integer& rhs)
{
	return lhs - ls_integer(rhs).get_value();
}

int ls_integer::operator-(const ls_boolean& other)
{
	return int(*this) - ls_boolean(other).get_value();
}

int ls_integer::operator-(const int& other)
{
	return int(*this) - other;
}

int operator-(const int& lhs, const ls_integer& rhs)
{
	return lhs - ls_integer(rhs).get_value();
}

int ls_integer::operator-(const ls_integer& other)
{
	return  int(*this) - ls_integer(other).get_value();
}

double operator-(const double& lhs, const ls_integer& rhs)
{
	return lhs - ls_integer(rhs).get_value();
}

double ls_integer::operator-(const double& other)
{
	return int(*this) - other;
}

#pragma endregion

#pragma region operator *

int ls_integer::operator*(const bool& other)
{
	return int(*this) * other;
}

int operator*(const bool& lhs, const ls_integer& rhs)
{
	return lhs * ls_integer(rhs).get_value();
}

int ls_integer::operator*(const ls_boolean& other)
{
	return int(*this) * ls_boolean(other).get_value();
}

int ls_integer::operator*(const int& other)
{
	return int(*this) * other;
}

int operator*(const int& lhs, const ls_integer& rhs)
{
	return lhs * ls_integer(rhs).get_value();
}

double ls_integer::operator*(const double& other)
{
	return int(*this) * other;
}

int ls_integer::operator*(const ls_integer& other)
{
	return int(*this) * ls_integer(other).get_value();
}

double operator*(const double& lhs, const ls_integer& rhs)
{
	return lhs * ls_integer(rhs).get_value();
}

#pragma endregion

#pragma region operator /

int ls_integer::operator/(const bool& other)
{
	return int(*this) / other;
}

int operator/(const bool& lhs, const ls_integer& rhs)
{
	return lhs / ls_integer(rhs).get_value();
}

int ls_integer::operator/(const ls_boolean& other)
{
	return int(*this) / ls_boolean(other).get_value();
}

int ls_integer::operator/(const int& other)
{
	return int(*this) / other;
}

int operator/(const int& lhs, const ls_integer& rhs)
{
	return lhs / ls_integer(rhs).get_value();
}

int ls_integer::operator/(const ls_integer& other)
{
	return int(*this) / ls_integer(other).get_value();
}

double ls_integer::operator/(const double& other)
{
	return int(*this) / other;
}

double operator/(const double& lhs, const ls_integer& rhs)
{
	return lhs / ls_integer(rhs).get_value();
}

#pragma endregion

#pragma region operator %

int ls_integer::operator%(const bool& other)
{
	return int(*this) % other;
}

int operator%(const bool& lhs, const ls_integer& rhs)
{
	return lhs % ls_integer(rhs).get_value();
}

int ls_integer::operator%(const ls_boolean& other)
{
	return int(*this) % ls_boolean(other).get_value();
}

int ls_integer::operator%(const int& other)
{
	return int(*this) % other;
}

int operator%(const int& lhs, const ls_integer& rhs)
{
	return lhs % ls_integer(rhs).get_value();
}

int ls_integer::operator%(const ls_integer& other)
{
	return int(*this) % ls_integer(other).get_value();
}

#pragma endregion

#pragma region operator >>

int ls_integer::operator>>(const bool& other)
{
	return int(*this) >> other;
}

int operator>>(const bool& lhs, const ls_integer& rhs)
{
	return lhs >> ls_integer(rhs).get_value();
}

int ls_integer::operator>>(const ls_boolean& other)
{
	return int(*this) >> ls_boolean(other).get_value();
}

int ls_integer::operator>>(const int& other)
{
	return int(*this) >> other;
}

int operator>>(const int& lhs, const ls_integer& rhs)
{
	return lhs >> ls_integer(rhs).get_value();
}

int ls_integer::operator>>(const ls_integer& other)
{
	return int(*this) >> ls_integer(other).get_value();
}

#pragma endregion

#pragma region operator <<

int ls_integer::operator<<(const bool& other)
{
	return int(*this) << other;
}

int operator<<(const bool& lhs, const ls_integer& rhs)
{
	return lhs << ls_integer(rhs).get_value();
}

int ls_integer::operator<<(const int& other)
{
	return int(*this) << other;
}

int ls_integer::operator<<(const ls_boolean& other)
{
	return int(*this) << ls_boolean(other).get_value();
}

int operator<<(const int& lhs, const ls_integer& rhs)
{
	return lhs << ls_integer(rhs).get_value();
}

int ls_integer::operator<<(const ls_integer& other)
{
	return int(*this) << ls_integer(other).get_value();
}

#pragma endregion

#pragma region operator &

int ls_integer::operator&(const bool& other)
{
	return int(*this) & other;
}

int operator&(const bool& lhs, const ls_integer& rhs)
{
	return lhs & ls_integer(rhs).get_value();
}

int ls_integer::operator&(const ls_boolean& other)
{
	return int(*this) & ls_boolean(other).get_value();
}

int ls_integer::operator&(const int& other)
{
	return int(*this) & other;
}

int ls_integer::operator&(const ls_integer& other)
{
	return int(*this) & ls_integer(other).get_value();
}

#pragma endregion

int ls_integer::operator^(const int& other)
{
	return int(*this) ^ other;
}

int ls_integer::operator^(const ls_integer& other)
{
	return int(*this) ^ ls_integer(other).get_value();
}

int ls_integer::operator|(const int& other)
{
	return int(*this) | other;
}

int ls_integer::operator|(const ls_integer& other)
{
	return int(*this) | ls_integer(other).get_value();
}

bool ls_integer::operator==(const int& other)
{
	return int(*this) == other;
}

bool ls_integer::operator==(const double& other)
{
	return int(*this) == other;
}

bool ls_integer::operator==(const ls_integer& other)
{
	return int(*this) == ls_integer(other).get_value();
}

bool ls_integer::operator!=(const int& other)
{
	return int(*this) != other;
}

bool ls_integer::operator!=(const double& other)
{
	return int(*this) != other;
}

bool ls_integer::operator!=(const ls_integer& other)
{
	return int(*this) != ls_integer(other).get_value();
}

bool ls_integer::operator<(const int& other)
{
	return int(*this) < other;
}

bool ls_integer::operator<(const double& other)
{
	return int(*this) < other;
}

bool ls_integer::operator<(const ls_integer& other)
{
	return int(*this) < ls_integer(other).get_value();
}

bool ls_integer::operator>(const int& other)
{
	return int(*this) > other;
}

bool ls_integer::operator>(const double& other)
{
	return int(*this) > other;
}

bool ls_integer::operator>(const ls_integer& other)
{
	return int(*this) > ls_integer(other).get_value();
}

bool ls_integer::operator<=(const int& other)
{
	return int(*this) <= other;
}

bool ls_integer::operator<=(const double& other)
{
	return int(*this) <= other;
}

bool ls_integer::operator<=(const ls_integer& other)
{
	return int(*this) <= ls_integer(other).get_value();
}

bool ls_integer::operator>=(const int& other)
{
	return int(*this) >= other;
}

bool ls_integer::operator>=(const double& other)
{
	return int(*this) >= other;
}

bool ls_integer::operator>=(const ls_integer& other)
{
	return int(*this) >= ls_integer(other).get_value();
}







int operator&(const int& lhs, const ls_integer& rhs)
{
	return lhs & ls_integer(rhs).get_value();
}

int operator^(const int& lhs, const ls_integer& rhs)
{
	return lhs ^ ls_integer(rhs).get_value();
}

int operator|(const int& lhs, const ls_integer& rhs)
{
	return lhs | ls_integer(rhs).get_value();
}

bool operator==(const int& lhs, const ls_integer& rhs)
{
	return lhs == ls_integer(rhs).get_value();
}

bool operator==(const double& lhs, const ls_integer& rhs)
{
	return lhs == ls_integer(rhs).get_value();
}

bool operator!=(const int& lhs, const ls_integer& rhs)
{
	return lhs != ls_integer(rhs).get_value();
}

bool operator!=(const double& lhs, const ls_integer& rhs)
{
	return lhs != ls_integer(rhs).get_value();
}

bool operator<(const int& lhs, const ls_integer& rhs)
{
	return lhs < ls_integer(rhs).get_value();
}

bool operator<(const double& lhs, const ls_integer& rhs)
{
	return lhs < ls_integer(rhs).get_value();
}

bool operator>(const int& lhs, const ls_integer& rhs)
{
	return lhs > ls_integer(rhs).get_value();
}

bool operator>(const double& lhs, const ls_integer& rhs)
{
	return lhs > ls_integer(rhs).get_value();
}

bool operator<=(const int& lhs, const ls_integer& rhs)
{
	return lhs <= ls_integer(rhs).get_value();
}

bool operator<=(const double& lhs, const ls_integer& rhs)
{
	return lhs <= ls_integer(rhs).get_value();
}

bool operator>=(const int& lhs, const ls_integer& rhs)
{
	return lhs >= ls_integer(rhs).get_value();
}

bool operator>=(const double& lhs, const ls_integer& rhs)
{
	return lhs >= ls_integer(rhs).get_value();
}

double pow(const int& lhs, const ls_integer& rhs)
{
	return pow(double(lhs), ls_integer(rhs).get_value());
}

double pow(const ls_integer& lhs, const ls_integer& rhs)
{
	return pow(double(ls_integer(lhs).get_value()), double(ls_integer(lhs).get_value()));
}

double pow(const double& lhs, const ls_integer& rhs)
{
	return pow(lhs, ls_integer(rhs).get_value());
}

float pow(const float& lhs, const ls_integer& rhs)
{
	return pow(lhs, ls_integer(rhs).get_value());
}

double pow(const ls_integer& lhs, const int& rhs)
{
	return pow(double(ls_integer(lhs).get_value()), rhs);
}

double pow(const ls_integer& lhs, const double& rhs)
{
	return pow(double(ls_integer(lhs).get_value()), rhs);
}