// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GradeSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NINELIVESPROJECT_API UGradeSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGradeSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "WinClass")
		int PlayerGrade(int seconds);

	UFUNCTION(BlueprintCallable, Category = "WinClass")
		void UpdateGradeRanges(float star3Range, float star2Range, float star1Range);

	UFUNCTION(BlueprintCallable, Category = "WinClass")
		float FastestTimeCheck(float currentFastTime, float levelTime);

	UPROPERTY(EditAnywhere, Category = "WinClass")
		float gradeRanges[3];

	UPROPERTY(EditAnywhere, Category = "WinClass")
		int index;
};
