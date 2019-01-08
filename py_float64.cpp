#include "ISXPyPCH.h"
#include "ISXPy.h"

py_float64::py_float64(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_float64& py_float64::operator=(const py_float64& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_float64& py_float64::operator=(py_float64&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

double py_float64::get_value()
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

std::string py_float64::get_deci()
{
	char* const member = static_cast<char *>("Deci");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_float64::get_centi()
{
	char* const member = static_cast<char *>("Centi");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_float64::get_milli()
{
	char* const member = static_cast<char *>("Milli");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

int py_float64::get_int()
{
	char* const member = static_cast<char *>("Int");
	return py_int(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_float64::precision(const unsigned int& decimal_places)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", decimal_places);
	argv[0] = buffer;
	char* const member = static_cast<char *>("Precision");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

int py_float64::get_ceil()
{
	char* const member = static_cast<char *>("Ceil");
	return py_int(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

int py_float64::get_round()
{
	char* const member = static_cast<char *>("Round");
	return py_int(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

void py_float64::inc(const std::string& formula)
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

void py_float64::dec(const std::string& formula)
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

void py_float64::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}