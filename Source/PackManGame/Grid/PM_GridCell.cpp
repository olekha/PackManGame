// Fill out your copyright notice in the Description page of Project Settings.

#include "PM_GridCell.h"


// Sets default values
APM_GridCell::APM_GridCell()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ROOT"));
	SetRootComponent(boxCollision);

	bonusMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BonusMesh"));
	bonusMesh->SetupAttachment(RootComponent);
}

int APM_GridCell::GetScorePoints()
{
	return scorePoints;
}

ECellPurpose APM_GridCell::GetCellPurpose()
{
	return cellPurpose;
}

bool APM_GridCell::CheckIsPicked()
{
	return isPicked;
}

void APM_GridCell::Pick()
{
	if (isPicked) { return; }

	isPicked = true;
	SetActorHiddenInGame(true);
}

// Called when the game starts or when spawned
void APM_GridCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APM_GridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

