// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4AutomationQuickEditor_NoPrecompTarget : UE4AutomationQuickEditorTarget
{
	public UE4AutomationQuickEditor_NoPrecompTarget(TargetInfo Target) : base(Target)
	{
		bUseUnityBuild = false;
		bUsePCHFiles = false;
	}
}
