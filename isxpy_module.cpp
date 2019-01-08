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

	class_<py_lsobject>("lsobject", init<const LSOBJECT&>())
		.add_property("to_bool", &py_lsobject::get_bool_from_lso)
		.add_property("to_byte", &py_lsobject::get_byte_from_lso)
		.add_property("to_float", &py_lsobject::get_float_from_lso)
		.add_property("to_int", &py_lsobject::get_int_from_lso)
		.add_property("to_int64", &py_lsobject::get_int64_from_lso)
		.add_property("to_string", &py_lsobject::get_string_from_lso)
		.add_property("to_uint", &py_lsobject::get_uint_from_lso)
		.def("to_lso", &py_lsobject::get_lso, return_value_policy<reference_existing_object>());

	class_<py_bool, bases<py_lsobject>>("lso_bool", init<const LSOBJECT&>())
		.add_property("value", &py_bool::get_value)
		.def("toggle", &py_bool::toggle)
		.def("set", &py_bool::set);

	class_<py_byte, bases<py_lsobject>>("lso_byte", init<const LSOBJECT&>())
		.add_property("value", &py_byte::get_value)
		.def("inc", &py_byte::inc, py_byte::inc_overloads(args("formula")))
		.def("inc", &py_byte::dec, py_byte::dec_overloads(args("formula")))
		.def("set", &py_byte::set);

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

	class_<py_int64, bases<py_lsobject>>("lso_int64", init<const LSOBJECT&>())
		.add_property("value", &py_int64::get_value)
		.add_property("as_float", &py_int64::get_float)
		.add_property("as_hex", &py_int64::get_hex)
		.def("leading_zeros", &py_int64::leading_zeros)
		.def("inc", &py_int64::inc, py_int64::inc_overloads(args("formula")))
		.def("dec", &py_int64::dec, py_int64::dec_overloads(args("formula")))
		.def("set", &py_int64::set);

	class_<py_float, bases<py_lsobject>>("lso_float", init<const LSOBJECT&>())
		.add_property("value", &py_float::get_value)
		.add_property("deci", &py_float::get_deci)
		.add_property("centi", &py_float::get_centi)
		.add_property("milli", &py_float::get_milli)
		.add_property("floor", &py_float::get_int)
		.def("precision", &py_float::precision)
		.add_property("ceil", &py_float::get_ceil)
		.add_property("round", &py_float::get_round)
		.def("inc", &py_float::inc, py_float::inc_overloads(args("formula")))
		.def("dec", &py_float::dec, py_float::dec_overloads(args("formula")))
		.def("set", &py_float::set);

	class_<py_float64, bases<py_lsobject>>("lso_float64", init<const LSOBJECT&>())
		.add_property("value", &py_float64::get_value)
		.add_property("deci", &py_float64::get_deci)
		.add_property("centi", &py_float64::get_centi)
		.add_property("milli", &py_float64::get_milli)
		.add_property("floor", &py_float64::get_int)
		.def("precision", &py_float64::precision)
		.add_property("ceil", &py_float64::get_ceil)
		.add_property("round", &py_float64::get_round)
		.def("inc", &py_float64::inc, py_float64::inc_overloads(args("formula")))
		.def("dec", &py_float64::dec, py_float64::dec_overloads(args("formula")))
		.def("set", &py_float64::set);

	class_<py_string, bases<py_lsobject>>("lso_string", init<const LSOBJECT&>())
		.add_property("value", &py_string::get_value)
		.def("mid", &py_string::mid)
		.def("left", &py_string::left)
		.def("right", &py_string::right)
		.def("find", &py_string::find)
		.add_property("length", &py_string::get_length)
		.add_property("to_lower", &py_string::get_lower)
		.add_property("to_upper", &py_string::get_upper)
		.def("__str__", &py_string::get_value);

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