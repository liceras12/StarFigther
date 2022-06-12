// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StarFigtherPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AStarFigtherPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
