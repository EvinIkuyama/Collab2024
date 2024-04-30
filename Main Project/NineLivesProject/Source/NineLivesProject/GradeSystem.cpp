// Fill out your copyright notice in the Description page of Project Settings.


#include "GradeSystem.h"

// Sets default values for this component's properties
UGradeSystem::UGradeSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGradeSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGradeSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UGradeSystem::PlayerGrade(int seconds, FString& endText)
{
	//insert the check values when needed, check the values and equivalate a percentage
	FString tempText;
	int tempSeconds = seconds;

	if (tempSeconds < gradeRanges[0])
	{
		tempText = "3 STAR";
	}
	else if (tempSeconds < gradeRanges[1])
	{
		tempText = "2 STAR";
	}
	else if (tempSeconds < gradeRanges[2])
	{
		tempText = "1 STAR";
	}
	else
	{
		tempText = "0 STAR";
	}

	return tempText;
}