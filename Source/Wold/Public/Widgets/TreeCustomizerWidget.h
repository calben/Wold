// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TreeCustomizerWidget.generated.h"

/**
 *
 */
UCLASS()
class WOLD_API UTreeCustomizerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomization")
		class AActor* DisplayedTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomization")
		FTransform DisplayedTreeSpawnTransform;

	// CURRENT OPTIONS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		int CurrentRandomSeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		float TrunkIrregularity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		FLinearColor LeafColorModifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		FLinearColor BarkColorModifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		class UMaterialInterface* LeafMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationCurrentValues")
		class UMaterialInterface* BarkMaterial;

	// OPTION LISTS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationOptions")
		TArray<class UMaterialInterface*> AvailableLeafMaterials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeCustomizationOptions")
		TArray<class UMaterialInterface*> AvailableBarkMaterials;

	// FUNCTIONS 

	UFUNCTION(BlueprintCallable)
		void PopulateAvailableLeafAndBarkMaterials();

};
