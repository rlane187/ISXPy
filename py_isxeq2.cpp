#include "ISXPyPCH.h"
#include "ISXPy.h"

py_isxeq2::py_isxeq2()
{
	pISInterface->IsTopLevelObject("ISXEQ2")(0, nullptr, *reinterpret_cast<LSOBJECT*>(this));
}

py_isxeq2::~py_isxeq2() = default;

py_isxeq2::py_isxeq2(const py_isxeq2& other) = default;

py_isxeq2::py_isxeq2(py_isxeq2&& other) noexcept = default;

py_isxeq2::py_isxeq2(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_isxeq2& py_isxeq2::operator=(const py_isxeq2& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_isxeq2& py_isxeq2::operator=(py_isxeq2&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

void py_isxeq2::add_loc(const std::string& label, const std::string& notes)
{
	char* const method = static_cast<char *>("AddLoc");
	const int argc = 1;
	const int argc_notes = 2;
	char* argv[argc];
	char* argv_notes[argc_notes];
	argv[0] = const_cast<char *>(label.c_str());
	argv_notes[0] = const_cast<char *>(label.c_str());
	argv_notes[1] = const_cast<char *>(notes.c_str());
	try
	{
		if (notes.empty())
			this->execute_method(method, argc, argv);
		else
			this->execute_method(method, argc_notes, argv_notes);
	}
	catch (exception&) {}
}

void py_isxeq2::clear_abilities_cache()
{
	char* const method = static_cast<char *>("ClearAbilitiesCache");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void py_isxeq2::disable_affliction_events()
{
	char* const method = static_cast<char *>("DisableAfflictionEvents");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void py_isxeq2::disable_custom_zoning_text()
{
	char* const method = static_cast<char *>("DisableCustomZoningText");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void py_isxeq2::enable_affliction_events()
{
	char* const method = static_cast<char *>("EnableAfflictionEvents");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void py_isxeq2::enable_custom_zoning_text()
{
	char* const method = static_cast<char *>("EnableCustomZoningText");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

bool py_isxeq2::get_affliction_events_on()
{
	char* const member = static_cast<char *>("AfflictionEventsOn");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

std::string py_isxeq2::get_api_version()
{
	char* const member = static_cast<char *>("APIVersion");
	try
	{
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	catch (exception &) {}
	return std::string("Error");
}

int py_isxeq2::get_eq2locs_count(const bool& all_zones)
{
	char* const member = static_cast<char *>("EQ2LocsCount");
	const int argc = 1;
	char* argv[argc];
	argv[0] = static_cast<char *>("AllZones");
	int count = 0;
	try
	{
		if (all_zones)
			count = this->get_member(member, argc, argv).get_int_from_lso();
		else
			count = this->get_member(member, 0, nullptr).get_int_from_lso();
	}
	catch (exception&) {}
	return count;
}

std::string py_isxeq2::get_version()
{
	char* const member = static_cast<char *>("Version");
	try
	{		
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	} 
	catch(exception &) {}
	return std::string("Error");
}

bool py_isxeq2::get_is_ready()
{
	char* const member = static_cast<char *>("IsReady");
	try
	{
		return this->get_member(member, 0, nullptr).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

bool py_isxeq2::get_is_valid_eq2press_key(const std::string& key_name)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(key_name.c_str());
	char* const member = static_cast<char *>("IsValidEQ2PressKey");
	try
	{
		return this->get_member(member, argc, argv).get_bool_from_lso();
	}
	catch (exception &) {}
	return false;
}

void py_isxeq2::popup(const std::string& message, const std::string& title, const std::string& status)
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(message.c_str());
	argv[1] = const_cast<char*>(title.c_str());
	argv[2] = const_cast<char*>(status.c_str());
	char* const method = static_cast<char *>("Popup");
	try
	{
		this->execute_method(method, argc, argv);
	}
	catch(exception&)	{}
}

void py_isxeq2::reset_internal_vending_system()
{
	char* const method = static_cast<char *>("ResetInternalVendingSystem");
	try
	{
		return this->execute_method(method, 0, nullptr);
	}
	catch (exception &) {}
}

void py_isxeq2::set_actor_events_range(const float& range)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(range).c_str());
	argv[0] = buffer;
	printf("%s", argv[0]);
	char* const method = static_cast<char *>("SetActorEventsRange");
	try
	{
		this->execute_method(method, argc, argv);
	}
	catch (exception&) {}
}

void py_isxeq2::set_actor_events_time_interval(const int& time)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	_itoa_s(time, buffer, _countof(buffer), 10);
	argv[0] = buffer;
	char* const method = static_cast<char *>("SetActorEventsTimeInterval");
	try
	{
		this->execute_method(method, argc, argv);
	}
	catch (exception&) {}
}

void py_isxeq2::set_affliction_events_time_interval(const int& interval)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	_itoa_s(interval, buffer, _countof(buffer), 10);
	argv[0] = buffer;
	char* const method = static_cast<char *>("SetAfflictionEventsTimeInterval");
	try
	{
		this->execute_method(method, argc, argv);
	}
	catch (exception&) {}
}
