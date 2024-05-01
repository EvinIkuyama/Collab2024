// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class NINELIVESPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> _PlayerCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCharacterMovementComponent> _PlayerMovement;
	UPROPERTY()
	FVector _PlayerVelocity;

	//Wall Running
	UFUNCTION(BlueprintCallable)
	void JumpOffWall(bool isWallRunning);
	UFUNCTION(BlueprintCallable)
	void WallRunning(float alpha);
	UFUNCTION(BlueprintCallable)
	void StopWallRunning(bool isWallRunning);

	//Sliding
	UFUNCTION(BlueprintCallable)
	void SlidingEvent();
	UFUNCTION(BlueprintCallable)
	void SlidingPhysics();
	UFUNCTION(BlueprintCallable)
	bool EndingSlide();
	
	void IncreaseTimerValue();
	void StopTimerValue();
	
	float wallJumpFactor = 750.0f;
	float launchPower;
	float slideFactor = 17000.0f;
	
	FVector WallJumpingVector;
	FVector CameraForwardVector;
	FVector SlideMultiplier;
	
	FTimerHandle _CoyoteTimer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float coyoteTime;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
