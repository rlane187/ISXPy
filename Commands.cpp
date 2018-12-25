#include "ISXPyPCH.h"
#include "ISXPy.h"

int CMD_Py(int argc, char *argv[])
{
	LSOBJECT tlo_object;
	if(pISInterface->IsTopLevelObject("Me")( 0, nullptr, tlo_object))
	{
		LSOBJECT IndexObject;
		//int key = pISInterface->PersistObject(IndexObject);
		//printf("%d", key);
		//IndexObject.ObjectType = pIndexType;
		//IndexObject.Ptr = new LSIndex(pEffectType, nullptr);
		const int argc = 1;
		char* argv_[argc];
		char buffer[MAX_VARSTRING];
		pISInterface->ExecuteCommand("DeclareVariable Effects index:effect global");
		sprintf_s(buffer, _countof(buffer), "Effects");
		argv_[0] = buffer;
		list<py_effect> effects;
		try
		{
			pISInterface->DataParse(argv_[0], IndexObject);			
			pCharacterType->GetMethodEx(tlo_object.GetObjectData(), "QueryEffects", 1, argv_);
			const auto size = static_cast<LSIndex*>(IndexObject.Ptr)->GetContainerUsed();
			for (size_t i = 0; i < size; i++)
			{
				auto item = reinterpret_cast<py_effect*>((*static_cast<LSIndex*>(IndexObject.Ptr)->GetIndex())[i]);
				printf("%d", item->get_id());
			}
		}
		catch (exception&) {}
		pISInterface->ExecuteCommand("DeleteVariable Effects");
		
		//printf("%s:", (LSIndex)IndexObject.Ptr);
		
	
	}
	return 0;
}

int CMD_GetType(int argc, char *argv[])
{
	
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
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}