#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

void adjust_path()
{
	wcscpy_s(PythonPathW, _countof(PythonPathW), Py_DecodeLocale(PythonScriptPath, nullptr));
	wcscat_s(PythonPathW, _countof(PythonPathW), L";");
	wcscat_s(PythonPathW, _countof(PythonPathW), Py_DecodeLocale(PythonLibPath, nullptr));
	wcscat_s(PythonPathW, _countof(PythonPathW), L";");
	wcscat_s(PythonPathW, _countof(PythonPathW), Py_DecodeLocale(PythonDLLPath, nullptr));
	wcscat_s(PythonPathW, _countof(PythonPathW), L";");
	// wcscat_s(PythonPathW, _countof(PythonPathW), Py_GetPath());

	Py_SetPath(PythonPathW);
	object sys_module = import("sys");
	object path_object = sys_module.attr("path");
	object result = path_object.attr("insert")(0, PythonScriptPath);
	result = path_object.attr("insert")(0, PythonLibPath);
	result = path_object.attr("insert")(0, PythonDLLPath);
	import("isxpy");

}

int quit_script()
{
	PyErr_SetInterrupt();
	return -1;
}

void redirect_output_to_console()
{
	object main_module = import("__main__");
	const dict main_namespace = extract<dict>(main_module.attr("__dict__"));
	exec("import sys", main_namespace, main_namespace);
	exec("import isxpy", main_namespace, main_namespace);
	exec("sys.stdout = isxpy.output_handler()", main_namespace, main_namespace);
	exec("sys.stderr = isxpy.error_handler()", main_namespace, main_namespace);
	exec("print(\'\agPython interpreter output successfully redirected to console.\')", main_namespace, main_namespace);
}

int get_frame_count()
{
	return frame_count;
}

void setup_channel(const char* module_name, const char* channel_name, boost::python::object& channel_object)
{
	object main_module = import("__main__");
	const dict main_namespace = boost::python::extract<dict>(main_module.attr("__dict__"));
	object channel_module = import(module_name);
	const dict channel_module_namespace = boost::python::extract<dict>(channel_module.attr("__dict__"));
	try
	{
		char buffer_channel_module_import[MAX_VARSTRING];
		sprintf_s(buffer_channel_module_import, _countof(buffer_channel_module_import), "import %s", module_name);
		exec(buffer_channel_module_import, main_namespace, main_namespace);
		exec("import stackless", main_namespace, main_namespace);
		char buffer_channel_instantiation[MAX_VARSTRING];
		sprintf_s(buffer_channel_instantiation, _countof(buffer_channel_instantiation), "%s.%s = stackless.channel()", module_name, channel_name);
		exec(buffer_channel_instantiation, main_namespace, main_namespace);
		channel_object = channel_module.attr(channel_name);
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}
}

void stop_channel(object& channel_object)
{
	try
	{
		if(!channel_object.is_none())
		{
			channel c(channel_object);
			c.close();
		}
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}
}

void setup_event(const char* module_name, const char* channel_name, boost::python::object& channel_object,
                 const char* event_name, fLSEventTarget callback)
{	
	try
	{
		setup_channel(module_name, channel_name, channel_object);
		pISInterface->AttachEventTarget(pISInterface->RegisterEvent(event_name), callback);
	} 
	catch (error_already_set&)
	{
		PyErr_Print();
	}
}

void stop_event(object& channel_object, const char* event_name, fLSEventTarget callback)
{
	pISInterface->DetachEventTarget(pISInterface->RegisterEvent(event_name), callback);
	stop_channel(channel_object);	
}