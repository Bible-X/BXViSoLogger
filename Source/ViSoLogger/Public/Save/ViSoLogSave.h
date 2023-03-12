// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ViSoLogSave.generated.h"

/**
 * 
 */
UCLASS()
class VISOLOGGER_API UViSoLogSave : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<FViSoLogSessionData> RuntimeSessionsData;

	UPROPERTY(BlueprintReadOnly)
	TArray<FViSoLogSessionData> EditorSessionsData;
};
