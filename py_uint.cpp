#include "ISXPyPCH.h"
#include "ISXPy.h"

py_uint::py_uint(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_uint& py_uint::operator=(const py_uint& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_uint& py_uint::operator=(py_uint&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

unsigned int py_uint::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintType)
	{
		return unsigned int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'uint' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return UINT_MAX;
}

float py_uint::get_float()
{
	char* const member = static_cast<char *>("Float");
	return ls_float(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_uint::get_hex()
{
	char* const member = static_cast<char *>("Hex");
	return ls_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

unsigned int py_uint::get_reverse()
{
	char* const member = static_cast<char *>("Reverse");
	return py_uint(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_uint::leading_zeros(const unsigned int& num_zeros)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", num_zeros);
	argv[0] = buffer;
	char* const member = static_cast<char *>("LeadingZeroes");
	return ls_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

int py_uint::get_signed()
{
	char* const member = static_cast<char *>("Signed");
	return ls_int(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

void py_uint::inc(const std::string& formula)
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

void py_uint::dec(const std::string& formula)
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

void py_uint::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}