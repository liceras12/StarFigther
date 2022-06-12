// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarFigtherGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AStarFigtherGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AStarFigtherGameModeBase();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
