#pragma once

struct OutputHandler
{
	void write(std::string msg)
	{
		printf(msg.c_str());
	}
};

void Initialize_Module_ISXPy();
void Shutdown_Module_ISXPy();