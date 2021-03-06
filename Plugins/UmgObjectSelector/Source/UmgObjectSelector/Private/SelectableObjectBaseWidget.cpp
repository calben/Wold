// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableObjectBaseWidget.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "ObjectSelectorBaseWidget.h"

//TSharedRef<SWidget> USelectableObjectBaseWidget::RebuildWidget()
//{
//	Super::RebuildWidget();
//	auto RootWidget = Cast<UPanelWidget>(GetRootWidget());
//	WidgetPanel = WidgetTree->ConstructWidget<UPanelWidget>(UPanelWidget::StaticClass(), TEXT("WidgetPanel"));
//	if (RootWidget == nullptr)
//	{
//		WidgetTree->RootWidget = WidgetPanel;
//	}
//	return Super::RebuildWidget();
//}

void USelectableObjectBaseWidget::OnSelectThisObject()
{
	if (ObjectSelectorWidget != nullptr)
	{
		ObjectSelectorWidget->CurrentSelectedObject = ContainedObject;
		ObjectSelectorWidget->OnObjectSelectionChanged(ContainedObject);
		//ObjectSelectorWidget->OnObjectSelectionChanged.Broadcast();
	}
}
