// ©Vi-So Construction

#include "ViSoLoggerEditor.h"
#include "LevelEditor.h"
#include "Widgets/SViSoLogToolBar.h"

#define LOCTEXT_NAMESPACE "FViSoLoggerEditorModule"

void FViSoLoggerEditorModule::StartupModule()
{
	if (FLevelEditorModule* LevelEditorModule = FModuleManager::GetModulePtr<FLevelEditorModule>(TEXT("LevelEditor")))
	{
		const TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddToolBarExtension("Play", EExtensionHook::After,
			nullptr, FToolBarExtensionDelegate::CreateRaw(this, &FViSoLoggerEditorModule::CreateViSoLogToolbar));
		LevelEditorModule->GetToolBarExtensibilityManager()->AddExtender(MenuExtender);
	}
}

void FViSoLoggerEditorModule::ShutdownModule()
{

}

void FViSoLoggerEditorModule::CreateViSoLogToolbar(FToolBarBuilder& ToolbarBuilder) const
{
	ToolbarBuilder.BeginSection("ViSoLogToolBar");
	{
		ToolbarBuilder.AddWidget(SNew(SViSoLogToolBar));
	}
	ToolbarBuilder.EndSection();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FViSoLoggerEditorModule, ViSoLoggerEditor)