// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaStrategy.h"
#include "StrategyRetirada.generated.h"

UCLASS()
class STARFIGTHER_API AStrategyRetirada : public AActor, public INaveEnemigaStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyRetirada();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Execute the Maneuver of this Strategy
	virtual void Maneuver() override;
};
