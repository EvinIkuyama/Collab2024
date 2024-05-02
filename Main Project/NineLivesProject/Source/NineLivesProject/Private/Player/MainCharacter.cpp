// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_PlayerCamera -> SetupAttachment(GetRootComponent());
	_PlayerCamera -> SetRelativeLocation(FVector(-10.0f, 0.0f, 60.0f));

	_PlayerMovement = GetCharacterMovement();
	_PlayerVelocity = _PlayerMovement->GetLastUpdateVelocity();
	
	CameraForwardVector = _PlayerCamera->GetForwardVector();
	WallJumpingVector = CameraForwardVector * wallJumpFactor;
	
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
		LaunchCharacter(FVector (_PlayerVelocity.X * wallJumpFactor, _PlayerVelocity.Y * wallJumpFactor, wallJumpFactor), true, true);
	}
}

void AMainCharacter::WallRunning(float alpha)
{
	_PlayerVelocity.Set(_PlayerVelocity.X, _PlayerVelocity.Y, 0.0f);
	_PlayerMovement->GravityScale = 0.0f;
}

void AMainCharacter::StopWallRunning(bool isWallRunning)
{
	_PlayerMovement->GravityScale = 1.75f;
	if(coyoteTime < 1.0f)
	{
		isWallRunning = true;
		GetWorld()->GetTimerManager().SetTimer(_CoyoteTimer, this, &AMainCharacter::IncreaseTimerValue, 0.1f, true);
	}
	else if(coyoteTime > 1.0f)
	{
		isWallRunning = false;
		StopTimerValue();
	}
}

void AMainCharacter::SlidingEvent()
{
	if(_PlayerMovement->IsMovingOnGround())
	{
		GetCapsuleComponent()->SetCapsuleHalfHeight(20.0f, true);
	}
}

void AMainCharacter::SlidingPhysics()
{
	FVector SlideForwardVector(GetActorForwardVector().X, GetActorForwardVector().Y, 0.0f);
	SlideMultiplier = SlideForwardVector * slideFactor;
	_PlayerMovement->AddImpulse(SlideMultiplier);
}

bool AMainCharacter::EndingSlide()
{
	if(_PlayerMovement->IsMovingOnGround())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AMainCharacter::IncreaseTimerValue()
{
	if(_CoyoteTimer.IsValid())
	{
		coyoteTime += 0.1f;
	}
}

void AMainCharacter::StopTimerValue()
{
	GetWorld()->GetTimerManager().ClearTimer(_CoyoteTimer);
	coyoteTime = 0.0f;
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

