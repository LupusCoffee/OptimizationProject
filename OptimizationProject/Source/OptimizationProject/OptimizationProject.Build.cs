// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OptimizationProject : ModuleRules
{
	public OptimizationProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GeometryCollectionEngine",
			"FieldSystemEngine"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"OptimizationProject",
			"OptimizationProject/Variant_Horror",
			"OptimizationProject/Variant_Horror/UI",
			"OptimizationProject/Variant_Shooter",
			"OptimizationProject/Variant_Shooter/AI",
			"OptimizationProject/Variant_Shooter/UI",
			"OptimizationProject/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
