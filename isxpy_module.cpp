#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(isxpy)
{
	def("frame_count", &get_frame_count);

	class_<output_handler>("output_handler")
		.def("write", &output_handler::write)
		.def("flush", &output_handler::flush);

	class_<error_handler>("error_handler")
		.def("write", &error_handler::write)
		.def("flush", &error_handler::flush);

	class_<py_lsobject>("lsobject", no_init);

	class_<py_int, bases<py_lsobject>>("lso_int", init<const LSOBJECT&>())
		.add_property("value", &py_int::get_value)
		.add_property("as_float", &py_int::get_float)
		.add_property("as_hex", &py_int::get_hex)
		.add_property("reverse", &py_int::get_reverse)
		.def("leading_zeros", &py_int::leading_zeros)
		.add_property("as_unsigned", &py_int::get_unsigned)
		.def("inc", &py_int::inc, py_int::inc_overloads(args("formula")))
		.def("dec", &py_int::dec, py_int::dec_overloads(args("formula")))
		.def("set", &py_int::set);

	class_<py_uint, bases<py_lsobject>>("lso_uint", init<const LSOBJECT&>())
		.add_property("value", &py_uint::get_value)
		.add_property("as_float", &py_uint::get_float)
		.add_property("as_hex", &py_uint::get_hex)
		.add_property("reverse", &py_uint::get_reverse)
		.def("leading_zeros", &py_uint::leading_zeros)
		.add_property("as_unsigned", &py_uint::get_signed)
		.def("inc", &py_uint::inc, py_uint::inc_overloads(args("formula")))
		.def("dec", &py_uint::dec, py_uint::dec_overloads(args("formula")))
		.def("set", &py_uint::set);

}

void initialize_module_isxpy()
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

void shutdown_module_isxpy()
{
	
}