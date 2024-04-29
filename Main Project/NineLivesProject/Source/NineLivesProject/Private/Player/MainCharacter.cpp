// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainCharacter.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	playerCamera -> SetupAttachment(GetRootComponent());
	playerCamera -> SetRelativeLocation(FVector(-10.0f, 0.0f, 60.0f));
	
	CameraForwardVector = playerCamera->GetForwardVector();
	WallJumpingVector = CameraForwardVector * wallJumpFactor;
	launchPower = wallJumpFactor * 1.2f;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::JumpOffWall(bool isWallRunning)
{
	if(isWallRunning)
	{
		LaunchCharacter(FVector (WallJumpingVector.X, WallJumpingVector.Y, launchPower), true, true);
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

