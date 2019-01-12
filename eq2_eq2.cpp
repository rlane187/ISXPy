#include "ISXPyPCH.h"
#include "ISXPy.h"

eq2_eq2::eq2_eq2()
{
	pISInterface->IsTopLevelObject("EQ2")(0, nullptr, this->lsobject_);
}

eq2_eq2::~eq2_eq2() = default;

eq2_eq2::eq2_eq2(const eq2_eq2& other) = default;

eq2_eq2::eq2_eq2(eq2_eq2&& other) noexcept = default;

eq2_eq2::eq2_eq2(const LSOBJECT& other)
{
	this->lsobject_ = other;
}

eq2_eq2& eq2_eq2::operator=(const eq2_eq2& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

eq2_eq2& eq2_eq2::operator=(eq2_eq2&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

void eq2_eq2::accept_pending_quest()
{
	char* const method = static_cast<char *>("AcceptPendingQuest");
	this->execute_method(method);
}

ls_bool eq2_eq2::check_collision(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z)
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
	return this->get_member("CheckCollision", argc, argv);
}

ls_bool eq2_eq2::check_collision_ls(const ls_float& from_x, const ls_float& from_y, const ls_float& from_z, const ls_float& to_x, const ls_float& to_y, const ls_float& to_z)
{
	const int argc = 6;
	char* argv[argc];
	char buffer_from_x[MAX_VARSTRING];
	char buffer_from_y[MAX_VARSTRING];
	char buffer_from_z[MAX_VARSTRING];
	char buffer_to_x[MAX_VARSTRING];
	char buffer_to_y[MAX_VARSTRING];
	char buffer_to_z[MAX_VARSTRING];
	strcpy_s(buffer_from_x, _countof(buffer_from_x), boost::lexical_cast<std::string>(ls_float(from_x).get_value()).c_str());
	strcpy_s(buffer_from_y, _countof(buffer_from_y), boost::lexical_cast<std::string>(ls_float(from_y).get_value()).c_str());
	strcpy_s(buffer_from_z, _countof(buffer_from_z), boost::lexical_cast<std::string>(ls_float(from_z).get_value()).c_str());
	strcpy_s(buffer_to_x, _countof(buffer_to_x), boost::lexical_cast<std::string>(ls_float(to_x).get_value()).c_str());
	strcpy_s(buffer_to_y, _countof(buffer_to_y), boost::lexical_cast<std::string>(ls_float(to_y).get_value()).c_str());
	strcpy_s(buffer_to_z, _countof(buffer_to_z), boost::lexical_cast<std::string>(ls_float(to_z).get_value()).c_str());
	argv[0] = buffer_from_x;
	argv[1] = buffer_from_y;
	argv[2] = buffer_from_z;
	argv[3] = buffer_to_x;
	argv[4] = buffer_to_y;
	argv[5] = buffer_to_z;
	return this->get_member("CheckCollision", argc, argv);
}

void eq2_eq2::confirm_zone_teleporter_destination()
{
	char* const method = static_cast<char *>("ConfirmZoneTeleporterDestination");
	this->execute_method(method);
}

void eq2_eq2::decline_pending_quest()
{
	char* const method = static_cast<char *>("DeclinePendingQuest");
	this->execute_method(method);
}

ls_float eq2_eq2::heading_to(const float& from_x, const float& from_y, const float& from_z, const float& to_x, const float& to_y, const float& to_z)
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
	return this->get_member("HeadingTo", argc, argv);
}

ls_float eq2_eq2::heading_to_ls(const ls_float& from_x, const ls_float& from_y, const ls_float& from_z, const ls_float& to_x, const ls_float& to_y, const ls_float& to_z)
{
	const int argc = 6;
	char* argv[argc];
	char buffer_from_x[MAX_VARSTRING];
	char buffer_from_y[MAX_VARSTRING];
	char buffer_from_z[MAX_VARSTRING];
	char buffer_to_x[MAX_VARSTRING];
	char buffer_to_y[MAX_VARSTRING];
	char buffer_to_z[MAX_VARSTRING];
	strcpy_s(buffer_from_x, _countof(buffer_from_x), boost::lexical_cast<std::string>(ls_float(from_x).get_value()).c_str());
	strcpy_s(buffer_from_y, _countof(buffer_from_y), boost::lexical_cast<std::string>(ls_float(from_y).get_value()).c_str());
	strcpy_s(buffer_from_z, _countof(buffer_from_z), boost::lexical_cast<std::string>(ls_float(from_z).get_value()).c_str());
	strcpy_s(buffer_to_x, _countof(buffer_to_x), boost::lexical_cast<std::string>(ls_float(to_x).get_value()).c_str());
	strcpy_s(buffer_to_y, _countof(buffer_to_y), boost::lexical_cast<std::string>(ls_float(to_y).get_value()).c_str());
	strcpy_s(buffer_to_z, _countof(buffer_to_z), boost::lexical_cast<std::string>(ls_float(to_z).get_value()).c_str());
	argv[0] = buffer_from_x;
	argv[1] = buffer_from_y;
	argv[2] = buffer_from_z;
	argv[3] = buffer_to_x;
	argv[4] = buffer_to_y;
	argv[5] = buffer_to_z;
	return this->get_member("HeadingTo", argc, argv);
}

