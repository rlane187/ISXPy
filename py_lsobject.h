#pragma once

struct output_handler
{
	void write(const std::string& msg) const
	{
		char message_buffer[MAX_VARSTRING];
		strcpy_s(message_buffer, _countof(message_buffer), msg.c_str());
		if (message_buffer[strlen(message_buffer) - 1] == '\n')
		{
			message_buffer[strlen(message_buffer) - 1] = '\0';
			if (strlen(message_buffer) == 0)
				return;
		}			
		char buffer[MAX_VARSTRING];
		strcpy_s(buffer, _countof(buffer), "[Python] ");
		strcat_s(buffer, _countof(buffer), message_buffer);
		printf(buffer);		
	}

	void flush() {}

};

struct error_handler
{
	void write(const std::string& msg) const
	{
		char message_buffer[MAX_VARSTRING];
		strcpy_s(message_buffer, _countof(message_buffer), msg.c_str());
		if (message_buffer[strlen(message_buffer) - 1] == '\n')
		{
			message_buffer[strlen(message_buffer) - 1] = '\0';
			if (strlen(message_buffer) == 0)
				return;
		}
		char buffer[MAX_VARSTRING];
		strcpy_s(buffer, _countof(buffer), "[PythonError] ");
		strcat_s(buffer, _countof(buffer), message_buffer);
		printf(buffer);
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
void AdjustPath();
int QuitScript();