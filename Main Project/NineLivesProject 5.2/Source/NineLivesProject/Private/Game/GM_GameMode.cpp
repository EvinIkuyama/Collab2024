// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GM_GameMode.h"


// Sets default values
AGM_GameMode::AGM_GameMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGM_GameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGM_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

