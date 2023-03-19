// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

struct FAssetData;
class UViSoLoggerSubsystem;

class VISOLOGGEREDITOR_API SViSoLogToolBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SViSoLogToolBar) {}
	SLATE_END_ARGS()

	UFUNCTION()
	void CreateToolBarWidget();

	void Construct(const FArguments& InArgs);

private:
	TObjectPtr<UViSoLoggerSubsystem> LoggerSubSystem;
	TSharedPtr<SHorizontalBox> Content;
	TSharedPtr<SButton> Button;

	void ComposeLogInfoBox();
	FReply OnButtonPress();
};