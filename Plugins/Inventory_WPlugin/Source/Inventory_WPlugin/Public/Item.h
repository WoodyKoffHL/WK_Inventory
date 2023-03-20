// Woodykoff Inventory for Unreal Engine
// Special for github

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8 {Item, Equip, Useble, Eatible, Currency, Other};

// Struct of Characteristics
USTRUCT(BlueprintType)
struct FItemStruct {

	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info")
		FString Name;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info")
		FText Description;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info", DisplayName = "Item Type")
		EItemType ItemType = EItemType::Other;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info")
		bool Skeletal = false;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info", DisplayName = "Item Image")
		UTexture2D* ItemIcon;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info")
		bool Stackeble = false;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Info", DisplayName = "Max Stack Size", meta = (EditCondition = "Stackeble", EditConditionHides))
		int32 MaxStackSize = 1;


	// Components
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components", DisplayName ="Mesh (Skeletal)" , meta = (EditCondition = "Skeletal", EditConditionHides))
		USkeletalMesh* SkeletalMesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components", DisplayName ="Mesh (Static)", meta = (EditCondition = "!Skeletal", EditConditionHides))
		UStaticMesh* Mesh;
};

UCLASS()
class INVENTORY_WPLUGIN_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item Structure", DisplayName = "Item Structure")
		FItemStruct ItemStruct;

};
