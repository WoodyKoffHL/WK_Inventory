// Woodykoff Inventory for Unreal Engine
// Special for github

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inventory_Interact.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventory_Interact : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_WPLUGIN_API IInventory_Interact
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void OnInteract(AActor* CallActor);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void StartFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void EndFocus();
};
