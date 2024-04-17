// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndLevelBox.generated.h"

class UBoxComponent;

UCLASS()
class NINELIVESPROJECT_API AEndLevelBox : public AActor
{
	GENERATED_BODY()

public:

	AEndLevelBox();
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBoxComponent> Box;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FName LevelToGo;

	UFUNCTION()
	void ChangeLevel(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
	                 bFromSweep, const FHitResult& SweepResult);
};
