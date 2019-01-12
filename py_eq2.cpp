#include "ISXPyPCH.h"
#include "ISXPy.h"

py_eq2::py_eq2()
{
	pISInterface->IsTopLevelObject("EQ2")(0, nullptr, this->lsobject_);
}

py_eq2::~py_eq2() = default;

py_eq2::py_eq2(const py_eq2& other) = default;

py_eq2::py_eq2(py_eq2&& other) noexcept = default;

py_eq2::py_eq2(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

py_eq2& py_eq2::operator=(const py_eq2& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

py_eq2& py_eq2::operator=(py_eq2&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

void py_eq2::accept_pending_quest()
{
	char* const method = static_cast<char *>("AcceptPendingQuest");
	this->execute_method(method, 0, nullptr);
}

bool py_eq2::check_collision(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z)
{
	const int argc = 6;
	char* argv[argc];
	char buffer_from_x[MAX_VARSTRING];
	char buffer_from_y[MAX_VARSTRING];
	char buffer_from_z[MAX_VARSTRING];
	char buffer_to_x[MAX_VARSTRING];
	char buffer_to_y[MAX_VARSTRING];
	char buffer_to_z[MAX_VARSTRING];
	strcpy_s(buffer_from_x, _countof(buffer_from_x), boost::lexical_cast<std::string>(from_x).c_str());
	strcpy_s(buffer_from_y, _countof(buffer_from_y), boost::lexical_cast<std::string>(from_y).c_str());
	strcpy_s(buffer_from_z, _countof(buffer_from_z), boost::lexical_cast<std::string>(from_z).c_str());
	strcpy_s(buffer_to_x, _countof(buffer_to_x), boost::lexical_cast<std::string>(to_x).c_str());
	strcpy_s(buffer_to_y, _countof(buffer_to_y), boost::lexical_cast<std::string>(to_y).c_str());
	strcpy_s(buffer_to_z, _countof(buffer_to_z), boost::lexical_cast<std::string>(to_z).c_str());
	argv[0] = buffer_from_x;
	argv[1] = buffer_from_y;
	argv[2] = buffer_from_z;
	argv[3] = buffer_to_x;
	argv[4] = buffer_to_y;
	argv[5] = buffer_to_z;
	char* const member = static_cast<char *>("CheckCollision");
	return this->get_member(member, argc, argv).get_bool_from_lso();
}

void py_eq2::confirm_zone_teleporter_destination()
{
	char* const method = static_cast<char *>("ConfirmZoneTeleporterDestination");
	this->execute_method(method, 0, nullptr);
}

void py_eq2::decline_pending_quest()
{
	char* const method = static_cast<char *>("DeclinePendingQuest");
	this->execute_method(method, 0, nullptr);
}

float py_eq2::heading_to(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z)
{
	const int argc = 6;
	char* argv[argc];
	char buffer_from_x[MAX_VARSTRING];
	char buffer_from_y[MAX_VARSTRING];
	char buffer_from_z[MAX_VARSTRING];
	char buffer_to_x[MAX_VARSTRING];
	char buffer_to_y[MAX_VARSTRING];
	char buffer_to_z[MAX_VARSTRING];
	strcpy_s(buffer_from_x, _countof(buffer_from_x), boost::lexical_cast<std::string>(from_x).c_str());
	strcpy_s(buffer_from_y, _countof(buffer_from_y), boost::lexical_cast<std::string>(from_y).c_str());
	strcpy_s(buffer_from_z, _countof(buffer_from_z), boost::lexical_cast<std::string>(from_z).c_str());
	strcpy_s(buffer_to_x, _countof(buffer_to_x), boost::lexical_cast<std::string>(to_x).c_str());
	strcpy_s(buffer_to_y, _countof(buffer_to_y), boost::lexical_cast<std::string>(to_y).c_str());
	strcpy_s(buffer_to_z, _countof(buffer_to_z), boost::lexical_cast<std::string>(to_z).c_str());
	argv[0] = buffer_from_x;
	argv[1] = buffer_from_y;
	argv[2] = buffer_from_z;
	argv[3] = buffer_to_x;
	argv[4] = buffer_to_y;
	argv[5] = buffer_to_z;
	char* const member = static_cast<char *>("HeadingTo");
	return this->get_member(member, argc, argv).get_float_from_lso();
}

int py_eq2::get_ho_current_wheel_slot()
{
	char* const member = static_cast<char *>("HOCurrentWheelSlot");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

std::string py_eq2::get_ho_description()
{
	char* const member = static_cast<char *>("HODescription");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2::get_ho_icon_id_1()
{
	char* const member = static_cast<char *>("HOIconID1");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_icon_id_2()
{
	char* const member = static_cast<char *>("HOIconID2");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_icon_id_3()
{
	char* const member = static_cast<char *>("HOIconID3");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_icon_id_4()
{
	char* const member = static_cast<char *>("HOIconID4");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_icon_id_5()
{
	char* const member = static_cast<char *>("HOIconID5");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_icon_id_6()
{
	char* const member = static_cast<char *>("HOIconID6");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

eq2_actor py_eq2::get_ho_last_manipulator()
{
	char* const member = static_cast<char *>("HOLastManipulator");
	eq2_actor actor_object = this->get_member(member, 0, nullptr).get_lso();
	return actor_object;
}

std::string py_eq2::get_ho_name()
{
	char* const member = static_cast<char *>("HOName");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

float py_eq2::get_ho_time_elapsed()
{
	char* const member = static_cast<char *>("HOTimeElapsed");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2::get_ho_time_limit()
{
	char* const member = static_cast<char *>("HOTimeLimit");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

float py_eq2::get_ho_time_remaining()
{
	char* const member = static_cast<char *>("HOTimeRemaining");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_eq2::get_ho_wheel_id()
{
	char* const member = static_cast<char *>("HOWheelID");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_wheel_state()
{
	char* const member = static_cast<char *>("HOWheelState");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_ho_wheel_type()
{
	char* const member = static_cast<char *>("HOWheelType");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_eq2::get_ho_window_active()
{
	char* const member = static_cast<char *>("HOWindowActive");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

int py_eq2::get_ho_window_state()
{
	char* const member = static_cast<char *>("HOWindowState");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

int py_eq2::get_inbox_mail_count()
{
	char* const member = static_cast<char *>("InboxMailCount");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

float py_eq2::get_master_volume()
{
	char* const member = static_cast<char *>("MasterVolume");
	return this->get_member(member, 0, nullptr).get_float_from_lso();
}

int py_eq2::get_num_radars()
{
	char* const member = static_cast<char *>("NumRadars");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

bool py_eq2::get_on_battleground()
{
	char* const member = static_cast<char *>("OnBattleground");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2::get_pending_quest_description()
{
	char* const member = static_cast<char *>("PendingQuestDescription");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

std::string py_eq2::get_pending_quest_name()
{
	char* const member = static_cast<char *>("PendingQuestName");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2::get_persistent_zones(boost::python::list& zone_list)
{
	LSOBJECT index_object;
	size_t size = 0;
	const int random = rand() % INT_MAX;
	const int argc = 1;
	char* argv[argc];
	char variable_name[MAX_VARSTRING];
	char declare_command[MAX_VARSTRING];
	char delete_command[MAX_VARSTRING];
	sprintf_s(variable_name, _countof(variable_name), "%s_%d", "ISXPy_index_random", random);
	sprintf_s(declare_command, _countof(declare_command), "DeclareVariable %s index:%s global", variable_name, "string");
	sprintf_s(delete_command, _countof(delete_command), "DeleteVariable %s", variable_name);
	argv[0] = variable_name;
	pISInterface->ExecuteCommand(declare_command);
	pISInterface->DataParse(argv[0], index_object);
	this->execute_method(const_cast<char*>("GetPersistentZones"), argc, argv);
	size = static_cast<LSIndex*>(index_object.Ptr)->GetContainerUsed();
	for (size_t i = 0; i < size; i++)
	{
		//auto thing = ls_object(*(*static_cast<LSIndex*>(index_object.Ptr)->GetIndex())[i]);
		//printf(thing.get_string_from_lso().c_str());
		zone_list.append(ls_object(*(*static_cast<LSIndex*>(index_object.Ptr)->GetIndex())[i]).get_mutable_string_from_lso());
	}
	pISInterface->ExecuteCommand(delete_command);
	return len(zone_list);
}

bool py_eq2::get_ready_to_refine_transmute_or_salvage()
{
	char* const member = static_cast<char *>("ReadyToRefineTransmuteOrSalvage");
	return this->get_member(member, 0, nullptr).get_bool_from_lso();
}

std::string py_eq2::get_server_name()
{
	char* const member = static_cast<char *>("ServerName");
	return this->get_member(member, 0, nullptr).get_string_from_lso();
}

int py_eq2::get_zoning()
{
	char* const member = static_cast<char *>("Zoning");
	return this->get_member(member, 0, nullptr).get_int_from_lso();
}

unsigned int py_eq2::persistent_zone_id(const std::string& zone_name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), zone_name.c_str());
	argv[0] = buffer;
	char* const member = static_cast<char *>("PersistentZoneID");
	return this->get_member(member, argc, argv).get_uint_from_lso();
}

void py_eq2::set_master_volume(const float& percent)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(percent).c_str());
	argv[0] = buffer;
	char* const method = static_cast<char *>("SetMasterVolume");
	this->execute_method(method, argc, argv);
}

void py_eq2::toggle_show_all_on_screen_announcements()
{
	char* const method = static_cast<char *>("ShowAllOnScreenAnnouncements");
	this->execute_method(method, 0, nullptr);
}
