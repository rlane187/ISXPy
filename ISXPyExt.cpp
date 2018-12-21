#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(isxpy)
{
	class_<OutputHandler>("OutputHandler")
		.def("write", &OutputHandler::write)
		.def("flush", &OutputHandler::flush);

	class_<ErrorHandler>("ErrorHandler")
		.def("write", &ErrorHandler::write)
		.def("flush", &ErrorHandler::flush);
}

void Initialize_Module_ISXPy()
{
	PyImport_AppendInittab("isxpy", PyInit_isxpy);
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

LSObject::LSObject() = default;

LSObject::LSObject(LSOBJECT& ls_object)
{	
	this->ls_object_ = ls_object;
}

void LSObject::execute_method(PCHAR method, int argc, char* argv[])
{
	if (this->ls_object_.ObjectType && this->has_method(method))
		this->ls_object_.ObjectType->GetMethodEx(this->ls_object_.GetObjectData(), method, argc, argv);
	else if (this->ls_object_.ObjectType && this->has_inherited_method(method))
		this->ls_object_.ObjectType->GetInheritedMethod(this->ls_object_.GetObjectData(), method, argc, argv);
}

LSObject LSObject::get_member(PCHAR member, int argc, char* argv[])
{
	LSOBJECT dest;
	if(this->ls_object_.ObjectType && this->has_member(member))
		this->ls_object_.ObjectType->GetMemberEx(this->ls_object_.GetObjectData(), member, argc, argv, dest);
	else if (this->ls_object_.ObjectType && this->has_inherited_member(member))
		this->ls_object_.ObjectType->GetInheritedMember(this->ls_object_.GetObjectData(), member, argc, argv, dest);
	return static_cast<LSObject>(dest);
}

void LSObject::get_member(PCHAR member, int argc, char* argv[], LSOBJECT& ls_object)
{
	if (this->ls_object_.ObjectType && this->has_member(member))
		this->ls_object_.ObjectType->GetMemberEx(this->ls_object_.GetObjectData(), member, argc, argv, ls_object);
	else if (this->ls_object_.ObjectType && this->has_inherited_member(member))
		this->ls_object_.ObjectType->GetInheritedMember(this->ls_object_.GetObjectData(), member, argc, argv, ls_object);
}

bool LSObject::has_inherited_member(PCHAR member) const
{
	if (this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->InheritedMember(member))
			return true;
	}
	return false;
}

bool LSObject::has_inherited_method(PCHAR method) const
{
	if (this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->InheritedMethod(method))
			return true;
	}
	return false;
}

bool LSObject::has_member(PCHAR member) const
{
	if(this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->FindMember(member))
			return true;
	}
	return false;
}

bool LSObject::has_method(PCHAR method) const
{
	if(this->ls_object_.ObjectType)
	{
		if (this->ls_object_.ObjectType->FindMethod(method))
			return true;
	}
	return false;
}

bool LSObject::get_bool_from_lso()
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

int LSObject::get_byte_from_lso()
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

float LSObject::get_float_from_lso()
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

int LSObject::get_int_from_lso()
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

int64_t LSObject::get_int64_from_lso()
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

LSOBJECT& LSObject::get_lso()
{
	return this->ls_object_;
}

std::string LSObject::get_string_from_lso()
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

template <class T>
int LSObject::get_list_from_index_method(PCHAR method, PCHAR index_type, PCHAR query, boost::python::list& python_list)
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

int PyCharacter::get_effects(boost::python::list& effect_list)
{
	return this->get_list_from_index_method<PyEffect>(static_cast<char *>("QueryEffects"), static_cast<char *>("effect"), nullptr, effect_list);
}

int PyCharacter::get_detrimental_effects(boost::python::list& detrimental_list)
{
	return this->get_list_from_index_method<PyEffect>(static_cast<char *>("QueryEffects"), static_cast<char *>("effect"), static_cast<char *>("Type == \"Detrimental\""), detrimental_list);
}

int PyCharacter::get_beneficial_effects(boost::python::list& beneficial_list)
{
	return this->get_list_from_index_method<PyEffect>(static_cast<char *>("QueryEffects"), static_cast<char *>("effect"), static_cast<char *>("Type == \"Beneficial\""), beneficial_list);
}