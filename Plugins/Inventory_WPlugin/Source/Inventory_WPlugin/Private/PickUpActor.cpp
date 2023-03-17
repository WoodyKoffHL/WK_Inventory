// Woodykoff Inventory for Unreal Engine
// Special for github


#include "PickUpActor.h"
#include "Item.h"

// Sets default values
APickUpActor::APickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SceneComponent->SetupAttachment(GetRootComponent());

	SkeletalMesh = CreateAbstractDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	SkeletalMesh->SetupAttachment(SceneComponent);
	StaticMesh->SetupAttachment(SceneComponent);

}

// Called when the game starts or when spawned
void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorDefaults();

}

// Called every frame
void APickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpActor::SetActorDefaults()
{
	if (Item) {
		switch (Item.GetDefaultObject()->ItemStruct.Skeletal) {
		case true: SkeletalMesh->SetSkeletalMesh(Item.GetDefaultObject()->ItemStruct.SkeletalMesh);
		default: StaticMesh->SetStaticMesh(Item.GetDefaultObject()->ItemStruct.Mesh);
		} 			
	}
}

