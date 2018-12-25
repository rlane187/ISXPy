#pragma once

struct OutputHandler
{
	void write(std::string msg)
	{
		if(!msg.empty())
		{
			if(msg.size() == 1 && msg.c_str()[msg.size() - 1] == '\n')
				return;
			char buffer[2048];
			strcpy_s(buffer, _countof(buffer), "[Python] ");
			strcat_s(buffer, _countof(buffer), msg.c_str());
			printf(buffer);
		}		
	}

	void flush() { }

};

struct ErrorHandler
{
	void write(std::string msg)
	{
		if (!msg.empty())
		{
			if (msg.size() == 1 && msg.c_str()[msg.size() - 1] == '\n')
				return;
			char buffer[2048];
			strcpy_s(buffer, _countof(buffer), "[PythonError] ");
			strcat_s(buffer, _countof(buffer), msg.c_str());
			printf(buffer);
		}
	}

	void flush() { }

};

class py_lsobject
{
public:
	py_lsobject() = default;
	py_lsobject(LSOBJECT& ls_object);
	const LSOBJECT& get_lso() const;
	void execute_method(PCHAR method, int argc, char* argv[]);
	py_lsobject get_member(PCHAR member, int argc, char* argv[]);
	void get_member(PCHAR member, int argc, char* argv[], LSOBJECT& ls_object);
	template <class T>
	int get_list_from_index_method(PCHAR method, PCHAR index_type, PCHAR query, boost::python::list& python_list);
	bool get_bool_from_lso();
	int get_byte_from_lso();
	float get_float_from_lso();
	int get_int_from_lso();
	int64_t get_int64_from_lso();
	std::string get_string_from_lso();
	unsigned int get_uint_from_lso();
protected:
	LSOBJECT ls_object_;
private:	
	bool has_inherited_member(PCHAR member) const;
	bool has_inherited_method(PCHAR method) const;
	bool has_member(PCHAR member) const;
	bool has_method(PCHAR method) const;	
	
};

void Initialize_Module_ISXPy();
void Shutdown_Module_ISXPy();
void Redirect_Output_to_Console();
bool GetLSObjectFromTLO(LSTypeDefinition* pTypeDef, PCHAR tlo_name, int tlo_argc, PCHAR tlo_argv[], PCHAR member_name, int argc, PCHAR argv[], LSOBJECT& dest);