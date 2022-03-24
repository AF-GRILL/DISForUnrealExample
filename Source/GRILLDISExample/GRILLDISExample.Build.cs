// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class GRILLDISExample : ModuleRules
{
	public GRILLDISExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GeoReferencing"});

		// Add Cesium for Unreal plugin dependency path
		PrivateDependencyModuleNames.AddRange(new string[] { "CesiumRuntime", "GeometricObjects" });

		// Tell Unreal Engine to use C++17
		CppStandard = CppStandardVersion.Cpp17;

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
