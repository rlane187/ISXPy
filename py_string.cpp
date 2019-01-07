#include "ISXPyPCH.h"
#include "ISXPy.h"

py_string::py_string(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_string& py_string::operator=(const py_string& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_string& py_string::operator=(py_string&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

std::string py_string::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pStringType)
	{
		size_t characters_converted;
		char buffer[MAX_VARSTRING];
		if (this->lsobject_.GetObjectData().CharPtr != nullptr)
			return std::string(this->lsobject_.GetObjectData().CharPtr);
		if (this->lsobject_.GetObjectData().ConstCharPtr != nullptr)
			return std::string(this->lsobject_.GetObjectData().ConstCharPtr);
		if (this->lsobject_.GetObjectData().WCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->lsobject_.GetObjectData().WCharPtr, _countof(buffer));
			return std::string(buffer);
		}
		if (this->lsobject_.GetObjectData().ConstWCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->lsobject_.GetObjectData().ConstWCharPtr, _countof(buffer));
			return std::string(buffer);
		}
		if (this->lsobject_.ObjectType)
		{
			char buffer_exception[MAX_VARSTRING];
			sprintf_s(buffer_exception, _countof(buffer_exception), R"(LS Type 'string' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
			PyErr_SetString(PyExc_TypeError, buffer_exception);
		}
		else
			PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pMutableStringType)
	{
		return this->get_mutable_string_from_lso();
	}
	return std::string("NULL");
}