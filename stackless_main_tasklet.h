#pragma once

class stackless_main_tasklet : public stackless_tasklet
{
public:
	stackless_main_tasklet(const boost::python::object& main_tasklet_object);
};