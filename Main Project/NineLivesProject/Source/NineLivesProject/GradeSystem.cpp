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

void UGradeSystem::PlayerGrade(FString& endText)
{
	//insert the check values when needed, check the values and equivalate a percentage
	FString tempText;
	float percentageAverage = 0.5f;

	if (percentageAverage >= 1.0f)
	{
		tempText = "S";
	}
	else if (percentageAverage >= gradeRanges[0])
	{
		tempText = "A";
	}
	else if (percentageAverage >= gradeRanges[1])
	{
		tempText = "B";
	}
	else if (percentageAverage >= gradeRanges[2])
	{
		tempText = "C";
	}
	else if (percentageAverage >= gradeRanges[3])
	{
		tempText = "D";
	}
	else if (percentageAverage >= gradeRanges[4])
	{
		tempText = "E";
	}
	else if (percentageAverage >= gradeRanges[5])
	{
		tempText = "F";
	}
	else
	{
		tempText = "Invalid Score";
	}
}