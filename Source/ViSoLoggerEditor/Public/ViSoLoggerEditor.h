// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UViSoLoggerSubsystem;

class FViSoLoggerEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void CreateViSoLogToolbar(FToolBarBuilder& ToolbarBuilder) const;
};