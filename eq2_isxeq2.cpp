#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_isxeq2::eq2_isxeq2()
{
	pISInterface->IsTopLevelObject("ISXEQ2")(0, nullptr, this->lsobject_);
}

eq2_isxeq2::~eq2_isxeq2() = default;

eq2_isxeq2::eq2_isxeq2(const eq2_isxeq2& other) = default;

eq2_isxeq2::eq2_isxeq2(eq2_isxeq2&& other) noexcept = default;

eq2_isxeq2::eq2_isxeq2(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_isxeq2& eq2_isxeq2::operator=(const eq2_isxeq2& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_isxeq2& eq2_isxeq2::operator=(eq2_isxeq2&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

void eq2_isxeq2::add_loc(const std::string& label, const std::string& notes)
{
	const int argc = 1;
	const int argc_notes = 2;
	char* argv[argc];
	char* argv_notes[argc_notes];
	argv[0] = const_cast<char *>(label.c_str());
	argv_notes[0] = const_cast<char *>(label.c_str());
	argv_notes[1] = const_cast<char *>(notes.c_str());
	if (notes.empty())
		this->execute_method("AddLoc", argc, argv);
	else
		this->execute_method("AddLoc", argc_notes, argv_notes);
}

void eq2_isxeq2::clear_abilities_cache()
{
	return this->execute_method("ClearAbilitiesCache");
}

void eq2_isxeq2::disable_affliction_events()
{
	return this->execute_method("DisableAfflictionEvents");
}

void eq2_isxeq2::disable_custom_zoning_text()
{
	return this->execute_method("DisableCustomZoningText");
}

void eq2_isxeq2::enable_affliction_events()
{
	return this->execute_method("EnableAfflictionEvents");
}

void eq2_isxeq2::enable_custom_zoning_text()
{
	return this->execute_method("EnableCustomZoningText");
}

ls_bool eq2_isxeq2::get_affliction_events_on()
{
	return this->get_member("AfflictionEventsOn");
}

ls_string eq2_isxeq2::get_api_version()
{
	return this->get_member("APIVersion");
}

ls_int eq2_isxeq2::get_eq2locs_count(const bool& all_zones)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char *>("AllZones");
	if (all_zones)
		return this->get_member("EQ2LocsCount", argc, argv);
	else
		return this->get_member("EQ2LocsCount");
}

ls_string eq2_isxeq2::get_version()
{
	return this->get_member("Version");
}

ls_bool eq2_isxeq2::get_is_ready()
{
	return this->get_member("IsReady");
}

ls_bool eq2_isxeq2::get_is_valid_eq2press_key(const std::string& key_name)
{
	const int argc = 1;
	char* argv[argc];
	argv[0] = const_cast<char*>(key_name.c_str());
	return this->get_member("IsValidEQ2PressKey", argc, argv);
}

void eq2_isxeq2::popup(const std::string& message, const std::string& title, const std::string& status)
{
	const int argc = 3;
	char* argv[argc];
	argv[0] = const_cast<char*>(message.c_str());
	argv[1] = const_cast<char*>(title.c_str());
	argv[2] = const_cast<char*>(status.c_str());
	this->execute_method("Popup", argc, argv);
}

void eq2_isxeq2::reset_internal_vending_system()
{
	return this->execute_method("ResetInternalVendingSystem");
}

void eq2_isxeq2::set_actor_events_range(const float& range)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(range).c_str());
	argv[0] = buffer;
	this->execute_method("SetActorEventsRange", argc, argv);
}

void eq2_isxeq2::set_actor_events_time_interval(const int& time)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	_itoa_s(time, buffer, _countof(buffer), 10);
	argv[0] = buffer;
	this->execute_method("SetActorEventsTimeInterval", argc, argv);
}

void eq2_isxeq2::set_affliction_events_time_interval(const int& interval)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	_itoa_s(interval, buffer, _countof(buffer), 10);
	argv[0] = buffer;
	this->execute_method("SetAfflictionEventsTimeInterval", argc, argv);
}
