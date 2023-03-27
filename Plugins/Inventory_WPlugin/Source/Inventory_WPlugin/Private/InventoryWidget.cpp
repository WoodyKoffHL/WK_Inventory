// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "SlotWidget.h"
#include "InventoryComponent.h"



void UInventoryWidget::GenerateSlotWidgets()
{
	if (!InventoryComponent) return;
	SlotWidgets.Empty();
	for (int32 Index = 0; Index < InventoryComponent->InventorySlots.Num(); Index++) {
		if (!SlotWidgetClass) return;
		USlotWidget* NewSlot = CreateWidget< USlotWidget>(this, SlotWidgetClass);
		FInvSlot SlotInfo = InventoryComponent->InventorySlots[Index];
		NewSlot->SlotIndex = Index;
		NewSlot->SlotItem = SlotInfo.Item;
		NewSlot->SlotAmount = SlotInfo.Amount;
		NewSlot->InventoryWidget = this;
		NewSlot->InventoryComponent = InventoryComponent;
		NewSlot->RowAndColumn.SlotRow = GetRow(Index);
		NewSlot->RowAndColumn.SlotColumn = GetColumn(Index);
		SlotWidgets.Add(NewSlot);
		NewSlot->EventUpdate_Implementation();
	}
}

void UInventoryWidget::UpdateAllSlots_Implementation()
{
	GenerateSlotWidgets();
	UpdateAllSlots();
}

int32 UInventoryWidget::GetRow(int32 Index)
{
	return int32(float(Index) / float(InventoryComponent->SlotsinRow));
}

int32 UInventoryWidget::GetColumn(int32 Index)
{
	return Index % InventoryComponent->SlotsinRow;
}
