// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ViSoLoggerEditorWidget.h"

void UViSoLoggerEditorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OnPIEPostStartedHandle = FEditorDelegates::PostPIEStarted.AddUObject(this, &UViSoLoggerEditorWidget::HandlePostPIEStarted);
	OnPIEPreEndedHandle = FEditorDelegates::PrePIEEnded.AddUObject(this, &UViSoLoggerEditorWidget::HandlePrePIEEnded);
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