#include "ISXPyPCH.h"
#include "ISXPy.h"

int CMD_Py(int argc, char *argv[])
{
	using namespace boost::python;
	try
	{
		object main_module = import("__main__");
		const dict main_namespace = boost::python::extract<dict>(main_module.attr("__dict__"));
		scope main_scope(main_module);
		object isxpy = import("isxpy");
		object isxeq2 = import("pyisxeq2");
		exec("import stackless", main_namespace, main_namespace);
		exec("stackless.getcurrent().block_trap = True", main_namespace, main_namespace);
		def("on_pulse", &stackless_module::on_pulse);
		stackless_module::call_method_main(main_module, "on_pulse", nullptr);
		printf("%d", stackless_module::get_run_count());
	}
	catch(error_already_set&)
	{
		PyErr_Print();
	}
	return 0;
}

int CMD_GetType(int argc, char *argv[])
{
	printf("%d", stackless_module::get_run_count());
	return 0;
}

int CMD_RunPythonScriptSubprocess(int argc, char *argv[])
{	
	using namespace boost::python;
	if (argc < 2)
	{
		printf("Format: runpysub module_name (optional) callable_name");
		return 0;
	}
	char module_name[MAX_VARSTRING];
	strcpy_s(module_name, _countof(module_name), argv[1]);
	char callable_name[MAX_VARSTRING];
	if (argc > 2)
		strcpy_s(callable_name, _countof(callable_name), argv[2]);
	else
		strcpy_s(callable_name, _countof(callable_name), "main");
	char file_path[MAX_VARSTRING];
	strcpy_s(file_path, _countof(file_path), PythonScriptPath);
	strcat_s(file_path, _countof(file_path), "\\");
	strcat_s(file_path, _countof(file_path), argv[1]);
	char map_id[MAX_VARSTRING];
	strcpy_s(map_id, _countof(map_id), module_name);
	strcat_s(map_id, _countof(map_id), "_");
	strcat_s(map_id, _countof(map_id), callable_name);
	printf("%s", map_id);
	const std::map<PCHAR, tasklet*>::iterator it = tasklet_map.find(map_id);
	if (it != tasklet_map.end())
	{
		printf("Callable %s from module %s already found running. Trying to kill tasklet and restart.", callable_name, module_name);
		if(it->second->kill() >= 0)
		{
			printf("Tasklet for callable %s from module %s successfully killed.", callable_name, module_name);
			delete it->second;
			tasklet_map.erase(it);
		}
		else
		{
			printf("Tasklet for callable %s from module %s could not be terminated.", callable_name, module_name);
		}
	}
	using namespace boost::python;
	try
	{
		//PyObject* p_script_module = PyImport_ImportModule(module_name);
		//PyObject* p_func = PyObject_GetAttrString(p_script_module, callable_name);
		//PyTaskletObject* p_tasklet = PyTasklet_New(nullptr, p_func);
		//Py_DecRef(p_func);		
		//PyObject* p_args = PyTuple_New(0);
		//int result = PyTasklet_Setup(p_tasklet, p_args, nullptr);
		//Py_DecRef(p_args);
		object script_module = import(module_name);		
		if(!script_module.ptr())
		{
			printf("Module %s cannot be loaded.", module_name);
			return 1;
		}
		object func = script_module.attr(callable_name);
		
		if (!func.ptr())
		{
			printf("Callable %s cannot be found in module %s.", callable_name, module_name);
			return 1;
		}
		
		tasklet* t = new tasklet(func);
		if (!t->get_ptr())
		{
			printf("Failed to initialize tasklet for callable %s in module %s.", callable_name, module_name);
			return 1;
		}
		t->setup();
		/*if(!t->bind_ex(func))
		{
			printf("Failed to tasklet and args/kwargs to callable %s in module %s.", callable_name, module_name);
			return 1;
		}

		if(!t->insert())
		{
			printf("Failed to insert tasklet for callable %s in module %s into scheduler.", callable_name, module_name);
			return 1;
		}*/
		tasklet_map[map_id] = t;
	}
	catch (error_already_set&) {
		PyErr_Print();
		return 0;
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

int CMD_GetPythonPath(int argc, char *argv[])
{
	wchar_t buffer_w[MAX_VARSTRING];
	char buffer[MAX_VARSTRING];
	size_t chars_converted = 0;
	memset(&buffer_w, 0, _countof(buffer_w));
	memset(&buffer, 0, _countof(buffer));
	try
	{
		wcscpy_s(buffer_w, _countof(buffer), Py_GetPath());
		wcstombs_s(&chars_converted, buffer, _countof(buffer), buffer_w, _countof(buffer_w));
	}
	catch(exception&) {}
	if (strlen(buffer) == 0)
		printf("Python path not found.");
	printf("Python path is: %s", buffer);
	return 0;
}