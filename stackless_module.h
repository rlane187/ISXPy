#pragma once

class stackless_module
{
public:
	static bool schedule(const bool& remove);
	static int schedule_nr(const bool& remove);
	static int get_run_count();
	static bool get_current(boost::python::object& tasklet);
	static long get_current_id();
	static int run_watchdog(const long& time_out, boost::python::object& tasklet);
	static int run_watchdog_ex(const long& time_out, const int& flags, boost::python::object& tasklet);
	static bool call_main(const boost::python::object& func,
	                      const boost::python::object& args = boost::python::object(),
	                      const boost::python::object& kwargs = boost::python::object());
	static bool call_method_main(const boost::python::object& py_object, PCHAR name, PCHAR format);
	static bool on_pulse();
};