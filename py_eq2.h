#pragma once

class py_eq2 : public py_lsobject
{
public:
	py_eq2();
	std::string get_server_name();
	int query_actors(boost::python::list& actor_list, const std::string& query = std::string());
	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(query_actors_overloads, query_actors, 1, 2)
	int get_zoning();
};