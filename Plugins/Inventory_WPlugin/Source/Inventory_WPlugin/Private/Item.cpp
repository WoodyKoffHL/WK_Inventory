// Woodykoff Inventory for Unreal Engine
// Special for github

#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Off for Tick. 
	//To expand the functionality associated with the work of each frame - True
	PrimaryActorTick.bCanEverTick = false;
	if (!ItemStruct.ItemIcon) {
		//Set default icon for item
		static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultIcon(TEXT("Texture2D'/Inventory_WPlugin/UI/DefaultIcon.DefaultIcon'"));
		ItemStruct.ItemIcon = DefaultIcon.Object;
	}

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

