// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Types/ViSoLoggerTypes.h"
#include "ViSoLoggerSubsystem.generated.h"

/**
 * Declares an gets the logger subsystem as ptr
 * Intended for static functions inside the logger subsystem
 */
#define GET_LOGGERSUBSYSTEM() static UViSoLoggerSubsystem* LoggerSubSystem; \
if (!LoggerSubSystem) \
{\
	if(!GEngine) {return;}\
	LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();\
	if (!LoggerSubSystem) {return;}\
}\

#define GET_CLASSNAME_WITH_FUNCTION                FString(__FUNCTION__)
#define GET_LINE_NUMBER                            FString::FromInt(__LINE__)

/**
 * Basic VISO log with minimal needed information
 * @param FViSoLogData - Minimal log data
 */
#define VISO_LOG(FViSoLogData) UViSoLoggerSubsystem::VSLog(FViSoLogData, GET_CLASSNAME_WITH_FUNCTION, GET_LINE_NUMBER)

/**
 * Extended VISO log which enables you to to navigate to a preferred location within the editor or C++ code
 * @param FViSoLogData - Minimal log data declared as
 * @param FViSoLogNavTarget - Can be of type, AActor, UClass or UObject.
 */
#define VISO_LOG_WITH_NAV(FViSoLogData, FViSoLogNavTarget) UViSoLoggerSubsystem::VSLogWithNav(FViSoLogData, FViSoLogNavTarget, GET_CLASSNAME_WITH_FUNCTION, GET_LINE_NUMBER)

DECLARE_LOG_CATEGORY_EXTERN(ViSoLog, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateViSoLogUI);

class UViSoLogSave;

UCLASS()
class VISOLOGGER_API UViSoLoggerSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UViSoLogSave> ViSoLogSave;

	UPROPERTY(BlueprintAssignable)
	FUpdateViSoLogUI UpdateViSoLogUI;

	UPROPERTY(BlueprintReadOnly)
	FViSoLogSessionData CurrentEditorSession;
	
	UPROPERTY(BlueprintReadOnly)
	FViSoLogSessionData CurrentRuntimeSession;
	
	UFUNCTION(BlueprintCallable, DisplayName = "Print ViSo Log", meta = (DefaultToSelf = Instigator))
	static void K2_VSLog(EVSL_Verbosity Category, UObject* Instigator, FString Message, FString WhatToDo);

	static void VSLog(FViSoLogData LogData, FString ClassName, FString Line);

	static void VSLogWithNav(FViSoLogData LogData, FViSoLogNavTarget NavData, FString ClassName, FString Line);

private:
	FString SaveGameName = "ViSoLogSave";

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;
};
