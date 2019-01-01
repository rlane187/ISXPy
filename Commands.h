#ifndef COMMAND
#define COMMAND_SELF
#define COMMAND(name,cmd,parse,hide) extern int cmd(int argc, char *argv[])
#endif
// ----------------------------------------------------
// commands

// sample
COMMAND("Py",CMD_Py,true,false);
COMMAND("RunPyScript", CMD_RunPythonScript, true, false);
COMMAND("EndPyScript", CMD_EndPythonScript, true, false);
COMMAND("RunPyScriptUnsafe", CMD_RunPythonScriptUnsafe, true, false);
COMMAND("EndPyScriptUnsafe", CMD_EndPythonScriptUnsafe, true, false);
COMMAND("GetType", CMD_GetType, true, false);
COMMAND("GetPythonPath", CMD_GetPythonPath, true, false);





// ----------------------------------------------------
#ifdef COMMAND_SELF
#undef COMMAND_SELF
#undef COMMAND
#endif