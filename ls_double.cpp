#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_double::ls_double(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_double& ls_double::operator=(const ls_double& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_double& ls_double::operator=(ls_double&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

double ls_double::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloat64Type)
	{
		return double(this->lsobject_.GetObjectData().Float64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloat64PtrType)
	{
		return double(*reinterpret_cast<double*>(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'float64' or 'float64ptr' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1.0;
}
