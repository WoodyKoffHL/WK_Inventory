// Woodykoff Inventory for Unreal Engine
// Special for github


#include "InventoryComponent.h"
#include "Item.h"
#include "PickUpActor.h"

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

	for (int32 Index = 0; Index < AmountOfSlots; ++Index) {
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


// Add Item To Index and Destroy PickUp Actor
bool UInventoryComponent::AddItemForIndex(TSubclassOf<AItem> Item, int32 Amount, int32 Index)
{
	if (Amount == 0 || !Amount) return false;
		FInvSlot InboundSlot;
		InboundSlot.Item = Item;
		InboundSlot.Amount = Amount;
		InventorySlots[Index] = InboundSlot;
		return true;
}

// Add item for all cases. Works only with PickUpActor
bool UInventoryComponent::AddItem(APickUpActor* ItemActor)
{
	bool debugBool = false;
	if (!ItemActor) return false;
	int32 FoundIndex = -1;
	APickUpActor* LocalActor = ItemActor;
	bool Stackeble = LocalActor->Item.GetDefaultObject()->ItemStruct.Stackeble;
	bool StackFounded = false;
	if (Stackeble) {
	 StackFounded = AddToStack(LocalActor->Item, LocalActor->Amount);
	}


	if(!StackFounded) {
	// Find index for not Stackeble
		for (int32 Index = 0; Index <= AmountOfSlots; ++Index) {
			if (InventorySlots.IsValidIndex(Index)) {
				if (!InventorySlots[Index].Item)
				{
					FoundIndex = Index;
					break;
				}
			}
		}
	}
	else {
		ItemActor->Destroy();
	}
	


	// Index founded or equal -1
	if (FoundIndex < 0) return false;
	if (!InventorySlots[FoundIndex].Item) {
		AddItemForIndex(LocalActor->Item, LocalActor->Amount, FoundIndex);
		ItemActor->Destroy();
		return true;
	}  
	return false;
}

bool UInventoryComponent::AddToStack(TSubclassOf<AItem> Item, int32 AmountToStack)
{
	int32 TotalAmount;
	int32 MaxStack = Item.GetDefaultObject()->ItemStruct.MaxStackSize;
	bool StackFounded;
	for (int32 Index = 0; Index <= AmountOfSlots; ++Index) {
		if (InventorySlots.IsValidIndex(Index)) {
			int32 LocalAmount = InventorySlots[Index].Amount;
			TSubclassOf<AItem> LocalItem = InventorySlots[Index].Item;
			if (LocalItem == Item)
			{
				TotalAmount = LocalAmount + AmountToStack;
				if (TotalAmount > MaxStack) {
					if (Index == (AmountOfSlots - 1)) {
						return false;
						break;
					}
					AddItemForIndex(Item, MaxStack, Index);
					TotalAmount = TotalAmount - MaxStack;
				}
				else {
					AddItemForIndex(Item, TotalAmount, Index);
					StackFounded = true;
					break;
				}

			}
			else StackFounded = false;
		}
	}

	return StackFounded;
}

void UInventoryComponent::UseItemAtIndex(int32 Index)
{
	if (!InventorySlots.IsValidIndex(Index)) return;
	if (!InventorySlots[Index].Item) return;
	if (InventorySlots[Index].Item.GetDefaultObject()->ItemStruct.ItemType != EItemType::Useble) return;
	TSubclassOf<AItem> Item = InventorySlots[Index].Item;
		if (Item.GetDefaultObject()->ItemStruct.Stackeble) {
			if (InventorySlots[Index].Amount > 1) {
				InventorySlots[Index].Amount = InventorySlots[Index].Amount - 1;
			}
			else {
				InventorySlots[Index].Amount = 0;
				InventorySlots[Index].Item = nullptr;
			}

		}
		else {
			InventorySlots[Index].Amount = 0;
			InventorySlots[Index].Item = nullptr;
		}

	AActor* SpawnItem = GetWorld()->SpawnActor(Item);
	AItem* ActorItem = Cast<AItem>(SpawnItem);
	ActorItem->UseItem(GetOwner());
	SpawnItem->Destroy();
}








