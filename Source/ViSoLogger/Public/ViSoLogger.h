// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/*
#define GET_CLASSNAME_WITH_FUNCTION                FString(__FUNCTION__)
#define GET_LINE_NUMBER                            FString::FromInt(__LINE__)
#define BX_LOG(CategoryName,Verbosity,Message) UE_LOG(CategoryName,Verbosity,TEXT("%s [%s]: %s"), *GET_CLASSNAME_WITH_FUNCTION,  *GET_LINE_NUMBER,*FString(Message))
#define BX_LOG_BP(CategoryName,Verbosity,BlueprintName, BlueprintMethod,Message) UE_LOG(CategoryName,Verbosity,TEXT("%s [%s]: %s"),*BlueprintName,*BlueprintMethod,*Message)

DECLARE_LOG_CATEGORY_EXTERN(ViSoLog, Log, All);

/* Examples:
DEFINE_LOG_CATEGORY(LogOBCombat)

DEFINE_LOG_CATEGORY(LogOBStatusEffects)

DEFINE_LOG_CATEGORY (LogDebugTrace)

DECLARE_LOG_CATEGORY_EXTERN(LogOBCombat, All, All);
DECLARE_LOG_CATEGORY_EXTERN(LogOBStatusEffects, Display, All);
DECLARE_LOG_CATEGORY_EXTERN(LogDebugTrace,All,All)
*/

class FViSoLoggerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
};
