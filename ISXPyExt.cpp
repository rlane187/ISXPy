#include "ISXPyPCH.h"
#include "ISXPy.h"

using namespace boost::python;

TLOBase::TLOBase()
{
	this->tlo_name_ = std::string("");
	this->p_type_def_ = nullptr;
}

bool TLOBase::get_ls_object_from_tlo_member(int tlo_argc, PCHAR tlo_argv[], PCHAR member_name, int argc, PCHAR argv[], LSOBJECT& dest) const
{
	bool is_valid = false;
	try
	{
		LSOBJECT tlo_object;
		is_valid = pISInterface->IsTopLevelObject(this->tlo_name_.c_str())(tlo_argc, tlo_argv, tlo_object);
		if(!is_valid)
		{
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, _countof(buffer), "%s is not a valid LS TLO.", this->tlo_name_.c_str());
			throw std::runtime_error(buffer);
		}
		this->p_type_def_->GetMember(tlo_object.GetObjectData(), this->p_type_def_->FindMember(member_name), argc, argv, dest);
		return is_valid;
	}
	catch (exception& e) {}
	return is_valid;
}

bool TLOBase::execute_tlo_method(int tlo_argc, PCHAR tlo_argv[], PCHAR method_name, int argc, PCHAR argv[]) const
{
	bool is_valid = false;
	try
	{
		LSOBJECT tlo_object;
		is_valid = pISInterface->IsTopLevelObject(this->tlo_name_.c_str())(tlo_argc, tlo_argv, tlo_object);
		if (!is_valid)
		{
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, _countof(buffer), "%s is not a valid LS TLO.", this->tlo_name_.c_str());
			throw std::runtime_error(buffer);
		}
		this->p_type_def_->GetMethod(tlo_object.GetObjectData(), this->p_type_def_->FindMethod(method_name), argc, argv);
		return is_valid;
	}
	catch (exception& e) {}
	return is_valid;
}

std::string TLOBase::get_string_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.Type->GetName(), "string") == 0 && ls_object.CharPtr != nullptr && strlen(ls_object.CharPtr) > 0)
		return std::string(ls_object.CharPtr);
	return std::string("Error");
}

bool TLOBase::get_bool_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.Type->GetName(), "bool") == 0)
		return bool(ls_object.DWord);
	return false;
}

int TLOBase::get_byte_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.Type->GetName(), "byte") == 0)
		return int(ls_object.DWord);
	return INT_MAX;
}

int TLOBase::get_int_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.Type->GetName(), "int") == 0)
		return int(ls_object.DWord);
	return INT_MAX;
}

int64_t TLOBase::get_int64_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.ObjectType->GetName(), "int64") == 0)
		return int64_t(ls_object.Int64);
	return INT64_MAX;
}

float TLOBase::get_float_from_ls_object(LSOBJECT& ls_object)
{
	if (strcmp(ls_object.ObjectType->GetName(), "float") == 0)
		return float(ls_object.Float);
	return FLT_MAX;
}

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
		if (this->ls_object_.CharPtr != nullptr)
			return std::string(this->ls_object_.CharPtr);
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