ls_int eq2_eq2::get_ho_current_wheel_slot()
{
	return this->get_member("HOCurrentWheelSlot");
}

ls_string eq2_eq2::get_ho_description()
{
	return this->get_member("HODescription");
}

ls_int eq2_eq2::get_ho_icon_id_1()
{
	return this->get_member("HOIconID1");
}

ls_int eq2_eq2::get_ho_icon_id_2()
{
	return this->get_member("HOIconID2");
}

ls_int eq2_eq2::get_ho_icon_id_3()
{
	return this->get_member("HOIconID3");
}

ls_int eq2_eq2::get_ho_icon_id_4()
{
	return this->get_member("HOIconID4");
}

ls_int eq2_eq2::get_ho_icon_id_5()
{
	return this->get_member("HOIconID5");
}

ls_int eq2_eq2::get_ho_icon_id_6()
{
	return this->get_member("HOIconID6");
}

eq2_actor eq2_eq2::get_ho_last_manipulator()
{
	return this->get_member("HOLastManipulator");
}

ls_string eq2_eq2::get_ho_name()
{
	return this->get_member("HOName");
}

ls_float eq2_eq2::get_ho_time_elapsed()
{
	return this->get_member("HOTimeElapsed");
}

ls_float eq2_eq2::get_ho_time_limit()
{
	return this->get_member("HOTimeLimit");
}

ls_float eq2_eq2::get_ho_time_remaining()
{
	return this->get_member("HOTimeRemaining");
}

ls_int eq2_eq2::get_ho_wheel_id()
{
	return this->get_member("HOWheelID");
}

ls_int eq2_eq2::get_ho_wheel_state()
{
	char* const member = static_cast<char *>("HOWheelState");
	return this->get_member(member);
}

ls_int eq2_eq2::get_ho_wheel_type()
{
	return this->get_member("HOWheelState");
}

ls_bool eq2_eq2::get_ho_window_active()
{
	return this->get_member("HOWindowActive");
}

ls_int eq2_eq2::get_ho_window_state()
{
	return this->get_member("HOWindowState");
}

ls_int eq2_eq2::get_inbox_mail_count()
{
	return this->get_member("InboxMailCount");
}

ls_float eq2_eq2::get_master_volume()
{
	return this->get_member("MasterVolume");
}

ls_int eq2_eq2::get_num_radars()
{
	return this->get_member("NumRadars");
}

ls_bool eq2_eq2::get_on_battleground()
{
	return this->get_member("OnBattleground");
}

ls_string eq2_eq2::get_pending_quest_description()
{
	return this->get_member("PendingQuestDescription");
}

ls_string eq2_eq2::get_pending_quest_name()
{
	return this->get_member("PendingQuestName");
}

int eq2_eq2::get_persistent_zones(boost::python::list& zone_list)
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
	this->execute_method("GetPersistentZones", argc, argv);
	size = static_cast<LSIndex*>(index_object.Ptr)->GetContainerUsed();
	for (size_t i = 0; i < size; i++)
	{
		zone_list.append(ls_object(*(*static_cast<LSIndex*>(index_object.Ptr)->GetIndex())[i]).get_mutable_string_from_lso());
	}
	pISInterface->ExecuteCommand(delete_command);
	return len(zone_list);
}

ls_bool eq2_eq2::get_ready_to_refine_transmute_or_salvage()
{
	return this->get_member("ReadyToRefineTransmuteOrSalvage");
}

ls_string eq2_eq2::get_server_name()
{
	return this->get_member("ServerName");
}

ls_int eq2_eq2::get_zoning()
{
	return this->get_member("Zoning");
}

ls_int eq2_eq2::persistent_zone_id(const std::string& zone_name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), zone_name.c_str());
	argv[0] = buffer;
	return this->get_member("PersistentZoneID", argc, argv);
}

ls_int eq2_eq2::persistent_zone_id_ls(const ls_string& zone_name)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), ls_string(zone_name).get_value().c_str());
	argv[0] = buffer;
	return this->get_member("PersistentZoneID", argc, argv);
}

void eq2_eq2::set_master_volume(const float& percent)
{
	const int argc = 1;
	char* argv[argc];
	char buffer[MAX_VARSTRING];
	strcpy_s(buffer, _countof(buffer), boost::lexical_cast<std::string>(percent).c_str());
	argv[0] = buffer;
	char* const method = static_cast<char *>("SetMasterVolume");
	this->execute_method(method, argc, argv);
}

void eq2_eq2::toggle_show_all_on_screen_announcements()
{
	char* const method = static_cast<char *>("ShowAllOnScreenAnnouncements");
	this->execute_method(method);
}
