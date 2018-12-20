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

class TLOBase
{
public:
	TLOBase();
	bool get_ls_object_from_tlo_member(int tlo_argc, PCHAR tlo_argv[], PCHAR member_name, int argc, PCHAR argv[], LSOBJECT& dest) const;
	bool execute_tlo_method(int tlo_argc, PCHAR tlo_argv[], PCHAR method_name, int argc, PCHAR argv[]) const;
	static std::string get_string_from_ls_object(LSOBJECT& ls_object);
	static bool get_bool_from_ls_object(LSOBJECT& ls_object);
	static int get_byte_from_ls_object(LSOBJECT& ls_object);
	static int get_int_from_ls_object(LSOBJECT& ls_object);
	static int64_t get_int64_from_ls_object(LSOBJECT& ls_object);
	static float get_float_from_ls_object(LSOBJECT& ls_object);
protected:
	std::string tlo_name_{};
	std::string ls_type_name_{};
	LSTypeDefinition* p_type_def_;
	LSOBJECT ls_object;
};

class LSObject
{
public:
	LSObject();
	LSObject(LSOBJECT& ls_object);
	bool get_bool_from_lso();
	int get_byte_from_lso();
	float get_float_from_lso();
	int get_int_from_lso();
	int64_t get_int64_from_lso();
	LSOBJECT& get_lso();
	std::string get_string_from_lso();
protected:
	void execute_method(PCHAR method, int argc, char* argv[]);	
	LSObject get_member(PCHAR member, int argc, char* argv[]);	
	bool has_inherited_member(PCHAR member) const;
	bool has_inherited_method(PCHAR method) const;
	bool has_member(PCHAR member) const;
	bool has_method(PCHAR method) const;
	LSOBJECT ls_object_;
};

void Initialize_Module_ISXPy();
void Shutdown_Module_ISXPy();
void Redirect_Output_to_Console();
bool GetLSObjectFromTLO(LSTypeDefinition* pTypeDef, PCHAR tlo_name, int tlo_argc, PCHAR tlo_argv[], PCHAR member_name, int argc, PCHAR argv[], LSOBJECT& dest);