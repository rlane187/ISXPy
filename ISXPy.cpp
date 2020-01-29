#include "ISXPyPCH.h"
//
// ISXPy
//
// Version guideline: YYYYMMDD
// Add lettering to the end to indicate a new version on the same date, such as 20060305a, 20060305b, etc
// You can also use a standard version numbering system such as 1.00, 1.01, etc. 
// Be aware that for the versioning system, this text is simply compared to another version text from the 
// same extension to check for new versions -- if this version text comes before the compared text (in a 
// dictionary), then an update is available.  Equal text means the version is up to date.  After means this 
// is newer than the compared version.  With that said, use whatever version numbering system you'd like.
#define EXTENSION_VERSION "20101128"

#include "ISXPy.h"
#include <PathCch.h>

char DllPath[MAX_PATH] = { 0 };
wchar_t DllPathW[MAX_PATH] = { 0 };
char PythonScriptPath[MAX_PATH] = { 0 };
char PythonLibPath[MAX_PATH] = { 0 };
char PythonDLLPath[MAX_PATH] = { 0 };
wchar_t PythonPathW[MAX_VARSTRING] = { 0 };

unsigned int frame_count = 0;

std::map<std::string, tasklet*> tasklet_map = {};

#pragma comment(lib,"isxdk.lib")
// The mandatory pre-setup function.  Our name is "ISXPy", and the class is ISXPy.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXPy",ISXPy)

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pUintType=0;
LSType *pBoolType=0;
LSType *pFloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;
LSType *pIntPtrType=0;
LSType *pBoolPtrType=0;
LSType *pFloatPtrType=0;
LSType *pBytePtrType=0;

LSType *pUintPtrType = 0;
LSType *pFloat64Type = 0;
LSType *pFloat64PtrType = 0;
LSType *pMutableStringType = 0;
LSType *pPoint3fType = 0;
LSType *pGroupMemberType = 0;
LSType *pActorEffectType = 0;
LSType *pEffectInfoType = 0;
LSType *pEffectType = 0;
LSType *pMaintainedType = 0;
LSType *pEQ2DynamicDataType = 0;
LSType *pInt64Type = 0;
LSType *pInt64PtrType = 0;
LSType *pISXEQ2Type = 0;
LSType *pEQ2Type = 0;
LSType *pActorType = 0;
LSType *pCharacterType = 0;
LSType *pIndexType = 0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService;
HISXSERVICE hMemoryService;
HISXSERVICE hHTTPService;
HISXSERVICE hTriggerService;
HISXSERVICE hSystemService;

char Py_Version[]=EXTENSION_VERSION;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData);


// The constructor of our class.  General initialization cannot be done yet, because we're not given
// the pointer to the Inner Space interface until it is ready for us to initialize.  Just set the
// pointer we have to the interface to 0.  Initialize data members, too.
ISXPy::ISXPy(void)
{
}

// Free any remaining resources in the destructor.  This is called when the DLL is unloaded, but
// Inner Space calls the "Shutdown" function first.  Most if not all of the shutdown process should
// be done in Shutdown.
ISXPy::~ISXPy(void)
{
}

