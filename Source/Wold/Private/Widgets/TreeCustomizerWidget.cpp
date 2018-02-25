// Fill out your copyright notice in the Description page of Project Settings.

#include "TreeCustomizerWidget.h"

void UTreeCustomizerWidget::PopulateAvailableLeafAndBarkMaterials()
{
	// use FObjectFinder to find all material with bark and leaf in their names
	// hacky way to do this is to just compile the code with a constant array of the names of all the materials you want
	// or you could create an array in the blueprint and compile the listing into the blueprint
}
