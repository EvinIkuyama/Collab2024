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

int UGradeSystem::PlayerGrade(int seconds)
{
	//insert the check values when needed, check the values and equivalate a percentage
	int tempSeconds = seconds;

	if (tempSeconds < gradeRanges[0])
	{
		index = 3;
	}
	else if (tempSeconds < gradeRanges[1])
	{
		index = 2;
	}
	else if (tempSeconds < gradeRanges[2])
	{
		index = 1;
	}
	else
	{
		index = 0;
	}

	return index;
}

void UGradeSystem::UpdateGradeRanges(float star3Range, float star2Range, float star1Range)
{
	gradeRanges[0] = star3Range;
	gradeRanges[1] = star2Range;
	gradeRanges[2] = star1Range;
}

float UGradeSystem::FastestTimeCheck(float currentFastTime, float levelTime)
{
	if (levelTime < currentFastTime)
	{
		return levelTime;
	}
	else if (currentFastTime == 0.0f)
	{
		return levelTime;
	}
	else
	{
		return currentFastTime;
	}

}