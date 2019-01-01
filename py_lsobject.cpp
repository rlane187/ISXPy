#include "ISXPyPCH.h"
#include "ISXPy.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(isxpy)
{
	class_<output_handler>("output_handler")
		.def("write", &output_handler::write)
		.def("flush", &output_handler::flush);

	class_<error_handler>("error_handler")
		.def("write", &error_handler::write)
		.def("flush", &error_handler::flush);

	//def("pulse_channel", &get_pulse_channel);
}

void Initialize_Module_ISXPy()
{
	PyImport_AppendInittab("isxpy", PyInit_isxpy);
	srand(unsigned int(time(nullptr)));
	size_t chars_converted = 0;
	// Set DllPath and DllPathW
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
	if(pISInterface->IsTopLevelObject(tlo_name))
	{
		LSOBJECT tlo_object;
		pISInterface->IsTopLevelObject(tlo_name)(tlo_argc, tlo_argv, tlo_object);
		pTypeDef->GetMember(tlo_object.GetObjectData(), pTypeDef->FindMember(member_name), argc, argv, dest);
		return true;
	}
	return false;
}

//boost::python::object get_pulse_channel()
//{
//	return pulse_channel.get_channel_object();
//}

py_lsobject::py_lsobject(LSOBJECT& ls_object)
{	
	this->ls_object_ = ls_object;
}

void py_lsobject::execute_method(PCHAR method, int argc, char* argv[])
{
	if (this->ls_object_.ObjectType && this->has_method(method))
		this->ls_object_.ObjectType->GetMethodEx(this->ls_object_.GetObjectData(), method, argc, argv);
	else if (this->ls_object_.ObjectType && this->has_inherited_method(method))
		this->ls_object_.ObjectType->GetInheritedMethod(this->ls_object_.GetObjectData(), method, argc, argv);
}

py_lsobject py_lsobject::get_member(PCHAR member, int argc, char* argv[])
{
	LSOBJECT dest;
	if(this->ls_object_.ObjectType && this->has_member(member))
		this->ls_object_.ObjectType->GetMemberEx(this->ls_object_.GetObjectData(), member, argc, argv, dest);
	else if (this->ls_object_.ObjectType && this->has_inherited_member(member))
		this->ls_object_.ObjectType->GetInheritedMember(this->ls_object_.GetObjectData(), member, argc, argv, dest);
	return static_cast<py_lsobject>(dest);
}

void py_lsobject::get_member(PCHAR member, int argc, char* argv[], LSOBJECT& ls_object)
{
	if (this->ls_object_.ObjectType && this->has_member(member))
		this->ls_object_.ObjectType->GetMemberEx(this->ls_object_.GetObjectData(), member, argc, argv, ls_object);
	else if (this->ls_object_.ObjectType && this->has_inherited_member(member))
		this->ls_object_.ObjectType->GetInheritedMember(this->ls_object_.GetObjectData(), member, argc, argv, ls_object);
}

bool py_lsobject::has_inherited_member(PCHAR member) const
{
	if (this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->InheritedMember(member))
			return true;
	}
	return false;
}

bool py_lsobject::has_inherited_method(PCHAR method) const
{
	if (this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->InheritedMethod(method))
			return true;
	}
	return false;
}

bool py_lsobject::has_member(PCHAR member) const
{
	if(this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->FindMember(member))
			return true;
	}
	return false;
}

bool py_lsobject::has_method(PCHAR method) const
{
	if(this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->FindMethod(method))
			return true;
	}
	return false;
}

bool py_lsobject::get_bool_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pBoolType)
	{
		return bool(this->ls_object_.GetObjectData().DWord);
	}
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pBoolPtrType)
	{
		return bool(*(this->ls_object_.GetObjectData().DWordPtr));
	}
	return false;
}

int py_lsobject::get_byte_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pByteType)
	{
		return int(this->ls_object_.GetObjectData().DWord);
	}
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pBytePtrType)
	{
		return int(*(this->ls_object_.GetObjectData().DWordPtr));
	}
	return false;
}

float py_lsobject::get_float_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pFloatType)
	{
		return float(this->ls_object_.GetObjectData().Float);
	}
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pFloatPtrType)
	{
		return float(*reinterpret_cast<float*>(this->ls_object_.GetObjectData().DWordPtr));
	}
	return FLT_MAX;
}

