// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Pickup.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPickup : public UInterface
{
	GENERATED_BODY()
};

class NINELIVESPROJECT_API IPickup
{
	GENERATED_BODY()


public:
	UFUNCTION()
	virtual void PickedUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
