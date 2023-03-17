// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ViSoLoggerEditorWidget.h"
//#include "ViSoLogger/Public/ViSoLoggerSubsystem.h"

void UViSoLoggerEditorWidget::UpdateContent()
{
	
}

void UViSoLoggerEditorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OnPIEPostStartedHandle = FEditorDelegates::PostPIEStarted.AddUObject(this, &UViSoLoggerEditorWidget::HandlePostPIEStarted);
	OnPIEPreEndedHandle = FEditorDelegates::PrePIEEnded.AddUObject(this, &UViSoLoggerEditorWidget::HandlePrePIEEnded);
	
	if(GEngine)
	{
		//LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();
		//LoggerSubSystem->UpdateDebuggerUI.AddDynamic(this,UViSoLoggerEditorWidget::UpdateContent);
	}
}

void UViSoLoggerEditorWidget::NativeDestruct()
{
	Super::NativeDestruct();
	
	FEditorDelegates::PostPIEStarted.Remove(OnPIEPostStartedHandle);
	FEditorDelegates::PrePIEEnded.Remove(OnPIEPreEndedHandle);
}

void UViSoLoggerEditorWidget::HandlePostPIEStarted(bool bIsSimulating) const
{
	
}

void UViSoLoggerEditorWidget::HandlePrePIEEnded(bool bIsSimulating) const
{
	
}