#pragma once
#include <isxdk.h>
#include <windows.h>

class ISXPy :
	public ISXInterface
{
public:
	ISXPy(void);
	~ISXPy(void);

	virtual bool Initialize(ISInterface *p_ISInterface);
	virtual void Shutdown();

	void RegisterExtension();

	void ConnectServices();
	void RegisterCommands();
	void RegisterAliases();
	void RegisterDataTypes();
	void RegisterTopLevelObjects();
	void RegisterServices();
	void RegisterTriggers();

	void DisconnectServices();
	void UnRegisterCommands();
	void UnRegisterAliases();
	void UnRegisterDataTypes();
	void UnRegisterTopLevelObjects();
	void UnRegisterServices();

};

extern ISInterface *pISInterface;
extern HISXSERVICE hPulseService;
extern HISXSERVICE hMemoryService;
extern HISXSERVICE hHTTPService;
extern HISXSERVICE hTriggerService;
extern HISXSERVICE hSystemService;

extern ISXPy *pExtension;
#define printf pISInterface->Printf

#define EzDetour(Address, Detour, Trampoline) IS_Detour(pExtension,pISInterface,hMemoryService,(unsigned int)Address,Detour,Trampoline)
#define EzUnDetour(Address) IS_UnDetour(pExtension,pISInterface,hMemoryService,(unsigned int)Address)
#define EzDetourAPI(_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_) IS_DetourAPI(pExtension,pISInterface,hMemoryService,_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_)
#define EzUnDetourAPI(Address) IS_UnDetourAPI(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzModify(Address,NewData,Length,Reverse) Memory_Modify(pExtension,pISInterface,hMemoryService,(unsigned int)Address,NewData,Length,Reverse)
#define EzUnModify(Address) Memory_UnModify(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzHttpRequest(_URL_,_pData_) IS_HttpRequest(pExtension,pISInterface,hHTTPService,_URL_,_pData_)

#define EzAddTrigger(Text,Callback,pUserData) IS_AddTrigger(pExtension,pISInterface,hTriggerService,Text,Callback,pUserData)
#define EzRemoveTrigger(ID) IS_RemoveTrigger(pExtension,pISInterface,hTriggerService,ID)
#define EzCheckTriggers(Text) IS_CheckTriggers(pExtension,pISInterface,hTriggerService,Text)

static LONG EzCrashFilter(_EXCEPTION_POINTERS *pExceptionInfo,const char *szIdentifier,...)
{
	unsigned int Code=pExceptionInfo->ExceptionRecord->ExceptionCode;
	if (Code==EXCEPTION_BREAKPOINT || Code==EXCEPTION_SINGLE_STEP)
		return EXCEPTION_CONTINUE_SEARCH;

	char szOutput[4096];
	szOutput[0]=0;
    va_list vaList;

    va_start( vaList, szIdentifier );
    vsprintf_s(szOutput,szIdentifier, vaList);

	IS_SystemCrashLog(pExtension,pISInterface,hSystemService,pExceptionInfo,szOutput);

	return EXCEPTION_EXECUTE_HANDLER;
}

extern LSType *pStringType;
extern LSType *pIntType;
extern LSType *pUintType;
extern LSType *pBoolType;
extern LSType *pFloatType;
extern LSType *pTimeType;
extern LSType *pByteType;
extern LSType *pIntPtrType;
extern LSType *pBoolPtrType;
extern LSType *pFloatPtrType;
extern LSType *pBytePtrType;

extern LSType *pUintPtrType;
extern LSType *pFloat64Type;
extern LSType *pFloat64PtrType;
extern LSType *pMutableStringType;
extern LSType *pPoint3fType;
extern LSType *pGroupMemberType;
extern LSType *pActorEffectType;
extern LSType *pEffectInfoType;
extern LSType *pEffectType;
extern LSType *pMaintainedType;
extern LSType *pEQ2DynamicDataType;
extern LSType *pInt64Type;
extern LSType *pInt64PtrType;
extern LSType *pISXEQ2Type;
extern LSType *pEQ2Type;
extern LSType *pActorType;
extern LSType *pCharacterType;
extern LSType *pIndexType;

extern char Py_Version[];

extern void set_pulse_channel();
#include "imgui.h"
#include "ui_manager.h"
#include "tasklet.h"
#include "channel.h"
#include "stackless_module.h"

#include "globals.h"

#include "Commands.h"
#include "DataTypes.h"
#include "TopLevelObjects.h"
#include "Services.h"

#include "ls_object.h"
#include "ls_bool.h"
#include "ls_int.h"
#include "ls_float.h"
#include "ls_string.h"
#include "ls_point3_f.h"

#include "eq2_effect_info.h"
#include "eq2_actor_effect.h"
#include "eq2_dynamic_data.h"
#include "eq2_effect.h"
#include "eq2_isxeq2.h"
#include "eq2_actor.h"
#include "eq2_maintained.h"
#include "eq2_eq2.h"
#include "eq2_group_member.h"
#include "eq2_item.h"
#include "eq2_recipe.h"
#include "eq2_character.h"

#include "eq2_actor_despawned_args.h"
#include "eq2_actor_spawned_args.h"
#include "eq2_on_quest_offered_args.h"

#include "isxpy_extensions.h"
#include "isxpy_module.h"
#include "isxpy_events.h"
#include "isxeq2_events.h"
#include "isxeq2_module.h"


