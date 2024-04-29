// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/EndLevelBox.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MainCharacter.h"


// Sets default values
AEndLevelBox::AEndLevelBox()
{
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(Box);
	Box->OnComponentBeginOverlap.AddUniqueDynamic(this,&AEndLevelBox::ChangeLevel);
}


void AEndLevelBox::ChangeLevel(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*TArray<AActor> enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AEnemy::StaticClass(),enemies);
	if(OtherActor->GetClass()->IsChildOf(AMainCharacter::StaticClass()) && enemies.Num()== 0)*/
	
	if(OtherActor->GetClass()->IsChildOf(AMainCharacter::StaticClass()))
	{
		UGameplayStatics::OpenLevel(GetWorld(),LevelToGo);
	}

}
