#include "ISXPyPCH.h"
#include "ISXPy.h"

channel::channel()
{
	PyChannelObject* p_object = PyChannel_New(nullptr);
	const boost::python::handle<> object_handle(reinterpret_cast<PyObject*>(boost::python::borrowed(p_object)));
	this->channel_object_ = boost::python::object(object_handle);
}

channel::channel(PyChannelObject* p_channel_object)
{
	const boost::python::handle<> object_handle(reinterpret_cast<PyObject*>(boost::python::borrowed(p_channel_object)));
	this->channel_object_ = boost::python::object(object_handle);
}

channel::channel(const channel& other) = default;

channel::channel(channel&& other) noexcept : channel_object_(nullptr)
{
	this->channel_object_ = other.channel_object_;
}

channel& channel::operator=(channel&& other) noexcept
{
	if (this != &other)
	{
		this->channel_object_ = other.channel_object_;
	}
	return *this;
}

channel& channel::operator=(const channel& other)
{
	if (this != &other)
	{
		this->channel_object_ = other.channel_object_;
	}
	return *this;
}

bool channel::send(const boost::python::object& arg) const
{
	return bool(PyChannel_Send(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()), arg.ptr()));
}

int channel::send_nr(const boost::python::object& arg) const
{
	return PyChannel_Send_nr(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()), arg.ptr());
}

bool channel::receive(boost::python::object& arg) const
{
	PyObject* p_object = PyChannel_Receive(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	arg = boost::python::object(object_handle);
	return p_object != nullptr;
}

int channel::receive_nr(boost::python::object& arg) const
{
	PyObject* p_object = PyChannel_Receive_nr(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	arg = boost::python::object(object_handle);
	if (p_object == nullptr)
		return -1;
	if (p_object == reinterpret_cast<PyObject*>(Py_UnwindToken))
		return 1;
	return 0;
}

bool channel::send_exception(const boost::python::object& klass, const boost::python::object& value) const
{
	return PyChannel_SendException(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()), klass.ptr(), value.ptr()) == 0;
}

bool channel::get_queue(boost::python::object& tasklet) const
{
	PyObject* p_object = PyChannel_GetQueue(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
	const boost::python::handle<> object_handle(boost::python::borrowed(p_object));
	tasklet = boost::python::object(object_handle);
	return p_object != nullptr;
}

void channel::close() const
{
	PyChannel_Close(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
}

void channel::open() const
{
	PyChannel_Open(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
}

bool channel::get_closing() const
{
	return PyChannel_GetClosing(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr())) == 1;
}

bool channel::get_closed() const
{
	return PyChannel_GetClosed(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr())) == 1;
}

int channel::get_preference() const
{
	return PyChannel_GetPreference(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
}

bool channel::get_schedule_all() const
{
	return bool(PyChannel_GetScheduleAll(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr())));
}

void channel::set_schedule_all(const bool& schedule_all) const
{
	PyChannel_SetScheduleAll(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()), int(schedule_all));
}

int channel::get_balance() const
{
	return PyChannel_GetBalance(reinterpret_cast<PyChannelObject*>(this->channel_object_.ptr()));
}
