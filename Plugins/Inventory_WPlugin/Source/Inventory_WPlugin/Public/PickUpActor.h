// Woodykoff Inventory for Unreal Engine
// Special for github

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Inventory_Interact.h"
#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"

class AItem;
class UStaticMeshComponent;
class USkeletalMeshComponent;

UCLASS()
class INVENTORY_WPLUGIN_API APickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item")
		int32 Amount;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item")
		TSubclassOf<AItem> Item;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (EditCondition = "!ItemStruct.Skeletal", EditConditionHides))
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (EditCondition = "ItemStruct.Skeletal", EditConditionHides))
		USkeletalMeshComponent* SkeletalMesh;





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void SetActorDefaults();

};
