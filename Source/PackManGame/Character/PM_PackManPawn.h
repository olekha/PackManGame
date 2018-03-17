// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

#include <Components/InputComponent.h>

#include <GameFramework/PlayerController.h>

#include "PM_PackManPawn.generated.h"

UENUM(BlueprintType)
enum class EDirectionEnum : uint8
{
	D_UP UMETA(DisplayName = "Up"),
	D_DOWN UMETA(DisplayName = "Down"),
	D_LEFT UMETA(DisplayName = "Left"),
	D_RIGHT UMETA(DisplayName = "Right")
};

UCLASS()
class PACKMANGAME_API APM_PackManPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APM_PackManPawn();

	virtual void PossessedBy(AController* NewController);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		USphereComponent* SphereCollisionRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controll")
		float minSlideSize;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnTuchPressed(ETouchIndex::Type index, FVector location);
	void OnTuchReleased(ETouchIndex::Type index, FVector location);

private:
	FVector2D touchCoord;
	FVector2D releaseCoord;
	FVector2D touchDirection;

	bool isTouch;

	APlayerController* OwnerPlayerController;

	bool CheckIsEnoughSlide(float first, float next);
	void DefineDirection();
};
