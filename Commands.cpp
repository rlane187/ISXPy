#include "ISXPyPCH.h"
#include "ISXPy.h"

int CMD_Py(int argc, char *argv[])
{
	using namespace boost::python;
	try
	{
		
	}
	catch(error_already_set&)
	{
		PyErr_Print();
	}
	return 0;
}

int CMD_GetType(int argc, char *argv[])
{
	for (auto& it : tasklet_map)
	printf("%s - %d", it.first.c_str(), it.second->is_scheduled());
	printf("%d", tasklet_map.size());
	return 0;
}

int CMD_RunPythonScript(int argc, char *argv[])
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
	char buffer_map_id[MAX_VARSTRING];
	strcpy_s(buffer_map_id, _countof(buffer_map_id), module_name);
	strcat_s(buffer_map_id, _countof(buffer_map_id), "_");
	strcat_s(buffer_map_id, _countof(buffer_map_id), callable_name);
	const std::string map_id(buffer_map_id);
	const std::map<std::string, tasklet*>::iterator it = tasklet_map.find(map_id);
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

		auto* t = new tasklet();
		if (!t->get_ptr())
		{
			printf("Failed to initialize tasklet for callable %s in module %s.", callable_name, module_name);
			return 1;
		}
		if(t->bind_ex(func))
		{
			
			if(t->insert())
				tasklet_map[map_id] = t;
		}			
	}
	catch (error_already_set&) {
		PyErr_Print();
		return 0;
	}
	return 0;
}

int CMD_RunPythonScriptUnsafe(int argc, char *argv[])
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
		object isxeq2 = import("isxeq2");
		object stackless = import("stackless");
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

int CMD_EndPythonScript(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Format:endpyscript *|module_name");
	}
	char buffer_module_name[MAX_VARSTRING];
	strcpy_s(buffer_module_name, _countof(buffer_module_name), argv[1]);
	const std::string module_name(buffer_module_name);
	std::map<std::string, tasklet*>::iterator it;	
	for (it = tasklet_map.begin(); it != tasklet_map.end(); ++it)
	{
		if (!strcmp(argv[1], "*"))
		{
			if (it->second->kill())
			{
				delete it->second;
				tasklet_map.erase(it);
			}
		}
		else
		{
			if (boost::algorithm::starts_with(it->first, module_name))
			{
				if (it->second->kill())
				{
					delete it->second;
					tasklet_map.erase(it);
				}
			}
		}		
	}
	

	return 0;
}

int CMD_EndPythonScriptUnsafe(int argc, char *argv[])
{
	quit_script();
	return 0;
}

int CMD_GetChannelBalances(int argc, char *argv[])
{
	using namespace boost::python;
	try
	{
		if (!pulse_channel.is_none())
			printf("isxpy.pulse_channel = %d.", channel(pulse_channel).get_balance());
		if (!eq2_actor_spawned_channel.is_none())
			printf("isxeq2.eq2_actor_spawned_channel = %d.", channel(eq2_actor_spawned_channel).get_balance());
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}
	
	return 0;
}

int CMD_GetTaskletRunCount(int argc, char *argv[])
{
	using namespace boost::python;

	try
	{
		printf("Tasklet run count is %d", stackless_module::get_run_count());	
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}

	return 0;
}