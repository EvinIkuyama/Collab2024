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

	//UPROPERTY(EditAnywhere, Category = "TimeSave")
		ULevelData levelSaves[3];

	UFUNCTION(BlueprintCallable, Category = "TimeSave")
		void CallLevelData(int levelNumber,int& levelRetries ,int& levelSeconds);
};

UCLASS(BlueprintType)
class ULevelData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "DataSave")
	int retries;
	UPROPERTY(EditAnywhere, Category = "DataSave")
	int seconds;
};
