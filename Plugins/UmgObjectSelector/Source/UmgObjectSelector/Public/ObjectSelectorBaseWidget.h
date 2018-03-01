// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "ObjectSelectorBaseWidget.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnObjectSelectionChanged);

/**
 *
 */
UCLASS()
class UMGOBJECTSELECTOR_API UObjectSelectorBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UObject* CurrentSelectedObject;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
		class UPanelWidget* BasePanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TSubclassOf<USelectableObjectBaseWidget> SelectableObjectBaseWidgetClass;

	UFUNCTION(BlueprintImplementableEvent)
		void OnObjectSelectionChanged(UObject* SelectedObject);

	//FOnObjectSelectionChanged OnObjectSelectionChanged;

};
