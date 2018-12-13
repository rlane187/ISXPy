#pragma once
#include <winnt.h>
#include <minwindef.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
EXTERN_C char DllPath[MAX_PATH];
EXTERN_C wchar_t DllPathW[MAX_PATH];
EXTERN_C char ExtensionPath[MAX_PATH];
EXTERN_C wchar_t ExtensionPathW[MAX_PATH];
EXTERN_C char PythonHome[MAX_PATH];
EXTERN_C wchar_t PythonHomeW[MAX_PATH];
EXTERN_C char PythonPath[2048];
EXTERN_C wchar_t PythonPathW[2048];
EXTERN_C char PythonDLLs[MAX_PATH];
EXTERN_C wchar_t PythonDLLsW[MAX_PATH];
EXTERN_C char PythonLibs[MAX_PATH];
EXTERN_C wchar_t PythonLibsW[MAX_PATH];