int py_lsobject::get_int_from_lso()
{
	if(this->ls_object_.ObjectType && this->ls_object_.ObjectType == pIntType)
	{
		return int(this->ls_object_.GetObjectData().DWord);
	}
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pIntPtrType)
	{
		return int(*(this->ls_object_.GetObjectData().DWordPtr));
	}
	return INT_MAX;
}

int64_t py_lsobject::get_int64_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pInt64Type)
	{
		return int64_t(this->ls_object_.GetObjectData().Int64);
	}
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pInt64PtrType)
	{
		return int64_t(*(this->ls_object_.GetObjectData().Int64Ptr));
	}
	return INT64_MAX;
}

const LSOBJECT& py_lsobject::get_lso() const
{
	return this->ls_object_;
}

std::string py_lsobject::get_string_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pStringType)
	{
		size_t characters_converted;
		char buffer[MAX_VARSTRING];
		if (this->ls_object_.GetObjectData().CharPtr != nullptr)
			return std::string(this->ls_object_.GetObjectData().CharPtr);
		if (this->ls_object_.GetObjectData().ConstCharPtr != nullptr)
			return std::string(this->ls_object_.GetObjectData().ConstCharPtr);
		if (this->ls_object_.GetObjectData().WCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->ls_object_.GetObjectData().WCharPtr, _countof(buffer));
			return std::string(buffer);
		}			
		if (this->ls_object_.GetObjectData().ConstWCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->ls_object_.GetObjectData().ConstWCharPtr, _countof(buffer));
			return std::string(buffer);
		}			
	}
	return std::string("Error");
}

unsigned int py_lsobject::get_uint_from_lso()
{
	if (this->ls_object_.ObjectType && this->ls_object_.ObjectType == pUintType)
	{
		return unsigned int(this->ls_object_.GetObjectData().DWord);
	}
	return UINT_MAX;
}

template <class T>
int py_lsobject::get_list_from_index_method(PCHAR method, PCHAR index_type, PCHAR query, boost::python::list& python_list)
{
	LSOBJECT index_object;
	size_t size = 0;
	const int random = rand() % INT_MAX;
	const int argc = 1;
	const int argc_query = 2;
	char* argv[argc];
	char* argv_query[argc_query];
	char variable_name[MAX_VARSTRING];
	char declare_command[MAX_VARSTRING];
	char delete_command[MAX_VARSTRING];
	sprintf_s(variable_name, _countof(variable_name), "%s_%d", "ISXPy_index_random", random);
	sprintf_s(declare_command, _countof(declare_command), "DeclareVariable %s index:%s global", variable_name, index_type);
	sprintf_s(delete_command, _countof(delete_command), "DeleteVariable %s", variable_name);
	argv[0] = variable_name;
	argv_query[0] = variable_name;
	argv_query[1] = query;
	try
	{
		pISInterface->ExecuteCommand(declare_command);
		pISInterface->DataParse(argv[0], index_object);
		if (query == nullptr)
			this->execute_method(method, argc, argv);
		else
			this->execute_method(method, argc_query, argv_query);
		size = static_cast<LSIndex*>(index_object.Ptr)->GetContainerUsed();
		for (size_t i = 0; i < size; i++)
		{
			python_list.append(reinterpret_cast<T*>((*static_cast<LSIndex*>(index_object.Ptr)->GetIndex())[i]));
		}
		pISInterface->ExecuteCommand(delete_command);
	}
	catch (exception &) {}
	return len(python_list);
}

int py_character::query_effects(boost::python::list& effect_list, const std::string& query)
{
	return this->get_list_from_index_method<py_effect>(static_cast<char *>("QueryEffects"),
	                                                   static_cast<char *>("effect"), const_cast<char *>(query.c_str()),
	                                                   effect_list);
}

int py_eq2::query_actors(boost::python::list& actor_list, const std::string& query)
{
	return this->get_list_from_index_method<py_actor>(static_cast<char *>("QueryActors"), static_cast<char *>("actor"),
	                                                  const_cast<char *>(query.c_str()), actor_list);
}

int py_character::query_inventory(boost::python::list& item_list, const std::string& query)
{
	return this->get_list_from_index_method<py_item>(static_cast<char *>("QueryInventory"), static_cast<char *>("item"),
	                                                 const_cast<char *>(query.c_str()), item_list);
}

int py_character::query_recipes(boost::python::list& recipe_list, const std::string& query)
{
	return this->get_list_from_index_method<py_recipe>(static_cast<char *>("QueryRecipes"),
	                                                   static_cast<char *>("recipe"), const_cast<char *>(query.c_str()),
	                                                   recipe_list);
}