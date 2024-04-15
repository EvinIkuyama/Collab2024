// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define NumOfLevels 3
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LevelSpeedSave.generated.h"

/**
 * 
 */
UCLASS()
class NINELIVESPROJECT_API ULevelSpeedSave : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveRetries[NumOfLevels];

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveSeconds[NumOfLevels];

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveStars[NumOfLevels];

	UFUNCTION(BlueprintCallable, Category = "TimeSave")
		void CallLevelData(int levelNumber,int& levelRetries ,int& levelSeconds, int& levelStars);
};
