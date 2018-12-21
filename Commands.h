#ifndef COMMAND
#define COMMAND_SELF
#define COMMAND(name,cmd,parse,hide) extern int cmd(int argc, char *argv[])
#endif
// ----------------------------------------------------
// commands

// sample
COMMAND("Py",CMD_Py,true,false);
COMMAND("RunPySub", CMD_RunPythonScriptSubprocess, true, false);
COMMAND("RunPy", CMD_RunPythonScript, true, false);
COMMAND("GetType", CMD_GetType, true, false);




// ----------------------------------------------------
#ifdef COMMAND_SELF
#undef COMMAND_SELF
#undef COMMAND
#endif