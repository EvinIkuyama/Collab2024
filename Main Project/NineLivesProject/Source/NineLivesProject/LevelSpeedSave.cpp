// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSpeedSave.h"

void ULevelSpeedSave::CallLevelData(int levelNumber, int& levelRetries, int& levelSeconds)
{
	levelRetries = levelSaveRetries[levelNumber];
	levelSeconds = levelSaveSeconds[levelNumber];
}