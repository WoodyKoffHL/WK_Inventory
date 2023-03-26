// Woodykoff Inventory for Unreal Engine
// Special for github

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryWidget.h"
#include "InventoryComponent.generated.h"

class AItem;
class APickUpActor;

USTRUCT(BlueprintType)
struct FInvSlot {
	// Slot inventory
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot")
		int32 Amount;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot")
		TSubclassOf<AItem> Item;

	
};

USTRUCT(BlueprintType)
struct FSlotInfo {
	// Slot inventory
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info")
		bool Empty = true;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot info")
		TSubclassOf<AItem> Item;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Slot")
		int32 Amount;


};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_WPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Inventory slots implementation
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Inventory slots")
		TArray<FInvSlot> InventorySlots;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Owner Actor Name")
		FText OwnerName;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Amount of slots")
		int32 AmountOfSlots = 16;


	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		void GenerateSlots();


	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		bool AddItemForIndex(TSubclassOf<AItem> Item, int32 Amount, int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		bool AddItem(APickUpActor* ItemActor);

	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		bool AddToStack(TSubclassOf<AItem> Item, int32 AmountToStack);

	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		void UseItemAtIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		void ThrowOutFromIndex(int32 Index, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory Plugin")
		void SwapSlots(int32 IndexIn, int32 IndexOut);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory Plugin")
		FSlotInfo GetSlotInfo(int32 Index);

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "User Interface")
		UInventoryWidget* InventoryWidget;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "User Interface", DisplayName = "Slots in Row")
		int32 SlotsinRow = 4;

private:


};
