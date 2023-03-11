// ©Vi-So Construction

#pragma once
#include "GameplayTagContainer.h"
#include "ViSoLoggerTypes.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FViSoLogData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UObject> Instigator = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector InstigatorWorldLocation = FVector();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> LogTimes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> WhatToDo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Log;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Categories = "ViSoLog.Category"))
	FGameplayTagContainer Category;
	
	FViSoLogData()
	{
		
	}
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