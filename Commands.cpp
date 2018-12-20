#include "ISXPyPCH.h"
#include "ISXPy.h"

int CMD_Py(int argc, char *argv[])
{
	LSOBJECT tlo_object;
	if(pISInterface->IsTopLevelObject("Me")( 0, nullptr, tlo_object))
	{
		LSOBJECT IndexObject;
		IndexObject.ObjectType = pIndexType;
		IndexObject.Ptr = new LSIndex(pEffectType, nullptr);
		const int argc = 1;
		char* argv[argc];
		argv[0] = "index:effect";
		try
		{
			printf("%.08x", pCharacterType->FindMethod("QueryEffects"));
			//pCharacterType->GetMethodEx(tlo_object.GetObjectData(), "QueryEffects", 1, argv);
		}
		catch (exception&) {}
		
		//printf("%s:", (LSIndex)IndexObject.Ptr);
		
	
	}
	return 0;
}

int CMD_GetType(int argc, char *argv[])
{
	
	return 0;
}

int CMD_Test(int argc, char *argv[])
{	
	using namespace boost::python;
	try
	{
		object main_module = import("__main__");
		dict main_namespace = extract<dict>(main_module.attr("__dict__"));
		object isxeq2 = import("pyisxeq2");
		std::string script = "import character\nme = character.character()\nprint(me.name)";
		exec(script.c_str(), main_namespace, main_namespace);
	}	catch (error_already_set& e) {
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}

int CMD_RunPythonScript(int argc, char *argv[])
{
	if (argc <= 1)
		return 0;
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
	catch (error_already_set& e) {
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}