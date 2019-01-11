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

	class_<ls_object>("ls_object", init<const LSOBJECT&>())
		.add_property("to_bool", &ls_object::get_bool_from_lso)
		.add_property("to_byte", &ls_object::get_byte_from_lso)
		.add_property("to_float", &ls_object::get_float_from_lso)
		.add_property("to_int", &ls_object::get_int_from_lso)
		.add_property("to_int64", &ls_object::get_int64_from_lso)
		.add_property("to_string", &ls_object::get_string_from_lso)
		.add_property("to_uint", &ls_object::get_uint_from_lso)
		.def("to_lso", &ls_object::get_lso, return_value_policy<reference_existing_object>());

#pragma region ls_bool

	class_<ls_bool, bases<ls_object>>("ls_bool", init<const LSOBJECT&>())
		.add_property("value", &ls_bool::get_value)
		.def(self_ns::str(self))
		.def(int_(self))
		.def("__bool__", &ls_bool::get_value)
		.def("__nonzero__", &ls_bool::operator!)
		.def(-self)

		.def(self + bool())
		.def(bool() + self)
		.def(self + ls_bool())
		.def(self + int())
		.def(int() + self)
		.def(self + ls_int())
		// ls_int + self
		//.def(self + int64_t())
		//.def(int64_t() + self)
		//.def(self + ls_int64())
		// ls_int64 + self
		//.def(self + float())
		//.def(float() + self)
		//.def(self + ls_float())
		// ls_float + self
		.def(self + double())
		.def(double() + self)
		.def(self + ls_double())

		.def(self == bool())
		.def(bool() == self)
		.def(self == ls_bool())		
		.def(self == int())
		.def(int() == self)
		.def(self == ls_int())
		// ls_int == self
		.def(self == double())
		.def(double() == self)

		.def(self != bool())
		.def(bool() != self)
		.def(self != ls_bool())
		.def(self != int())
		.def(int() != self)
		.def(self != ls_int())
		// ls_int == self
		.def(self != double())
		.def(double() != self)
		
		

		.def(self - bool())
		.def(bool() - self)
		.def(self - ls_bool())
		.def(self - int())
		.def(int() - self)
		.def(self - ls_int())
		// ls_int - self
		.def(self - double())
		.def(double() - self)
		
		.def(self * bool())
		.def(bool() * self)
		.def(self * ls_bool())
		.def(self * int())
		.def(self * ls_int())
		// ls_int * self
		.def(int() * self)
		.def(self * double())
		.def(double() * self)

		.def(self / bool())
		.def(bool() / self)
		.def(self / ls_bool())
		.def(self / int())
		.def(self / ls_int())
		// ls_int / self
		.def(int() / self)
		.def(self / double())
		.def(double() / self)

		.def(self % bool())
		.def(bool() % self)
		.def(self % ls_bool())
		.def(self % int())
		.def(int() % self)
		.def(self % ls_int())
		// ls_int % self

		.def(self >> bool())
		.def(bool() >> self)
		.def(self >> ls_bool())
		.def(self >> int())
		.def(int() >> self)
		.def(self >> ls_int())
		// ls_int >> self	
		
		.def(self << bool())
		.def(bool() << self)
		.def(self << ls_bool())
		.def(self << int())
		.def(int() << self)
		.def(self << ls_int())
		// ls_int << self
		
		.def(self & bool())
		.def(bool() & self)
		.def(self & ls_bool())
		.def(self & int())
		.def(int() & self)
		.def(self & ls_int())
		// ls_int & self

		.def(self ^ bool())
		.def(bool() ^ self)
		.def(self ^ ls_bool())
		.def(self ^ int())
		.def(int() ^ self)
		.def(self ^ ls_int())
		// ls_int ^ self		

		.def(self | bool())
		.def(bool() | self)
		.def(self | ls_bool())
		.def(self | int())
		.def(int() | self)
		.def(self | ls_int())
		// ls_int | self		

		.def(self < bool())
		.def(bool() < self)
		.def(self < ls_bool())
		.def(self < int())
		.def(int() < self)
		.def(self < ls_int())
		// ls_int < self		
		.def(self < double())
		.def(double() < self)	

		.def(self > bool())
		.def(bool() > self)
		.def(self > ls_bool())
		.def(self > int())
		.def(int() > self)
		.def(self > ls_int())
		// ls_int > self
		.def(self > double())
		.def(double() > self)		

		.def(self <= bool())
		.def(bool() <= self)
		.def(self <= ls_bool())
		.def(self <= int())
		.def(int() <= self)
		.def(self <= ls_int())
		// ls_int <= self
		.def(self <= double())
		.def(double() <= self)

		.def(self >= bool())
		.def(bool() >= self)
		.def(self >= ls_bool())
		.def(self >= int())
		.def(int() >= self)
		.def(self >= ls_int())
		// ls_int >= self
		.def(self >= double())
		.def(double() >= self)		

		.def(pow(int(), self))
		.def(pow(double(), self))
		.def(pow(self, ls_bool()))
		.def(pow(self, int()))
		.def(pow(self, double()));

#pragma endregion

	class_<py_byte, bases<ls_object>>("lso_byte", init<const LSOBJECT&>())
		.add_property("value", &py_byte::get_value)
		.def("inc", &py_byte::inc, py_byte::inc_overloads(args("formula")))
		.def("inc", &py_byte::dec, py_byte::dec_overloads(args("formula")))
		.def("set", &py_byte::set);

