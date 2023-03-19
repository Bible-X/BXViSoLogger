// ©Vi-So Construction

#include "ViSoLoggerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Save/ViSoLogSave.h"

DEFINE_LOG_CATEGORY(ViSoLog)

void UViSoLoggerSubsystem::K2_VSLog(UObject* Instigator, FString Message, FString WhatToDo)
{
	GET_LOGGERSUBSYSTEM();
	
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Message);
	
	FViSoLogData LogData = FViSoLogData(Instigator, Message, WhatToDo);
	FViSoLogNavTarget NavData = FViSoLogNavTarget();
	LoggerSubSystem->CurrentEditorSession.SessionLogs.Add(FViSoStoredLogData(LogData, NavData, false));
	LoggerSubSystem->UpdateViSoLogUI.Broadcast();
}

void UViSoLoggerSubsystem::VSLog(FViSoLogData LogData, FString ClassName, FString Line)
{
	GET_LOGGERSUBSYSTEM();
	
	const FString Log = ClassName + "[" + Line + "]: " + LogData.Message + LogData.WhatToDo;
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Log);

	FViSoLogNavTarget NavData = FViSoLogNavTarget();
	LoggerSubSystem->CurrentEditorSession.SessionLogs.Add(FViSoStoredLogData(LogData, NavData, true));
	LoggerSubSystem->UpdateViSoLogUI.Broadcast();
}


void UViSoLoggerSubsystem::VSLogWithNav(FViSoLogData LogData, FViSoLogNavTarget NavData, FString ClassName, FString Line)
{
	GET_LOGGERSUBSYSTEM();
	
	const FString Log = ClassName + "[" + Line + "]: " + LogData.Message + LogData.WhatToDo;
	UE_LOG(ViSoLog, Error, TEXT("%s"), *Log);

	LoggerSubSystem->CurrentEditorSession.SessionLogs.Add(FViSoStoredLogData(LogData, NavData, true));
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
