// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/DataTable.h"

#include "PM_GridCell.generated.h"

UENUM(BlueprintType)
enum class ECellPurpose : uint8 
{
	P_Empty UMETA(DisplayName = "Empty"),
	P_Block UMETA(DisplayName = "Block"),
	P_Regular UMETA(DisplayName = "Regular"),
	P_Extra UMETA(DisplayName = "Extra"),
	P_Fruit UMETA(DisplayName = "Fruit")
};

USTRUCT(Blueprintable)
struct FCellType : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	ECellPurpose cellPurpose;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	int scorePoints;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "CellType")
	UStaticMesh* bonusMesh = nullptr;
};

UCLASS()
class PACKMANGAME_API APM_GridCell : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APM_GridCell();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CellSettings")
	UBoxComponent* boxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CellSettings")
	UStaticMeshComponent* bonusMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CellSettings")
	UDataTable* DataTable;

	UFUNCTION(BlueprintCallable, Category = "Cell")
	int GetScorePoints();

	UFUNCTION(BlueprintCallable, Category = "Cell")
	ECellPurpose GetCellPurpose();

	UFUNCTION(BlueprintCallable, Category = "Cell")
	bool CheckIsPicked();

	UFUNCTION(BlueprintCallable, Category = "Cell")
	void Pick();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void SetInitialCellValues();

	ECellPurpose cellPurpose;
	int scorePoints; 

	bool isPicked;
	
};
