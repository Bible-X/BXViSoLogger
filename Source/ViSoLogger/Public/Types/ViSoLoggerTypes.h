// ©Vi-So Construction

#pragma once
#include "GameplayTagContainer.h"
#include "ViSoLoggerTypes.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FViSoLogNavTarget
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<UObject> NavigationAsset;
	
	UPROPERTY(BlueprintReadOnly)
	TSoftClassPtr<UObject> NavigationTargetClass;

	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<AActor> NavigationActor;
	
	UPROPERTY(BlueprintReadOnly)
	FVector InstigatorWorldLocation = {0,0,0};

	FViSoLogNavTarget(const UClass* InNavigationTargetClass)
	{
		NavigationTargetClass = InNavigationTargetClass;
	}

	FViSoLogNavTarget(TSoftObjectPtr<UObject> InNavigationAsset)
	{
		NavigationAsset = InNavigationAsset;
	}

	FViSoLogNavTarget(const AActor* InNavigationActor)
	{
		if (!InNavigationActor) {return;}
		NavigationActor = InNavigationActor;
		InstigatorWorldLocation = InNavigationActor->GetActorLocation();
	}
	
	FViSoLogNavTarget() {}
};

USTRUCT(BlueprintType)
struct FViSoLogData
{
	GENERATED_BODY()

	TSoftObjectPtr<UObject> Instigator;
	FString Message;
	FString WhatToDo;
	
	FViSoLogData(TSoftObjectPtr<UObject> InInstigator, FString InMessage, FString InWhatToDo)
	{
		Instigator = InInstigator;
		Message = InMessage;
		WhatToDo = InWhatToDo;
	}
	
	FViSoLogData(TSoftObjectPtr<UObject> InInstigator, FString InMessage)
	{
		Instigator = InInstigator;
		Message = InMessage;
	}

	FViSoLogData() {}
};

USTRUCT(BlueprintType)
struct FViSoStoredLogData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<UObject> Instigator;
	
	UPROPERTY(BlueprintReadOnly)
	FString Message;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> WhatToDo;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> LogTimes;
	
	UPROPERTY(BlueprintReadOnly)
	FViSoLogNavTarget NavigationData;
	
	UPROPERTY(BlueprintReadOnly, meta = (Categories = "ViSoLog.Tags"))
	FGameplayTagContainer Tags;
	
	UPROPERTY(BlueprintReadOnly)
	bool IsNative = false;
	
	FViSoStoredLogData(FViSoLogData& LogData, FViSoLogNavTarget& NavData, bool InIsNative)
	{
		Message = LogData.Message;
		WhatToDo.Add(LogData.WhatToDo);
		NavigationData = NavData;
		IsNative = InIsNative;
	}

	FViSoStoredLogData()
	{
		
	}
};

USTRUCT(BlueprintType)
struct FViSoLogSessionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FViSoStoredLogData> SessionLogs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SessionDateAndTime;
};