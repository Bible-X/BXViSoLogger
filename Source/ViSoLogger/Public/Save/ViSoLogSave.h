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

	TArray<FViSoLogSessionData> RuntimeSessionsData;
	TArray<FViSoLogSessionData> EditorSessionsData;
};
