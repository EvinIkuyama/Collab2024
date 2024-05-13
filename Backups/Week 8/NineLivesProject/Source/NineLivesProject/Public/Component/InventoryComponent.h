// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Potion.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NINELIVESPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TObjectPtr<APotion>> Inventory;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int HeldIndex;

	void AddToInventory(APotion* PotionToAdd);
};
