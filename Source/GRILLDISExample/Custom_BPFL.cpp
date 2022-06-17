// Fill out your copyright notice in the Description page of Project Settings.


#include "Custom_BPFL.h"

FString UCustom_BPFL::GetCustomConfigVar_String(FString SectionName, FString VariableName, bool& IsValid)
{
	//Taken from Rama's Victory Plugin
	if (!GConfig) return "";
	//~~~~~~~~~~~

	FString Value;
	IsValid = GConfig->GetString(
		*SectionName,
		*VariableName,
		Value,
		GGameIni
	);
	return Value;
}