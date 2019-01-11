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

float ls_float::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatType)
	{
		return float(this->lsobject_.GetObjectData().Float);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatPtrType)
	{
		return float(*reinterpret_cast<float*>(this->lsobject_.GetObjectData().DWordPtr));
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

