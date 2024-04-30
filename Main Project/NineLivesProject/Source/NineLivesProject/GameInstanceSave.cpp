// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceSave.h"

void UGameInstanceSave::CallLevelData(int levelNumber, int& levelRetries, int& levelSeconds, int& levelStars)
{
	levelRetries = levelSaveRetries[levelNumber];
	levelSeconds = levelSaveSeconds[levelNumber];
	levelStars = levelSaveSeconds[levelNumber];
}

void UGameInstanceSave::SaveLevelData(int levelNumber, int levelRetries, int levelSeconds, int levelStars)
{
	levelSaveRetries[levelNumber] = levelRetries;
	levelSaveSeconds[levelNumber] = levelSeconds;
	levelSaveSeconds[levelNumber] = levelStars;
}