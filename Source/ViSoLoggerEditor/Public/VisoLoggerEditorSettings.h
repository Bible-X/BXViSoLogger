// ©Vi-So Construction

#pragma once

#include "Engine/DeveloperSettings.h"
#include "VisoLoggerEditorSettings.generated.h"

class UEditorUtilityWidgetBlueprint;

UCLASS(Config = Editor, defaultconfig, meta = (DisplayName = "ViSoLogger"))
class VISOLOGGEREDITOR_API UVisoLoggerEditorSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()
	
	static UVisoLoggerEditorSettings* Get() { return CastChecked<UVisoLoggerEditorSettings>(UVisoLoggerEditorSettings::StaticClass()->GetDefaultObject()); }

	UPROPERTY(EditDefaultsOnly, config, Category = "UI")
	TSoftObjectPtr<UEditorUtilityWidgetBlueprint> ViSoLoggerWidget;
};
