#include "ISXPyPCH.h"
#include "ISXPy.h"

py_bool::py_bool(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_bool& py_bool::operator=(const py_bool& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_bool& py_bool::operator=(py_bool&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

bool py_bool::get_value()
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

void py_bool::toggle()
{
	char* const method = static_cast<char *>("Toggle");
	this->execute_method(method, 0, nullptr);
}

void py_bool::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	argv[0] = buffer;
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}

bool py_bool::operator!()
{
	return !this->get_value();
}
