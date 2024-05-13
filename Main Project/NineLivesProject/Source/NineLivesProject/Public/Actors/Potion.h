// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Interface/Pickup.h"
#include "Potion.generated.h"

UENUM(BlueprintType)
enum class Enum_ActiveElement : uint8
{
	Fire,
	Wind,
	Water,
	Null,
};

UCLASS()
class NINELIVESPROJECT_API APotion : public AActor, public IPickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APotion();

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TObjectPtr<USphereComponent> Collider;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	Enum_ActiveElement Type;

	UFUNCTION(BlueprintCallable)
	virtual void PickedUp_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
	                                     bFromSweep, const FHitResult& SweepResult);
protected:
	


};
