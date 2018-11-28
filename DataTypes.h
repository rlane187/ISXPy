#pragma once
#include "DataTypeList.h"

// custom data type declarations 

class PyType : public LSTypeDefinition
{
public:
	// All data members (retrieving data) should be listed in this enumeration
	enum PyTypeMembers
	{
		RetrieveData,
	};
	// All data methods (performing actions on or with the object) should be listed in this enumeration
	enum PyTypeMethods
	{
		PerformAction,
	};

	PyType() : LSType("py")
	{
		// Use the TypeMember macro to activate each member, or use AddMember
		TypeMember(RetrieveData);

		// Use the TypeMethod macro to activate each member, or use AddMethod
		TypeMethod(PerformAction);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
