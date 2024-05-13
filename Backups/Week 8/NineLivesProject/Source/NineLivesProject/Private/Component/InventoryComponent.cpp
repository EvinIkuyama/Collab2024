// Fill out your copyright notice in the Description page of Project Settings.



#include "Component/InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	
}

void UInventoryComponent::AddToInventory(APotion* PotionToAdd)
{
	Inventory.Add(PotionToAdd);
}

