#include "ISXPyPCH.h"
#include "ISXPy.h"

stackless_tasklet::stackless_tasklet(PyTaskletObject* p_tasklet_object)
{
	this->p_tasklet_object_ = p_tasklet_object;
}

stackless_tasklet::stackless_tasklet(boost::python::object* func)
{
	this->p_tasklet_object_ = PyTasklet_New(nullptr, func->ptr());
}

stackless_tasklet::stackless_tasklet()
{
	this->p_tasklet_object_ = PyTasklet_New(nullptr, nullptr);
}

bool stackless_tasklet::setup(boost::python::object* args, boost::python::object* kwargs) const
{
	const int result = PyTasklet_Setup(this->p_tasklet_object_, args->ptr(), kwargs->ptr());
	return result == 0;
}

bool stackless_tasklet::bind_ex(boost::python::object* func, boost::python::object* args, boost::python::object* kwargs) const
{
	return PyTasklet_BindEx(this->p_tasklet_object_, func->ptr(), args->ptr(), kwargs->ptr()) == 0;
}

bool stackless_tasklet::run() const
{
	return PyTasklet_Run(this->p_tasklet_object_) == 0;
}

int stackless_tasklet::run_nr() const
{
	return PyTasklet_Run_nr(this->p_tasklet_object_);
}

bool stackless_tasklet::switch_task() const
{
	return PyTasklet_Switch(this->p_tasklet_object_) == 0;
}

int stackless_tasklet::switch_task_nr() const
{
	return PyTasklet_Switch_nr(this->p_tasklet_object_);
}

bool stackless_tasklet::remove() const
{
	return PyTasklet_Remove(this->p_tasklet_object_) == 0;
}

bool stackless_tasklet::insert() const
{
	return PyTasklet_Insert(this->p_tasklet_object_) != -1;
}

int stackless_tasklet::raise_exception(boost::python::object* klass, boost::python::object* args) const
{
	return PyTasklet_RaiseException(this->p_tasklet_object_, klass->ptr(), args->ptr());
}

int stackless_tasklet::kill() const
{
	return PyTasklet_Kill(this->p_tasklet_object_);
}

int stackless_tasklet::kill_ex(const bool& pending) const
{
	return PyTasklet_KillEx(this->p_tasklet_object_, int(pending));
}

bool stackless_tasklet::get_atomic() const
{
	return bool(PyTasklet_GetAtomic(this->p_tasklet_object_));
}

bool stackless_tasklet::set_atomic(const bool& is_atomic) const
{
	return bool(PyTasklet_SetAtomic(this->p_tasklet_object_, int(is_atomic)));
}

bool stackless_tasklet::get_ignore_nesting() const
{
	return bool(PyTasklet_GetIgnoreNesting(this->p_tasklet_object_));
}

bool stackless_tasklet::set_ignore_nesting(const bool& ignore_nesting) const
{
	return bool(PyTasklet_SetIgnoreNesting(this->p_tasklet_object_, int(ignore_nesting)));
}

bool stackless_tasklet::get_block_trap() const
{
	return bool(PyTasklet_GetBlockTrap(this->p_tasklet_object_));
}

void stackless_tasklet::set_block_trap(const bool& block_trap) const
{
	PyTasklet_SetBlockTrap(this->p_tasklet_object_, int(block_trap));
}

bool stackless_tasklet::is_main() const
{
	return bool(PyTasklet_IsMain(this->p_tasklet_object_));
}

bool stackless_tasklet::is_current() const
{
	return bool(PyTasklet_IsCurrent(this->p_tasklet_object_));
}

int stackless_tasklet::get_recursion_depth() const
{
	return PyTasklet_GetRecursionDepth(this->p_tasklet_object_);
}

int stackless_tasklet::get_nesting_level() const
{
	return PyTasklet_GetNestingLevel(this->p_tasklet_object_);
}

bool stackless_tasklet::is_alive() const
{
	return bool(PyTasklet_Alive(this->p_tasklet_object_));
}

bool stackless_tasklet::is_paused() const
{
	return bool(PyTasklet_Paused(this->p_tasklet_object_));
}

bool stackless_tasklet::is_scheduled() const
{
	return bool(PyTasklet_Scheduled(this->p_tasklet_object_));
}

bool stackless_tasklet::is_restorable() const
{
	return bool(PyTasklet_Restorable(this->p_tasklet_object_));
}
