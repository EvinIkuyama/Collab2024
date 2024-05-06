// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define NumOfLevels 4
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstanceSave.generated.h"

/**
 * 
 */
UCLASS()
class NINELIVESPROJECT_API UGameInstanceSave : public UGameInstance
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveRetries[NumOfLevels];

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		float levelSaveSeconds[NumOfLevels];

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveStars[NumOfLevels];

	UFUNCTION(BlueprintCallable, Category = "TimeSave")
		void CallLevelData(int levelNumber, int& levelRetries, float& levelSeconds, int& levelStars);

	UFUNCTION(BlueprintCallable, Category = "TimeSave")
		void SaveLevelData(int levelNumber, int levelRetries, float levelSeconds, int levelStars);
};
