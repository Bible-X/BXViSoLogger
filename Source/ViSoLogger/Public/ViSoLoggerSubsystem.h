// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Types/ViSoLoggerTypes.h"
#include "ViSoLoggerSubsystem.generated.h"

#define GET_CLASSNAME_WITH_FUNCTION                FString(__FUNCTION__)
#define GET_LINE_NUMBER                            FString::FromInt(__LINE__)
#define VISO_LOG(LogData) UViSoLoggerSubsystem::VSLog(LogData, FViSoLogNavigationData(this), GET_CLASSNAME_WITH_FUNCTION, GET_LINE_NUMBER)

DECLARE_LOG_CATEGORY_EXTERN(ViSoLog, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateDebuggerUI);

class UViSoLogSave;

/**
 * 
 */
UCLASS()
class VISOLOGGER_API UViSoLoggerSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UViSoLogSave> ViSoLogSave;

	UPROPERTY(BlueprintAssignable)
	FUpdateDebuggerUI UpdateDebuggerUI;
	
	UFUNCTION(BlueprintCallable)
	static void K2_VSLog(FString Log);

	static void VSLog(FViSoLogData LogData, FViSoLogNavigationData NavData, FString ClassName, FString Line);
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
