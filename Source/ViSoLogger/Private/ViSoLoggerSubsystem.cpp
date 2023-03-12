// ©Vi-So Construction

#include "ViSoLoggerSubsystem.h"

DEFINE_LOG_CATEGORY(ViSoLog)

void UViSoLoggerSubsystem::K2_VSLog(FString Log)
{
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Log);
}

void UViSoLoggerSubsystem::VSLog(FViSoLogData LogData, FViSoLogNavigationData NavData, FString ClassName, FString Line)
{
	const FString Log = ClassName + "[" + Line + "]: " + LogData.Message + LogData.WhatToDo;
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Log);
}

void UViSoLoggerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	VISO_LOG(FViSoLogData("ViSoLoggerSubSystem is initialized"));
}
