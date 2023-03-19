// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "ViSoLoggerEditorWidget.generated.h"

class UScrollBox;
class UViSoLoggerSubsystem;
class ULogLineWidget;

UCLASS()
class VISOLOGGEREDITOR_API UViSoLoggerEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UScrollBox* MainContentBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ULogLineWidget> LogWidgetClass;

	UFUNCTION()
	void UpdateContent();
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	TObjectPtr<UViSoLoggerSubsystem> LoggerSubSystem;
	
	FDelegateHandle OnPIEPostStartedHandle;
	FDelegateHandle OnPIEPreEndedHandle;
	
	void HandlePostPIEStarted(bool bIsSimulating) const;
	void HandlePrePIEEnded(bool bIsSimulating) const;
};
