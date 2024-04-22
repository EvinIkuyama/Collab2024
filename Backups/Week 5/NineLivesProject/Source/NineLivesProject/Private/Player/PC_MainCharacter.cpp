// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PC_MainCharacter.h"


// Sets default values
APC_MainCharacter::APC_MainCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APC_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APC_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

