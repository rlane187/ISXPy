#pragma once

class PyEQ2 : public PyLSObject
{
public:
	PyEQ2();
	std::string get_server_name();
	int query_actors(boost::python::list& actor_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_actors_overloads, query_actors, 1, 2)
};