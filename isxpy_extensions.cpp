#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(isxpy)
{
	scope().attr("pulse_channel");
	def("frame_count", &get_frame_count);

	class_<output_handler>("output_handler")
		.def("write", &output_handler::write)
		.def("flush", &output_handler::flush);

	class_<error_handler>("error_handler")
		.def("write", &error_handler::write)
		.def("flush", &error_handler::flush);
}

void Initialize_Module_ISXPy()
{
	PyImport_AppendInittab("isxpy", PyInit_isxpy);
	srand(unsigned int(time(nullptr)));
	size_t chars_converted = 0;
	GetModuleFileName(HINSTANCE(&__ImageBase), DllPath, _countof(DllPath));
	mbstowcs_s(&chars_converted, DllPathW, _countof(DllPathW), DllPath, _countof(DllPath));
	pISInterface->GetInnerSpacePath(PythonScriptPath, _countof(PythonScriptPath));
	strcat_s(PythonScriptPath, _countof(PythonScriptPath), "\\PythonScripts");
	mbstowcs_s(&chars_converted, PythonPathW, _countof(PythonPathW), PythonScriptPath, _countof(PythonScriptPath));
}

void AdjustPath()
{
	wcscpy_s(PythonPathW, _countof(PythonPathW), Py_DecodeLocale(PythonScriptPath, nullptr));
	wcscat_s(PythonPathW, _countof(PythonPathW), L";");
	wcscat_s(PythonPathW, _countof(PythonPathW), Py_GetPath());

	Py_SetPath(PythonPathW);
	object sys_module = import("sys");
	object path_object = sys_module.attr("path");
	object result = path_object.attr("insert")(0, PythonScriptPath);
	import("isxpy");

}

int QuitScript()
{
	PyErr_SetInterrupt();
	return -1;
}

void Shutdown_Module_ISXPy()
{

}

void Redirect_Output_to_Console()
{
	object main_module = import("__main__");
	dict main_namespace = extract<dict>(main_module.attr("__dict__"));
	object output_module = import("isxpy");
	char file_path[MAX_PATH];
	strcpy_s(file_path, _countof(file_path), PythonScriptPath);
	strcat_s(file_path, _countof(file_path), "\\redirect_output.py");
	exec_file(file_path, main_namespace, main_namespace);
	exec("print(\'\agPython interpreter output successfully redirected to console.\')", main_namespace, main_namespace);
}

bool GetLSObjectFromTLO(LSTypeDefinition* pTypeDef, PCHAR tlo_name, int tlo_argc, PCHAR tlo_argv[], PCHAR member_name, int argc, PCHAR argv[], LSOBJECT& dest)
{
	if (pISInterface->IsTopLevelObject(tlo_name))
	{
		LSOBJECT tlo_object;
		pISInterface->IsTopLevelObject(tlo_name)(tlo_argc, tlo_argv, tlo_object);
		pTypeDef->GetMember(tlo_object.GetObjectData(), pTypeDef->FindMember(member_name), argc, argv, dest);
		return true;
	}
	return false;
}

object get_pulse_channel()
{
	return pulse_channel;
}

void set_pulse_channel(object& channel)
{
	pulse_channel = channel;
}

int get_frame_count()
{
	return FrameCount;
}