// Fill out your copyright notice in the Description page of Project Settings.

#include "PM_PackManPawn.h"


// Sets default values
APM_PackManPawn::APM_PackManPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollisionRoot = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	SetRootComponent(SphereCollisionRoot);

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(RootComponent);
	//PawnMesh->SetRelativeLocation(FVector(.0f, .0f, .0f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(SpringArm);
}

void APM_PackManPawn::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);

	OwnerPlayerController = Cast<APlayerController>(NewController);
}

// Called when the game starts or when spawned
void APM_PackManPawn::BeginPlay()
{
	Super::BeginPlay();
}

void APM_PackManPawn::OnTuchPressed(ETouchIndex::Type index, FVector location)
{
	//UE_LOG(LogTemp, Log, TEXT("Touch"));
	isTouch = true;
	touchCoord = FVector2D(location.X, location.Y);
}

void APM_PackManPawn::OnTuchReleased(ETouchIndex::Type index, FVector location)
{
	//UE_LOG(LogTemp, Log, TEXT("Released"));
	isTouch = false;
	releaseCoord = FVector2D(location.X, location.Y);
	touchDirection = releaseCoord - touchCoord;

}

// Called every frame
void APM_PackManPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isTouch) {
		UE_LOG(LogTemp, Log, TEXT("Touch : %f : %f"), touchDirection.X, touchDirection.Y);
	}
}

// Called to bind functionality to input
void APM_PackManPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &APM_PackManPawn::OnTuchPressed);
	InputComponent->BindTouch(IE_Released, this, &APM_PackManPawn::OnTuchReleased);
}

