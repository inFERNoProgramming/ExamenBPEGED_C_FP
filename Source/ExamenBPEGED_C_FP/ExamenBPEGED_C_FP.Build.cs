// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExamenBPEGED_C_FP : ModuleRules
{
	public ExamenBPEGED_C_FP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
