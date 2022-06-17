// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <CesiumRuntime/Public/CesiumIonRasterOverlay.h>
#include <CesiumRuntime/Public/CesiumTileMapServiceRasterOverlay.h>
#include "Custom_BPFL.generated.h"

/**
 * 
 */
UCLASS()
class GRILLDISEXAMPLE_API UCustom_BPFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/** Get Custom Config Var! These are stored in Saved/Config/Windows/Game.ini */
	UFUNCTION(BlueprintPure)
	static FString GetCustomConfigVar_String(FString SectionName, FString VariableName, bool& IsValid);

	UFUNCTION(BlueprintCallable)
	static void SetTmsUrl(UCesiumTileMapServiceRasterOverlay* TmsServer, FString NewUrl);

	UFUNCTION(BlueprintCallable)
	static void SetRasterOverlayData(UCesiumIonRasterOverlay* IonRasterOverlay, FString NewIonAccessToken, int NewIonAssetId);

};
