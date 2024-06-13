// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GP3_NT8 : ModuleRules
{
	public GP3_NT8(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"ApplicationCore",
				"EngineSettings",
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore", 
				"EnhancedInput",
				"UMG",
				"Slate",
				"SlateCore"
			});
		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
