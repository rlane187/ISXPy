#include "ISXPyPCH.h"
#include "ISXPy.h"

int CMD_Py(int argc, char *argv[])
{
	size_t chars_conv;
	wchar_t path_w[MAX_VARSTRING];
	try
	{
		wcscpy_s(path_w, _countof(path_w), Py_GetPythonHome());
	}
	catch (exception&) {}
	char path[MAX_VARSTRING];
	wcstombs_s(&chars_conv, path, _countof(path), path_w, _countof(path_w));
	printf(path);
	return 0;
}

int CMD_GetType(int argc, char *argv[])
{
	LSOBJECT tlo_object;
	if(pISInterface->IsTopLevelObject("Me")(0, nullptr, tlo_object))
	{
		LSOBJECT member_object;
		pCharacterType->GetMemberEx(tlo_object.GetObjectData(), const_cast<char*>("ArcaneResist"), 0, nullptr, member_object);
		try
		{
			printf("%d", member_object.GetObjectData().DWord);
		}
		catch(exception&) {}
	}
	return 0;
}

int CMD_RunPythonScriptSubprocess(int argc, char *argv[])
{	
	if (argc <= 1)
	{
		printf("You must provide a script file name.");
		return 0;
	}
	char subprocess_file_path[MAX_VARSTRING];
	strcpy_s(subprocess_file_path, _countof(subprocess_file_path), PythonScriptPath);
	strcat_s(subprocess_file_path, _countof(subprocess_file_path), "\\open_script_as_subprocess.py");
	char file_path[MAX_VARSTRING];
	strcpy_s(file_path, _countof(file_path), PythonScriptPath);
	strcat_s(file_path, _countof(file_path), "\\");
	strcat_s(file_path, _countof(file_path), argv[1]);
	wchar_t file_path_w[MAX_VARSTRING];
	size_t characters_converted;
	mbstowcs_s(&characters_converted, file_path_w, _countof(file_path_w), file_path, _countof(file_path));
	wchar_t* p_file_path_w = &file_path_w[0];
	PySys_SetArgv(1, &p_file_path_w);
	using namespace boost::python;
	try
	{

		object main_module = import("__main__");
		const dict main_namespace = extract<dict>(main_module.attr("__dict__"));
		object isxpy = import("isxpy");
		object isxeq2 = import("pyisxeq2");
		exec_file(subprocess_file_path, main_namespace, main_namespace);
	}
	catch (error_already_set&) {
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}

int CMD_RunPythonScript(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("You must provide a script file name.");
		return 0;
	}		
	char file_path[MAX_VARSTRING];
	strcpy_s(file_path, _countof(file_path), PythonScriptPath);
	strcat_s(file_path, _countof(file_path), "\\");
	strcat_s(file_path, _countof(file_path), argv[1]);
	using namespace boost::python;
	try
	{
		object main_module = import("__main__");
		const dict main_namespace = extract<dict>(main_module.attr("__dict__"));
		object isxpy = import("isxpy");
		object isxeq2 = import("pyisxeq2");
		exec_file(file_path, main_namespace, main_namespace);
	}
	catch (error_already_set&) {
		PyErr_Print();
		return 1;
	}
	return 0;
}