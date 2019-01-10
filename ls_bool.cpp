#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_bool::ls_bool(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_bool& ls_bool::operator=(const ls_bool& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_bool& ls_bool::operator=(ls_bool&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

bool ls_bool::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBoolType)
	{
		return bool(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBoolPtrType)
	{
		return bool(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'bool' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return false;
}

bool ls_bool::operator!()
{
	return !this->get_value();
}

int ls_bool::operator-()
{
	return -1 * bool(*this);
}

#pragma region operator ==

bool ls_bool::operator==(const bool& other)
{
	return bool(*this) == other;
}

bool operator==(const bool& lhs, const ls_bool& rhs)
{
	return lhs == ls_bool(rhs).get_value();
}

bool ls_bool::operator==(const ls_bool& other)
{
	return bool(*this) == ls_bool(other).get_value();
}

bool ls_bool::operator==(const int& other)
{
	return bool(*this) == other;
}

bool operator==(const int& lhs, const ls_bool& rhs)
{
	return lhs == ls_bool(rhs).get_value();
}

bool ls_bool::operator==(const ls_int& other)
{
	return bool(*this) == ls_int(other).get_value();
}

bool ls_bool::operator==(const double& other)
{
	return bool(*this) == other;
}

bool operator==(const double& lhs, const ls_bool& rhs)
{
	return lhs == ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator !-

bool ls_bool::operator!=(const bool& other)
{
	return bool(*this) != other;
}

bool operator!=(const bool& lhs, const ls_bool& rhs)
{
	return lhs != ls_bool(rhs).get_value();
}

bool ls_bool::operator!=(const ls_bool& other)
{
	return bool(*this) != ls_bool(other).get_value();
}

bool ls_bool::operator!=(const int& other)
{
	return bool(*this) != other;
}

bool operator!=(const int& lhs, const ls_bool& rhs)
{
	return lhs != ls_bool(rhs).get_value();
}

bool ls_bool::operator!=(const ls_int& other)
{
	return bool(*this) != ls_int(other).get_value();
}

bool ls_bool::operator!=(const double& other)
{
	return bool(*this) != other;
}

bool operator!=(const double& lhs, const ls_bool& rhs)
{
	return lhs != ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator &&

bool ls_bool::operator&&(const bool& other)
{
	return bool(*this) && other;
}

bool operator&&(const bool& lhs, const ls_bool& rhs)
{
	return lhs && ls_bool(rhs).get_value();
}

bool ls_bool::operator&&(const ls_bool& other)
{
	return bool(*this) && ls_bool(other).get_value();
}

#pragma endregion

#pragma region operator ||

bool ls_bool::operator||(const bool& other)
{
	return bool(*this) || other;
}

bool operator||(const bool& lhs, const ls_bool& rhs)
{
	return lhs || ls_bool(rhs).get_value();
}

bool ls_bool::operator||(const ls_bool& other)
{
	return bool(*this) || ls_bool(other).get_value();
}

#pragma endregion

#pragma region operator +

int ls_bool::operator+(const bool& other)
{
	return bool(*this) + other;
}

int operator+(const bool& lhs, const ls_bool& rhs)
{
	return lhs + ls_bool(rhs).get_value();
}

int ls_bool::operator+(const ls_bool& other)
{
	return bool(*this) + ls_bool(other).get_value();
}

int ls_bool::operator+(const int& other)
{
	return bool(*this) + other;
}

int operator+(const int& lhs, const ls_bool& rhs)
{
	return lhs + ls_bool(rhs).get_value();
}

int ls_bool::operator+(const ls_int& other)
{
	return bool(*this) + ls_int(other).get_value();
}

double ls_bool::operator+(const double& other)
{
	return bool(*this) + other;
}

double operator+(const double& lhs, const ls_bool& rhs)
{
	return lhs + ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator -

int ls_bool::operator-(const bool& other)
{
	return bool(*this) - other;
}

int operator-(const bool& lhs, const ls_bool& rhs)
{
	return lhs - ls_bool(rhs).get_value();
}

int ls_bool::operator-(const ls_bool& other)
{
	return  bool(*this) - ls_bool(other).get_value();
}

int ls_bool::operator-(const int& other)
{
	return bool(*this) - other;
}

int operator-(const int& lhs, const ls_bool& rhs)
{
	return lhs - ls_bool(rhs).get_value();
}

int ls_bool::operator-(const ls_int& other)
{
	return bool(*this) - ls_int(other).get_value();
}

double ls_bool::operator-(const double& other)
{
	return bool(*this) - other;
}

double operator-(const double& lhs, const ls_bool& rhs)
{
	return lhs - ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator *

int ls_bool::operator*(const bool& other)
{
	return bool(*this) * other;
}

int operator*(const bool& lhs, const ls_bool& rhs)
{
	return lhs * ls_bool(rhs).get_value();
}

int ls_bool::operator*(const ls_bool& other)
{
	return bool(*this) * ls_bool(other).get_value();
}

int ls_bool::operator*(const int& other)
{
	return bool(*this) * other;
}

int operator*(const int& lhs, const ls_bool& rhs)
{
	return lhs * ls_bool(rhs).get_value();
}

int ls_bool::operator*(const ls_int& other)
{
	return bool(*this) * ls_int(other).get_value();
}

double ls_bool::operator*(const double& other)
{
	return bool(*this) * other;
}

double operator*(const double& lhs, const ls_bool& rhs)
{
	return lhs * ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator /

int ls_bool::operator/(const bool& other)
{
	return bool(*this) / other;
}

int operator/(const bool& lhs, const ls_bool& rhs)
{
	return lhs / ls_bool(rhs).get_value();
}

int ls_bool::operator/(const ls_bool& other)
{
	return bool(*this) / ls_bool(other).get_value();
}

int ls_bool::operator/(const int& other)
{
	return bool(*this) / other;
}

int operator/(const int& lhs, const ls_bool& rhs)
{
	return lhs / ls_bool(rhs).get_value();
}

int ls_bool::operator/(const ls_int& other)
{
	return bool(*this) / ls_int(other).get_value();
}

double ls_bool::operator/(const double& other)
{
	return bool(*this) / other;
}

double operator/(const double& lhs, const ls_bool& rhs)
{
	return lhs / ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator %

int ls_bool::operator%(const bool& other)
{
	return bool(*this) % other;
}

int operator%(const bool& lhs, const ls_bool& rhs)
{
	return lhs % ls_bool(rhs).get_value();
}

int ls_bool::operator%(const ls_bool& other)
{
	return bool(*this) % ls_bool(other).get_value();
}

int ls_bool::operator%(const int& other)
{
	return bool(*this) % other;
}

int operator%(const int& lhs, const ls_bool& rhs)
{
	return lhs % ls_bool(rhs).get_value();
}

int ls_bool::operator%(const ls_int& other)
{
	return bool(*this) % ls_int(other).get_value();
}

#pragma endregion

#pragma region operator >>

int ls_bool::operator>>(const bool& other)
{
	return bool(*this) >> other;
}

int operator>>(const bool& lhs, const ls_bool& rhs)
{
	return lhs >> ls_bool(rhs).get_value();
}

int ls_bool::operator>>(const ls_bool& other)
{
	return bool(*this) >> ls_bool(other).get_value();
}

int ls_bool::operator>>(const int& other)
{
	return bool(*this) >> other;
}

int operator>>(const int& lhs, const ls_bool& rhs)
{
	return lhs >> ls_bool(rhs).get_value();
}

int ls_bool::operator>>(const ls_int& other)
{
	return bool(*this) >> ls_int(other).get_value();
}

#pragma endregion

#pragma region operator <<

int ls_bool::operator<<(const bool& other)
{
	return bool(*this) << other;
}

int operator<<(const bool& lhs, const ls_bool& rhs)
{
	return lhs << ls_bool(rhs).get_value();
}

int ls_bool::operator<<(const ls_bool& other)
{
	return bool(*this) << ls_bool(other).get_value();
}

int ls_bool::operator<<(const int& other)
{
	return bool(*this) << other;
}

int operator<<(const int& lhs, const ls_bool& rhs)
{
	return lhs << ls_bool(rhs).get_value();
}

int ls_bool::operator<<(const ls_int& other)
{
	return bool(*this) << ls_int(other).get_value();
}

#pragma endregion

#pragma region operator &

int ls_bool::operator&(const bool& other)
{
	return bool(*this) & other;
}

int operator&(const bool& lhs, const ls_bool& rhs)
{
	return lhs & ls_bool(rhs).get_value();
}

int ls_bool::operator&(const ls_bool& other)
{
	return bool(*this) & ls_bool(other).get_value();
}

int ls_bool::operator&(const int& other)
{
	return bool(*this) & other;
}

int operator&(const int& lhs, const ls_bool& rhs)
{
	return lhs & ls_bool(rhs).get_value();
}

int ls_bool::operator&(const ls_int& other)
{
	return bool(*this) & ls_int(other).get_value();
}

#pragma endregion

#pragma region operator ^

int ls_bool::operator^(const bool& other)
{
	return bool(*this) ^ other;
}

int operator^(const bool& lhs, const ls_bool& rhs)
{
	return lhs ^ ls_bool(rhs).get_value();
}

int ls_bool::operator^(const ls_bool& other)
{
	return bool(*this) ^ ls_bool(other).get_value();
}

int ls_bool::operator^(const int& other)
{
	return bool(*this) ^ other;
}

int operator^(const int& lhs, const ls_bool& rhs)
{
	return lhs ^ ls_bool(rhs).get_value();
}

int ls_bool::operator^(const ls_int& other)
{
	return bool(*this) ^ ls_int(other).get_value();
}

#pragma endregion

#pragma region operator |

int ls_bool::operator|(const bool& other)
{
	return bool(*this) | other;
}

int operator|(const bool& lhs, const ls_bool& rhs)
{
	return lhs ^ ls_bool(rhs).get_value();
}

int ls_bool::operator|(const ls_bool& other)
{
	return bool(*this) | ls_bool(other).get_value();
}

int ls_bool::operator|(const int& other)
{
	return bool(*this) | other;
}

int operator|(const int& lhs, const ls_bool& rhs)
{
	return lhs | ls_bool(rhs).get_value();
}

int ls_bool::operator|(const ls_int& other)
{
	return bool(*this) | ls_int(other).get_value();
}

#pragma endregion

#pragma region operator <

bool ls_bool::operator<(const bool& other)
{
	return bool(*this) < other;
}

bool operator<(const bool& lhs, const ls_bool& rhs)
{
	return lhs < ls_bool(rhs).get_value();
}

bool ls_bool::operator<(const ls_bool& other)
{
	return bool(*this) < ls_bool(other).get_value();
}

bool ls_bool::operator<(const int& other)
{
	return bool(*this) < other;
}

bool operator<(const int& lhs, const ls_bool& rhs)
{
	return lhs < ls_bool(rhs).get_value();
}

bool ls_bool::operator<(const ls_int& other)
{
	return bool(*this) < ls_int(other).get_value();
}

bool ls_bool::operator<(const double& other)
{
	return bool(*this) < other;
}

bool operator<(const double& lhs, const ls_bool& rhs)
{
	return lhs < ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator >

bool ls_bool::operator>(const bool& other)
{
	return bool(*this) > other;
}

bool operator>(const bool& lhs, const ls_bool& rhs)
{
	return lhs > ls_bool(rhs).get_value();
}

bool ls_bool::operator>(const ls_bool& other)
{
	return bool(*this) > ls_bool(other).get_value();
}

bool ls_bool::operator>(const int& other)
{
	return bool(*this) > other;
}

bool operator>(const int& lhs, const ls_bool& rhs)
{
	return lhs > ls_bool(rhs).get_value();
}

bool ls_bool::operator>(const ls_int& other)
{
	return bool(*this) > ls_int(other).get_value();
}

bool ls_bool::operator>(const double& other)
{
	return bool(*this) > other;
}

bool operator>(const double& lhs, const ls_bool& rhs)
{
	return lhs > ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator <=

bool ls_bool::operator<=(const bool& other)
{
	return bool(*this) <= other;
}

bool operator<=(const bool& lhs, const ls_bool& rhs)
{
	return lhs <= ls_bool(rhs).get_value();
}

bool ls_bool::operator<=(const ls_bool& other)
{
	return bool(*this) <= ls_bool(other).get_value();
}

bool ls_bool::operator<=(const int& other)
{
	return bool(*this) <= other;
}

bool operator<=(const int& lhs, const ls_bool& rhs)
{
	return lhs <= ls_bool(rhs).get_value();
}

bool ls_bool::operator<=(const ls_int& other)
{
	return bool(*this) <= ls_int(other).get_value();
}

bool ls_bool::operator<=(const double& other)
{
	return bool(*this) <= other;
}

bool operator<=(const double& lhs, const ls_bool& rhs)
{
	return lhs <= ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region operator >=

bool ls_bool::operator>=(const bool& other)
{
	return bool(*this) >= other;
}

bool operator>=(const bool& lhs, const ls_bool& rhs)
{
	return lhs >= ls_bool(rhs).get_value();
}

bool ls_bool::operator>=(const ls_bool& other)
{
	return bool(*this) >= ls_bool(other).get_value();
}

bool ls_bool::operator>=(const int& other)
{
	return bool(*this) >= other;
}

bool operator>=(const int& lhs, const ls_bool& rhs)
{
	return lhs >= ls_bool(rhs).get_value();
}

bool ls_bool::operator>=(const ls_int& other)
{
	return bool(*this) >= ls_int(other).get_value();
}

bool ls_bool::operator>=(const double& other)
{
	return bool(*this) >= other;
}

bool operator>=(const double& lhs, const ls_bool& rhs)
{
	return lhs >= ls_bool(rhs).get_value();
}

#pragma endregion

#pragma region pow

double pow(const int& lhs, const ls_bool& rhs)
{
	return pow(double(lhs), ls_bool(rhs).get_value());
}

double pow(const ls_bool& lhs, const ls_bool& rhs)
{
	return pow(double(ls_bool(lhs).get_value()), double(ls_bool(lhs).get_value()));
}

double pow(const double& lhs, const ls_bool& rhs)
{
	return pow(lhs, ls_bool(rhs).get_value());
}

float pow(const float& lhs, const ls_bool& rhs)
{
	return pow(lhs, ls_bool(rhs).get_value());
}

double pow(const ls_bool& lhs, const int& rhs)
{
	return pow(double(ls_bool(lhs).get_value()), rhs);
}

double pow(const ls_bool& lhs, const double& rhs)
{
	return pow(double(ls_bool(lhs).get_value()), rhs);
}

#pragma endregion