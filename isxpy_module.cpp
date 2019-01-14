#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(isxpy)
{
	def("frame_count", &get_frame_count);

#pragma region output_handler and error_handler

	class_<output_handler>("output_handler")
		.def("write", &output_handler::write)
		.def("flush", &output_handler::flush);

	class_<error_handler>("error_handler")
		.def("write", &error_handler::write)
		.def("flush", &error_handler::flush);

#pragma endregion

#pragma region ls_object

	class_<ls_object>("ls_object", init<const LSOBJECT&>())
		.add_property("to_bool", &ls_object::get_bool_from_lso)
		.add_property("to_byte", &ls_object::get_byte_from_lso)
		.add_property("to_float", &ls_object::get_float_from_lso)
		.add_property("to_int", &ls_object::get_int_from_lso)
		.add_property("to_int64", &ls_object::get_int64_from_lso)
		.add_property("to_string", &ls_object::get_string_from_lso)
		.add_property("to_uint", &ls_object::get_uint_from_lso)
		.def("to_lso", &ls_object::get_lso, return_value_policy<reference_existing_object>());

#pragma endregion

#pragma region ls_bool

	class_<ls_bool, bases<ls_object>>("ls_bool", init<const LSOBJECT&>())
		.add_property("value", &ls_bool::get_value)
		.add_property("is_valid", &ls_bool::get_is_valid)
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
		.def(self + int64_t())
		.def(int64_t() + self)
		.def(self + ls_int())
		// ls_int + self
		.def(self + double())
		.def(double() + self)
		.def(self + ls_float())
		// ls_float + self

		.def(self - bool())
		.def(bool() - self)
		.def(self - ls_bool())
		.def(self - int())
		.def(int() - self)
		.def(self - int64_t())
		.def(int64_t() - self)
		.def(self - ls_int())
		// ls_int - self
		.def(self - double())
		.def(double() - self)
		.def(self - ls_float())
		// ls_float - self

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
						
		.def(self * bool())
		.def(bool() * self)
		.def(self * ls_bool())
		.def(self * int())		
		.def(int() * self)
		.def(self * int64_t())
		.def(int64_t() * self)
		.def(self * ls_int())
		// ls_int * self
		.def(self * double())
		.def(double() * self)
		.def(self * ls_float())
		// ls_float * self

		.def(self / bool())
		.def(bool() / self)
		.def(self / ls_bool())
		.def(self / int())
		.def(int() / self)
		.def(self / int64_t())
		.def(int64_t() / self)
		.def(self / ls_int())
		// ls_int / self
		.def(self / double())
		.def(double() / self)
		.def(self / ls_float())
		// ls_float / self

		.def(self % bool())
		.def(bool() % self)
		.def(self % ls_bool())
		.def(self % int())
		.def(int() % self)
		.def(self % int64_t())
		.def(int64_t() % self)
		.def(self % ls_int())
		// ls_int % self

		.def(self >> bool())
		.def(bool() >> self)
		.def(self >> ls_bool())
		.def(self >> int())
		.def(int() >> self)
		.def(self >> int64_t())
		.def(int64_t() >> self)
		.def(self >> ls_int())
		// ls_int >> self	
		
		.def(self << bool())
		.def(bool() << self)
		.def(self << ls_bool())
		.def(self << int())
		.def(int() << self)
		.def(self << int64_t())
		.def(int64_t() << self)
		.def(self << ls_int())
		// ls_int << self
		
		.def(self & bool())
		.def(bool() & self)
		.def(self & ls_bool())
		.def(self & int())
		.def(int() & self)
		.def(self & int64_t())
		.def(int64_t() & self)
		.def(self & ls_int())
		// ls_int & self

		.def(self ^ bool())
		.def(bool() ^ self)
		.def(self ^ ls_bool())
		.def(self ^ int())
		.def(int() ^ self)
		.def(self ^ int64_t())
		.def(int64_t() ^ self)
		.def(self ^ ls_int())
		// ls_int ^ self		

		.def(self | bool())
		.def(bool() | self)
		.def(self | ls_bool())
		.def(self | int())
		.def(int() | self)
		.def(self | int64_t())
		.def(int64_t() | self)
		.def(self | ls_int())
		// ls_int | self		

		.def(self == bool())
		.def(bool() == self)
		.def(self == ls_bool())
		.def(self == int())
		.def(int() == self)
		.def(self == int64_t())
		.def(int64_t() == self)
		.def(self == ls_int())
		// ls_int == self
		.def(self == double())
		.def(double() == self)
		.def(self == ls_float())
		// ls_float == self

		.def(self != bool())
		.def(bool() != self)
		.def(self != ls_bool())
		.def(self != int())
		.def(int() != self)
		.def(self != int64_t())
		.def(int64_t() != self)
		.def(self != ls_int())
		// ls_int != self
		.def(self != double())
		.def(double() != self)
		.def(self != ls_float())
		// ls_float != self

		.def(self < bool())
		.def(bool() < self)
		.def(self < ls_bool())
		.def(self < int())
		.def(int() < self)
		.def(self < int64_t())
		.def(int64_t() < self)
		.def(self < ls_int())
		// ls_int < self
		.def(self < double())
		.def(double() < self)
		.def(self < ls_float())
		// ls_float < self

		.def(self > bool())
		.def(bool() > self)
		.def(self > ls_bool())
		.def(self > int())
		.def(int() > self)
		.def(self > int64_t())
		.def(int64_t() > self)
		.def(self > ls_int())
		// ls_int > self
		.def(self > double())
		.def(double() > self)
		.def(self > ls_float())
		// ls_float > self		

		.def(self <= bool())
		.def(bool() <= self)
		.def(self <= ls_bool())
		.def(self <= int())
		.def(int() <= self)
		.def(self <= int64_t())
		.def(int64_t() <= self)
		.def(self <= ls_int())
		// ls_int <= self
		.def(self <= double())
		.def(double() <= self)
		.def(self <= ls_float())
		// ls_float <= self	

		.def(self >= bool())
		.def(bool() >= self)
		.def(self >= ls_bool())
		.def(self >= int())
		.def(int() >= self)
		.def(self >= int64_t())
		.def(int64_t() >= self)
		.def(self >= ls_int())
		// ls_int >= self
		.def(self >= double())
		.def(double() >= self)
		.def(self >= ls_float())
		// ls_float >= self		

		.def(pow(int(), self))
		.def(pow(double(), self))
		.def(pow(self, ls_bool()))
		.def(pow(self, int()))
		.def(pow(self, double()));

#pragma endregion

#pragma region ls_int

	class_<ls_int, bases<ls_object>>("ls_int", init<const LSOBJECT&>())
		.add_property("value", &ls_int::get_value)
		.add_property("is_valid", &ls_int::get_is_valid)
		.def(self_ns::str(self))
		.def("__bool__", &ls_int::get_value)
		.def("__nonzero__", &ls_int::operator!)
		.def(int_(self))
		.def(float_(self))
		.def(-self)

		.def(self + bool())
		.def(bool() + self)
		.def(self + ls_bool())
		// ls_bool + self		
		.def(self + int())
		.def(int() + self)
		.def(self + int64_t())
		.def(int64_t() + self)
		.def(self + ls_int())
		.def(self + double())
		.def(double() + self)
		.def(self + ls_float())
		// ls_float + self

		.def(self - bool())
		.def(bool() - self)
		.def(self - ls_bool())
		// ls_bool - self		
		.def(self - int())
		.def(int() - self)
		.def(self - int64_t())
		.def(int64_t() - self)
		.def(self - ls_int())
		.def(self - double())
		.def(double() - self)
		.def(self - ls_float())
		// ls_float - self

		.def(self * bool())
		.def(bool() * self)
		.def(self * ls_bool())
		// ls_bool * self
		.def(self * int())
		.def(int() * self)
		.def(self * ls_int())
		.def(self * int64_t())
		.def(int64_t() * self)
		.def(self * double())
		.def(double() * self)
		.def(self * ls_float())
		// ls_float * self

		.def(self / bool())
		.def(bool() / self)
		.def(self / ls_bool())
		// ls_bool / self
		.def(self / int())
		.def(int() / self)
		.def(self / ls_int())
		.def(self / int64_t())
		.def(int64_t() / self)
		.def(self / double())
		.def(double() / self)
		.def(self / ls_float())
		// ls_float / self

		.def(self % bool())
		.def(bool() % self)
		.def(self % ls_bool())
		// ls_bool % self
		.def(self % int())
		.def(int() % self)
		.def(self % ls_int())
		.def(self % int64_t())
		.def(int64_t() % self)

		.def(self >> bool())
		.def(bool() >> self)
		.def(self >> ls_bool())
		// ls_bool >> self
		.def(self >> int())
		.def(int() >> self)
		.def(self >> int64_t())
		.def(int64_t() >> self)
		.def(self >> ls_int())

		.def(self << bool())
		.def(bool() << self)
		.def(self << ls_bool())
		// ls_bool << self
		.def(self << int())
		.def(int() << self)
		.def(self << int64_t())
		.def(int64_t() << self)
		.def(self << ls_int())

		.def(self & bool())
		.def(bool() & self)
		.def(self & ls_bool())
		// ls_bool & self
		.def(self & int())
		.def(int() & self)
		.def(self & int64_t())
		.def(int64_t() & self)
		.def(self & ls_int())

		.def(self ^ bool())
		.def(bool() ^ self)
		.def(self ^ ls_bool())
		// ls_bool ^ self
		.def(self ^ int())
		.def(int() ^ self)
		.def(self ^ int64_t())
		.def(int64_t() ^ self)
		.def(self ^ ls_int())

		.def(self | bool())
		.def(bool() | self)
		.def(self | ls_bool())
		// ls_bool | self
		.def(self | int())
		.def(int() | self)
		.def(self | int64_t())
		.def(int64_t() | self)
		.def(self | ls_int())

		.def(self == bool())
		.def(bool() == self)
		.def(self == ls_bool())
		// ls_bool == self
		.def(self == int())
		.def(int() == self)
		.def(self == int64_t())
		.def(int64_t() == self)
		.def(self == ls_int())
		.def(self == double())
		.def(double() == self)
		.def(self == ls_float())
		// ls_float == self

		.def(self != bool())
		.def(bool() != self)
		.def(self != ls_bool())
		// ls_bool != self
		.def(self != int())
		.def(int() != self)
		.def(self != int64_t())
		.def(int64_t() != self)
		.def(self != ls_int())
		.def(self != double())
		.def(double() != self)
		.def(self != ls_float())
		// ls_float != self
		
		.def(self < bool())
		.def(bool() < self)
		.def(self < ls_bool())
		// ls_bool < self
		.def(self < int())
		.def(int() < self)
		.def(self < int64_t())
		.def(int64_t() < self)
		.def(self < ls_int())
		.def(self < double())
		.def(double() < self)
		.def(self < ls_float())
		// ls_float < self

		.def(self > bool())
		.def(bool() > self)
		.def(self > ls_bool())
		// ls_bool > self
		.def(self > int())
		.def(int() > self)
		.def(self > int64_t())
		.def(int64_t() > self)
		.def(self > ls_int())
		.def(self > double())
		.def(double() > self)
		.def(self > ls_float())
		// ls_float > self
		
		.def(self <= bool())
		.def(bool() <= self)
		.def(self <= ls_bool())
		// ls_bool <= self
		.def(self <= int())
		.def(int() <= self)
		.def(self <= int64_t())
		.def(int64_t() <= self)
		.def(self <= ls_int())
		.def(self <= double())
		.def(double() <= self)
		.def(self <= ls_float())
		// ls_float <= self
		
		.def(self >= bool())
		.def(bool() >= self)
		.def(self >= ls_bool())
		// ls_bool >= self
		.def(self >= int())
		.def(int() >= self)
		.def(self >= int64_t())
		.def(int64_t() >= self)
		.def(self >= ls_int())
		.def(self >= double())
		.def(double() >= self)
		.def(self >= ls_float())
		// ls_float >= self		

		.def(pow(int(), self))
		.def(pow(double(), self))
		.def(pow(self, ls_int()))
		.def(pow(self, int()))
		.def(pow(self, double()));

#pragma endregion

#pragma region ls_float

	class_<ls_float, bases<ls_object>>("lso_float", init<const LSOBJECT&>())
		.add_property("value", &ls_float::get_value)
		.add_property("is_valid", &ls_float::get_is_valid)
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
		.def(self + int64_t())
		.def(int64_t() + self)
		.def(self + ls_int())
		// ls_int + self
		.def(self + double())
		.def(double() + self)
		.def(self + ls_float())

		.def(self - bool())
		.def(bool() - self)
		.def(self - ls_bool())
		// ls_bool - self
		.def(self - int())
		.def(int() - self)
		.def(self - int64_t())
		.def(int64_t() - self)
		.def(self - ls_int())
		// ls_int - self
		.def(self - double())
		.def(double() - self)
		.def(self - ls_float())

		.def(self * bool())
		.def(bool() * self)
		.def(self * ls_bool())
		// ls_bool * self
		.def(self * int())
		.def(int() * self)
		.def(self * int64_t())
		.def(int64_t() * self)
		.def(self * ls_int())
		// ls_int * self
		.def(self * double())
		.def(double() * self)
		.def(self * ls_float())

		.def(self / bool())
		.def(bool() / self)
		.def(self / ls_bool())
		// ls_bool / self
		.def(self / int())
		.def(int() / self)
		.def(self / int64_t())
		.def(int64_t() / self)
		.def(self / ls_int())
		// ls_int / self
		.def(self / double())
		.def(double() / self)
		.def(self / ls_float())

		.def(self == bool())
		.def(bool() == self)
		.def(self == ls_bool())
		// ls_bool == self
		.def(self == int())
		.def(int() == self)
		.def(self == int64_t())
		.def(int64_t() == self)
		.def(self == ls_int())
		// ls_int == self
		.def(self == double())
		.def(double() == self)
		.def(self == ls_float())

		.def(self != bool())
		.def(bool() != self)
		.def(self != ls_bool())
		// ls_bool != self
		.def(self != int())
		.def(int() != self)
		.def(self != int64_t())
		.def(int64_t() != self)
		.def(self != ls_int())
		// ls_int != self
		.def(self != double())
		.def(double() != self)
		.def(self != ls_float())

		.def(self < bool())
		.def(bool() < self)
		.def(self < ls_bool())
		// ls_bool < self
		.def(self < int())
		.def(int() < self)
		.def(self < int64_t())
		.def(int64_t() < self)
		.def(self < ls_int())
		// ls_int < self
		.def(self < double())
		.def(double() < self)
		.def(self < ls_float())

		.def(self > bool())
		.def(bool() > self)
		.def(self > ls_bool())
		// ls_bool > self
		.def(self > int())
		.def(int() > self)
		.def(self > int64_t())
		.def(int64_t() > self)
		.def(self > ls_int())
		// ls_int > self
		.def(self > double())
		.def(double() > self)
		.def(self > ls_float())

		.def(self <= bool())
		.def(bool() <= self)
		.def(self <= ls_bool())
		// ls_bool <= self
		.def(self <= int())
		.def(int() <= self)
		.def(self <= int64_t())
		.def(int64_t() <= self)
		.def(self <= ls_int())
		// ls_int <= self
		.def(self <= double())
		.def(double() <= self)
		.def(self <= ls_float())

		.def(self >= bool())
		.def(bool() >= self)
		.def(self >= ls_bool())
		// ls_bool >= self
		.def(self >= int())
		.def(int() >= self)
		.def(self >= int64_t())
		.def(int64_t() >= self)
		.def(self >= ls_int())
		// ls_int >= self
		.def(self >= double())
		.def(double() >= self)
		.def(self >= ls_float())

		.def(pow(self, int()))
		.def(pow(self, double()))
		.def(pow(double(), self))
		.def(pow(self, ls_float()))
		.def(pow(ls_float(), self))
	;

#pragma endregion

#pragma region ls_string

	class_<ls_string, bases<ls_object>>("lso_string", init<const LSOBJECT&>())
		.add_property("value", &ls_string::get_value)
		.add_property("is_valid", &ls_string::get_is_valid)
		.def("__str__", &ls_string::get_value)
		.def(self_ns::str(self))
		.def(self == std::string())
		.def(std::string() == self)
		.def(self != std::string())
		.def(std::string() != self)
		.def(self < std::string())
		.def(std::string() < self)
		.def(self > std::string())
		.def(std::string() > self)
		.def(self <= std::string())
		.def(std::string() <= self)
		.def(self >= std::string())
		.def(std::string() >= self)
		;

#pragma endregion

#pragma region ls_point3_f

	class_<ls_point3_f, bases<ls_object>>("point3f")
		.add_property("x", &ls_point3_f::get_x)
		.add_property("y", &ls_point3_f::get_y)
		.add_property("z", &ls_point3_f::get_z)
		.def("xyz", &ls_point3_f::get_xyz, ls_point3_f::get_xyz_overloads(args("separator")));

#pragma endregion

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