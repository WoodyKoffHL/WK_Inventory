// Woodykoff Inventory for Unreal Engine
// Special for github


#include "InventoryComponent.h"
#include "Item.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	GenerateSlots();
}


void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInventoryComponent::GenerateSlots()
{
	TArray<FInvSlot> InboundSlots = InventorySlots;
	InventorySlots.Empty();

	for (int32 Index = 0; Index <= AmountOfSlots; ++Index) {
		if (InboundSlots.IsValidIndex(Index)) {
			InventorySlots.Add(InboundSlots[Index]);
		}
		else {
			FInvSlot InboundSlot;
			InboundSlot.Amount = 0;
			InboundSlot.Item = nullptr;
			InventorySlots.Add(InboundSlot);
		}
	}
}
