// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Types/ViSoLoggerTypes.h"
#include "LogLineWidget.generated.h"

/**
 * 
 */
UCLASS()
class VISOLOGGEREDITOR_API ULogLineWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FViSoStoredLogData LogData;

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeWidget();
};
