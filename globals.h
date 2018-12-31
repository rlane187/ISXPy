#pragma once
#include <winnt.h>
#include <minwindef.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

EXTERN_C char DllPath[MAX_PATH];
EXTERN_C wchar_t DllPathW[MAX_PATH];
EXTERN_C char PythonScriptPath[MAX_PATH];
EXTERN_C char PythonPath[MAX_VARSTRING];
EXTERN_C wchar_t PythonPathW[MAX_VARSTRING];
EXTERN_C char PythonLib[MAX_VARSTRING];
EXTERN_C wchar_t PythonLibW[MAX_VARSTRING];
EXTERN_C char PythonDLLs[MAX_VARSTRING];
EXTERN_C wchar_t PythonDLLsW[MAX_VARSTRING];

EXTERN_C unsigned int FrameCount;

EXTERN_C tasklet* p_Main_Tasklet;

EXTERN_C std::map<PCHAR, tasklet*> tasklet_map;