// Initialize is called by Inner Space when the extension should initialize.
bool ISXPy::Initialize(ISInterface *p_ISInterface)
{
	/* 
	 * Most of the functionality in Initialize is completely optional and could be removed or
	 * changed if so desired.  The defaults are simply a suggestion that can be easily followed.
	 */
	__try // exception handling. See __except below.
	{

		// Keep a global copy of the ISInterface pointer, which is for calling Inner Space API
		pISInterface=p_ISInterface;

		// Register the extension to make launching and updating the extension easy
		RegisterExtension();

		// retrieve basic LavishScript data types for use in ISXPy data types
		pStringType=pISInterface->FindLSType("string");
		pIntType=pISInterface->FindLSType("int");
		pUintType=pISInterface->FindLSType("uint");
		pBoolType=pISInterface->FindLSType("bool");
		pFloatType=pISInterface->FindLSType("float");
		pTimeType=pISInterface->FindLSType("time");
		pByteType=pISInterface->FindLSType("byte");
		pIntPtrType=pISInterface->FindLSType("intptr");
		pBoolPtrType=pISInterface->FindLSType("boolptr");
		pFloatPtrType=pISInterface->FindLSType("floatptr");
		pBytePtrType=pISInterface->FindLSType("byteptr");

		pUintPtrType = pISInterface->FindLSType("uintptr");
		pFloat64Type = pISInterface->FindLSType("float64");
		pFloat64PtrType = pISInterface->FindLSType("float64ptr");
		pMutableStringType = pISInterface->FindLSType("mutablestring");
		pPoint3fType = pISInterface->FindLSType("point3f");
		pGroupMemberType = pISInterface->FindLSType("groupmember");
		pActorEffectType = pISInterface->FindLSType("actoreffect");
		pEffectInfoType = pISInterface->FindLSType("effectinfo");
		pEffectType = pISInterface->FindLSType("effect");
		pMaintainedType = pISInterface->FindLSType("maintained");
		pEQ2DynamicDataType = pISInterface->FindLSType("eq2dynamicdata");
		pInt64Type = pISInterface->FindLSType("int64");
		pInt64PtrType = pISInterface->FindLSType("int64ptr");
		pISXEQ2Type = pISInterface->FindLSType("ISXEQ2");
		pActorType = pISInterface->FindLSType("actor");
		pEQ2Type = pISInterface->FindLSType("eq2");		
		pCharacterType = pISInterface->FindLSType("character");
		pIndexType = pISInterface->FindLSType("index");

		// Connect to commonly used Inner Space services
		ConnectServices();

		// Register LavishScript extensions (commands, aliases, data types, objects)
		RegisterCommands();
		RegisterAliases();
		RegisterDataTypes();
		RegisterTopLevelObjects();

		// Register (create) our own services
		RegisterServices();

		// Register any text triggers built into ISXPy
		RegisterTriggers();

		printf("ISXPy version %s Loaded",Py_Version);
		
		initialize_module_isxpy();
		initialize_module_isxeq2();	
		Py_Initialize();
		adjust_path();		
		printf("\ayPython %s on %s", Py_GetVersion(), Py_GetPlatform());
		redirect_output_to_console();
		initialize_isxpy_events();
		initialize_eq2_events();
		initialize_directx_hooks();
	}	
	// Exception handling sample.  Exception handling should at LEAST be used in functions that
	// are suspected of causing user crashes.  This will help users report the crash and hopefully
	// enable the extension developer to locate and fix the crash condition.
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine")) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	
	return true;
	
	/* 
	 * EzCrashFilter takes printf-style formatting after the first parameter.  The above
	 * could look something like this:
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine (%s:%d)",__FILE__,__LINE__)) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	 * of course, the FILE and LINE macros would be the location of the exception handler, not the
	 * actual crash, but you should get the idea that extra parameters can be used as if EzCrashFilter
	 * was printf.
	 *
	 * EzCrashFilter will automatically produce a crash log (CrashLog.txt) and open it in notepad for
	 * non-breakpoint exceptions (and hopefully the user will report the crash to the extension developer).  
	 * Your exception handler (the part within the {} under __except) should simply terminate the process 
	 * and return from the function as in the sample.  The return will not be hit, but the compiler will 
	 * whine without it because it doesn't automatically know that the function will not return.  
	 */

}

// shutdown sequence
void ISXPy::Shutdown()
{
	// Disconnect from services we connected to
	DisconnectServices();

	// Unregister (destroy) services we created
	UnRegisterServices();

	// Remove LavishScript extensions (commands, aliases, data types, objects)
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();
	//shutdown_eq2_events();
	//shutdown_isxpy_events();
	
	shutdown_module_isxpy();
	shutdown_module_isxeq2();
	//quit_script();
	shutdown_directx_hooks();
	Py_Finalize();
	printf("ISXPy Unloaded");
}

/*
 * Note that Initialize and Shutdown are the only two REQUIRED functions in your ISXInterface class.
 * All others are for suggested breakdown of routines, and for example purposes.
 */

void ISXPy::RegisterExtension()
{
	// add this extension to, or update this extension's info in, InnerSpace.xml.
	// This accomplishes a few things.  A) The extension can be loaded by name (ISXPy)
	// no matter where it resides on the system.  B) A script or extension can
	// check a repository to determine if there is an update available (and update
	// if necessary)

	unsigned int ExtensionSetGUID=pISInterface->GetExtensionSetGUID("ISXPy");
	if (!ExtensionSetGUID)
	{
		ExtensionSetGUID=pISInterface->CreateExtensionSet("ISXPy");
		if (!ExtensionSetGUID)
			return;
	}
	pISInterface->SetSetting(ExtensionSetGUID,"Filename",ModuleFileName);
	pISInterface->SetSetting(ExtensionSetGUID,"Path",ModulePath);
	pISInterface->SetSetting(ExtensionSetGUID,"Version",Py_Version);
}

