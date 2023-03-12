// ©Vi-So Construction

#include "ViSoLoggerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Save/ViSoLogSave.h"

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

	static FString SaveGameName = "ViSoLogSave";

	if (UGameplayStatics::DoesSaveGameExist(SaveGameName, 0))
	{
		ViSoLogSave = Cast<UViSoLogSave>(UGameplayStatics::LoadGameFromSlot(SaveGameName, 0));
	}
	else
	{
		ViSoLogSave = Cast<UViSoLogSave>(UGameplayStatics::CreateSaveGameObject(UViSoLogSave::StaticClass()));
		UGameplayStatics::SaveGameToSlot(ViSoLogSave, SaveGameName, 0);
	}
}