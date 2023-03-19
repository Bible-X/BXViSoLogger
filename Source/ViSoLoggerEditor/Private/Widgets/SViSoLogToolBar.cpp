// ©Vi-So Construction

#include "Widgets/SViSoLogToolBar.h"
#include "EditorAssetLibrary.h"
#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "VisoLoggerEditorSettings.h"
#include "ViSoLoggerSubsystem.h"

#define LOCTEXT_NAMESPACE "SLevelEditorFlow"

void SViSoLogToolBar::CreateToolBarWidget()
{
	if (!LoggerSubSystem) {return;}

	ComposeLogInfoBox();
	
	ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
					[
						Button.ToSharedRef()
					]
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
					[
						Content.ToSharedRef()
					]
			]
	];
}

void SViSoLogToolBar::Construct(const FArguments& InArgs)
{
	if(GEngine)
	{
		LoggerSubSystem = GEngine->GetEngineSubsystem<UViSoLoggerSubsystem>();
		//LoggerSubSystem->UpdateViSoLogUI.AddDynamic(this, &SViSoLogToolBar::CreateToolBarWidget);
	}
	SAssignNew(Content, SHorizontalBox).Visibility(EVisibility::HitTestInvisible);
	SAssignNew(Button, SButton).OnClicked(FOnClicked::CreateRaw(this, &SViSoLogToolBar::OnButtonPress));
	
	CreateToolBarWidget();
}

void SViSoLogToolBar::ComposeLogInfoBox()
{
	Content->ClearChildren();
	
	Content->AddSlot()
	[
		SNew(STextBlock)
		.Text(FText::FromString("10"))
		.ColorAndOpacity(FColor::Red)
		.Margin(5)
	];

	Content->AddSlot()
	[
		SNew(STextBlock)
		.Text(FText::FromString("5"))
		.ColorAndOpacity(FColor::Yellow)
		.Margin(5)
	];
}

FReply SViSoLogToolBar::OnButtonPress()
{
	if (!UVisoLoggerEditorSettings::Get()->ViSoLoggerWidget.IsNull())
	{
		if(UObject* Blueprint = UEditorAssetLibrary::LoadAsset(
		UVisoLoggerEditorSettings::Get()->ViSoLoggerWidget.ToSoftObjectPath().ToString()))
		{
			if(UEditorUtilityWidgetBlueprint* EditorWidgetBP = Cast<UEditorUtilityWidgetBlueprint>(Blueprint))
			{
				UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
				EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidgetBP);
			}
		}
	}
	
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