void ISXPy::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);

	// The HTTP service handles URL retrieval
	hHTTPService=pISInterface->ConnectService(this,"HTTP",HTTPService);

	// The Triggers service handles trigger-related functions, including the
	// ability to pass text TO the trigger parser, as well as the ability to
	// add triggers.
	hTriggerService=pISInterface->ConnectService(this,"Triggers",TriggerService);

	// The System service provides general system-related services, including
	// a diagnostics message that allows the extension to insert diagnostic
	// information for the "diagnostics" command, and extension crash logs.
	hSystemService=pISInterface->ConnectService(this,"System",SystemService);
}
void ISXPy::RegisterCommands()
{
	// add any commands
//	pISInterface->AddCommand("ISXPy",CMD_ISXPy,true,false);
#define COMMAND(name,cmd,parse,hide) pISInterface->AddCommand(name,cmd,parse,hide);
#include "Commands.h"
#undef COMMAND
}

void ISXPy::RegisterAliases()
{
	// add any aliases
}

void ISXPy::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddLSType(*pMyType);


#define DATATYPE(_class_,_variable_,_inherits_) _variable_ = new _class_; pISInterface->AddLSType(*_variable_); _variable_->SetInheritance(_inherits_);
#include "DataTypeList.h"
#undef DATATYPE
}

void ISXPy::RegisterTopLevelObjects()
{
	// add any Top-Level Objects
	//pISInterface->AddTopLevelObject("ISXPy",TLO_ISXPy);
#define TOPLEVELOBJECT(name,funcname) pISInterface->AddTopLevelObject(name,funcname);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}

void ISXPy::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
//	hISXPyService=pISInterface->RegisterService(this,"ISXPy Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
//	pISInterface->ServiceBroadcast(this,hISXPyService,ISXSERVICE_MSG+1,0);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->RegisterService(this,_name_,_callback_);
#include "Services.h"
#undef SERVICE
}

void ISXPy::RegisterTriggers()
{
	// add any Triggers
}

void ISXPy::DisconnectServices()
{
	// gracefully disconnect from services
	if (hPulseService)
		pISInterface->DisconnectService(this,hPulseService);
	if (hMemoryService)
	{
		pISInterface->DisconnectService(this,hMemoryService);
		// memory modifications are automatically undone when disconnecting
		// also, since this service accepts messages from clients we should reset our handle to
		// 0 to make sure we dont try to continue using it
		hMemoryService=0; 
	}
	if (hHTTPService)
	{
		pISInterface->DisconnectService(this,hHTTPService);
	}
	if (hTriggerService)
	{
		pISInterface->DisconnectService(this,hTriggerService);
	}
	if (hSystemService)
	{
		pISInterface->DisconnectService(this,hSystemService);
	}
}

void ISXPy::UnRegisterCommands()
{
	// remove commands
//	pISInterface->RemoveCommand("ISXPy");
#define COMMAND(name,cmd,parse,hide) pISInterface->RemoveCommand(name);
#include "Commands.h"
#undef COMMAND
}
void ISXPy::UnRegisterAliases()
{
	// remove aliases
}
void ISXPy::UnRegisterDataTypes()
{
	// remove data types
#define DATATYPE(_class_,_variable_,_inherits_) pISInterface->RemoveLSType(*_variable_); delete _variable_;
#include "DataTypeList.h"
#undef DATATYPE

}
void ISXPy::UnRegisterTopLevelObjects()
{
	// remove Top-Level Objects
//	pISInterface->RemoveTopLevelObject("ISXPy");
#define TOPLEVELOBJECT(name,funcname) pISInterface->RemoveTopLevelObject(name);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}
void ISXPy::UnRegisterServices()
{
	// shutdown our own services
//	if (hISXPyService)
//		pISInterface->ShutdownService(this,hISXPyService);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->ShutdownService(this,_variable_);
#include "Services.h"
#undef SERVICE
}

void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
	using namespace boost::python;
	if (MSG==PULSE_PULSE)
	{		
		/*
		 * "OnPulse"
		 * This message is received by the extension before each frame is
		 * displayed by the game.  This is the place to put any repeating
		 * tasks.
		 */
		on_frame(0, nullptr, nullptr);
	}
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==SYSTEMSERVICE_DIAGNOSTICS)
	{
		// Diagnostics sample
		/*
		FILE *file=(FILE*)lpData;
		fprintf(file,"ISXPy version %s\n",EXTENSION_VERSION);
		fprintf(file,"------------------------------------\n",EXTENSION_VERSION);
		fprintf(file,"Any ISXPy diagnostic information here\n");
		fprintf(file,"\n");// extra spacing for making the crash log look nice
		/**/
	}
}

void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
#define pReq ((HttpFile*)lpData)
	case HTTPSERVICE_FAILURE:
		// HTTP request failed to retrieve document
		printf("ISXPy URL %s failed",pReq->URL);
		break;
	case HTTPSERVICE_SUCCESS:
		// HTTP request successfully retrieved document
		printf("ISXPy URL %s -- %d bytes",pReq->URL,pReq->Size);
		// Retrieved data buffer is pReq->pBuffer and is null-terminated
		break;
#undef pReq
	}
}

