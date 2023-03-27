// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlotWidget.generated.h"

class AItem;
class UInventoryWidget;
class UInventoryComponent;

USTRUCT(BlueprintType)
struct FRowAndColumn {
	// For Uniform Grid Panel
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info", DisplayName = "Slot Row")
		int32 SlotRow;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info", DisplayName = "Slot Column")
		int32 SlotColumn;
};

UCLASS()
class INVENTORY_WPLUGIN_API USlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info", DisplayName = "Row and column for uniform grid panel")
		FRowAndColumn RowAndColumn;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info", DisplayName = "Slot Item")
		TSubclassOf<AItem> SlotItem;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info", DisplayName = "Slot Amount")
		int32 SlotAmount;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true), Category = "Slot info", DisplayName = "Slot Index")
		int32 SlotIndex;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true), Category = "Slot info", DisplayName = "Widget Inventory")
		UInventoryWidget* InventoryWidget;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true), Category = "Slot info", DisplayName = "Inventory Component")
		UInventoryComponent* InventoryComponent;

	// Functions and procedures
	
	UFUNCTION(BlueprintNativeEvent, Category = "Inventory Component", DisplayName = "Event Update Slot Widget")
		void EventUpdate();



};
