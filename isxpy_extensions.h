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

void Initialize_Module_ISXPy();
void Shutdown_Module_ISXPy();
void Redirect_Output_to_Console();
void AdjustPath();
int QuitScript();
boost::python::object get_pulse_channel();
int get_frame_count();