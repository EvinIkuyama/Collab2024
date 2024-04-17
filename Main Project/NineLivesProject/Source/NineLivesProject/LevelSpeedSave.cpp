// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSpeedSave.h"

void ULevelSpeedSave::CallLevelData(int levelNumber, int& levelRetries, int& levelSeconds, int& levelStars)
{
	levelRetries = levelSaveRetries[levelNumber];
	levelSeconds = levelSaveSeconds[levelNumber];
	levelStars = levelSaveSeconds[levelNumber];
}