// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FViSoLoggerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
