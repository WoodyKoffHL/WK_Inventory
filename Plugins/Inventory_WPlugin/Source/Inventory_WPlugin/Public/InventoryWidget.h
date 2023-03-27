// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class USlotWidget;
class UInventoryComponent;

UCLASS()
class INVENTORY_WPLUGIN_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory Widget")
		UUserWidget* Main_Hud;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true), Category = "Inventory Widget")
		UInventoryComponent* InventoryComponent;



	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory Widget", DisplayName = "Slot Widget Class")
		TSubclassOf<USlotWidget> SlotWidgetClass;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory Widget")
		TArray<USlotWidget*> SlotWidgets;

	UFUNCTION(BlueprintCallable, Category = "Inventory Widget")
		void GenerateSlotWidgets();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Event Update Inventory", Category = "Inventory Widget")
		void UpdateAllSlots();

private:

	int32 GetRow(int32 Index);
	int32 GetColumn(int32 Index);
	
};
