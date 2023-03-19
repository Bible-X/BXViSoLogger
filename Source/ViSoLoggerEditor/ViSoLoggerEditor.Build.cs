// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ViSoLoggerEditor : ModuleRules
{
	public ViSoLoggerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"ViSoLogger"
				// ... add other public dependencies that you statically link with here ...
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"GameplayTags",
				"UnrealEd",
				"EditorSubsystem",
				"Blutility",
				"UMG",
				"UMGEditor",
				"DeveloperSettings", 
				"EditorScriptingUtilities"
			}
			);
	}
}
