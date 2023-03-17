// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "ViSoLoggerEditorWidget.generated.h"

class UScrollBox;
class UViSoLoggerSubsystem;

UCLASS()
class VISOLOGGEREDITOR_API UViSoLoggerEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UScrollBox* MainContentBox;

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
