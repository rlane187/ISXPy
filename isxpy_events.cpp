#include "ISXPyPCH.h"
#include "ISXPy.h"

boost::python::object pulse_channel = boost::python::object();

void initialize_isxpy_events()
{
	setup_channel("isxpy", "pulse_channel", pulse_channel);
}

void shutdown_isxpy_events()
{
	stop_channel(pulse_channel);
}

void on_frame(int argc, char* argv[], PLSOBJECT p_lsobject)
{
	using namespace boost::python;
	frame_count += 1;
	channel c(pulse_channel);
	int balance = c.get_balance();
	if (Py_IsInitialized() && balance < 0)
	{
		try
		{
			const int max_iterations = 100;
			int current_iteration = 1;
			while (current_iteration < max_iterations && balance < 0)
			{
				tasklet t;
				boost::python::list args_list;
				args_list.append(frame_count);
				boost::python::tuple args(args_list);
				if (t.bind_ex(pulse_channel.attr("send"), args))
					t.run();
				balance++;
				current_iteration++;
			}
		}
		catch (error_already_set&)
		{
			PyErr_Print();
		}
	}
	if (Py_IsInitialized() && stackless_module::get_run_count() > 0)
	{
		try
		{
			stackless_module::on_pulse();
		}
		catch (error_already_set&)
		{
			PyErr_Print();
		}
	}
}