// ©Vi-So Construction

#pragma once
#include "GameplayTagContainer.h"
#include "ViSoLoggerTypes.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FViSoLogNavigationData
{
	GENERATED_BODY()
	
	TSoftObjectPtr<UObject> Instigator;
	TSoftClassPtr<UObject> InstigatorClass;

	FViSoLogNavigationData(const UObject* InInstigator)
	{
		Instigator = InInstigator;
		if (IsValid(InInstigator))
		{
			InstigatorClass = Instigator->GetClass();
		}
	}

	FViSoLogNavigationData()
	{
		
	}
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FViSoLogData
{
	GENERATED_BODY()
	
	FString Message;
	FString WhatToDo;
	
	FViSoLogData(FString InMessage, FString InWhatToDo)
	{
		Message = InMessage;
		WhatToDo = InWhatToDo;
	}
	
	FViSoLogData(FString InMessage)
	{
		Message = InMessage;
	}
	
	FViSoLogData()
	{
	
	}
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FViSoStoredLogData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString Message;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> WhatToDo;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> LogTimes;
	
	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<UObject> Instigator = nullptr;

	UPROPERTY(BlueprintReadOnly)
	TSoftClassPtr<UObject> InstigatorClass = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (Categories = "ViSoLog.Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(BlueprintReadOnly)
	FVector InstigatorWorldLocation = {0,0,0};
};

/**
 * Struct that holds all log info of a session
 */
USTRUCT(BlueprintType)
struct FViSoLogSessionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FViSoLogData> SessionLogs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SessionDateAndTime;
};