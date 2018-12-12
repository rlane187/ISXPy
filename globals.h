#pragma once
#include <winnt.h>
#include <minwindef.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
EXTERN_C char DllPath[MAX_PATH];
EXTERN_C char PythonHome[MAX_PATH];
