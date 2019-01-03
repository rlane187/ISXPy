#pragma once

class tasklet
{
public:
	tasklet();
	tasklet(const tasklet& other);
	tasklet(tasklet&& other) noexcept;
	explicit tasklet(PyTaskletObject* p_tasklet_object);
	explicit tasklet(const boost::python::object& func);
	bool setup(const boost::python::tuple& args = boost::python::tuple(), const boost::python::object& kwargs = boost::python::object()) const;
	bool bind_ex(const boost::python::object& func, const boost::python::tuple& args = boost::python::tuple(), const boost::python::dict& kwargs = boost::python::dict()) const;
	bool run() const;
	int run_nr() const;
	bool switch_task() const;
	int switch_task_nr() const;
	bool remove() const;
	bool insert() const;
	int raise_exception(const boost::python::object& klass, const boost::python::object& args) const;
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
	PyObject* get_ptr() const;
	tasklet& operator=(tasklet&& other) noexcept;
	tasklet& operator=(const tasklet& other);
private:
	boost::python::object tasklet_object_;
};