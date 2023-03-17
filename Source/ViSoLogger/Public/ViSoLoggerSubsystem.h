// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Types/ViSoLoggerTypes.h"
#include "ViSoLoggerSubsystem.generated.h"

#define GET_CLASSNAME_WITH_FUNCTION                FString(__FUNCTION__)
#define GET_LINE_NUMBER                            FString::FromInt(__LINE__)

/**
 *	Regular Log
 *  @param Instigator - Instigator that caused the log, will be auto set as navigation target
 *  @param LogData - Information about the log
 */
#define VISO_LOG(Instigator, LogData) UViSoLoggerSubsystem::VSLog(LogData, FViSoLogNavigationData(Instigator), GET_CLASSNAME_WITH_FUNCTION, GET_LINE_NUMBER)

/**
 *	Log that also allows a custom navigation target.
 *	Can be used if the instigator and the navigation target differs
 *  @param Instigator - Instigator that caused the log, will be auto set as navigation target
 *  @param NavigationTarget - 
 *  @param LogData - Information about the log
 */
#define VISO_LOG_WithTarget(Instigator, NavigationTarget, LogData) UViSoLoggerSubsystem::VSLog(LogData, FViSoLogNavigationData(Instigator, NavigationTarget), GET_CLASSNAME_WITH_FUNCTION, GET_LINE_NUMBER)

DECLARE_LOG_CATEGORY_EXTERN(ViSoLog, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateDebuggerUI);

class UViSoLogSave;

UCLASS()
class VISOLOGGER_API UViSoLoggerSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UViSoLogSave> ViSoLogSave;

	UPROPERTY(BlueprintAssignable)
	FUpdateDebuggerUI UpdateDebuggerUI;

	UPROPERTY(BlueprintReadOnly)
	FViSoLogSessionData CurrentEditorSession;
	
	UPROPERTY(BlueprintReadOnly)
	FViSoLogSessionData CurrentRuntimeSession;
	
	UFUNCTION(BlueprintCallable, DisplayName = "Print ViSo Log")
	static void K2_VSLog(FString Message, FString WhatToDo);

	static void VSLog(FViSoLogData LogData, FViSoLogNavigationData NavData, FString ClassName, FString Line);
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;

private:
	FString SaveGameName = "ViSoLogSave";
};
