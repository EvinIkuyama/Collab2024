// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Potion.h"

#include "Component/InventoryComponent.h"

// Sets default values
APotion::APotion()
{
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(Collider);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	Collider->OnComponentBeginOverlap.AddUniqueDynamic(this,&APotion::PickedUp_Implementation);
}

void APotion::PickedUp_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	TObjectPtr<UInventoryComponent> inv = nullptr;
	if(OtherActor->GetOwner()->GetComponentByClass<UInventoryComponent>() != nullptr)
	{
		inv = OtherActor->GetOwner()->GetComponentByClass<UInventoryComponent>();
	}
	
	if(inv != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(1,5.0f,FColor::Red,TEXT("PICKEDUP"));
		inv->AddToInventory(this);
		Destroy();
	}
}
