#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_int64::ls_int64(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_int64& ls_int64::operator=(const ls_int64& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_int64& ls_int64::operator=(ls_int64&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int64_t ls_int64::get_value()
{	
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64Type)
	{
		return int64_t(this->lsobject_.GetObjectData().Int64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64PtrType)
	{
		return int64_t(*(this->lsobject_.GetObjectData().Int64Ptr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'int64' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

int64_t ls_int64::operator-()
{
	return -1 * int64_t(*this);
}

#pragma region operator +

int64_t ls_int64::operator+(const bool& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const bool& lhs, const ls_int64& rhs)
{
	return lhs + ls_int64(rhs).get_value();
}

int64_t ls_int64::operator+(const ls_bool& other)
{
	return int64_t(*this) + ls_bool(other).get_value();
}

int64_t ls_int64::operator+(const int& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const int& lhs, const ls_int64& rhs)
{
	return lhs + ls_int64(rhs).get_value();
}

int64_t ls_int64::operator+(const int64_t& other)
{
	return int64_t(*this) + other;
}

int64_t operator+(const int64_t& lhs, const ls_int64& rhs)
{
	return lhs + ls_int64(rhs).get_value();
}

int64_t ls_int64::operator+(const ls_int& other)
{
	return int64_t(*this) + ls_int(other).get_value();
}

int64_t ls_int64::operator+(const ls_int64& other)
{
	return int64_t(*this) + ls_int64(other).get_value();
}

double ls_int64::operator+(const double& other)
{
	return int64_t(*this) + other;
}

double operator+(const double& lhs, const ls_int64& rhs)
{
	return lhs + ls_int64(rhs).get_value();
}

double ls_int64::operator+(const ls_float& other)
{
	return int64_t(*this) + ls_float(other).get_value();
}

#pragma endregion