#pragma region ls_int

	class_<ls_int, bases<ls_object>>("ls_int", init<const LSOBJECT&>())
		.add_property("value", &ls_int::get_value)
		.def(self_ns::str(self))
		.def(int_(self))
		.def(float_(self))
		.def(-self)

		.def(self + bool())
		.def(bool() + self)
		.def(self + ls_bool())
		// ls_bool + self		
		.def(self + int())
		.def(int() + self)
		.def(self + ls_int())
		.def(self + double())
		.def(double() + self)

		.def(self - bool())
		.def(bool() - self)
		.def(self - ls_bool())
		// ls_bool - self		
		.def(self - int())
		.def(int() - self)
		.def(self - ls_int())
		.def(self - double())
		.def(double() - self)

		.def(self * bool())
		.def(bool() * self)
		.def(self * ls_bool())
		// ls_bool * self
		.def(self * int())
		.def(int() * self)
		.def(self * ls_int())
		.def(self * double())
		.def(double() * self)

		.def(self / bool())
		.def(bool() / self)
		.def(self / ls_bool())
		// ls_bool / self		
		.def(self / int())
		.def(int() / self)
		.def(self / ls_int())
		.def(self / double())
		.def(double() / self)

		.def(self % bool())
		.def(bool() % self)
		.def(self % ls_bool())
		// ls_bool % self		
		.def(self % int())
		.def(int() % self)
		.def(self % ls_int())

		.def(self >> bool())
		.def(bool() >> self)
		.def(self >> ls_bool())
		// ls_bool >> self
		.def(self >> int())
		.def(int() >> self)
		.def(self >> ls_int())

		.def(self << bool())
		.def(bool() << self)
		.def(self << ls_bool())
		// ls_bool << self
		.def(self << int())
		.def(int() << self)
		.def(self << ls_int())

		.def(self & bool())
		.def(bool() & self)
		.def(self & ls_bool())
		// ls_bool & self
		.def(self & int())
		.def(int() & self)
		.def(self & ls_int())

		.def(self ^ bool())
		.def(bool() ^ self)
		.def(self ^ ls_bool())
		// ls_bool ^ self
		.def(self ^ int())
		.def(int() ^ self)
		.def(self ^ ls_int())

		.def(self | bool())
		.def(bool() | self)
		.def(self | ls_bool())
		// ls_bool | self
		.def(self | int())
		.def(int() | self)
		.def(self | ls_int())

		.def(self == bool())
		.def(bool() == self)
		.def(self == ls_bool())
		// ls_bool == self
		.def(self == int())
		.def(int() == self)
		.def(self == ls_int())
		.def(self == double())
		.def(double() == self)		

		.def(self != bool())
		.def(bool() != self)
		.def(self != ls_bool())
		// ls_bool != self
		.def(self != int())
		.def(int() != self)
		.def(self != ls_int())
		.def(self != double())
		.def(double()!= self)
		
		.def(self < bool())
		.def(bool() < self)
		.def(self < ls_bool())
		// ls_bool < self
		.def(self < int())
		.def(int() < self)
		.def(self < double())
		.def(double() < self)
		.def(self < ls_int())

		.def(self > bool())
		.def(bool() > self)
		.def(self > ls_bool())
		// ls_bool > self
		.def(self > int())
		.def(int() > self)
		.def(self > ls_int())
		.def(self > double())
		.def(double() > self)
		
		.def(self <= bool())
		.def(bool() <= self)
		.def(self <= ls_bool())
		// ls_bool <= self
		.def(self <= int())
		.def(int() <= self)
		.def(self <= ls_int())
		.def(self <= double())
		.def(double() <= self)
		
		.def(self >= bool())
		.def(bool() >= self)
		.def(self >= ls_bool())
		// ls_bool >= self
		.def(self >= int())
		.def(int() >= self)
		.def(self >= ls_int())
		.def(self >= double())
		.def(double() >= self)		

		.def(pow(int(), self))
		.def(pow(double(), self))
		.def(pow(self, ls_int()))
		.def(pow(self, int()))
		.def(pow(self, double()));

#pragma endregion

	class_<py_uint, bases<ls_object>>("lso_uint", init<const LSOBJECT&>())
		.add_property("value", &py_uint::get_value)
		.add_property("as_float", &py_uint::get_float)
		.add_property("as_hex", &py_uint::get_hex)
		.add_property("reverse", &py_uint::get_reverse)
		.def("leading_zeros", &py_uint::leading_zeros)
		.add_property("as_unsigned", &py_uint::get_signed)
		.def("inc", &py_uint::inc, py_uint::inc_overloads(args("formula")))
		.def("dec", &py_uint::dec, py_uint::dec_overloads(args("formula")))
		.def("set", &py_uint::set);

#pragma region ls_int64

	class_<ls_int64, bases<ls_object>>("lso_int64", init<const LSOBJECT&>())
		.add_property("value", &ls_int64::get_value)
		.def(self_ns::str(self))
		.def(int_(self))
		.def(float_(self))
		.def(-self)
	;
		

#pragma endregion

	class_<ls_float, bases<ls_object>>("lso_float", init<const LSOBJECT&>())
		.add_property("value", &ls_float::get_value)
		;

	class_<ls_double, bases<ls_object>>("lso_float64", init<const LSOBJECT&>())
		.add_property("value", &ls_double::get_value)
		;

	class_<py_string, bases<ls_object>>("lso_string", init<const LSOBJECT&>())
		.add_property("value", &py_string::get_value)
		.def("mid", &py_string::mid)
		.def("left", &py_string::left)
		.def("right", &py_string::right)
		.def("find", &py_string::find)
		.add_property("length", &py_string::get_length)
		.add_property("to_lower", &py_string::get_lower)
		.add_property("to_upper", &py_string::get_upper)
		.def("compare", &py_string::compare)
		.def("compare_cs", &py_string::compare_cs)
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