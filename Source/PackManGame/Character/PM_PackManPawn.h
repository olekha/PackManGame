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

UCLASS()
class PACKMANGAME_API APM_PackManPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APM_PackManPawn();

	virtual void PossessedBy(AController* NewController);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnTuchPressed(ETouchIndex::Type index, FVector location);
	void OnTuchReleased(ETouchIndex::Type index, FVector location);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	USphereComponent* SphereCollisionRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="Pawn")
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UCameraComponent* PlayerCamera;

private:
	FVector2D touchCoord;
	FVector2D releaseCoord;
	FVector2D touchDirection;

	bool isTouch;

	APlayerController* OwnerPlayerController;
};
