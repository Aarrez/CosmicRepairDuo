// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GP3_NT8 : ModuleRules
{
	public GP3_NT8(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
			{ 
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
