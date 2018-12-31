#include "ISXPyPCH.h"
#include "ISXPy.h"

tasklet::tasklet()
{
	PyTaskletObject* p_object = PyTasklet_New(nullptr, nullptr);
	const boost::python::handle<> object_handle(reinterpret_cast<PyObject*>(boost::python::borrowed(p_object)));
	this->tasklet_object_ = boost::python::object(object_handle);
}

tasklet::tasklet(PyTaskletObject* p_tasklet_object)
{
	const boost::python::handle<> object_handle(reinterpret_cast<PyObject*>(boost::python::borrowed(p_tasklet_object)));
	this->tasklet_object_ = boost::python::object(object_handle);
}

tasklet::tasklet(const tasklet& other) = default;

tasklet::tasklet(tasklet&& other) noexcept
{
	this->tasklet_object_ = other.tasklet_object_;
}

tasklet::tasklet(const boost::python::object& func)
{
	PyTaskletObject* p_object = PyTasklet_New(nullptr, func.ptr());
	const boost::python::handle<> object_handle(reinterpret_cast<PyObject*>(boost::python::borrowed(p_object)));
	this->tasklet_object_ = boost::python::object(object_handle);
}

tasklet& tasklet::operator=(tasklet&& other) noexcept
{
	if (this != &other)
	{
		this->tasklet_object_ = other.tasklet_object_;
	}
	return *this;
}

tasklet& tasklet::operator=(const tasklet& other)
{
	if (this != &other)
	{
		this->tasklet_object_ = other.tasklet_object_;
	}
	return *this;
}

bool tasklet::setup(const boost::python::tuple& args, const boost::python::object& kwargs) const
{
	const int result = PyTasklet_Setup(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), args.ptr(),
	                                   kwargs.ptr());
	return result == 0;
}

bool tasklet::bind_ex(const boost::python::object& func, const boost::python::tuple& args,
                      const boost::python::object& kwargs) const
{
	return PyTasklet_BindEx(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), func.ptr(), args.ptr(),
	                        kwargs.ptr()) == 0;
}

bool tasklet::run() const
{
	return PyTasklet_Run(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())) == 0;
}

int tasklet::run_nr() const
{
	return PyTasklet_Run_nr(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()));
}

bool tasklet::switch_task() const
{
	return PyTasklet_Switch(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())) == 0;
}

int tasklet::switch_task_nr() const
{
	return PyTasklet_Switch_nr(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()));
}

bool tasklet::remove() const
{
	return PyTasklet_Remove(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())) == 0;
}

bool tasklet::insert() const
{
	return PyTasklet_Insert(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())) != -1;
}

int tasklet::raise_exception(const boost::python::object& klass, const boost::python::object& args) const
{
	return PyTasklet_RaiseException(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), klass.ptr(),
	                                args.ptr());
}

int tasklet::kill() const
{
	return PyTasklet_Kill(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()));
}

int tasklet::kill_ex(const bool& pending) const
{
	return PyTasklet_KillEx(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), int(pending));
}

bool tasklet::get_atomic() const
{
	return bool(PyTasklet_GetAtomic(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::set_atomic(const bool& is_atomic) const
{
	return bool(PyTasklet_SetAtomic(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), int(is_atomic)));
}

bool tasklet::get_ignore_nesting() const
{
	return bool(PyTasklet_GetIgnoreNesting(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::set_ignore_nesting(const bool& ignore_nesting) const
{
	return bool(PyTasklet_SetIgnoreNesting(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()),
	                                       int(ignore_nesting)));
}

bool tasklet::get_block_trap() const
{
	return bool(PyTasklet_GetBlockTrap(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

void tasklet::set_block_trap(const bool& block_trap) const
{
	PyTasklet_SetBlockTrap(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()), int(block_trap));
}

bool tasklet::is_main() const
{
	return bool(PyTasklet_IsMain(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::is_current() const
{
	return bool(PyTasklet_IsCurrent(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

int tasklet::get_recursion_depth() const
{
	return PyTasklet_GetRecursionDepth(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()));
}

int tasklet::get_nesting_level() const
{
	return PyTasklet_GetNestingLevel(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr()));
}

bool tasklet::is_alive() const
{
	return bool(PyTasklet_Alive(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::is_paused() const
{
	return bool(PyTasklet_Paused(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::is_scheduled() const
{
	return bool(PyTasklet_Scheduled(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

bool tasklet::is_restorable() const
{
	return bool(PyTasklet_Restorable(reinterpret_cast<PyTaskletObject*>(this->tasklet_object_.ptr())));
}

PyObject* tasklet::get_ptr() const
{
	return this->tasklet_object_.ptr();
}
