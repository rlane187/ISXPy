#include "ISXPyPCH.h"
#include "ISXPy.h"

ls_object::ls_object() = default;

ls_object::ls_object(const ls_object& other)
{
	this->lsobject_ = other.lsobject_;
}

ls_object::ls_object(ls_object&& other) noexcept
{
	this->lsobject_ = other.lsobject_;
}

ls_object::ls_object(const LSOBJECT& other)
{	
	this->lsobject_ = other;
}

ls_object::~ls_object() = default;

ls_object& ls_object::operator=(const ls_object& other)
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

ls_object& ls_object::operator=(ls_object&& other) noexcept
{
	if (this != &other)
		this->lsobject_ = other.lsobject_;
	return *this;
}

void ls_object::execute_method(PCHAR method, int argc, char* argv[])
{
	if (this->lsobject_.ObjectType && this->has_method(method))
		this->lsobject_.ObjectType->GetMethodEx(this->lsobject_.GetObjectData(), method, argc, argv);
	else if (this->lsobject_.ObjectType && this->has_inherited_method(method))
		this->lsobject_.ObjectType->GetInheritedMethod(this->lsobject_.GetObjectData(), method, argc, argv);
	else
	{
		if (this->lsobject_.ObjectType)
		{
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, _countof(buffer), R"(LS Object of type '%s' does not have a method '%s'.)",
				this->lsobject_.ObjectType->GetName(), method);
			PyErr_SetString(PyExc_NameError, buffer);
		}
		else
			PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	}
		
}

bool ls_object::get_bool_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBoolType)
	{
		return bool(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBoolPtrType)
	{
		return bool(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'bool' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return false;
}

int ls_object::get_byte_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pByteType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pBytePtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'byte' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

float ls_object::get_float_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatType)
	{
		return float(this->lsobject_.GetObjectData().Float);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pFloatPtrType)
	{
		return float(*reinterpret_cast<float*>(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'float' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1.0f;
}

int ls_object::get_int_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntType)
	{
		return int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pIntPtrType)
	{
		return int(*(this->lsobject_.GetObjectData().DWordPtr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'int' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

int64_t ls_object::get_int64_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64Type)
	{
		return int64_t(this->lsobject_.GetObjectData().Int64);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pInt64PtrType)
	{
		return int64_t(*(this->lsobject_.GetObjectData().Int64Ptr));
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'int64' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return -1;
}

const LSOBJECT& ls_object::get_lso() const
{
	return this->lsobject_;
}

ls_object ls_object::get_member(PCHAR member, int argc, char* argv[])
{
	LSOBJECT dest;
	if(this->lsobject_.ObjectType && this->has_member(member))
		this->lsobject_.ObjectType->GetMemberEx(this->lsobject_.GetObjectData(), member, argc, argv, dest);
	else if (this->lsobject_.ObjectType && this->has_inherited_member(member))
		this->lsobject_.ObjectType->GetInheritedMember(this->lsobject_.GetObjectData(), member, argc, argv, dest);
	else
	{
		if (this->lsobject_.ObjectType)
		{
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, _countof(buffer), R"(Object of type '%s' does not have a member '%s'.)",
				this->lsobject_.ObjectType->GetName(), member);
			PyErr_SetString(PyExc_NameError, buffer);
		}
		else
			PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	}
	return dest;
}

std::string ls_object::get_mutable_string_from_lso()
{
	if(this->lsobject_.ObjectType && this->lsobject_.ObjectType == pMutableStringType)
	{
		char* const member = static_cast<char *>("String");
		return this->get_member(member, 0, nullptr).get_string_from_lso();
	}
	return std::string("NULL");
}


std::string ls_object::get_string_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pStringType)
	{
		size_t characters_converted;
		char buffer[MAX_VARSTRING];
		if (this->lsobject_.GetObjectData().CharPtr != nullptr)
			return std::string(this->lsobject_.GetObjectData().CharPtr);
		if (this->lsobject_.GetObjectData().ConstCharPtr != nullptr)
			return std::string(this->lsobject_.GetObjectData().ConstCharPtr);
		if (this->lsobject_.GetObjectData().WCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->lsobject_.GetObjectData().WCharPtr, _countof(buffer));
			return std::string(buffer);
		}
		if (this->lsobject_.GetObjectData().ConstWCharPtr != nullptr)
		{
			wcstombs_s(&characters_converted, buffer, _countof(buffer), this->lsobject_.GetObjectData().ConstWCharPtr, _countof(buffer));
			return std::string(buffer);
		}
		if (this->lsobject_.ObjectType)
		{
			char buffer_exception[MAX_VARSTRING];
			sprintf_s(buffer_exception, _countof(buffer_exception), R"(LS Type 'string' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
			PyErr_SetString(PyExc_TypeError, buffer_exception);
		}
		else
			PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	}
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pMutableStringType)
	{
		return this->get_mutable_string_from_lso();
	}
	return std::string("NULL");
}

