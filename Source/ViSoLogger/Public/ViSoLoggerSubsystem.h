// ©Vi-So Construction

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "ViSoLoggerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class VISOLOGGER_API UViSoLoggerSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;
};
