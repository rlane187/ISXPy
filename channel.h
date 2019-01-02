#pragma once

class channel
{
public:
	channel();
	channel(const channel& other);
	channel(channel&& other) noexcept;
	explicit channel(PyChannelObject* p_channel_object);
	bool send(const boost::python::tuple& arg = boost::python::tuple()) const;
	int send_nr(const boost::python::object& arg) const;
	bool receive(boost::python::object& arg) const;
	int receive_nr(boost::python::object& arg) const;
	bool send_exception(const boost::python::object& klass, const boost::python::object& value) const;
	bool get_queue(boost::python::object& tasklet) const;
	void close() const;
	void open() const;
	bool get_closing() const;
	bool get_closed() const;
	int get_preference() const;
	bool get_schedule_all() const;
	void set_schedule_all(const bool& schedule_all) const;
	int get_balance() const;
	boost::python::object get_channel_object() const;
	channel& operator=(channel&& other) noexcept;
	channel& operator=(const channel& other);
private:
	boost::python::object channel_object_;
};