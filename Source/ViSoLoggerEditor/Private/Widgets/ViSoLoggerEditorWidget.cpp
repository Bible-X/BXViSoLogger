// ©Vi-So Construction

#include "Widgets/ViSoLoggerEditorWidget.h"

#include "Components/ScrollBox.h"
#include "Components/ScrollBoxSlot.h"
#include "ViSoLogger/Public/ViSoLoggerSubsystem.h"
#include "Widgets/LogLineWidget.h"

//TODO: Function can be in a function library? to reuse for the runtime UI widget
void UViSoLoggerEditorWidget::UpdateContent()
{
	if (!LoggerSubSystem) {return;}
	if (!MainContentBox) {return;}
	if (!LogWidgetClass) {return;}
	
	MainContentBox->ClearChildren();
	
	for (const auto& Log : LoggerSubSystem->CurrentEditorSession.SessionLogs)
	{
		if (ULogLineWidget* LogWidget = Cast<ULogLineWidget>(CreateWidget(this, LogWidgetClass)))
		{
			LogWidget->LogData = Log;
			MainContentBox->AddChild(LogWidget);
			LogWidget->InitializeWidget();
		}
	}
	
	MainContentBox->ScrollToEnd();
}

void UViSoLoggerEditorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OnPIEPostStartedHandle = FEditorDelegates::PostPIEStarted.AddUObject(this, &UViSoLoggerEditorWidget::HandlePostPIEStarted);
	OnPIEPreEndedHandle = FEditorDelegates::PrePIEEnded.AddUObject(this, &UViSoLoggerEditorWidget::HandlePrePIEEnded);
	
	if(GEngine)
	{
		LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();
		LoggerSubSystem->UpdateViSoLogUI.AddDynamic(this, &UViSoLoggerEditorWidget::UpdateContent);
		UpdateContent();
	}
}

void UViSoLoggerEditorWidget::NativeDestruct()
{
	FEditorDelegates::PostPIEStarted.Remove(OnPIEPostStartedHandle);
	FEditorDelegates::PrePIEEnded.Remove(OnPIEPreEndedHandle);

	Super::NativeDestruct();
}

void UViSoLoggerEditorWidget::HandlePostPIEStarted(bool bIsSimulating) const
{
	
}

void UViSoLoggerEditorWidget::HandlePrePIEEnded(bool bIsSimulating) const
{
	
}