#include "ISXPyPCH.h"
#include "ISXPy.h"

py_int::py_int(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_int& py_int::operator=(const py_int& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_int& py_int::operator=(py_int&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

int py_int::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntPtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'int' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

float py_int::get_float()
{
	char* const member = static_cast<char *>("Float");
	return py_float(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_int::get_hex()
{
	char* const member = static_cast<char *>("Hex");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

int py_int::get_reverse()
{
	char* const member = static_cast<char *>("Reverse");
	return py_int(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_int::leading_zeros(const unsigned int& num_zeros)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%u", num_zeros);
	argv[0] = buffer;
	char* const member = static_cast<char *>("LeadingZeroes");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

unsigned int py_int::get_unsigned()
{
	char* const member = static_cast<char *>("Unsigned");
	return py_uint(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

void py_int::inc(const std::string& formula)
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

void py_int::dec(const std::string& formula)
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

void py_int::set(const std::string& formula)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), formula.c_str());
	char* const method = static_cast<char *>("Set");
	this->execute_method(method, argc, argv);
}

int py_int::operator-()
{
	return -1 * int(*this);
}

int py_int::operator+(const int& other)
{
	return int(*this) + other;
}

double py_int::operator+(const double& other)
{
	return int(*this) + other;
}

int py_int::operator+(const py_int& other)
{
	return int(*this) + py_int(other).get_value();
}

int py_int::operator-(const int& other)
{
	return int(*this) - other;
}

double py_int::operator-(const double& other)
{
	return int(*this) - other;
}

int py_int::operator-(const py_int& other)
{
	return  int(*this) - py_int(other).get_value();
}

int py_int::operator*(const int& other)
{
	return int(*this) * other;
}

double py_int::operator*(const double& other)
{
	return int(*this) * other;
}

int py_int::operator*(const py_int& other)
{
	return int(*this) * py_int(other).get_value();
}

int py_int::operator/(const int& other)
{
	return int(*this) / other;
}

double py_int::operator/(const double& other)
{
	return int(*this) / other;
}

int py_int::operator/(const py_int& other)
{
	return int(*this) / py_int(other).get_value();
}

int py_int::operator%(const int& other)
{
	return int(*this) % other;
}

int py_int::operator%(const py_int& other)
{
	return int(*this) % py_int(other).get_value();
}

int py_int::operator>>(const int& other)
{
	return int(*this) >> other;
}

int py_int::operator>>(const py_int& other)
{
	return int(*this) >> py_int(other).get_value();
}

int py_int::operator<<(const int& other)
{
	return int(*this) << other;
}

int py_int::operator<<(const py_int& other)
{
	return int(*this) << py_int(other).get_value();
}

int py_int::operator&(const int& other)
{
	return int(*this) & other;
}

int py_int::operator&(const py_int& other)
{
	return int(*this) & py_int(other).get_value();
}

int py_int::operator^(const int& other)
{
	return int(*this) ^ other;
}

int py_int::operator^(const py_int& other)
{
	return int(*this) ^ py_int(other).get_value();
}

int py_int::operator|(const int& other)
{
	return int(*this) | other;
}

int py_int::operator|(const py_int& other)
{
	return int(*this) | py_int(other).get_value();
}

bool py_int::operator==(const int& other)
{
	return int(*this) == other;
}

bool py_int::operator==(const double& other)
{
	return int(*this) == other;
}

bool py_int::operator==(const py_int& other)
{
	return int(*this) == py_int(other).get_value();
}

bool py_int::operator!=(const int& other)
{
	return int(*this) != other;
}

bool py_int::operator!=(const double& other)
{
	return int(*this) != other;
}

bool py_int::operator!=(const py_int& other)
{
	return int(*this) != py_int(other).get_value();
}

bool py_int::operator<(const int& other)
{
	return int(*this) < other;
}

bool py_int::operator<(const double& other)
{
	return int(*this) < other;
}

bool py_int::operator<(const py_int& other)
{
	return int(*this) < py_int(other).get_value();
}

bool py_int::operator>(const int& other)
{
	return int(*this) > other;
}

bool py_int::operator>(const double& other)
{
	return int(*this) > other;
}

bool py_int::operator>(const py_int& other)
{
	return int(*this) > py_int(other).get_value();
}

bool py_int::operator<=(const int& other)
{
	return int(*this) <= other;
}

bool py_int::operator<=(const double& other)
{
	return int(*this) <= other;
}

bool py_int::operator<=(const py_int& other)
{
	return int(*this) <= py_int(other).get_value();
}

bool py_int::operator>=(const int& other)
{
	return int(*this) >= other;
}

bool py_int::operator>=(const double& other)
{
	return int(*this) >= other;
}

bool py_int::operator>=(const py_int& other)
{
	return int(*this) >= py_int(other).get_value();
}

int operator+(const int& lhs, const py_int& rhs)
{
	return lhs + py_int(rhs).get_value();
}

double operator+(const double& lhs, const py_int& rhs)
{
	return lhs + py_int(rhs).get_value();
}

int operator-(const int& lhs, const py_int& rhs)
{
	return lhs - py_int(rhs).get_value();
}

double operator-(const double& lhs, const py_int& rhs)
{
	return lhs - py_int(rhs).get_value();
}

int operator*(const int& lhs, const py_int& rhs)
{
	return lhs * py_int(rhs).get_value();
}

double operator*(const double& lhs, const py_int& rhs)
{
	return lhs * py_int(rhs).get_value();
}

int operator/(const int& lhs, const py_int& rhs)
{
	return lhs / py_int(rhs).get_value();
}

double operator/(const double& lhs, const py_int& rhs)
{
	return lhs / py_int(rhs).get_value();
}

int operator%(const int& lhs, const py_int& rhs)
{
	return lhs % py_int(rhs).get_value();
}

int operator>>(const int& lhs, const py_int& rhs)
{
	return lhs >> py_int(rhs).get_value();
}

int operator<<(const int& lhs, const py_int& rhs)
{
	return lhs << py_int(rhs).get_value();
}

int operator&(const int& lhs, const py_int& rhs)
{
	return lhs & py_int(rhs).get_value();
}

int operator^(const int& lhs, const py_int& rhs)
{
	return lhs ^ py_int(rhs).get_value();
}

int operator|(const int& lhs, const py_int& rhs)
{
	return lhs | py_int(rhs).get_value();
}

bool operator==(const int& lhs, const py_int& rhs)
{
	return lhs == py_int(rhs).get_value();
}

bool operator==(const double& lhs, const py_int& rhs)
{
	return lhs == py_int(rhs).get_value();
}

bool operator!=(const int& lhs, const py_int& rhs)
{
	return lhs != py_int(rhs).get_value();
}

bool operator!=(const double& lhs, const py_int& rhs)
{
	return lhs != py_int(rhs).get_value();
}

bool operator<(const int& lhs, const py_int& rhs)
{
	return lhs < py_int(rhs).get_value();
}

bool operator<(const double& lhs, const py_int& rhs)
{
	return lhs < py_int(rhs).get_value();
}

bool operator>(const int& lhs, const py_int& rhs)
{
	return lhs > py_int(rhs).get_value();
}

bool operator>(const double& lhs, const py_int& rhs)
{
	return lhs > py_int(rhs).get_value();
}

bool operator<=(const int& lhs, const py_int& rhs)
{
	return lhs <= py_int(rhs).get_value();
}

bool operator<=(const double& lhs, const py_int& rhs)
{
	return lhs <= py_int(rhs).get_value();
}

bool operator>=(const int& lhs, const py_int& rhs)
{
	return lhs >= py_int(rhs).get_value();
}

bool operator>=(const double& lhs, const py_int& rhs)
{
	return lhs >= py_int(rhs).get_value();
}

double pow(const int& lhs, const py_int& rhs)
{
	return pow(double(lhs), py_int(rhs).get_value());
}

double pow(const py_int& lhs, const py_int& rhs)
{
	return pow(double(py_int(lhs).get_value()), double(py_int(lhs).get_value()));
}

double pow(const double& lhs, const py_int& rhs)
{
	return pow(lhs, py_int(rhs).get_value());
}

float pow(const float& lhs, const py_int& rhs)
{
	return pow(lhs, py_int(rhs).get_value());
}

double pow(const py_int& lhs, const int& rhs)
{
	return pow(double(py_int(lhs).get_value()), rhs);
}

double pow(const py_int& lhs, const double& rhs)
{
	return pow(double(py_int(lhs).get_value()), rhs);
}