unsigned int ls_object::get_uint_from_lso()
{
	if (this->lsobject_.ObjectType && this->lsobject_.ObjectType == pUintType)
	{
		return unsigned int(this->lsobject_.GetObjectData().DWord);
	}
	if (this->lsobject_.ObjectType)
	{
		char buffer[MAX_VARSTRING];
		sprintf_s(buffer, _countof(buffer), R"(LS Type 'uint' expected. LS Type is '%s'.)", this->lsobject_.ObjectType->GetName());
		PyErr_SetString(PyExc_TypeError, buffer);
	}
	else
		PyErr_WarnEx(PyExc_RuntimeWarning, "LS Object did not have a valid LS Type.", 1);
	return UINT_MAX;
}

bool ls_object::has_inherited_member(PCHAR member) const
{
	if (this->lsobject_.ObjectType)
	{
		if (this->lsobject_.ObjectType->InheritedMember(member))
			return true;
	}
	return false;
}

bool ls_object::has_inherited_method(PCHAR method) const
{
	if (this->lsobject_.ObjectType)
	{
		if (this->lsobject_.ObjectType->InheritedMethod(method))
			return true;
	}
	return false;
}

bool ls_object::has_member(PCHAR member) const
{
	if(this->lsobject_.ObjectType)
	{
		if (this->lsobject_.ObjectType->FindMember(member))
			return true;
	}
	return false;
}

bool ls_object::has_method(PCHAR method) const
{
	if(this->lsobject_.ObjectType)
	{
		if (this->lsobject_.ObjectType->FindMethod(method))
			return true;
	}
	return false;
}

template <class T>
int ls_object::get_list_from_index_method(PCHAR method, PCHAR index_type, PCHAR query, boost::python::list& python_list)
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
	return len(python_list);
}

int py_eq2::query_actors(boost::python::list& actor_list, const std::string& query)
{
	return this->get_list_from_index_method<py_eq2_actor>(static_cast<char *>("QueryActors"), static_cast<char *>("actor"),
		const_cast<char *>(query.c_str()), actor_list);
}

int py_eq2_character::query_effects(boost::python::list& effect_list, const std::string& query)
{
	return this->get_list_from_index_method<py_eq2_effect>(static_cast<char *>("QueryEffects"),
	                                                   static_cast<char *>("effect"), const_cast<char *>(query.c_str()),
	                                                   effect_list);
}

int py_eq2_character::query_inventory(boost::python::list& item_list, const std::string& query)
{
	return this->get_list_from_index_method<py_eq2_item>(static_cast<char *>("QueryInventory"), static_cast<char *>("item"),
	                                                 const_cast<char *>(query.c_str()), item_list);
}

int py_eq2_character::query_recipes(boost::python::list& recipe_list, const std::string& query)
{
	return this->get_list_from_index_method<py_eq2_recipe>(static_cast<char *>("QueryRecipes"),
	                                                   static_cast<char *>("recipe"), const_cast<char *>(query.c_str()),
	                                                   recipe_list);
}