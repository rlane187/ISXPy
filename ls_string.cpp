#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_string::ls_string(const ls_object& other)
{
	this->lsobject_ = other.get_lso();
}

ls_string::ls_string(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

ls_string& ls_string::operator=(const ls_string& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_string& ls_string::operator=(ls_string&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

std::string ls_string::get_value()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pStringType)
	{
		size_t characters_converted;
		char buffer[MAX_VARSTRING];
		if (this->lsobject_.GetObjectData().CharPtr != nullptr)
		{
			return std::string(this->lsobject_.GetObjectData().CharPtr);
		}			
		if (this->lsobject_.GetObjectData().ConstCharPtr != nullptr)
		{
			return std::string(this->lsobject_.GetObjectData().ConstCharPtr);
		}
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
		char* const member = static_cast<char *>("String");
		return ls_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
	}
	return std::string("NULL");
}

bool ls_string::get_is_valid()
{
	return this->get_value() != std::string("NULL");
}

bool ls_string::operator==(const std::string& other)
{
	return std::string(*this) == other;
}

bool operator==(const std::string& lhs, const ls_string& rhs)
{
	return lhs == ls_string(rhs).get_value();
}

bool ls_string::operator!=(const std::string& other)
{
	return std::string(*this) != other;
}

bool operator!=(const std::string& lhs, const ls_string& rhs)
{
	return lhs != ls_string(rhs).get_value();
}

bool ls_string::operator>(const std::string& other)
{
	return std::string(*this) > other;
}

bool operator>(const std::string& lhs, const ls_string& rhs)
{
	return lhs > ls_string(rhs).get_value();
}

bool ls_string::operator<(const std::string& other)
{
	return std::string(*this) < other;
}

bool operator<(const std::string& lhs, const ls_string& rhs)
{
	return lhs < ls_string(rhs).get_value();
}

bool ls_string::operator>=(const std::string& other)
{
	return std::string(*this) >= other;
}

bool operator>=(const std::string& lhs, const ls_string& rhs)
{
	return lhs >= ls_string(rhs).get_value();
}

bool ls_string::operator<=(const std::string& other)
{
	return std::string(*this) <= other;
}

bool operator<=(const std::string& lhs, const ls_string& rhs)
{
	return lhs <= ls_string(rhs).get_value();
}