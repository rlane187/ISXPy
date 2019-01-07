#include "ISXPyPCH.h"
#include "ISXPy.h"

py_int64::py_int64(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_int64& py_int64::operator=(const py_int64& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_int64& py_int64::operator=(py_int64&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int64_t py_int64::get_value()
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

float py_int64::get_float()
{
	char* const member = static_cast<char *>("Float");
	return py_float(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_int64::get_hex()
{
	char* const member = static_cast<char *>("Hex");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_int64::leading_zeros(const unsigned int& num_zeros)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", num_zeros);
	argv[0] = buffer;
	char* const member = static_cast<char *>("LeadingZeroes");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

void py_int64::inc(const std::string& formula)
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

void py_int64::dec(const std::string& formula)
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

void py_int64::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}