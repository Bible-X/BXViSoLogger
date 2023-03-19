// ©Vi-So Construction

#include "ViSoLoggerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Save/ViSoLogSave.h"

DEFINE_LOG_CATEGORY(ViSoLog)

void UViSoLoggerSubsystem::K2_VSLog(FString Message, FString WhatToDo)
{
	static UViSoLoggerSubsystem* LoggerSubSystem;
	if (!LoggerSubSystem)
	{
		if(!GEngine) {return;}
		LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();
		if (!LoggerSubSystem) {return;}
	}
	
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Message);
	
	FViSoLogData LogData = FViSoLogData(Message, WhatToDo);
	FViSoLogNavigationData NavData = FViSoLogNavigationData();
	LoggerSubSystem->CurrentEditorSession.SessionLogs.Insert(FViSoStoredLogData(LogData, NavData, false), 0);
	LoggerSubSystem->UpdateViSoLogUI.Broadcast();
}

void UViSoLoggerSubsystem::VSLog(FViSoLogData LogData, FViSoLogNavigationData NavData, FString ClassName, FString Line)
{
	static UViSoLoggerSubsystem* LoggerSubSystem;
	if (!LoggerSubSystem)
	{
		if(!GEngine) {return;}
		LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();
		if (!LoggerSubSystem) {return;}
	}
	
	const FString Log = ClassName + "[" + Line + "]: " + LogData.Message + LogData.WhatToDo;
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Log);

	LoggerSubSystem->CurrentEditorSession.SessionLogs.Insert(FViSoStoredLogData(LogData, NavData, true), 0);
	LoggerSubSystem->UpdateViSoLogUI.Broadcast();
}

void UViSoLoggerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

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

void UViSoLoggerSubsystem::Deinitialize()
{
	if (ViSoLogSave)
	{
		UGameplayStatics::SaveGameToSlot(ViSoLogSave, SaveGameName, 0);
	}
	
	Super::Deinitialize();
}
