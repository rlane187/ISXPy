#pragma once
#include <winnt.h>
#include <minwindef.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

EXTERN_C char DllPath[MAX_PATH];
EXTERN_C wchar_t DllPathW[MAX_PATH];
EXTERN_C char PythonScriptPath[MAX_PATH];
EXTERN_C char PythonPath[MAX_PATH];
EXTERN_C wchar_t PythonPathW[MAX_PATH];
EXTERN_C char PythonLib[MAX_PATH];
EXTERN_C wchar_t PythonLibW[MAX_PATH];
EXTERN_C char PythonDLLs[MAX_PATH];
EXTERN_C wchar_t PythonDLLsW[MAX_PATH];
