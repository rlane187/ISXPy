#include "ISXPyPCH.h"
#include "ISXPy.h"

bool stackless_module::schedule(const bool& remove)
{
	PyObject* p_object = nullptr;
	PyStackless_Schedule(p_object, int(remove));
	return p_object != nullptr;
}

int stackless_module::schedule_nr(const bool& remove)
{
	PyObject* p_object = nullptr;
	PyStackless_Schedule_nr(p_object, int(remove));
	if (p_object == nullptr)
		return -1;
	if (p_object == reinterpret_cast<PyObject*>(Py_UnwindToken))
		return 1;
	return 0;
}

int stackless_module::get_run_count()
{
	return PyStackless_GetRunCount();
}

bool stackless_module::get_current(boost::python::object& tasklet)
{
	PyObject* p_object = PyStackless_GetCurrent();
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	tasklet = boost::python::object(object_handle);
	return p_object != nullptr;
}

long stackless_module::get_current_id()
{
	return PyStackless_GetCurrentId();
}

int stackless_module::run_watchdog(const long& time_out, boost::python::object& tasklet)
{
	PyObject* p_object = PyStackless_RunWatchdog(time_out);
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	tasklet = boost::python::object(object_handle);
	if (p_object == nullptr)
		return -1;
	if (p_object == Py_None)
		return 0;
	return 1;
}

int stackless_module::run_watchdog_ex(const long& time_out, const int& flags, boost::python::object& tasklet)
{
	PyObject* p_object = PyStackless_RunWatchdogEx(time_out, flags);
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	tasklet = boost::python::object(object_handle);
	if (p_object == nullptr)
		return -1;
	if (p_object == Py_None)
		return 0;
	return 1;
}

bool stackless_module::call_main(const boost::python::object& func, const boost::python::object& args, const boost::python::object& kwargs)
{
	PyObject* p_object = PyStackless_Call_Main(func.ptr(), args.ptr(), kwargs.ptr());
	return p_object != nullptr;
}

bool stackless_module::call_method_main(const boost::python::object& py_object, PCHAR name, PCHAR format)
{
	PyObject* p_object = PyStackless_CallMethod_Main(py_object.ptr(), name, format);
	return p_object != nullptr;
}

bool stackless_module::on_pulse()
{
	boost::python::object tasklet_object;
	run_watchdog_ex(100, PY_WATCHDOG_TOTALTIMEOUT, tasklet_object);
	if (tasklet_object.is_none())
		return true;
	if(tasklet_object.ptr() != nullptr)
	{
		tasklet t(reinterpret_cast<PyTaskletObject*>(tasklet_object.ptr()));
		return t.insert();
	}
	return false;
}

void stackless_module::kill_all()
{
	boost::python::object tasklet_object;
	run_watchdog_ex(1, PY_WATCHDOG_TOTALTIMEOUT, tasklet_object);
	const int max_iterations = 100;
	int current_iteration = 1;
	while (tasklet_object.ptr() != nullptr && current_iteration <= max_iterations)
	{
		tasklet t(reinterpret_cast<PyTaskletObject*>(tasklet_object.ptr()));
		t.kill_ex();
		run_watchdog_ex(1, PY_WATCHDOG_TOTALTIMEOUT, tasklet_object);
		current_iteration++;
		if (current_iteration >= max_iterations)
			printf("stackless_module.kill_all() failed on max iterations.");
	}
}
