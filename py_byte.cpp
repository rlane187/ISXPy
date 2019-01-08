#include "ISXPyPCH.h"
#include "ISXPy.h"

py_byte::py_byte(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_byte& py_byte::operator=(const py_byte& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_byte& py_byte::operator=(py_byte&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

unsigned int py_byte::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pByteType)
	{
		return unsigned int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBytePtrType)
	{
		return unsigned int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'byte' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return UINT_MAX;
}


void py_byte::inc(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Inc");
	if (formula.empty())
		this->execute_method(method, 0, nullptr);
	else
		this->execute_method(method, argc, argv);
}

void py_byte::dec(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Dec");
	if (formula.empty())
		this->execute_method(method, 0, nullptr);
	else
		this->execute_method(method, argc, argv);
}

void py_byte::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}