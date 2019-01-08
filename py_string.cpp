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

std::string py_string::mid(const unsigned int& position, const unsigned int& length)
{
	const int argc = 2;
	char* argv[argc];
	char buffer_position[MAX_VARSTRING];
	char buffer_length[MAX_VARSTRING];
	sprintf_s(buffer_position, _countof(buffer_position), "%u", position);
	sprintf_s(buffer_length, _countof(buffer_length), "%u", length);
	argv[0] = buffer_position;
	argv[1] = buffer_length;
	char* const member = static_cast<char *>("Mid");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

std::string py_string::left(const int& num_chars)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%d", num_chars);
	argv[0] = buffer;
	char* const member = static_cast<char*>("Left");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

std::string py_string::right(const int& num_chars)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	sprintf_s(buffer, _countof(buffer), "%d", num_chars);
	argv[0] = buffer;
	char* const member = static_cast<char*>("Right");
	return py_string(this->get_member(member, argc, argv).get_lso()).get_value();
}

int64_t py_string::find(const std::string& substring)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), substring.c_str());
	argv[0] = buffer;
	char* const member = static_cast<char*>("Find");
	return py_int64(this->get_member(member, argc, argv).get_lso()).get_value();
}

int64_t py_string::get_length()
{
	char* const member = static_cast<char*>("Length");
	return py_int64(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_string::get_lower()
{
	char* const member = static_cast<char*>("Lower");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}

std::string py_string::get_upper()
{
	char* const member = static_cast<char*>("Upper");
	return py_string(this->get_member(member, 0, nullptr).get_lso()).get_value();
}