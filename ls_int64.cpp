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

int64_t ls_int::operator+(const bool& other)
{
	return int(*this) + other;
}

int64_t operator+(const bool& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

int64_t ls_int::operator+(const ls_bool& other)
{
	return int(*this) + ls_bool(other).get_value();
}

int64_t ls_int::operator+(const int& other)
{
	return int(*this) + other;
}

int64_t operator+(const int& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

int64_t ls_int::operator+(const ls_int& other)
{
	return int(*this) + ls_int(other).get_value();
}

double ls_int::operator+(const double& other)
{
	return int(*this) + other;
}

double operator+(const double& lhs, const ls_int& rhs)
{
	return lhs + ls_int(rhs).get_value();
}

#pragma endregion