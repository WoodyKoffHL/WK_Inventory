// Woodykoff Inventory for Unreal Engine
// Special for github

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AItem;

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
struct FRowColumn {
	// Slot inventory
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Slots in Row")
		int32 SlotsPerRow = 4;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Slots in Column")
		int32 SlotsInColumn = 4;
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

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Amount of slots")
		int32 AmountOfSlots = 16;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", DisplayName = "Slots in Row / Column")
		FRowColumn SlotsRowAndColumn;

	UFUNCTION(BlueprintCallable)
		void GenerateSlots();

	UFUNCTION(BlueprintCallable)
		int32 SearhEmptySlot();

	UFUNCTION(BlueprintCallable)
		int32 SearhStackSlot();

	UFUNCTION(BlueprintCallable)
		void AddItem(int32 Index);

private:


};
