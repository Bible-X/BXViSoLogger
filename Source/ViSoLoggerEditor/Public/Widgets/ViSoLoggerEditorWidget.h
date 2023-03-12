// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "ViSoLoggerEditorWidget.generated.h"

/**
 * 
 */
UCLASS()
class VISOLOGGEREDITOR_API UViSoLoggerEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	FDelegateHandle OnPIEPostStartedHandle;
	FDelegateHandle OnPIEPreEndedHandle;
	
	void HandlePostPIEStarted(bool bIsSimulating) const;
	void HandlePrePIEEnded(bool bIsSimulating) const;
};
