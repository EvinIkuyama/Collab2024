// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
		int levelSaveRetries[3];

	UPROPERTY(EditAnywhere, Category = "TimeSave")
		int levelSaveSeconds[3];

	UFUNCTION(BlueprintCallable, Category = "TimeSave")
		void CallLevelData(int levelNumber,int& levelRetries ,int& levelSeconds);
};
