// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RamaUDPBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WOLD_API URamaUDPBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};

USTRUCT(BlueprintType)
struct FAnyCustomData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tree Creator")
		FString Name = "Tree!";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tree Creator")
		int32 Seed = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tree Creator")
		float Irregularity = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tree Creator")
		FLinearColor LeafColor = FLinearColor::Green;


	FAnyCustomData()
	{}
};

FORCEINLINE FArchive& operator<<(FArchive &Ar, FAnyCustomData& TheStruct)
{
	Ar << TheStruct.Name;
	Ar << TheStruct.Seed;
	Ar << TheStruct.Irregularity;
	Ar << TheStruct.LeafColor;

	return Ar;
}