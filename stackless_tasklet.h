#pragma once

class stackless_tasklet
{
public:
	stackless_tasklet();
	stackless_tasklet(PyTaskletObject* p_tasklet_object);
	stackless_tasklet(boost::python::object* func);
	bool setup(boost::python::object* args, boost::python::object* kwargs) const;
	bool bind_ex(boost::python::object* func, boost::python::object* args, boost::python::object* kwargs) const;
	bool run() const;
	int run_nr() const;
	bool switch_task() const;
	int switch_task_nr() const;
	bool remove() const;
	bool insert() const;
	int raise_exception(boost::python::object* klass, boost::python::object* args) const;
	int kill() const;
	int kill_ex(const bool& pending = false) const;
	bool get_atomic() const;
	bool set_atomic(const bool& is_atomic) const;
	bool get_ignore_nesting() const;
	bool set_ignore_nesting(const bool& ignore_nesting) const;
	bool get_block_trap() const;
	void set_block_trap(const bool& block_trap) const;
	bool is_main() const;
	bool is_current() const;
	int get_recursion_depth() const;
	int get_nesting_level() const;
	bool is_alive() const;
	bool is_paused() const;
	bool is_scheduled() const;
	bool is_restorable() const;
private:
	PyTaskletObject* p_tasklet_object_;
};